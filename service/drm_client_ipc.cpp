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

#include "drm_client_ipc.h"
#include "drm_client_log.h"

/**
 *  This API is used to send a request to the Server to call corresponding API
 *
 * @param[in]	client_in	Carries the input parameters of Client API to Server
 * @param[out]	server_out	Carries the output parameters of Client API from Server
 * @return		0 on success & other values on failure
 * @remarks
 * @see
 * @since      	0.1
 */
int drm_client_comm(drm_request_data_s *client_in, drm_response_data_s *server_out)
{
	int sockfd = 0;
	struct sockaddr_un clientaddr;
	drm_request_data_s send_data;
	drm_response_data_s recv_data;
	int temp_len_sock = 0;
	int retval = 0;
	drm_result_e result = DRM_RETURN_SUCCESS;

	unsigned int offset = 0;
	int bytes_write = DRM_MAX_CHUNK_SIZE;
	int bytes_read = DRM_MAX_CHUNK_SIZE;

	/* memset the structures */
	memset(&send_data, 0x0, sizeof(drm_request_data_s));
	memset(&recv_data, 0x0, sizeof(drm_response_data_s));

	/* Create a socket */
	if ((sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
		DRM_CLIENT_EXCEPTION("socket error!!, sockfd = %d, error = %s",
				sockfd, strerror(errno));
		result = DRM_RETURN_COMMUNICATION_ERROR;
		goto ErrorExit;
	}

	/* Copy the data received from the client into local */
	memcpy(&send_data, client_in, sizeof(drm_request_data_s));

	/* Set parameters to be used in connect */
	temp_len_sock = strlen(DRM_SOCK_PATH);

	memset(&clientaddr, 0x00, sizeof(clientaddr));
	clientaddr.sun_family = AF_UNIX;
	memcpy(clientaddr.sun_path, DRM_SOCK_PATH, temp_len_sock);
	clientaddr.sun_path[temp_len_sock] = '\0';

	if ((retval = connect(sockfd, (struct sockaddr*) &clientaddr,
			sizeof(clientaddr))) < 0) {
		DRM_CLIENT_EXCEPTION("connect error!!, retval = %d, error = %s",
				retval, strerror(errno));
		result = DRM_RETURN_COMMUNICATION_ERROR;
		goto ErrorExit;
	}

	/* First write the static structures */
	DRM_CLIENT_LOG("Writing socket sockfd = %d size=%d",sockfd,sizeof(drm_req_fixed_data_s));
	if ((retval = write(sockfd, (char*) &send_data.fixed_data,
			sizeof(drm_req_fixed_data_s))) < 0) {
		DRM_CLIENT_EXCEPTION("write error!!, retval = %d, error = %s",
				retval, strerror(errno));
		result = DRM_RETURN_COMMUNICATION_ERROR;
		goto ErrorExit;
	}
	DRM_CLIENT_LOG("Written socket sockfd = %d retval=%d",sockfd,retval);

	/* Now send the additional data items if any */
	if (send_data.fixed_data.num_data_items > 0) {

		for (int i = 0; i < send_data.fixed_data.num_data_items; i++) {

			if (send_data.fixed_data.data_length[i]	> DRM_MAX_CHUNK_SIZE) {

				while (bytes_write > 0) {
					DRM_CLIENT_LOG("Writing socket sockfd = %d size=%d",sockfd,bytes_write);
					if ((retval = write(sockfd,
							(void*)(send_data.data_items[i] + offset), bytes_write))
							< 0) {
						DRM_CLIENT_EXCEPTION(
								"write error!!, retval = %d, error = %s",
								retval, strerror(errno));
						result = DRM_RETURN_COMMUNICATION_ERROR;
						goto ErrorExit;
					}
					DRM_CLIENT_LOG("Written socket sockfd = %d retval=%d",sockfd,retval);

					offset += DRM_MAX_CHUNK_SIZE;
					bytes_write = (int)(send_data.fixed_data.data_length[i] - offset) > (int)DRM_MAX_CHUNK_SIZE ?
							DRM_MAX_CHUNK_SIZE :
							(int)(send_data.fixed_data.data_length[i] - offset);

					DRM_CLIENT_LOG("offset = %d, bytes_write = %d", offset, bytes_write);

				}
				bytes_write = 0;
			} else {
				DRM_CLIENT_LOG("Writing socket sockfd = %d size=%d",sockfd,send_data.fixed_data.data_length[i]);
				if ((retval = write(sockfd, send_data.data_items[i], send_data.fixed_data.data_length[i])) < 0) {
					DRM_CLIENT_EXCEPTION("write error!!, retval = %d, error = %s",
							retval, strerror(errno));
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
	if ((retval = read(sockfd, (char*) &recv_data.fixed_data,
			sizeof(drm_resp_fixed_data_s))) < 0) {
		DRM_CLIENT_EXCEPTION("read error!!, retval = %d, error = %s",
				retval, strerror(errno));
		result = DRM_RETURN_COMMUNICATION_ERROR;
		goto ErrorExit;
	}
	DRM_CLIENT_LOG("Read socket sockfd = %d retval=%d",sockfd,retval);

	if (recv_data.fixed_data.num_data_items > 0) {

		for (int loop = 0; loop < recv_data.fixed_data.num_data_items; loop++) {

			/* Allocate memory for the data items */
			recv_data.data_items[loop] = (char*) malloc(
					recv_data.fixed_data.data_length[loop]);
			if (!recv_data.data_items[loop]) {
				DRM_CLIENT_EXCEPTION(
						"Memory Allocation Error!, buf = %p",
						recv_data.data_items[loop]);
				recv_data.fixed_data.resp_result =
						DRM_RETURN_INSUFFICIENT_MEMORY;
				goto ErrorExit;
			}

			if (recv_data.fixed_data.data_length[loop] > DRM_MAX_CHUNK_SIZE) {

				while (bytes_read > 0) {
					DRM_CLIENT_LOG("Reading socket sockfd = %d size=%d",sockfd,bytes_read);
					if ((retval = read(sockfd,
							(void*)(recv_data.data_items[loop] + offset),
							bytes_read)) < 0) {
						DRM_CLIENT_EXCEPTION(
								"Read error!!, retval = %d, error = %s", retval,
								strerror(errno));
						recv_data.fixed_data.resp_result =
								DRM_RETURN_COMMUNICATION_ERROR;
						goto ErrorExit;
					}
					DRM_CLIENT_LOG("Read socket sockfd = %d retval=%d",sockfd,retval);

					offset += DRM_MAX_CHUNK_SIZE;
					bytes_read = (int)(recv_data.fixed_data.data_length[loop] - offset) > (int) DRM_MAX_CHUNK_SIZE ?
							DRM_MAX_CHUNK_SIZE :
							(int)(recv_data.fixed_data.data_length[loop] - offset);

					DRM_CLIENT_LOG("offset = %d, bytes_write = %d", offset, bytes_read);

				}
				bytes_write = 0;
			} else
			{
				DRM_CLIENT_LOG("Reading socket sockfd = %d size=%d",sockfd,recv_data.fixed_data.data_length[loop]);
				if ((retval = read(sockfd,
						recv_data.data_items[loop],
						recv_data.fixed_data.data_length[loop])) < 0) {
					DRM_CLIENT_EXCEPTION("Read error!!, retval = %d, error = %s",
							retval, strerror(errno));
					recv_data.fixed_data.resp_result =
							DRM_RETURN_COMMUNICATION_ERROR;
					goto ErrorExit;
				}
				DRM_CLIENT_LOG("Read socket sockfd = %d retval=%d",sockfd,retval);
			}
		}
	}

	/* Copy the data from the server back to the client into the output parameter */
	memcpy(server_out, &recv_data, sizeof(drm_response_data_s));

	DRM_CLIENT_LOG("drm_client_comm success!!!, result = %d", result);

ErrorExit:
	if(-1 != sockfd)
		close(sockfd);

	return result;
}
