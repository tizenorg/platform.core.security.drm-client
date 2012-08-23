/*
 * drm-client
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
 * @file 		drm_client.cpp
 * @brief       DRM Client API defintions.
 * @author      Mahendra Kumar Prajapat (mahendra.p@samsung.com)
 * @author      Harsha Shekar (h.shekar@samsung.com)
 * @version     0.1
 * @history     0.1: First version of DRM Client API Definitions.
 */

#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "drm_client.h"
#include "drm_client_ipc.h"
#include "drm_client_log.h"
//#include "security-server.h"

#include <glib.h>

#ifndef EXPORT_API
#define EXPORT_API __attribute__((visibility("default")))
#endif



/**
 *  Private function
 *
 *
 * @param[in]	file_path		Specifies the pointer points a DRM file path.
 * @return		This function returns DRM file type.
 * @remarks
 * @see
 * @since       0.1
 */
static drm_file_type_e _drm_client_get_file_type(const char* file_path);

/**
 *  An application can check that a file is DRM file
 *  (OMA DRM, PlayReady, DivX etc.)
 *
 * @param[in]	file_path		Specifies the pointer points a DRM file path.
 * @param[out]	is_drm_file 	DRM_TRUE if the input file is a DRM file
 * 								else DRM_FALSE.
 * @return		0 on success, else a negative error value
 * @retval		DRM_RETURN_SUCCESS on success
 * @retval		DRM_RETURN_INVALID_ARG if arguments are invalid
 * @retval		DRM_RETURN_COMMUNICATION_ERROR if socket error
 * @retval		DRM_RETURN_INTERNAL_ERROR if operation error
 *
 * @remarks
 * @see
 * @since       0.1
 */
EXPORT_API int drm_is_drm_file(const char *file_path,
		drm_bool_type_e *is_drm_file)
{
	DRM_CLIENT_LOG("Enter: file_path = %s", (!file_path) ? NULL:file_path);
	drm_request_data_s req_data;
	drm_response_data_s resp_data;
	int ret_comm = 0;
	drm_file_type_e file_type = DRM_TYPE_UNDEFINED;
	int ret_cpy = 0;

	/* Check input parameters */
	if (!file_path || '\0' == file_path[0] || !is_drm_file) {
		DRM_CLIENT_EXCEPTION("Invalid Arg!!, file_path = %p, is_drm_file = %p",
				file_path, is_drm_file);
		return DRM_RETURN_INVALID_ARG;
	}

	file_type = _drm_client_get_file_type(file_path);

	switch (file_type) {
	case DRM_TYPE_OMA_V1:
	case DRM_TYPE_OMA_V2:
	case DRM_TYPE_PLAYREADY:
	case DRM_TYPE_PLAYREADY_ENVELOPE:
		/* All the above 4 cases correspond to a file being DRM file! */
		DRM_CLIENT_LOG("file_type = %d", file_type);
		*is_drm_file = DRM_TRUE;
		break;

	case DRM_TYPE_DIVX: {

		/* memset the structures */
		memset(&req_data, 0x0, sizeof(drm_request_data_s));
		memset(&resp_data, 0x0, sizeof(drm_response_data_s));

		/* In this case, further analysis of headers required to identify DRM file */
		/* Contact the server to perform operations */

		/* Store the input parameters to the Request Data structure to be sent to server */
		if ((ret_cpy = g_strlcpy(req_data.fixed_data.request_data, file_path,
				DRM_MAX_LEN_FILEPATH)) >= DRM_MAX_LEN_FILEPATH) {
			DRM_CLIENT_EXCEPTION("file_path = %s, filepath_len = %d, ret_cpy = %d",
					file_path, strlen(file_path), ret_cpy);
			return DRM_RETURN_INVALID_ARG;
		}

		/* Tell the server which API to be used */
		req_data.fixed_data.api_name = DRM_IS_DRM_FILE;

		/* Call the Client Communication API */
		if ((ret_comm = drm_client_comm(&req_data, &resp_data)) != 0) {
			DRM_CLIENT_EXCEPTION("drm_client_comm error!!, ret_comm = %d", ret_comm);
			return DRM_RETURN_COMMUNICATION_ERROR;
		}

		/* Copy the response obtained from the server into the output parameter */
		if (resp_data.fixed_data.resp_result != 0) {
			DRM_CLIENT_EXCEPTION("Error returned from server!!, resp_data.fixed_data.resp_result = 0x%x",
					resp_data.fixed_data.resp_result);
			*is_drm_file = DRM_FALSE;
			goto ErrorExit;
		} else {
			DRM_CLIENT_LOG("resp_data.fixed_data.resp_result = 0x%x", resp_data.fixed_data.resp_result);
			*is_drm_file = resp_data.fixed_data.bool_val;
		}

	}
		break;

	case DRM_TYPE_UNDEFINED:
		DRM_CLIENT_LOG("file_type = %d", file_type);
		*is_drm_file = DRM_FALSE;
		break;

	default:
		DRM_CLIENT_EXCEPTION("Undefined file type!!");
		*is_drm_file = DRM_FALSE;
		goto ErrorExit;
	}

	DRM_CLIENT_LOG("Exit:Success!!, is_drm_file = %d",
			*is_drm_file);
	return DRM_RETURN_SUCCESS;

ErrorExit:
	DRM_CLIENT_EXCEPTION("Exit:failed!!, is_drm_file = %d",
			*is_drm_file);
	return DRM_RETURN_INTERNAL_ERROR;

}

/**
 *  An application can get DRM file type of the file that is
 *  specified in file_path
 *
 * @param[in]	file_path	Specifies the pointer points a DRM file path.
 * @param[out]	file_type	DRM file type.
 * @return		0 on success, else a negative error value
 * @retval		DRM_RETURN_SUCCESS on success
 * @retval		DRM_RETURN_INVALID_ARG if arguments are invalid
 * @remarks
 * @see
 * @since      	0.1
 */
EXPORT_API int drm_get_file_type(const char *file_path, drm_file_type_e *file_type)
{
	DRM_CLIENT_LOG("Enter: file_path = %s", (!file_path) ? NULL:file_path);

	/* Check input parameters */
	if (!file_path || '\0' == file_path[0] || !file_type) {
		DRM_CLIENT_EXCEPTION("Invalid Arg!!, file_path = %p, file_type = %p",
				file_path, file_type);
		return DRM_RETURN_INVALID_ARG;
	}

	*file_type = _drm_client_get_file_type(file_path);
	DRM_CLIENT_LOG("Exit:Success!! file_type = %d", *file_type);
	return DRM_RETURN_SUCCESS;
}

/**
 * An application can check that a DRM file has valid license or not.
 *
 * @param[in]	file_path	   	DRM file path.
 * @param[in]	perm_type		Enumeration type of permission.
 * @param[out]	license_status	license status.
 * @return		0 on success, else a negative error value
 * @retval		DRM_RETURN_SUCCESS on success
 * @retval		DRM_RETURN_INVALID_ARG if arguments are invalid
 * @retval		DRM_RETURN_COMMUNICATION_ERROR if socket error
 * @retval		DRM_RETURN_INTERNAL_ERROR if operation error
 * @remarks
 * @see
 * @since      	0.1
 */
