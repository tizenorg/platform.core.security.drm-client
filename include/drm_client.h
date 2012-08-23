/*
 *  drm-client
 *
 * Copyright (c) 2000 - 2011 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Contact: Hakjoo Ko <hakjoo.ko@samsung.com>
 * 			Mahendra Kumar Prajapat <mahendra.p@samsung.com>
 *			Harsha Shekar <h.shekar@samsung.com>
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
 * @file 		drm_client.h
 * @brief       DRM Client API declaration header file.
 * @author      Mahendra Kumar Prajapat (mahendra.p@samsung.com)
 * @author      Harsha Shekar (h.shekar@samsung.com)
 * @version     0.1
 * @history     0.1: DRM Client API Declarations
 */

#ifndef __DRM_CLIENT_H__
#define __DRM_CLIENT_H__

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus */

#include "drm_client_types.h"

/**
 * @defgroup DRMCLIENT drm-client
 * @{
 */

/**
 * @}
 */

/**
 * @addtogroup DRMCLIENT
 * @{
 */

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
int drm_is_drm_file(const char *file_path, drm_bool_type_e *is_drm_file);

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
int drm_get_file_type(const char *file_path, drm_file_type_e *file_type);

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
int drm_get_license_status(const char *file_path,
		drm_permission_type_e perm_type,
		drm_license_status_e *license_status);

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
int drm_get_content_info(const char *file_path,
		drm_content_info_s *content_info);

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
int drm_get_file_info(const char *file_path, drm_file_info_s *file_info);

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
int drm_get_constraint_info(const char *file_path,
		drm_permission_type_e perm_type,
		drm_constraint_info_s *constraint_info);

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
int drm_is_action_allowed(drm_action_type_e action,
		drm_action_allowed_data_s *action_data,
		drm_bool_type_e *is_allowed);


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
int drm_get_data(drm_data_type_e data_type, void *input, void *output);

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
 * 				and output type: output = NULL
 *
 * 				if request_type = DRM_REQUEST_TYPE_UNREGISTER_SETAS
 * 				then input type: input = pointer to struct drm_unregister_setas_info_s
 * 				and output type: output = NULL
 *
 * @see
 * @since      	0.1
 */
int drm_process_request(drm_request_type_e request_type,
		void *input, void *output);


/**
 * @}
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /*__DRM_CLIENT_H__ */
