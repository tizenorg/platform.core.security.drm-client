/*
 *  drm-client
 *
 * Copyright (c) 2000 - 2011 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Contact: Hakjoo Ko <hakjoo.ko@samsung.com>
 * 			Mahendra Kumar Prajapat <mahendra.p@samsung.com>
 *			Harsha Shekar <h.shekar@samsung.com>
 *
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/**
 * @file 		drm_client_ipc.cpp
 * @brief       DRM Client Inter process communication definitions.
 * @author      Mahendra Kumar Prajapat (mahendra.p@samsung.com)
 * @author      Harsha Shekar (h.shekar@samsung.com)
 * @version     0.1
 * @history     0.1: DRM Client Inter process communication definitions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <pthread.h>

#include "drm_client_ipc.h"
#include "drm_client_log.h"

/**
 * @brief Sync socket fd on a thread basis
 */
static __thread int sockfd = -1;

/**
 * @brief Client info on a thread basis
 */
static __thread drm_client_info_s client_info;

/**
 * @brief Async socket fd on a process basis
 */
static int async_sockfd = -1;

/**
 * @brief Storing the registered callbacks
 */
static drm_client_cb_info_s client_cb_info[DRM_MAX_CLIENT_SUPPORTED];

/**
 * @brief Mutex to serialise async socket per process
 */
pthread_mutex_t async_mutex = PTHREAD_MUTEX_INITIALIZER;


/**
 *  Private function
 *
 *
 * @param[in]	callinfo	Callback information
 * @return		void
 * @remarks
 * @see
 * @since       0.1
 */
void __search_client_info_cb(drm_client_cb_data_s* callinfo)
{
	int i = 0;
	for (i = 0; i < DRM_MAX_CLIENT_SUPPORTED; i++) {

		DRM_CLIENT_LOG("client_cb_info[i].client_id = %d", client_cb_info[i].client_id);
		DRM_CLIENT_LOG("callinfo->client_id = %d", callinfo->client_id);

		if (client_cb_info[i].client_id == callinfo->client_id) {
			if (client_cb_info[i].operation_callback.callback) {

				client_cb_info[i].operation_callback.callback(
						&callinfo->callback_operation_info,
						&callinfo->call_bk_data);
			} else {
				DRM_CLIENT_EXCEPTION("Callback function is NULL here!!!!");
			}
			/* Callback found, return from here */
			return;
		}
	}

	if (DRM_MAX_CLIENT_SUPPORTED == i) {
		/* Client information for the process not yet stored */
		DRM_CLIENT_EXCEPTION("Callback information not stored!!, i = %d", i);
		return;
	}
}

/**
 *  Private function
 *	Thread handler
 *
 * @param[in]	thread_arg	Thread argument
 * @return		void
 * @remarks
 * @see
 * @since       0.1
 */
void *client_async_cb_handler(void *thread_arg)
{
	drm_client_cb_data_s callinfo;
	int retval = 0, result = 0;
	memset(&callinfo, 0x00, sizeof(drm_client_cb_data_s));

	/* This Async thread will be running for the entire process alive time
	 * to handle all the async related operations sent from the server
	 */
	while(1)
 	{
		/* waiting for data on async socket */
		if ((retval = read(async_sockfd, &callinfo, sizeof(drm_client_cb_data_s))) < 0) {
			DRM_CLIENT_EXCEPTION(" Async call_back read error!!, retval = %d, error = %s",
					retval, strerror(errno));
			result = DRM_RETURN_COMMUNICATION_ERROR;
			goto ErrorExit;
		}
 		DRM_CLIENT_LOG("Calling application  call back function from client");

 		/* Search the client cb info from the received client_id and call corresponding handler */
 		__search_client_info_cb(&callinfo);
 	}
 	ErrorExit:
 	if(-1 != async_sockfd)
 		close(async_sockfd);
 	return NULL;
}



/**
 *  Private function
 *	Create Async socket
 *
 * @param[in]	client_in	Client request data
 * @return		void
 * @remarks
 * @see
 * @since       0.1
 */