EXPORT_API int drm_get_license_status(const char *file_path,
		drm_permission_type_e perm_type,
		drm_license_status_e *license_status)
{
	DRM_CLIENT_LOG("Enter: file_path = %s, perm_type = %d",
			(!file_path) ? NULL:file_path, perm_type);

	drm_request_data_s req_data;
	drm_response_data_s resp_data;
	int ret_comm = 0;
	drm_result_e result = DRM_RETURN_SUCCESS;
	int ret_cpy = 0;

	/* memset the structures */
	memset(&req_data, 0x0, sizeof(drm_request_data_s));
	memset(&resp_data, 0x0, sizeof(drm_response_data_s));

	/* Check input parameters */
	if (!file_path || '\0' == file_path[0] || !license_status) {
		DRM_CLIENT_EXCEPTION("Invalid Arg!!, file_path = %p, license_status = %p",
				file_path, license_status);
		return DRM_RETURN_INVALID_ARG;
	}

	/* Store the input parameters to the Request Data structure to be sent to server */
	if ((ret_cpy = g_strlcpy(req_data.fixed_data.request_data, file_path,
			DRM_MAX_LEN_FILEPATH)) >= DRM_MAX_LEN_FILEPATH) {
		DRM_CLIENT_EXCEPTION("file_path = %s, filepath_len = %d, ret_cpy = %d",
				file_path, strlen(file_path), ret_cpy);
		return DRM_RETURN_INVALID_ARG;
	}

	req_data.fixed_data.permission_type = perm_type;

	/* Tell the server which API to be used */
	req_data.fixed_data.api_name = DRM_GET_LICENSE_STATUS;

	/* Send Data to DRM server */
	/* Call the Client Communication API */
	if ((ret_comm = drm_client_comm(&req_data, &resp_data)) != 0) {
		DRM_CLIENT_EXCEPTION("drm_client_comm error!!, ret_comm = %d", ret_comm);
		result = DRM_RETURN_COMMUNICATION_ERROR;
		goto ErrorExit;
	}

	/* Copy the response obtained from the server into the output parameter */
	if (resp_data.fixed_data.resp_result != 0) {
		DRM_CLIENT_EXCEPTION("Error returned from server!!, resp_data.fixed_data.resp_result = 0x%x",
				resp_data.fixed_data.resp_result);
		*license_status = DRM_LICENSE_STATUS_UNDEFINED;
		result = resp_data.fixed_data.resp_result;
		goto ErrorExit;
	} else {
		DRM_CLIENT_LOG("resp_data.fixed_data.resp_result = 0x%x", resp_data.fixed_data.resp_result);
		*license_status = resp_data.fixed_data.lic_status;
	}

	DRM_CLIENT_LOG("*license_status = %d", *license_status);

ErrorExit:
	if (result != DRM_RETURN_SUCCESS) {
		DRM_CLIENT_EXCEPTION("Exit:failed!!, result = 0x%x", result);
	} else {
		DRM_CLIENT_LOG("Exit:Success!!, result = 0x%x", result);
	}

	return result;
}

/**
 * An application can get DRM Content information for the file
 * specified in file_path.
 *
 * @param[in]	file_path	   	DRM file path.
 * @param[out]	content_info	Content information.
 * @return		0 on success, else a negative error value
 * @retval		DRM_RETURN_SUCCESS on success
 * @retval		DRM_RETURN_INVALID_ARG if arguments are invalid
 * @retval		DRM_RETURN_COMMUNICATION_ERROR if socket error
 * @retval		DRM_RETURN_INTERNAL_ERROR if operation error
 * @remarks
 * @see
 * @since      	0.1
 */
EXPORT_API int drm_get_content_info(const char *file_path,
		drm_content_info_s *content_info)
{
	DRM_CLIENT_LOG("Enter: file_path = %s", (!file_path) ? NULL:file_path);

	drm_request_data_s req_data;
	drm_response_data_s resp_data;
	int ret_comm = 0;
	drm_result_e result = DRM_RETURN_SUCCESS;
	int ret_cpy = 0;

	/* memset the structures */
	memset(&req_data, 0x0, sizeof(drm_request_data_s));
	memset(&resp_data, 0x0, sizeof(drm_response_data_s));

	/* Check input parameters */
	if (!file_path || '\0' == file_path[0] || !content_info) {
		DRM_CLIENT_EXCEPTION("Invalid Arg!!, file_path = %p, content_info = %p",
				file_path, content_info);
		return DRM_RETURN_INVALID_ARG;
	}

	/* memset the output structure */
	memset(content_info, 0x00, sizeof(drm_content_info_s));

	/* Store the input parameters to the Request Data structure to be sent to server */
	if ((ret_cpy = g_strlcpy(req_data.fixed_data.request_data, file_path,
			DRM_MAX_LEN_FILEPATH)) >= DRM_MAX_LEN_FILEPATH) {
		DRM_CLIENT_EXCEPTION("file_path = %s, filepath_len = %d, ret_cpy = %d",
				file_path, strlen(file_path), ret_cpy);
		return DRM_RETURN_INVALID_ARG;
	}

	/* Tell the server which API to be used */
	req_data.fixed_data.api_name = DRM_GET_CONTENT_INFO;

	/* Send Data to DRM server */
	/* Call the Client Communication API */
	if ((ret_comm = drm_client_comm(&req_data, &resp_data)) != 0) {
		DRM_CLIENT_EXCEPTION("drm_client_comm error!!, ret_comm = %d", ret_comm);
		result = DRM_RETURN_COMMUNICATION_ERROR;
		goto ErrorExit;
	}

	/* Copy the response obtained from the server into the output parameter */
	if (resp_data.fixed_data.resp_result != 0) {
		DRM_CLIENT_EXCEPTION("Error returned from server!!, resp_data.fixed_data.resp_result = 0x%x",
				resp_data.fixed_data.resp_result);
		memset(content_info, 0x00, sizeof(drm_content_info_s));
		result = resp_data.fixed_data.resp_result;
		goto ErrorExit;
	} else {
		DRM_CLIENT_LOG("resp_data.fixed_data.resp_result = 0x%x", resp_data.fixed_data.resp_result);
		memcpy(content_info, &resp_data.fixed_data.response_data, sizeof(drm_content_info_s));
	}

	DRM_CLIENT_LOG("content_info->author = %s", content_info->author);
	DRM_CLIENT_LOG("content_info->content_id = %s", content_info->content_id);
	DRM_CLIENT_LOG("content_info->content_url = %s", content_info->content_url);
	DRM_CLIENT_LOG("content_info->copyright = %s", content_info->copyright);
	DRM_CLIENT_LOG("content_info->description = %s", content_info->description);
	DRM_CLIENT_LOG("content_info->icon_uri = %s", content_info->icon_uri);
	DRM_CLIENT_LOG("content_info->info_url = %s", content_info->info_url);
	DRM_CLIENT_LOG("content_info->mime_type = %s", content_info->mime_type);
	DRM_CLIENT_LOG("content_info->rights_url = %s", content_info->rights_url);
	DRM_CLIENT_LOG("content_info->title = %s", content_info->title);

ErrorExit:
if (result != DRM_RETURN_SUCCESS) {
		DRM_CLIENT_EXCEPTION("Exit:failed!!, result = 0x%x", result);
	} else {
		DRM_CLIENT_LOG("Exit:Success!!, result = 0x%x", result);
	}

	return result;
}

