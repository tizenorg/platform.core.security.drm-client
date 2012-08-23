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
 * @file 		drm_client_ipc.h
 * @brief       DRM Client Inter process communication declarations.
 * @author      Harsha Shekar (h.shekar@samsung.com)
 * @version     0.1
 * @history     0.1: DRM Client Inter process communication declarations.
 */

#ifndef __DRM_CLIENT_IPC_H__
#define __DRM_CLIENT_IPC_H__

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus */

#include "drm_client_types.h"

/*
 * DRM Socket Path
 */
#define	DRM_SOCK_PATH		"/tmp/DrmSocket"

/*
 * Maximum Size of Cookie
 */
#define	DRM_MAX_LEN_COOKIE	 	(20)

/**
* Maximum Request Data length
*/
#define DRM_MAX_REQUEST_DATA_LENGTH		(4096)

/**
* Maximum Response Data length
*/
#define DRM_MAX_RESPONSE_DATA_LENGTH	(4096)

/**
* Maximum number of Data Items
*/
#define DRM_MAX_DATA_ITEMS_NUM (5)

/**
* Maximum Read/Write Chunk Size
*/
#define DRM_MAX_CHUNK_SIZE (10 * 1024)

/**
* Maximum concurrent clients supported
*/
#define DRM_MAX_CLIENT_SUPPORTED 5

/**
* Maximum callback data size
*/
#define DRM_MAX_CB_DATA_SIZE 256



/**
 * @enum drm_request_api_e
 * @brief DRM API names.
 */
typedef enum {
	DRM_API_NONE,				/**< For initialization purpose */
	DRM_IS_DRM_FILE,			/**< Is DRM file */
	DRM_GET_FILE_TYPE,			/**< Get DRM file type */
	DRM_GET_LICENSE_STATUS,		/**< Get License Status */
	DRM_GET_CONTENT_INFO,		/**< Get Content Information */
	DRM_GET_FILE_INFO,			/**< Get DRM file Information */
	DRM_GET_CONSTRAINT_INFO,	/**< Get Constraint Information */
	DRM_IS_ACTION_ALLOWED,		/**< Is Action allowed */
	DRM_GET_DATA,				/**< Get Data */
	DRM_PROCESS_REQUEST,		/**< Process Request */
	DRM_API_MAX					/**< Max enum value */
} drm_request_api_e;

/**
 * @struct drm_client_cb_data_s
 * @brief DRM operation callback information structure
 * with additional information.
 */
typedef struct
{
	/** Client Id */
	int client_id;

	/** Callback operation info */
	drm_user_operation_info_s callback_operation_info;

	/** Callback user data */
	char call_bk_data[DRM_MAX_CB_DATA_SIZE];
} drm_client_cb_data_s;

/**
 * @struct 	drm_client_cb_info_s
 * @brief 	Client Callback info.
 * @remark	Stores details about Registered client callbacks
 */
typedef struct {

	/** Client Id */
	int client_id;

	/** Callback */
	drm_operation_cb_s operation_callback;
} drm_client_cb_info_s;

/**
 * @struct 	drm_client_info_s
 * @brief 	Client Information structure.
 * @remark	It can be used to track drm clients.
 */
typedef struct {
	/** Active state for structure */
	int active;

	/** Client Id */
	int client_id;

	/** Process Id */
	int p_id;

	/** Thread Id */
	int thread_id;

	/** Sync Socket */
	int sync_sock_fd;

	/** Async Socket */
	int async_sock_fd;
} drm_client_info_s;

/**
 * @struct drm_req_fixed_data_s
 * @brief DRM input parameter(request) fixed data structure.
 */
typedef struct {

	/* Client Request Type */
	drm_request_api_e api_name;

	/* Permission type */
	drm_permission_type_e permission_type;

	/* Action type */
	drm_action_type_e action;

	/* Request Data Type */
	drm_data_type_e data_type;

	/* Process Request Type */
	drm_request_type_e request_type;

	/* Client specific Information */
	drm_client_info_s client_info;

	/** No of data items(Pointers) */
	unsigned int num_data_items;

	/** Length of each data item */
	unsigned int data_length[DRM_MAX_DATA_ITEMS_NUM];

	/* Request Data */
	char request_data[DRM_MAX_REQUEST_DATA_LENGTH];

}drm_req_fixed_data_s;

/**
 * @struct drm_request_data_s
 * @brief DRM input parameter(request) structure.
 */
typedef struct {

	/** Fixed Data */
	drm_req_fixed_data_s fixed_data;

	/** Array of individual data items */
	char *data_items[DRM_MAX_DATA_ITEMS_NUM];

} drm_request_data_s;

/**
 * @struct drm_resp_fixed_data_s
 * @brief DRM output parameter(response) fixed data structure.
 */
typedef struct {

	/* Response Result */
	drm_result_e resp_result;

	/* Bool value */
	drm_bool_type_e bool_val;

	/* file type */
	drm_file_type_e file_type;

	/* License Status */
	drm_license_status_e lic_status;

	/** No of data items(Pointers) */
	unsigned int num_data_items;

	/** Length of each data item */
	unsigned int data_length[DRM_MAX_DATA_ITEMS_NUM];

	/* Response Data */
	char response_data[DRM_MAX_RESPONSE_DATA_LENGTH];

} drm_resp_fixed_data_s;

/**
 * @struct drm_response_data_s
 * @brief DRM output parameter(response) structure.
 */
typedef struct {

	/** Fixed Data */
	drm_resp_fixed_data_s fixed_data;

	/** Array of individual data items */
	char *data_items[DRM_MAX_DATA_ITEMS_NUM];

} drm_response_data_s;

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
int drm_client_comm(drm_request_data_s *client_in, drm_response_data_s *server_out);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /*__DRM_CLIENT_IPC_H__ */