static int  __create_async_socket(drm_request_data_s *client_in)
{
	struct sockaddr_un clientaddr;
	int temp_len_sock = 0;
	unsigned int retval = 0;
	drm_result_e result = DRM_RETURN_SUCCESS;
	pthread_t async_thread = 0;
	int rv = 0;
	/* Create a Async socket */
	if ((async_sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
	{
		DRM_CLIENT_EXCEPTION("socket error!!, async_sockfd = %d, error = %s",async_sockfd, strerror(errno));
		result = DRM_RETURN_COMMUNICATION_ERROR;
		goto ErrorExit;
	}
	DRM_CLIENT_LOG(" async_sockfd created successful , async_sockfd = %d",async_sockfd);

	temp_len_sock = strlen(DRM_SOCK_PATH);
	memset(&clientaddr, 0x00, sizeof(clientaddr));
	clientaddr.sun_family = AF_UNIX;
	memcpy(clientaddr.sun_path, DRM_SOCK_PATH, temp_len_sock);
	clientaddr.sun_path[temp_len_sock] = '\0';

	/* connect to the server, on same server SOCK_PATH */
	if ((retval = connect(async_sockfd, (struct sockaddr*) &clientaddr,sizeof(clientaddr))) < 0)
	{
		DRM_CLIENT_EXCEPTION("Async socket connect error!!, retval = %d, error = %s",retval, strerror(errno));
		result = DRM_RETURN_COMMUNICATION_ERROR;
		goto ErrorExit;
	}
	DRM_CLIENT_LOG("async_sockfd Connection success retval=%d ", retval);

	/* Store the necessary information into the client info and send to server */
	client_info.p_id = getpid();
	client_info.thread_id = pthread_self();
	client_info.client_id = client_info.p_id + client_info.thread_id;
	DRM_CLIENT_LOG("Client_id = %d", client_info.client_id);
	client_info.sync_sock_fd = -1;
	client_info.async_sock_fd = async_sockfd;

	/* Send the server */
	if ((retval = write(async_sockfd, (char*) &client_info,sizeof(client_info))) < 0|| retval < sizeof(client_info))
	{
		DRM_CLIENT_EXCEPTION("Async write error!!, retval = %d, error = %s",retval, strerror(errno));
		result = DRM_RETURN_COMMUNICATION_ERROR;
		goto ErrorExit;
	}
	DRM_CLIENT_LOG("async_sockfd Sent info to server");

	/* Separate thread is created to handle async callback handling */
	rv = pthread_create(&async_thread, NULL, client_async_cb_handler, NULL);
	if (rv != 0) {
		DRM_CLIENT_EXCEPTION("pthread_create creation failed for Async socket");
		goto ErrorExit;
	}
	DRM_CLIENT_LOG("pthread_create success = [%d]", async_thread);
	DRM_CLIENT_LOG("Async socket create success");
	return 1;

ErrorExit:
	if(async_sockfd)
		close(async_sockfd);
	return 0;
}

/**
 *  Private function
 *	Create Sync socket
 *
 * @param[in]	client_in	Client request data
 * @return		void
 * @remarks
 * @see
 * @since       0.1
 */
static int __get_socket(drm_request_data_s *client_in)
{
	int fd;
	int temp_len_sock = 0;
	unsigned int retval = 0;
	struct sockaddr_un clientaddr;
	static int num_clients = 0;

	if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
		DRM_CLIENT_EXCEPTION("sockfd socket create error!!, sockfd = %d, error = %s",fd, strerror(errno));
		goto ErrorExit;
	}
	DRM_CLIENT_LOG(" sockfd created successful , sockfd = %d",fd);

	/* Set parameters to be used in connect */
	temp_len_sock = strlen(DRM_SOCK_PATH);
	memset(&clientaddr, 0x00, sizeof(clientaddr));
	clientaddr.sun_family = AF_UNIX;
	memcpy(clientaddr.sun_path, DRM_SOCK_PATH, temp_len_sock);
	clientaddr.sun_path[temp_len_sock] = '\0';

	if ((retval = connect(fd, (struct sockaddr*)&clientaddr,sizeof(clientaddr))) < 0)
	{
		DRM_CLIENT_EXCEPTION("connect error!!, retval = %d, error = %s",retval, strerror(errno));
		goto ErrorExit;
	}
	DRM_CLIENT_LOG("sync socket is created sockfd = %d retval = %d",fd,retval);

	client_info.p_id = getpid();
	client_info.thread_id = pthread_self();
	client_info.client_id = client_info.p_id + client_info.thread_id;
	DRM_CLIENT_LOG("Client_id = %d", client_info.client_id);
	client_info.sync_sock_fd = fd;
	client_info.async_sock_fd = async_sockfd;

	/* Store the callback on a thread basis to be handled for each client */
	if (((drm_initiator_info_s*) (client_in->fixed_data.request_data))->operation_callback.callback) {
		if (num_clients <= (DRM_MAX_CLIENT_SUPPORTED - 1)) {
			DRM_CLIENT_LOG("num_clients = %d", num_clients);
			client_cb_info[num_clients].client_id = client_info.client_id;
			memcpy(&client_cb_info[num_clients].operation_callback,
					&(((drm_initiator_info_s*) (client_in->fixed_data.request_data))->operation_callback),
					sizeof(drm_operation_cb_s));
			num_clients++;
		} else {
			DRM_CLIENT_EXCEPTION("Num of clients exceeded!!, num_clients = %d", num_clients);
			goto ErrorExit;
		}
	}

	DRM_CLIENT_LOG("Writing socket sockfd = %d size=%d",fd,sizeof(client_info));

	DRM_CLIENT_LOG("client_info.client_id before send = %d", client_info.client_id);
	if ((retval = write(fd, (char*) &client_info,sizeof(client_info))) < 0 || retval < sizeof(client_info))
	{
		DRM_CLIENT_EXCEPTION("write error!!, retval = %d, error = %s",retval, strerror(errno));
		goto ErrorExit;
	}
	DRM_CLIENT_LOG("Written socket sockfd = %d retval=%d",fd,retval);

	return fd;
ErrorExit:

	if (fd)
		close(fd);
	return 0;
}

/**
 *  This API is used to send a request to the Server to call corresponding API
 *
 * @param[in]	client_in	Carries the input parameters of Client API to Server
 * @param[out]	server_out	Carries the output parameters of Client API from Server
 * @return		0 on success & other values on failure
 * @remarks
 * @see
 * @since 0.1
 */
int drm_client_comm(drm_request_data_s *client_in, drm_response_data_s *server_out)
{
	unsigned int retval = 0;
	drm_request_data_s send_data;
	drm_response_data_s recv_data;
	drm_result_e result = DRM_RETURN_SUCCESS;
	unsigned int offset = 0;
	unsigned int bytes_write = DRM_MAX_CHUNK_SIZE;
	unsigned int bytes_read = DRM_MAX_CHUNK_SIZE;

	/* memset the structures */
	memset(&send_data, 0x0, sizeof(drm_request_data_s));
	memset(&recv_data, 0x0, sizeof(drm_response_data_s));

	DRM_CLIENT_LOG("drm_client_comm in");

	/* Create Async socket if not created already for this process */
	pthread_mutex_lock(&async_mutex);
	if (-1 == async_sockfd) {
		DRM_CLIENT_LOG("Creating async socket for current process!!");
		if(!__create_async_socket(client_in))
		{
			DRM_CLIENT_EXCEPTION("__create_async_socket returned error");
			pthread_mutex_unlock(&async_mutex);
			goto ErrorExit;
		}
	}
	pthread_mutex_unlock(&async_mutex);

	/* Create Sync Socket on a per thread basis */
	if (-1 == sockfd) {
		DRM_CLIENT_LOG("initial sockfd = %d", sockfd);
		sockfd = __get_socket(client_in);
		DRM_CLIENT_LOG("after get_socket sockfd = %d", sockfd);
		if (!sockfd) {
			DRM_CLIENT_EXCEPTION("get_socket failed sockfd = %d", sockfd);
			result = DRM_RETURN_COMMUNICATION_ERROR;
			goto ErrorExit;
		}
	}

	/* Copy the data received from the client into local */
	memcpy(&send_data, client_in, sizeof(drm_request_data_s));
	/* First write the static structures */
	DRM_CLIENT_LOG("Writing socket sockfd = %d size=%d",sockfd,sizeof(drm_req_fixed_data_s));
	if ((retval = write(sockfd, (char*) &send_data.fixed_data,sizeof(drm_req_fixed_data_s))) < 0|| retval < sizeof(drm_req_fixed_data_s))
	{
		DRM_CLIENT_EXCEPTION("write error!!, retval = %d, error = %s",retval, strerror(errno));
		result = DRM_RETURN_COMMUNICATION_ERROR;
		goto ErrorExit;
	}
	DRM_CLIENT_LOG("Written socket sockfd = %d retval=%d",sockfd,retval);

	/* Now send the additional data items if any */
	if (send_data.fixed_data.num_data_items > 0) {
		for (unsigned int i = 0; i < send_data.fixed_data.num_data_items; i++)
		{
			if (send_data.fixed_data.data_length[i]	> DRM_MAX_CHUNK_SIZE)
			{
				while (bytes_write > 0)
				{
					DRM_CLIENT_LOG("Writing socket sockfd = %d size=%d",sockfd,bytes_write);
					if ((retval = write(sockfd,(void*)(send_data.data_items[i] + offset), bytes_write)) < 0 || retval < bytes_write)
					{
						DRM_CLIENT_EXCEPTION("write error!!, retval = %d, error = %s",retval, strerror(errno));
						result = DRM_RETURN_COMMUNICATION_ERROR;
						goto ErrorExit;
					}
					DRM_CLIENT_LOG("Written socket sockfd = %d retval=%d",sockfd,retval);
					offset += DRM_MAX_CHUNK_SIZE;
					bytes_write = (int)(send_data.fixed_data.data_length[i] - offset) > (int)DRM_MAX_CHUNK_SIZE ? DRM_MAX_CHUNK_SIZE :(int)(send_data.fixed_data.data_length[i] - offset);
					DRM_CLIENT_LOG("offset = %d, bytes_write = %d", offset, bytes_write);
				}
				bytes_write = DRM_MAX_CHUNK_SIZE;
			}
			else
			{
				DRM_CLIENT_LOG("Writing socket sockfd = %d size=%d",sockfd,send_data.fixed_data.data_length[i]);
				if ((retval = write(sockfd, send_data.data_items[i], send_data.fixed_data.data_length[i])) < 0 || retval < send_data.fixed_data.data_length[i])
				{
					DRM_CLIENT_EXCEPTION("write error!!, retval = %d, error = %s",retval, strerror(errno));
					result = DRM_RETURN_COMMUNICATION_ERROR;
					goto ErrorExit;
				}
				DRM_CLIENT_LOG("Written socket sockfd = %d retval=%d",sockfd,retval);
			}
		}
	}
	/* Set offset to be used again */
	offset = 0;
	/* Read the fixed data into the receive structure */
	DRM_CLIENT_LOG("Reading socket sockfd = %d size=%d",sockfd,sizeof(drm_resp_fixed_data_s));
	if ((retval = read(sockfd, (char*) &recv_data.fixed_data,sizeof(drm_resp_fixed_data_s))) < 0 || retval < sizeof(drm_resp_fixed_data_s))
	{
		DRM_CLIENT_EXCEPTION("read error!!, retval = %d, error = %s",retval, strerror(errno));
		result = DRM_RETURN_COMMUNICATION_ERROR;
		goto ErrorExit;
	}
	DRM_CLIENT_LOG("Read socket sockfd = %d retval=%d",sockfd,retval);
	if (recv_data.fixed_data.num_data_items > 0) {
		for (unsigned int loop = 0; loop < recv_data.fixed_data.num_data_items; loop++)
		{
			/* Allocate memory for the data items */
			recv_data.data_items[loop] = (char*) malloc(recv_data.fixed_data.data_length[loop]);
			if (!recv_data.data_items[loop]) {
				DRM_CLIENT_EXCEPTION("Memory Allocation Error!, buf = %p",recv_data.data_items[loop]);
				recv_data.fixed_data.resp_result=DRM_RETURN_INSUFFICIENT_MEMORY;
				goto ErrorExit;
			}
			if (recv_data.fixed_data.data_length[loop] > DRM_MAX_CHUNK_SIZE)
			{
				while (bytes_read > 0)
				{
					DRM_CLIENT_LOG("Reading socket sockfd = %d size=%d",sockfd,bytes_read);
					if ((retval = read(sockfd,(void*)(recv_data.data_items[loop] + offset),bytes_read)) < 0 || retval < bytes_read)
					{
						DRM_CLIENT_EXCEPTION("Read error!!, retval = %d, error = %s", retval,strerror(errno));
						recv_data.fixed_data.resp_result=DRM_RETURN_COMMUNICATION_ERROR;
						goto ErrorExit;
					}
					DRM_CLIENT_LOG("Read socket sockfd = %d retval=%d",sockfd,retval);
					offset += DRM_MAX_CHUNK_SIZE;
					bytes_read = (int)(recv_data.fixed_data.data_length[loop] - offset) > (int) DRM_MAX_CHUNK_SIZE ? DRM_MAX_CHUNK_SIZE :(int)(recv_data.fixed_data.data_length[loop] - offset);
					DRM_CLIENT_LOG("offset = %d, bytes_read = %d", offset, bytes_read);
				}
				bytes_read = DRM_MAX_CHUNK_SIZE;
			}
			else
			{
				DRM_CLIENT_LOG("Reading socket sockfd = %d size=%d",sockfd,recv_data.fixed_data.data_length[loop]);
				if ((retval = read(sockfd,recv_data.data_items[loop],recv_data.fixed_data.data_length[loop])) < 0 || retval < recv_data.fixed_data.data_length[loop])
				{
					DRM_CLIENT_EXCEPTION("Read error!!, retval = %d, error = %s",retval, strerror(errno));
					recv_data.fixed_data.resp_result=DRM_RETURN_COMMUNICATION_ERROR;
					goto ErrorExit;
				}
				DRM_CLIENT_LOG("Read socket sockfd = %d retval=%d",sockfd,retval);
			}
		}
	}
	/* Copy the data from the server back to the client into the output parameter */
	memcpy(server_out, &recv_data, sizeof(drm_response_data_s));
	DRM_CLIENT_LOG("drm_client_comm success!!!, result = %d", result);
	return result;

	ErrorExit:
	if (sockfd) {
		close(sockfd);
	}
	return result;
}