/**
 * An application can get file information of a DRM file.
 *
 * @param[in]	file_path	   	DRM file path.
 * @param[out]	fileInfo		DRM file info.
 * @return		0 on success, else a negative error value
 * @retval		DRM_RETURN_SUCCESS on success
 * @retval		DRM_RETURN_INVALID_ARG if arguments are invalid
 * @retval		DRM_RETURN_COMMUNICATION_ERROR if socket error
 * @retval		DRM_RETURN_INTERNAL_ERROR if operation error
 * @remarks
 * @see
 * @since      	0.1
 */
EXPORT_API int drm_get_file_info(const char *file_path,
		drm_file_info_s *fileInfo)
{
	DRM_CLIENT_LOG("Enter: file_path = %s", (!file_path) ? NULL:file_path);
	drm_request_data_s req_data;
	drm_response_data_s resp_data;
	int ret_comm = 0;
	drm_result_e result = DRM_RETURN_SUCCESS;
	int ret_cpy = 0;

	/* memset the structures */
	memset(&req_data, 0x0, sizeof(drm_request_data_s));
	memset(&resp_data, 0x0, sizeof(drm_response_data_s));

	/* Check input parameters */
	if (!file_path || '\0' == file_path[0] || !fileInfo) {
		DRM_CLIENT_EXCEPTION("Invalid Arg!!, file_path = %p, fileInfo = %p",
				file_path, fileInfo);
		return DRM_RETURN_INVALID_ARG;
	}

	DRM_CLIENT_LOG("file_path = %s", file_path);

	/* memset the output structure */
	memset(fileInfo, 0x00, sizeof(drm_file_info_s));

	/* Store the input parameters to the Request Data structure to be sent to server */
	if ((ret_cpy = g_strlcpy(req_data.fixed_data.request_data, file_path,
			DRM_MAX_LEN_FILEPATH)) >= DRM_MAX_LEN_FILEPATH) {
		DRM_CLIENT_EXCEPTION("file_path = %s, filepath_len = %d, ret_cpy = %d",
				file_path, strlen(file_path), ret_cpy);
		return DRM_RETURN_INVALID_ARG;
	}

	/* Tell the server which API to be used */
	req_data.fixed_data.api_name = DRM_GET_FILE_INFO;

	/* Send Data to DRM server */
	/* Call the Client Communication API */
	if ((ret_comm = drm_client_comm(&req_data, &resp_data)) != 0) {
		DRM_CLIENT_EXCEPTION("drm_client_comm error!!, ret_comm = %d", ret_comm);
		result = DRM_RETURN_COMMUNICATION_ERROR;
		goto ErrorExit;
	}

	/* Copy the response obtained from the server into the output parameter */
	if (resp_data.fixed_data.resp_result != 0) {
		DRM_CLIENT_EXCEPTION("Error returned from server!!, resp_data.fixed_data.resp_result = 0x%x",
				resp_data.fixed_data.resp_result);
		memset(fileInfo, 0x00, sizeof(drm_file_info_s));
		result = resp_data.fixed_data.resp_result;
		goto ErrorExit;
	} else {
		DRM_CLIENT_LOG("resp_data.fixed_data.resp_result = 0x%x", resp_data.fixed_data.resp_result);
		memcpy(fileInfo, &resp_data.fixed_data.response_data, sizeof(drm_file_info_s));
	}

	DRM_CLIENT_LOG("fileInfo->oma_info.method = %d", fileInfo->oma_info.method);
	DRM_CLIENT_LOG("fileInfo->oma_info.version = %d", fileInfo->oma_info.version);

ErrorExit:
	if (result != DRM_RETURN_SUCCESS) {
		DRM_CLIENT_EXCEPTION("Exit:failed!!, result = 0x%x", result);
	} else {
		DRM_CLIENT_LOG("Exit:Success!!, result = 0x%x", result);
	}
	return result;
}

/**
 * An application can get constraints associated with
 * given permission & given file
 *
 * @param[in]	file_path	   		DRM file path.
 * @param[in]	perm_type			Enumeration type of permission.
 * @param[out]	constraint_info		Constraint info.
 * @return		0 on success, else a negative error value
 * @retval		DRM_RETURN_SUCCESS on success
 * @retval		DRM_RETURN_INVALID_ARG if arguments are invalid
 * @retval		DRM_RETURN_COMMUNICATION_ERROR if socket error
 * @retval		DRM_RETURN_INTERNAL_ERROR if operation error
 * @remarks
 * @see
 * @since      	0.1
 */
EXPORT_API int drm_get_constraint_info(const char *file_path,
		drm_permission_type_e perm_type,
		drm_constraint_info_s *constraint_info)
{
	DRM_CLIENT_LOG("Enter: file_path = %s, perm_type = %d",
			(!file_path) ? NULL:file_path, perm_type);

	drm_request_data_s req_data;
	drm_response_data_s resp_data;
	int ret_comm = 0;
	drm_result_e result = DRM_RETURN_SUCCESS;
	int ret_cpy = 0;

	/* memset the structures */
	memset(&req_data, 0x0, sizeof(drm_request_data_s));
	memset(&resp_data, 0x0, sizeof(drm_response_data_s));

	/* Check input parameters */
	if (!file_path || '\0' == file_path[0] || !constraint_info) {
		DRM_CLIENT_EXCEPTION("Invalid Arg!!, file_path = %p, constraint_info = %p",
				file_path, constraint_info);
		return DRM_RETURN_INVALID_ARG;
	}

	DRM_CLIENT_LOG("file_path = %s, perm_type = %d", file_path, perm_type);

	/* memset the output structure */
	memset(constraint_info, 0x00, sizeof(drm_constraint_info_s));

	/* Store the input parameters to the Request Data structure to be sent to server */
	if ((ret_cpy = g_strlcpy(req_data.fixed_data.request_data, file_path,
			DRM_MAX_LEN_FILEPATH)) >= DRM_MAX_LEN_FILEPATH) {
		DRM_CLIENT_EXCEPTION("file_path = %s, filepath_len = %d, ret_cpy = %d",
				file_path, strlen(file_path), ret_cpy);
		return DRM_RETURN_INVALID_ARG;
	}
	req_data.fixed_data.permission_type = perm_type;

	/* Tell the server which API to be used */
	req_data.fixed_data.api_name = DRM_GET_CONSTRAINT_INFO;

	/* Send Data to DRM server */
	/* Call the Client Communication API */
	if ((ret_comm = drm_client_comm(&req_data, &resp_data)) != 0) {
		DRM_CLIENT_EXCEPTION("drm_client_comm error!!, ret_comm = %d", ret_comm);
		result = DRM_RETURN_COMMUNICATION_ERROR;
		goto ErrorExit;
	}

	/* Copy the response obtained from the server into the output parameter */
	if (resp_data.fixed_data.resp_result != 0) {
		DRM_CLIENT_EXCEPTION("Error returned from server!!, resp_data.fixed_data.resp_result = 0x%x",
				resp_data.fixed_data.resp_result);
		memset(constraint_info, 0x00, sizeof(drm_constraint_info_s));
		result = resp_data.fixed_data.resp_result;
		goto ErrorExit;
	} else {
		DRM_CLIENT_LOG("resp_data.fixed_data.resp_result = 0x%x", resp_data.fixed_data.resp_result);
		memcpy(constraint_info, &resp_data.fixed_data.response_data, sizeof(drm_constraint_info_s));
	}

ErrorExit:
	if (result != DRM_RETURN_SUCCESS) {
		DRM_CLIENT_EXCEPTION("Exit:failed!!, result = 0x%x", result);
	} else {
		DRM_CLIENT_LOG("Exit:Success!!, result = 0x%x", result);
	}
	return result;
}

/**
 * An application can check the feasibility of actions to be
 * performed based on the type of DRM file.
 *
 * @param[in]	action	   			Action to be taken.
 * @param[in]	action_data 		Data needed to check action
 * 									allowed operation
 * @param[out]	is_allowed			DRM_TRUE if action is allowed
 * 									else DRM_FALSE
 * @return		0 on success, else a negative error value
 * @retval		DRM_RETURN_SUCCESS on success
 * @retval		DRM_RETURN_INVALID_ARG if arguments are invalid
 * @retval		DRM_RETURN_COMMUNICATION_ERROR if socket error
 * @retval		DRM_RETURN_INTERNAL_ERROR if operation error
 * @remarks
 * @see
 * @since      	0.1
 */
EXPORT_API int drm_is_action_allowed(drm_action_type_e action,
		drm_action_allowed_data_s *action_data,
		drm_bool_type_e *is_allowed)
{
	DRM_CLIENT_LOG("Enter: action = %d, action_data = %p", action, action_data);
	drm_request_data_s req_data;
	drm_response_data_s resp_data;
	int ret_comm = 0;
	drm_result_e result = DRM_RETURN_SUCCESS;

	/* memset the structures */
	memset(&req_data, 0x0, sizeof(drm_request_data_s));
	memset(&resp_data, 0x0, sizeof(drm_response_data_s));

	/* Check input parameters based on action type */
	switch(action){
	case DRM_IS_FORWARDING_ALLOWED:
	case DRM_HAS_VALID_SETAS_STATUS:
	{
		/* Check input parameters */
		if (!action_data->file_path
				|| '\0' == action_data->file_path[0] || !is_allowed) {
			DRM_CLIENT_EXCEPTION("Invalid Arg!!, action_data->file_path = %p,"
					" is_allowed = %p", action_data->file_path, is_allowed);
			return DRM_RETURN_INVALID_ARG;
		}
		DRM_CLIENT_LOG("action_data->file_path = %s, action = %d, data = %d",
				action_data->file_path, action, action_data->data);

		/* Copy the input parameters to the Request structure */
		req_data.fixed_data.action = action;
		memcpy(req_data.fixed_data.request_data, action_data,
				sizeof(drm_action_allowed_data_s));
		break;
	}

	case DRM_IS_DEVICE_ACTIVATED:
	case DRM_IS_VALID_SECURE_CLOCK:
	{
		/* Check input parameters */
		if (!is_allowed) {
			DRM_CLIENT_EXCEPTION("Invalid Arg!!,is_allowed = %p",is_allowed);
			return DRM_RETURN_INVALID_ARG;
		}

		/* Copy the input parameters to the Request structure */
		req_data.fixed_data.action = action;
		break;
	}

	default:
		DRM_CLIENT_EXCEPTION("Invalid action type=%d",action);
		return DRM_RETURN_INVALID_ARG;
	}

	/* Tell the server which API to be used */
	req_data.fixed_data.api_name = DRM_IS_ACTION_ALLOWED;

	/* Send Data to DRM server */
	/* Call the Client Communication API */
	if ((ret_comm = drm_client_comm(&req_data, &resp_data)) != 0) {
		DRM_CLIENT_EXCEPTION("drm_client_comm error!!, ret_comm = %d", ret_comm);
		result = DRM_RETURN_COMMUNICATION_ERROR;
		goto ErrorExit;
	}

	/* Copy the response obtained from the server into the output parameter */
	if (resp_data.fixed_data.resp_result != 0) {
		DRM_CLIENT_EXCEPTION("Error returned from server!!, resp_data.fixed_data.resp_result = 0x%x",
				resp_data.fixed_data.resp_result);
		*is_allowed = DRM_FALSE;
		result = resp_data.fixed_data.resp_result;
		goto ErrorExit;
	} else {
		DRM_CLIENT_LOG("resp_data.fixed_data.resp_result = 0x%x", resp_data.fixed_data.resp_result);
		*is_allowed = resp_data.fixed_data.bool_val;
	}

ErrorExit:
	if (result != DRM_RETURN_SUCCESS) {
		DRM_CLIENT_EXCEPTION("Exit:failed!!, result = 0x%x", result);
	} else {
		DRM_CLIENT_LOG("Exit:Success!!, result = 0x%x", result);
	}
	return result;
}

/**
 * An application can get the requested data from DRM.
 *
 * @param[in]	data_type	Data types as per enum drm_data_type_e.
 * @param[in]	input		Pointer to appropriate structure as per data_type.
 * @param[out]	output		Output data. Pointer to appropriate structure as
 * 							per data_type.
 *
 * @return		0 on success, else a negative error value
 * @retval		DRM_RETURN_SUCCESS on success
 * @retval		DRM_RETURN_INVALID_ARG if arguments are invalid
 * @retval		DRM_RETURN_COMMUNICATION_ERROR if socket error
 * @retval		DRM_RETURN_INTERNAL_ERROR if operation error
 * @remarks		Please typecast to appropriate data structures
 * 				as per data types.
 *
 * 				if data_type = DRM_DATA_TYPE_SECURE_CLOCK
 * 				then input type: input = NULL
 * 				and output type: output = pointer to struct
 * 				drm_secure_clock_data_s
 *
 * 				if data_type = DRM_DATA_TYPE_TRANSACTION_TRACKING_FLAG
 * 				then input type: input = NULL
 * 				and output type: output = pointer to int
 *
 * 				if data_type = DRM_DATA_TYPE_TRANSACTION_TRACKING_ID
 * 				then input type: input = pointer to file path (const char)
 * 				and output type: output = pointer to struct
 * 				drm_transaction_id_info_s
 *
 * 				if data_type = DRM_DATA_TYPE_DIVX_REGISTRATION_CODE
 * 				then input type: input = NULL
 * 				and output type: output = pointer to struct drm_code_info_s
 *
 * 				if data_type = DRM_DATA_TYPE_DIVX_DEREGISTRATION_CODE
 * 				then input type: input = NULL
 * 				and output type: output = pointer to struct drm_code_info_s
 *
 * @see
 * @since      	0.1
 */
EXPORT_API int drm_get_data(drm_data_type_e data_type, void *input, void *output)
{
	DRM_CLIENT_LOG("Enter: data_type = %d, input = %p, output = %p",
			data_type, input, output);
	/* Local Variables */
	drm_result_e result = DRM_RETURN_SUCCESS;
	drm_request_data_s req_data;
	drm_response_data_s resp_data;
	int ret_comm = 0;
	int ret_cpy = 0;

	/* memset the structures */
	memset(&req_data, 0x0, sizeof(drm_request_data_s));
	memset(&resp_data, 0x0, sizeof(drm_response_data_s));

	/* Check Input & Output Parameters and fill the Request data */
	switch (data_type) {
	case DRM_DATA_TYPE_SECURE_CLOCK:
	case DRM_DATA_TYPE_TRANSACTION_TRACKING_FLAG:
	case DRM_DATA_TYPE_DIVX_REGISTRATION_CODE:
	case DRM_DATA_TYPE_DIVX_DEREGISTRATION_CODE:
		if (!output) {
			DRM_CLIENT_EXCEPTION("Invalid arguments!!, output = %p", output);
			return DRM_RETURN_INVALID_ARG;
		}
		break;
	case DRM_DATA_TYPE_TRANSACTION_TRACKING_ID: {
		if (!input || ((char*)input)[0] == '\0' || !output) {
			DRM_CLIENT_EXCEPTION("Invalid arguments!!, input = %p, output = %p",
					input, output);
			return DRM_RETURN_INVALID_ARG;
		}

		/* Copy the input parameter to be sent as Request Data */
		if ((ret_cpy = g_strlcpy(req_data.fixed_data.request_data,
				(const gchar*) input, DRM_MAX_LEN_FILEPATH))
				>= DRM_MAX_LEN_FILEPATH) {
			DRM_CLIENT_EXCEPTION("file_path = %s, filepath_len = %d, ret_cpy = %d",
					(const char*)input, strlen(((const char*)input)), ret_cpy);
			return DRM_RETURN_INVALID_ARG;
		}
	}
		break;
	default:
		DRM_CLIENT_EXCEPTION("Invalid argument, data_type = %d", data_type);
		return DRM_RETURN_INVALID_ARG;
	}

	DRM_CLIENT_LOG("data_type=%d input=%p output=%p", data_type, input, output);

	/* Fill other parameters to be sent */
	req_data.fixed_data.data_type = data_type;

	/* Tell the server which API to be used */
	req_data.fixed_data.api_name = DRM_GET_DATA;

	/* Send Data to DRM server */
	/* Call the Client Communication API */
	if ((ret_comm = drm_client_comm(&req_data, &resp_data)) != 0) {
		DRM_CLIENT_EXCEPTION("drm_client_comm error!!, ret_comm = %d", ret_comm);
		result = DRM_RETURN_COMMUNICATION_ERROR;
		goto ErrorExit;
	}

	/* Copy the response obtained from the server into the output parameter */
	if (resp_data.fixed_data.resp_result != 0) {
		DRM_CLIENT_EXCEPTION("Error returned from server!!, resp_data.fixed_data.resp_result = 0x%x",
				resp_data.fixed_data.resp_result);

		result = resp_data.fixed_data.resp_result;
		goto ErrorExit;
	} else {
		DRM_CLIENT_LOG("resp_data.fixed_data.resp_result = 0x%x", resp_data.fixed_data.resp_result);

		/* Store the response result to the output based on the request data type */
		switch (data_type) {

		case DRM_DATA_TYPE_SECURE_CLOCK: {
			drm_secure_clock_data_s sec_clk_data = { 0, };

			/* Copy from response data into local structure */
			memcpy(&sec_clk_data, resp_data.fixed_data.response_data,
					sizeof(drm_secure_clock_data_s));
			DRM_CLIENT_LOG("sec_clk_data.is_secure_clock_set = %d",
					sec_clk_data.is_secure_clock_set);
			DRM_CLIENT_LOG("Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					sec_clk_data.secure_clock.tm_year,
					sec_clk_data.secure_clock.tm_mon,
					sec_clk_data.secure_clock.tm_mday,
					sec_clk_data.secure_clock.tm_hour,
					sec_clk_data.secure_clock.tm_min,
					sec_clk_data.secure_clock.tm_sec);

			/* Now copy into output parameter */
			memcpy(output, &sec_clk_data, sizeof(drm_secure_clock_data_s));

		}
			break;

		case DRM_DATA_TYPE_TRANSACTION_TRACKING_FLAG: {

			int transtrack_flag = 0;

			/* Copy from response data into local structure */
			memcpy(&transtrack_flag, resp_data.fixed_data.response_data, sizeof(int));
			DRM_CLIENT_LOG("transtrack_flag = %d", transtrack_flag);

			/* Now copy into output parameter */
			memcpy(output, &transtrack_flag, sizeof(int));

		}
			break;

		case DRM_DATA_TYPE_TRANSACTION_TRACKING_ID: {
			drm_transaction_id_info_s transid_info;
			memset(&transid_info,0,sizeof(transid_info));

			/* Copy from response data into local structure */
			memcpy(&transid_info, resp_data.fixed_data.response_data,
					sizeof(drm_transaction_id_info_s));
			DRM_CLIENT_LOG("transid_info.tr_id = %s", transid_info.tr_id);
			DRM_CLIENT_LOG("transid_info.tr_id_len = %d",
					transid_info.tr_id_len)

			/* Now copy into output parameter */
			memcpy(output, &transid_info, sizeof(drm_transaction_id_info_s));

		}
			break;

		case DRM_DATA_TYPE_DIVX_REGISTRATION_CODE: {

			drm_code_info_s registration_info;
			memset(&registration_info,0,sizeof(registration_info));

			/* Copy from response data into local structure */
			memcpy(&registration_info, resp_data.fixed_data.response_data,
					sizeof(drm_code_info_s));
			DRM_CLIENT_LOG("registration_info.code = %s",
					registration_info.code);
			DRM_CLIENT_LOG("registration_info.code_len = %d",
					registration_info.code_len);

			/* Now copy into output parameter */
			memcpy(output, &registration_info, sizeof(drm_code_info_s));

		}
			break;

		case DRM_DATA_TYPE_DIVX_DEREGISTRATION_CODE: {

			drm_code_info_s deregis_info;
			memset(&deregis_info,0,sizeof(deregis_info));

			/* Copy from response data into local structure */
			memcpy(&deregis_info, resp_data.fixed_data.response_data,
					sizeof(drm_code_info_s));
			DRM_CLIENT_LOG("deregis_info.code = %s",
					deregis_info.code);
			DRM_CLIENT_LOG("deregis_info.code_len = %d",
					deregis_info.code_len);

			/* Now copy into output parameter */
			memcpy(output, &deregis_info, sizeof(drm_code_info_s));

		}
			break;

		default:
			DRM_CLIENT_EXCEPTION("Invalid data type, data_type = %d", data_type);
			goto ErrorExit;
		}

	}

	/* Success */
	DRM_CLIENT_LOG("Exit:Success:result=0x%x",result);
	return result;

ErrorExit:
	/* Failure */
	DRM_CLIENT_EXCEPTION("Exit:failed:result=0x%x",result);
	return result;
}

/**
 * An application can do particular request to DRM.
 *
 * @param[in]	request_type	Request types as per enum drm_request_type_e.
 * @param[in]	input			Pointer to appropriate structure as per
 * 								request_type.
 * @param[out]	output			Output data. Pointer to appropriate structure as
 * 								per request_type.
 *
 * @return		0 on success, else a negative error value
 * @retval		DRM_RETURN_SUCCESS on success
 * @retval		DRM_RETURN_INVALID_ARG if arguments are invalid
 * @retval		DRM_RETURN_COMMUNICATION_ERROR if socket error
 * @retval		DRM_RETURN_INTERNAL_ERROR if operation error
 * @remarks		Please typecast to appropriate data structures
 * 				as per data types.
 *
 * 				if request_type = DRM_REQUEST_TYPE_REGISTER_FILE
 * 				then input type: input = pointer to const char (file_path)
 * 				and output type: output = NULL
 *
 * 				if request_type = DRM_REQUEST_TYPE_UNREGISTER_FILE
 * 				then input type: input = pointer to struct drm_unregister_info_s
 * 				and output type: output = NULL
 *
 * 				if request_type = DRM_REQUEST_TYPE_UNREGISTER_ALL_FILES
 * 				then input type: input = NULL
 * 				and output type: output = NULL
 *
 * 				if request_type = DRM_REQUEST_TYPE_REGISTER_LICENSE
 * 				then input type: input = pointer to
 * 				struct drm_register_lic_info_s.
 * 				and output type: output = pointer to
 * 				struct drm_register_lic_resp_s.
 *
 * 				if request_type = DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL
 * 				then input type: input = pointer to struct drm_initiator_info_s
 * 				and output type: output = pointer to struct drm_web_server_resp_data_s
 *
 * 				if request_type = DRM_REQUEST_TYPE_SUBMIT_ROAP_MESSAGE
 * 				then input type: input = pointer to struct drm_submit_roap_message_info_s
 * 				and output type: output = NULL
 *
 * 				if request_type = DRM_REQUEST_TYPE_SUBMIT_ROAP_USER_CONSENT
 * 				then input type: input = pointer to struct drm_submit_roap_user_consent_info_s
 * 				and output type: output = NULL
 *
 * 				if request_type = DRM_REQUEST_TYPE_HTTP_USER_CANCEL
 * 				then input type: input = pointer to struct drm_http_user_cancel_info_s
 * 				and output type: output = NULL
 *
 * 				if request_type = DRM_REQUEST_TYPE_REGISTER_COPY_FILE
 * 				then input type: input = pointer to struct drm_register_copy_file_info_s
 * 				and output type: output = NULL
 *
 * 				if request_type = DRM_REQUEST_TYPE_REGISTER_MOVE_FILE
 * 				then input type: input = pointer to struct drm_register_copy_file_info_s
 * 				and output type: output = NULL
 *
 * 				if request_type = DRM_REQUEST_TYPE_INSERT_EXT_MEMORY
 * 				then input type: input = NULL
 * 				and output type: output = NULL
 *
 * 				if request_type = DRM_REQUEST_TYPE_EXTRACT_EXT_MEMORY
 * 				then input type: input = NULL
 * 				and output type: output = NULL
 *
 * 				if request_type = DRM_REQUEST_TYPE_REGISTER_SETAS
 * 				then input type: input = pointer to struct drm_register_setas_info_s
 * 				and output type: output = pointer to the struct drm_register_setas_resp_data_s
 *
 * 				if request_type = DRM_REQUEST_TYPE_UNREGISTER_SETAS
 * 				then input type: input = pointer to struct drm_unregister_setas_info_s
 * 				and output type: output = NULL
 *
 * @see
 * @since      	0.1
 */
EXPORT_API int drm_process_request(drm_request_type_e request_type,
		void *input, void *output)
{
	DRM_CLIENT_LOG("Enter: request_type = %d, input = %p, output = %p",
			request_type, input, output);
	/* Local Variables */
	drm_result_e result = DRM_RETURN_SUCCESS;
	drm_request_data_s req_data;
	drm_response_data_s resp_data;
	int ret_comm = 0;
	int ret_cpy = 0;

	/* memset the structures */
	memset(&req_data, 0x0, sizeof(drm_request_data_s));
	memset(&resp_data, 0x0, sizeof(drm_response_data_s));

	DRM_CLIENT_LOG("request_type = %d", request_type);

	/* Check Input & Output Parameters */
	switch (request_type) {
	case DRM_REQUEST_TYPE_REGISTER_FILE: {
		if (!input || ((char*)input)[0] == '\0') {
			DRM_CLIENT_EXCEPTION("Invalid argument!!, input = %p", input);
			return DRM_RETURN_INVALID_ARG;
		} else {
			/* Copy the input to Request Structure */
			if ((ret_cpy = g_strlcpy(req_data.fixed_data.request_data,
					(const gchar*) input, DRM_MAX_LEN_FILEPATH))
					>= DRM_MAX_LEN_FILEPATH) {
				DRM_CLIENT_EXCEPTION("file_path = %s, filepath_len = %d, ret_cpy = %d",
						(const char*)input, strlen(((const char*)input)), ret_cpy);
				return DRM_RETURN_INVALID_ARG;
			}
		}
	}
		break;

	case DRM_REQUEST_TYPE_UNREGISTER_FILE: {
		if (!input || ((char*)input)[0] == '\0') {
			DRM_CLIENT_EXCEPTION("Invalid argument!!, input = %p", input);
			return DRM_RETURN_INVALID_ARG;
		} else {
			/* Copy the input to Request Structure */
			memcpy(req_data.fixed_data.request_data, input, sizeof(drm_unregister_info_s));
		}
	}
		break;

	case DRM_REQUEST_TYPE_UNREGISTER_ALL_FILES: {
		DRM_CLIENT_LOG("No parameters required!");
	}
		break;

	case DRM_REQUEST_TYPE_REGISTER_LICENSE: {
		if (!input || ((char*)input)[0] == '\0' || !output) {
			DRM_CLIENT_EXCEPTION("Invalid argument!!, input = %p, output = %p",
					input, output);
			return DRM_RETURN_INVALID_ARG;
		} else {
			/* Copy the input to Request Structure */
			memcpy(req_data.fixed_data.request_data, input,
					sizeof(drm_register_lic_info_s));

		}
	}
		break;

	case DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL: {
		if (!input || ((char*)input)[0] == '\0' || !output) {
			DRM_CLIENT_EXCEPTION("Invalid argument!!, input = %p, output = %p",
					input, output);
			return DRM_RETURN_INVALID_ARG;
		} else {
			/* Copy the input to Request Structure */
			memcpy(req_data.fixed_data.request_data, input,
					sizeof(drm_initiator_info_s));
		}
	}
		break;

	case DRM_REQUEST_TYPE_SUBMIT_ROAP_MESSAGE: {

		if (!input
			|| (!((drm_submit_roap_message_info_s*) input)->buffer)
			|| (((drm_submit_roap_message_info_s*) input)->buffer[0] == '\0')
			|| (((drm_submit_roap_message_info_s*) input)->buff_size == 0)) {
			DRM_CLIENT_EXCEPTION("Invalid argument!!, input = %p", input);
			return DRM_RETURN_INVALID_ARG;
		} else {

			/* Copy the input to Request Structure */
			memcpy(req_data.fixed_data.request_data, input,
					sizeof(drm_submit_roap_message_info_s));

			/* Number of additional data items to be sent */
			if ((((drm_submit_roap_message_info_s*) input)->app_session_data.pData)
				&& (((drm_submit_roap_message_info_s*) input)->app_session_data.size_pData != 0)) {
				req_data.fixed_data.num_data_items = 2;
			} else {
				req_data.fixed_data.num_data_items = 1;
			}

			/* Fill details pertaining to additional pointers to be sent */
			req_data.fixed_data.data_length[0] =
					((drm_submit_roap_message_info_s*) input)->buff_size;

			/* Allocate memory for data items */
			req_data.data_items[0] = (char*) malloc(
					req_data.fixed_data.data_length[0]);
			if (!req_data.data_items[0]) {
				DRM_CLIENT_EXCEPTION("Memory Allocation Error!, Buf = %p",
						req_data.data_items[0]);
				result = DRM_RETURN_INSUFFICIENT_MEMORY;
				goto ErrorExit;
			}

			/* Copy the buffer into data items */
			memcpy(req_data.data_items[0],
					((drm_submit_roap_message_info_s*) input)->buffer,
					((drm_submit_roap_message_info_s*) input)->buff_size);

			if (2 == req_data.fixed_data.num_data_items) {
				req_data.fixed_data.data_length[1] =
						((drm_submit_roap_message_info_s*) input)->app_session_data.size_pData;

				req_data.data_items[1] = (char*) malloc(
						req_data.fixed_data.data_length[1]);
				if (!req_data.data_items[1]) {
					DRM_CLIENT_EXCEPTION("Memory Allocation Error!, Buf = %p",
							req_data.data_items[1]);
					result = DRM_RETURN_INSUFFICIENT_MEMORY;
					goto ErrorExit;
				}

				/* Copy the Additional data */
				memcpy(	req_data.data_items[1],
						((drm_submit_roap_message_info_s*) input)->app_session_data.pData,
						((drm_submit_roap_message_info_s*) input)->app_session_data.size_pData);
			}
		}

	}
		break;

	case DRM_REQUEST_TYPE_SUBMIT_ROAP_USER_CONSENT: {

		if (!input
			|| (!((drm_submit_roap_user_consent_info_s*) input)->agentdata)
			|| (((drm_submit_roap_user_consent_info_s*) input)->size_agentdata == 0)) {
			DRM_CLIENT_EXCEPTION("Invalid argument!!, input = %p", input);
			return DRM_RETURN_INVALID_ARG;
		} else {

			/* Copy the input to Request Structure */
			memcpy(req_data.fixed_data.request_data, input,
					sizeof(drm_submit_roap_user_consent_info_s));

			/* Number of additional data items to be sent */
			req_data.fixed_data.num_data_items = 1;

			/* Fill details pertaining to additional pointers to be sent */
			req_data.fixed_data.data_length[0] =
					((drm_submit_roap_user_consent_info_s*) input)->size_agentdata;

			/* Allocate memory for data items */
			req_data.data_items[0] = (char*) malloc(
					req_data.fixed_data.data_length[0]);
			if (!req_data.data_items[0]) {
				DRM_CLIENT_EXCEPTION("Memory Allocation Error!, Buf = %p",
						req_data.data_items[0]);
				result = DRM_RETURN_INSUFFICIENT_MEMORY;
				goto ErrorExit;
			}

			/* Copy the buffer into data items */
			memcpy(req_data.data_items[0],
				   ((drm_submit_roap_user_consent_info_s*) input)->agentdata,
				   ((drm_submit_roap_user_consent_info_s*) input)->size_agentdata);
		}

	}
		break;

	case DRM_REQUEST_TYPE_HTTP_USER_CANCEL: {

		if (!input
			|| (!((drm_http_user_cancel_info_s*) input)->app_session_data)
			|| (((drm_http_user_cancel_info_s*) input)->size_app_session_data == 0)) {
			DRM_CLIENT_EXCEPTION("Invalid argument!!, input = %p", input);
			return DRM_RETURN_INVALID_ARG;
		} else {

			/* Copy the input to Request Structure */
			memcpy(req_data.fixed_data.request_data, input,
					sizeof(drm_http_user_cancel_info_s));

			/* Number of additional data items to be sent */
			req_data.fixed_data.num_data_items = 1;

			/* Fill details pertaining to additional pointers to be sent */
			req_data.fixed_data.data_length[0] =
					((drm_http_user_cancel_info_s*) input)->size_app_session_data;

			/* Allocate memory for data items */
			req_data.data_items[0] = (char*) malloc(
					req_data.fixed_data.data_length[0]);
			if (!req_data.data_items[0]) {
				DRM_CLIENT_EXCEPTION("Memory Allocation Error!, Buf = %p",
						req_data.data_items[0]);
				result = DRM_RETURN_INSUFFICIENT_MEMORY;
				goto ErrorExit;
			}

			/* Copy the buffer into data items */
			memcpy(req_data.data_items[0],
					((drm_http_user_cancel_info_s*) input)->app_session_data,
					((drm_http_user_cancel_info_s*) input)->size_app_session_data);

		}

	}
		break;

	case DRM_REQUEST_TYPE_REGISTER_COPY_FILE: {

		if (!input
				|| (((drm_register_copy_file_info_s*) input)->src_file_path[0] == '\0')
				|| (((drm_register_copy_file_info_s*) input)->dest_file_path[0] == '\0')) {
			DRM_CLIENT_EXCEPTION("Invalid argument!!, input = %p", input);
			return DRM_RETURN_INVALID_ARG;
		} else {

			/* Copy the input to Request Structure */
			memcpy(req_data.fixed_data.request_data, input,
					sizeof(drm_register_copy_file_info_s));
		}
	}
		break;

	case DRM_REQUEST_TYPE_REGISTER_MOVE_FILE: {

		if (!input
				|| (((drm_register_move_file_info_s*) input)->src_file_path[0] == '\0')
				|| (((drm_register_move_file_info_s*) input)->dest_file_path[0] == '\0')) {
			DRM_CLIENT_EXCEPTION("Invalid argument!!, input = %p", input);
			return DRM_RETURN_INVALID_ARG;
		} else {

			/* Copy the input to Request Structure */
			memcpy(req_data.fixed_data.request_data, input,
					sizeof(drm_register_move_file_info_s));
		}
	}
		break;

	case DRM_REQUEST_TYPE_INSERT_EXT_MEMORY:
	case DRM_REQUEST_TYPE_EXTRACT_EXT_MEMORY:
		DRM_CLIENT_LOG("No parameters to check!!");
		break;

	case DRM_REQUEST_TYPE_REGISTER_SETAS: {

		if (!input
			|| (((drm_register_setas_info_s*) input)->file_path[0] == '\0')) {
			DRM_CLIENT_EXCEPTION("Invalid argument!!, input = %p", input);
			return DRM_RETURN_INVALID_ARG;
		} else {
			/* Copy the input to Request Structure */
			memcpy(req_data.fixed_data.request_data, input,
					sizeof(drm_register_setas_info_s));
		}

	}
		break;

	case DRM_REQUEST_TYPE_UNREGISTER_SETAS: {

		if (!input
				|| (((drm_unregister_setas_info_s*) input)->file_path[0] == '\0')) {
			DRM_CLIENT_EXCEPTION("Invalid argument!!, input = %p", input);
			return DRM_RETURN_INVALID_ARG;
		} else {
			/* Copy the input to Request Structure */
			memcpy(req_data.fixed_data.request_data, input,
					sizeof(drm_unregister_setas_info_s));
		}
	}
		break;

	default:
		DRM_CLIENT_EXCEPTION("Invalid Argument! request_type = %d",
				request_type);
		return DRM_RETURN_INVALID_ARG;
	}

	DRM_CLIENT_LOG("input=%p output=%p", input, output);

	/* Fill other parameters to be sent */
	req_data.fixed_data.request_type = request_type;

	/* Tell the server which API to be used */
	req_data.fixed_data.api_name = DRM_PROCESS_REQUEST;

	/* Send Data to DRM server */
	/* Call the Client Communication API */
	if ((ret_comm = drm_client_comm(&req_data, &resp_data)) != 0) {
		DRM_CLIENT_EXCEPTION("drm_client_comm error!!, ret_comm = %d", ret_comm);
		result = DRM_RETURN_COMMUNICATION_ERROR;
		goto ErrorExit;
	}

	/* Copy the response obtained from the server into the output parameter */
	if (resp_data.fixed_data.resp_result != 0) {
		DRM_CLIENT_EXCEPTION("Error returned from server!!, resp_data.fixed_data.resp_result = 0x%x",
				resp_data.fixed_data.resp_result);

		result = resp_data.fixed_data.resp_result;
		goto ErrorExit;
	} else {
		DRM_CLIENT_LOG("resp_data.fixed_data.resp_result = 0x%x", resp_data.fixed_data.resp_result);

		/* Store the response result to the output based on the Request type */
		switch (request_type) {
		case DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL: {

			drm_web_server_resp_data_s ws_resp_data;
			memset(&ws_resp_data,0,sizeof(ws_resp_data));
			/* Copy from response data into local structure */
			memcpy(&ws_resp_data, resp_data.fixed_data.response_data,
					sizeof(drm_web_server_resp_data_s));
			DRM_CLIENT_LOG("ws_resp_data.fixed_data.content_url = %s",
					ws_resp_data.content_url);
			DRM_CLIENT_LOG("ws_resp_data.result_code = 0x%x",
					ws_resp_data.result_code);

			/* Now copy into output parameter */
			memcpy(output, &ws_resp_data, sizeof(drm_web_server_resp_data_s));

		}
			break;

		case DRM_REQUEST_TYPE_REGISTER_LICENSE: {

			drm_register_lic_resp_s lic_resp;
			memset(&lic_resp,0,sizeof(lic_resp));

			/* Copy from response data into local structure */
			memcpy(&lic_resp, resp_data.fixed_data.response_data,
					sizeof(drm_register_lic_resp_s));
			DRM_CLIENT_LOG("lic_resp.cid = %s", lic_resp.cid);

			/* Now copy into output parameter */
			memcpy(output, &lic_resp, sizeof(drm_register_lic_resp_s));

		}
			break;

		case DRM_REQUEST_TYPE_REGISTER_SETAS: {

			DRM_CLIENT_LOG("Register Setas Successful");
			drm_register_setas_resp_data_s setas_resp = { 0, };

			/* Copy from response data into local structure */
			memcpy(&setas_resp, resp_data.fixed_data.response_data,
			sizeof(drm_register_setas_resp_data_s));

			/* Now copy into output parameter */
			memcpy(output, &setas_resp, sizeof(drm_register_setas_resp_data_s));
		}
			break;
		case DRM_REQUEST_TYPE_REGISTER_FILE:
		case DRM_REQUEST_TYPE_UNREGISTER_FILE:
		case DRM_REQUEST_TYPE_UNREGISTER_ALL_FILES:
		case DRM_REQUEST_TYPE_SUBMIT_ROAP_MESSAGE:
		case DRM_REQUEST_TYPE_SUBMIT_ROAP_USER_CONSENT:
		case DRM_REQUEST_TYPE_HTTP_USER_CANCEL:
		case DRM_REQUEST_TYPE_REGISTER_COPY_FILE:
		case DRM_REQUEST_TYPE_REGISTER_MOVE_FILE:
		case DRM_REQUEST_TYPE_INSERT_EXT_MEMORY:
		case DRM_REQUEST_TYPE_EXTRACT_EXT_MEMORY:
		case DRM_REQUEST_TYPE_UNREGISTER_SETAS:
			DRM_CLIENT_LOG("No output parameters to be handled!!");
			break;

		default:
			DRM_CLIENT_EXCEPTION("Invalid Argument!!");
			result = DRM_RETURN_INVALID_ARG;
			goto ErrorExit;
		}
	}


ErrorExit:

	/* Free Request Data memory */
	for (unsigned int i = 0; i < req_data.fixed_data.num_data_items; i++) {
		if (req_data.data_items[i])
			free(req_data.data_items[i]);
	}

	/* Free Response Data memory */
	for (unsigned int i = 0; i < resp_data.fixed_data.num_data_items; i++) {
		if (resp_data.data_items[i])
			free(resp_data.data_items[i]);
	}

	if (DRM_RETURN_SUCCESS == result) {
		/* Success */
		DRM_CLIENT_LOG("Exit:Success:result=0x%x",result);
		return result;
	} else {
		/* Failure */
		DRM_CLIENT_EXCEPTION("Exit:failed:result=0x%x",result);
		return result;
	}

}

/**
 *  Private function
 *
 *
 * @param[in]	file_path		Specifies the pointer points a DRM file path.
 * @return		This function returns DRM file type.
 * @remarks
 * @see
 * @since       0.1
 */
static drm_file_type_e _drm_client_get_file_type(const char* file_path)
{
	char *p = NULL;
	p = (char *) strrchr(file_path, '.');
	if (!p) {
		DRM_CLIENT_EXCEPTION("Invalid file_path!, file_path = %s", file_path);
		return DRM_TYPE_UNDEFINED;
	}

	DRM_CLIENT_LOG("file_path=[%s], p=[0x%x]", file_path, p);

	if (p && ((strncasecmp(p, ".dcf", 4) == 0))) {

		DRM_CLIENT_LOG("OMA DRM V1 File: file_path=%s p=%s", file_path, p);
		return DRM_TYPE_OMA_V1;

	} else if (p &&  ((strncasecmp(p, ".odf", 4) == 0)
			|| (strncasecmp(p, ".o4a", 4) == 0)
			|| (strncasecmp(p, ".o4v", 4) == 0))) {

		DRM_CLIENT_LOG("OMA DRM V2 File: file_path=%s p=%s", file_path, p);
		return DRM_TYPE_OMA_V2;

	} else if ((p && ((strncasecmp(p, ".pya", 4) == 0)
			|| (strncasecmp(p, ".pyv", 4) == 0)))) {

		DRM_CLIENT_LOG("PlayReady File: file_path=%s p=%s", file_path, p);
		return DRM_TYPE_PLAYREADY;

	} else if (p && ((strncasecmp(p, ".eny", 4) == 0)
			|| (strncasecmp(p, ".pye", 4) == 0)
			|| (strncasecmp(p, ".jue", 4) == 0)))	{

		DRM_CLIENT_LOG("PlayReady Envelope File: file_path=%s p=%s", file_path, p);
		return DRM_TYPE_PLAYREADY_ENVELOPE;

	} else if (p && ((strncasecmp(p, ".avi", 4) == 0)
			|| (strncasecmp(p, ".divx", 5) == 0))) {

		DRM_CLIENT_LOG("DivX DRM File: file_path=%s p=%s", file_path, p);
		return DRM_TYPE_DIVX;

	} else {
		DRM_CLIENT_LOG("NON DRM file=%s", file_path);
		return DRM_TYPE_UNDEFINED;
	}
}
