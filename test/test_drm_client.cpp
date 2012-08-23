/*
 * drm-client test utility
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
 * @file 		test_drm_client.cpp
 * @brief       Test case implementation specific to DRM Client APIs.
 * @author      Mahendra Kumar Prajapat (mahendra.p@samsung.com)
 * @author      Harsha Shekar (h.shekar@samsung.com)
 * @version     0.1
 * @history     0.1: First version of DRM Client test utility.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <stdarg.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <linux/unistd.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#include <assert.h>

#include "drm_client.h"

#define drm_client_tid() (long int)syscall(__NR_gettid)
#define DRM_CLIENT_TEST_FILENAME(X)   (strrchr((char*)(X), '/') ? (char*)(strrchr((char*)(X), '/') + 1) : ((char*)(X)) )

#define DRM_CLIENT_TEST_LOG(FMT, ARG...)	do{\
	fprintf(stderr,"[PID=%ld]:[TID=%ld]:[%s:%s:%d]:",(long int)getpid(),drm_client_tid(),DRM_CLIENT_TEST_FILENAME(__FILE__),__func__,__LINE__);	\
	fprintf(stderr,FMT,##ARG); \
	fprintf(stderr,"\n"); \
	} while(0);

#define	DRM_CLIENT_TEST_EXCEPTION(FMT, ARG...)	do{\
	fprintf(stderr,"[PID=%ld]:[TID=%ld]:[%s:%s:%d]:",(long int)getpid(),drm_client_tid(),DRM_CLIENT_TEST_FILENAME(__FILE__),__func__,__LINE__);	\
	fprintf(stderr,"[ERROR]"FMT,##ARG); \
	fprintf(stderr,"\n"); \
	} while(0);

enum {
	DRM_CLIENT_TEST_NONE,
	DRM_CLIENT_TEST_is_drm_file,
	DRM_CLIENT_TEST_get_file_type,
	DRM_CLIENT_TEST_get_license_status,
	DRM_CLIENT_TEST_get_content_info,
	DRM_CLIENT_TEST_get_file_info,
	DRM_CLIENT_TEST_get_constraint_info,
	DRM_CLIENT_TEST_is_action_allowed,
	DRM_CLIENT_TEST_get_data,
	DRM_CLIENT_TEST_process_request,
	DRM_CLIENT_TEST_print_return_code_values,
	DRM_CLIENT_TEST_MAX
};

void test_operation_cb(drm_user_operation_info_s *operation_info,
		void *output_data)
{
	DRM_CLIENT_TEST_LOG("Callback HIT");
}

int test_case(int option)
{
	DRM_CLIENT_TEST_LOG("option=[%d]", option);

	switch (option) {
	case DRM_CLIENT_TEST_NONE:
	{
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_NONE start");
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_NONE completed");
		break;
	}

	case DRM_CLIENT_TEST_is_drm_file:
	{
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_is_drm_file start");

		char file_path[512] = {0,};
		drm_bool_type_e is_drm_file = DRM_UNKNOWN;
		int ret = -1;

		DRM_CLIENT_TEST_LOG("Enter complete file name with path");
		scanf("%511s", file_path);
		DRM_CLIENT_TEST_LOG("file_path = %s",file_path);

		ret = drm_is_drm_file(file_path,&is_drm_file);
		DRM_CLIENT_TEST_LOG("file_path = %s ret=%d is_drm_file=%d",file_path,ret,is_drm_file);
		if(DRM_RETURN_SUCCESS == ret && DRM_TRUE == is_drm_file){
			DRM_CLIENT_TEST_LOG("file_path = %s DRM FILE",file_path);
		}else{
			DRM_CLIENT_TEST_LOG("file_path = %s NOT a DRM FILE",file_path);
		}

		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_is_drm_file completed");
		break;
	}

	case DRM_CLIENT_TEST_get_file_type:
	{
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_get_file_type start");
		char file_path[512] = {0,};
		drm_file_type_e file_type = DRM_TYPE_UNDEFINED;
		int ret = -1;

		DRM_CLIENT_TEST_LOG("Enter complete file name with path");
		scanf("%511s", file_path);
		DRM_CLIENT_TEST_LOG("file_path = %s",file_path);

		ret = drm_get_file_type(file_path,&file_type);
		DRM_CLIENT_TEST_LOG("file_path = %s ret=%d file_type=%d",file_path,ret,file_type);
		if(DRM_RETURN_SUCCESS == ret){
			DRM_CLIENT_TEST_LOG("file_path = %s DRM FILE type = %d",file_path,file_type);
			switch(file_type){
			case DRM_TYPE_OMA_V1:				/**< OMA DRM v1 file */
				DRM_CLIENT_TEST_LOG("file_path = %s DRM FILE type = DRM_TYPE_OMA_V1 ",file_path);
				break;

			case DRM_TYPE_OMA_V2:				/**< OMA DRM v2 file */
				DRM_CLIENT_TEST_LOG("file_path = %s DRM FILE type = DRM_TYPE_OMA_V2 ",file_path);
				break;

			case DRM_TYPE_PLAYREADY:				/**< PlayReady file */
				DRM_CLIENT_TEST_LOG("file_path = %s DRM FILE type = DRM_TYPE_PLAYREADY ",file_path);
				break;

			case DRM_TYPE_PLAYREADY_ENVELOPE:	/**< PlayReady Envelope file */
				DRM_CLIENT_TEST_LOG("file_path = %s DRM FILE type = DRM_TYPE_PLAYREADY_ENVELOPE ",file_path);
				break;

			case DRM_TYPE_DIVX:					/**< DivX file */
				DRM_CLIENT_TEST_LOG("file_path = %s DRM FILE type = DRM_TYPE_DIVX ",file_path);
				break;

			default:
				DRM_CLIENT_TEST_LOG("file_path = %s Unkown DRM FILE type = %d",file_path,file_type);
			}

		}else{
			DRM_CLIENT_TEST_LOG("file_path = %s Unknown DRM type",file_path);
		}

		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_get_file_type completed");
		break;
	}

	case DRM_CLIENT_TEST_get_license_status:
	{
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_get_license_status start");

		char file_path[512] = {0,};
		drm_permission_type_e perm_type;
		drm_license_status_e license_status = DRM_LICENSE_STATUS_UNDEFINED;
		int ret = -1;

		DRM_CLIENT_TEST_LOG("Enter complete file name with path");
		scanf("%511s", file_path);

		DRM_CLIENT_TEST_LOG("Enter permission type");
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_NONE",DRM_PERMISSION_TYPE_NONE);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_ANY",DRM_PERMISSION_TYPE_ANY);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_PLAY",DRM_PERMISSION_TYPE_PLAY);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_COLLABORATIVE_PLAY",DRM_PERMISSION_TYPE_COLLABORATIVE_PLAY);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_DISPLAY",DRM_PERMISSION_TYPE_DISPLAY);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_EXECUTE",DRM_PERMISSION_TYPE_EXECUTE);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_PRINT",DRM_PERMISSION_TYPE_PRINT);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_EXPORT_COPY",DRM_PERMISSION_TYPE_EXPORT_COPY);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_EXPORT_MOVE",DRM_PERMISSION_TYPE_EXPORT_MOVE);
		scanf("%d", (int*)&perm_type);
		DRM_CLIENT_TEST_LOG("perm_type = %d file_path=%s",perm_type,file_path);

		ret = drm_get_license_status(file_path,perm_type,&license_status);
		if(DRM_RETURN_SUCCESS == ret){
			DRM_CLIENT_TEST_LOG("drm_get_license_status success:license_status=%d",license_status);
			switch(license_status){
			case DRM_LICENSE_STATUS_VALID:		/**< Valid License */
				DRM_CLIENT_TEST_LOG("file_path = %s DRM_LICENSE_STATUS_VALID",file_path);
				break;

			case DRM_LICENSE_STATUS_FUTURE_USE:	/**< License for future use */
				DRM_CLIENT_TEST_LOG("file_path = %s DRM_LICENSE_STATUS_FUTURE_USE",file_path);
				break;
			case DRM_LICENSE_STATUS_EXPIRED:		/**< Expired License */
				DRM_CLIENT_TEST_LOG("file_path = %s DRM_LICENSE_STATUS_EXPIRED",file_path);
				break;

			case DRM_LICENSE_STATUS_NO_LICENSE:	/**< No License */
				DRM_CLIENT_TEST_LOG("file_path = %s DRM_LICENSE_STATUS_NO_LICENSE",file_path);
				break;

			default:
				DRM_CLIENT_TEST_EXCEPTION("file_path = %s Unknown License Status=%d",file_path,license_status);
			}
		}else{
			DRM_CLIENT_TEST_EXCEPTION("drm_get_license_status failed");
		}

		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_get_license_status completed");
		break;
	}

	case DRM_CLIENT_TEST_get_content_info:
	{
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_get_content_info start");
		char file_path[512] = {0,};
		drm_content_info_s content_info;
		memset(&content_info,0x0,sizeof(drm_content_info_s));
		int ret = -1;

		DRM_CLIENT_TEST_LOG("Enter complete file name with path");
		scanf("%511s", file_path);
		DRM_CLIENT_TEST_LOG("file_path=%s",file_path);

		ret = drm_get_content_info(file_path,&content_info);
		if(DRM_RETURN_SUCCESS == ret){
			DRM_CLIENT_TEST_LOG("drm_get_content_info success");
			if('\0' != content_info.author[0]) DRM_CLIENT_TEST_LOG("author=%s",content_info.author);
			if('\0' != content_info.copyright[0]) DRM_CLIENT_TEST_LOG("copyright=%s",content_info.copyright);
			if('\0' != content_info.description[0]) DRM_CLIENT_TEST_LOG("description=%s",content_info.description);
			if('\0' != content_info.icon_uri[0]) DRM_CLIENT_TEST_LOG("icon_uri=%s",content_info.icon_uri);
			if('\0' != content_info.info_url[0]) DRM_CLIENT_TEST_LOG("info_url=%s",content_info.info_url);
			if('\0' != content_info.content_url[0]) DRM_CLIENT_TEST_LOG("content_url=%s",content_info.content_url);
			if('\0' != content_info.rights_url[0]) DRM_CLIENT_TEST_LOG("rights_url=%s",content_info.rights_url);
			if('\0' != content_info.title[0]) DRM_CLIENT_TEST_LOG("title=%s",content_info.title);
			if('\0' != content_info.mime_type[0]) DRM_CLIENT_TEST_LOG("mime_type=%s",content_info.mime_type);
			if('\0' != content_info.content_id[0]) DRM_CLIENT_TEST_LOG("content_id=%s",content_info.content_id);
		}else{
			DRM_CLIENT_TEST_EXCEPTION("drm_get_content_info failed");
		}
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_get_content_info completed");
		break;
	}

	case DRM_CLIENT_TEST_get_file_info:
	{
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_get_file_info start");
		char file_path[512] = {0,};
		drm_file_info_s fileInfo;
		memset(&fileInfo,0x0,sizeof(drm_file_info_s));
		int ret = -1;

		DRM_CLIENT_TEST_LOG("Enter complete file name with path");
		scanf("%511s", file_path);
		DRM_CLIENT_TEST_LOG("file_path=%s",file_path);

		ret = drm_get_file_info(file_path,&fileInfo);
		if(DRM_RETURN_SUCCESS == ret){
			DRM_CLIENT_TEST_LOG("drm_get_file_info success");

			if(DRM_METHOD_TYPE_UNDEFINED != fileInfo.oma_info.method){
				DRM_CLIENT_TEST_LOG("OMA DRM File");
				DRM_CLIENT_TEST_LOG("method=%d",fileInfo.oma_info.method);
				DRM_CLIENT_TEST_LOG("version=%d",fileInfo.oma_info.version);
			}else if(0 != fileInfo.pr_env_info.org_file_size){
				DRM_CLIENT_TEST_LOG("PlayReady Envelope File");
				DRM_CLIENT_TEST_LOG("org_file_name=%s",fileInfo.pr_env_info.org_file_name);
				DRM_CLIENT_TEST_LOG("org_file_size=%d",fileInfo.pr_env_info.org_file_size);
			}else{
				DRM_CLIENT_TEST_LOG("Other DRM File=%s",file_path);
			}
		}else{
			DRM_CLIENT_TEST_EXCEPTION("drm_get_file_info failed");
		}
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_get_file_info completed");
		break;
	}

	case DRM_CLIENT_TEST_get_constraint_info:
	{
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_get_constraint_info start");
		char file_path[512] = {0,};
		drm_constraint_info_s constraint_info;
		drm_permission_type_e perm_type;
		memset(&constraint_info,0x0,sizeof(drm_constraint_info_s));
		int ret = -1;

		DRM_CLIENT_TEST_LOG("Enter complete file name with path");
		scanf("%511s", file_path);

		DRM_CLIENT_TEST_LOG("Enter permission type");
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_NONE",DRM_PERMISSION_TYPE_NONE);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_ANY",DRM_PERMISSION_TYPE_ANY);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_PLAY",DRM_PERMISSION_TYPE_PLAY);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_COLLABORATIVE_PLAY",DRM_PERMISSION_TYPE_COLLABORATIVE_PLAY);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_DISPLAY",DRM_PERMISSION_TYPE_DISPLAY);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_EXECUTE",DRM_PERMISSION_TYPE_EXECUTE);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_PRINT",DRM_PERMISSION_TYPE_PRINT);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_EXPORT_COPY",DRM_PERMISSION_TYPE_EXPORT_COPY);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_PERMISSION_TYPE_EXPORT_MOVE",DRM_PERMISSION_TYPE_EXPORT_MOVE);
		scanf("%d", (int*)&perm_type);
		DRM_CLIENT_TEST_LOG("perm_type = %d file_path=%s",perm_type,file_path);

		ret = drm_get_constraint_info(file_path,perm_type,&constraint_info);
		if(DRM_RETURN_SUCCESS == ret){
			DRM_CLIENT_TEST_LOG("drm_get_constraint_info success");

			if(constraint_info.const_type.is_unlimited){
				DRM_CLIENT_TEST_LOG("Unlimited:for permission=%d",perm_type);
				break;
			}

			if(constraint_info.const_type.is_accumulated){
				DRM_CLIENT_TEST_LOG("Accumulated Constraint is present");
				DRM_CLIENT_TEST_LOG("accumulated_original_seconds=%d",
						constraint_info.accumulated_original_seconds);
				DRM_CLIENT_TEST_LOG("accumulated_remaining_seconds=%d",
						constraint_info.accumulated_remaining_seconds);
			}

			if(constraint_info.const_type.is_count){
				DRM_CLIENT_TEST_LOG("Count Constraint is present");
				DRM_CLIENT_TEST_LOG("original_count=%d",
						constraint_info.original_count);
				DRM_CLIENT_TEST_LOG("remaining_count=%d",
						constraint_info.remaining_count);
			}

			if(constraint_info.const_type.is_datetime){
				DRM_CLIENT_TEST_LOG("DATETIME Constraint is present");
				DRM_CLIENT_TEST_LOG("start_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.start_time.tm_year,
					constraint_info.start_time.tm_mon,
					constraint_info.start_time.tm_mday,
					constraint_info.start_time.tm_hour,
					constraint_info.start_time.tm_min,
					constraint_info.start_time.tm_sec);

				DRM_CLIENT_TEST_LOG("end_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.end_time.tm_year,
					constraint_info.end_time.tm_mon,
					constraint_info.end_time.tm_mday,
					constraint_info.end_time.tm_hour,
					constraint_info.end_time.tm_min,
					constraint_info.end_time.tm_sec);
			}

			if(constraint_info.const_type.is_individual){
				DRM_CLIENT_TEST_LOG("INDIVIDUAL Constraint is present");
				DRM_CLIENT_TEST_LOG("individual_identity_type=%d "
						"individual_id=%s",
						constraint_info.individual_identity_type,
						constraint_info.individual_id);

			}

			if(constraint_info.const_type.is_interval){
				DRM_CLIENT_TEST_LOG("INTERVAL Constraint is present");
				DRM_CLIENT_TEST_LOG("interval_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.interval_time.tm_year,
					constraint_info.interval_time.tm_mon,
					constraint_info.interval_time.tm_mday,
					constraint_info.interval_time.tm_hour,
					constraint_info.interval_time.tm_min,
					constraint_info.interval_time.tm_sec);
			}

			if(constraint_info.const_type.is_system){
				DRM_CLIENT_TEST_LOG("SYSTEM Constraint is present");
				DRM_CLIENT_TEST_LOG("system_identity_type=%d "
						"system_id=%s",
						constraint_info.system_identity_type,
						constraint_info.system_id);

			}

			if(constraint_info.const_type.is_timedcount){
				DRM_CLIENT_TEST_LOG("TIMED-COUNT Constraint is present");
				DRM_CLIENT_TEST_LOG("timed_original_count=%d",
						constraint_info.timed_original_count);

				DRM_CLIENT_TEST_LOG("timed_remaining_count=%d",
						constraint_info.timed_remaining_count);

				DRM_CLIENT_TEST_LOG("timed_count_timer=%d",
						constraint_info.timed_count_timer);
			}
		}else{
			DRM_CLIENT_TEST_EXCEPTION("drm_get_constraint_info failed");
		}

		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_get_constraint_info completed");
		break;
	}

	case DRM_CLIENT_TEST_is_action_allowed:
	{
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_is_action_allowed start");

		drm_bool_type_e is_allowed = DRM_UNKNOWN;
		drm_action_type_e action = DRM_ACTION_UNDEFINED;
		drm_action_allowed_data_s action_data;
		int ret = -1;
		memset(&action_data,0x0,sizeof(drm_action_allowed_data_s));

		DRM_CLIENT_TEST_LOG("Enter complete file name with path");
		scanf("%511s", action_data.file_path);
		DRM_CLIENT_TEST_LOG("file_path=%s",action_data.file_path);

		DRM_CLIENT_TEST_LOG("Enter the action to be performed!");
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_ACTION_UNDEFINED",
				DRM_ACTION_UNDEFINED);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_IS_FORWARDING_ALLOWED",
				DRM_IS_FORWARDING_ALLOWED);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_HAS_VALID_SETAS_STATUS",
				DRM_HAS_VALID_SETAS_STATUS);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_IS_DEVICE_ACTIVATED",
				DRM_IS_DEVICE_ACTIVATED);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_IS_VALID_SECURE_CLOCK",
				DRM_IS_VALID_SECURE_CLOCK);

		scanf("%d", (int*)&action);

		DRM_CLIENT_TEST_LOG("Action entered = %d", action);

		ret = drm_is_action_allowed(action,&action_data,&is_allowed);
		if(DRM_RETURN_SUCCESS == ret && DRM_TRUE == is_allowed){
			DRM_CLIENT_TEST_LOG("Action=%d is allowed",action);
		}else{
			DRM_CLIENT_TEST_EXCEPTION("drm_is_action_allowed failed");
		}

		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_is_action_allowed completed");
		break;
	}

	case DRM_CLIENT_TEST_get_data:
	{
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_get_data start");
		char file_path[512] = {0,};
		int ret = -1;
		drm_data_type_e data_type = DRM_DATA_TYPE_NONE;

		DRM_CLIENT_TEST_LOG("Enter the data type to be received");
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_DATA_TYPE_SECURE_CLOCK",
				DRM_DATA_TYPE_SECURE_CLOCK);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_DATA_TYPE_TRANSACTION_TRACKING_FLAG",
				DRM_DATA_TYPE_TRANSACTION_TRACKING_FLAG);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_DATA_TYPE_TRANSACTION_TRACKING_ID",
				DRM_DATA_TYPE_TRANSACTION_TRACKING_ID);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_DATA_TYPE_DIVX_REGISTRATION_CODE",
				DRM_DATA_TYPE_DIVX_REGISTRATION_CODE);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_DATA_TYPE_DIVX_DEREGISTRATION_CODE",
				DRM_DATA_TYPE_DIVX_DEREGISTRATION_CODE);

		scanf("%d", (int*)&data_type);
		DRM_CLIENT_TEST_LOG("Data type received=%d",data_type);

		if(DRM_DATA_TYPE_TRANSACTION_TRACKING_ID == data_type){
			DRM_CLIENT_TEST_LOG("Enter complete file name with path");
			scanf("%511s", file_path);
			DRM_CLIENT_TEST_LOG("file_path=%s",file_path);
		}

		switch(data_type){
		case DRM_DATA_TYPE_SECURE_CLOCK:
		{
			DRM_CLIENT_TEST_LOG("Get DRM_DATA_TYPE_SECURE_CLOCK");
			drm_secure_clock_data_s secure_clock_info={0};
			ret = drm_get_data(data_type,NULL,(void*)&secure_clock_info);
			DRM_CLIENT_TEST_LOG("ret=0x%x",ret);
			if(DRM_RETURN_SUCCESS == ret
					&& 1 == secure_clock_info.is_secure_clock_set){
				DRM_CLIENT_TEST_LOG("Secure Clock is SET:ret=0x%x",ret);
				DRM_CLIENT_TEST_LOG("Secure Time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
						secure_clock_info.secure_clock.tm_year,
						secure_clock_info.secure_clock.tm_mon,
						secure_clock_info.secure_clock.tm_mday,
						secure_clock_info.secure_clock.tm_hour,
						secure_clock_info.secure_clock.tm_min,
						secure_clock_info.secure_clock.tm_sec);
			}else if(DRM_RETURN_SUCCESS == ret
					&& 0 == secure_clock_info.is_secure_clock_set){
				DRM_CLIENT_TEST_LOG("Secure Clock is NOT SET:ret=0x%x",ret);
			}else{
				DRM_CLIENT_TEST_LOG("Secure Clock Retrieval FAILED:ret=0x%x",ret);
			}
			break;
		}

		case DRM_DATA_TYPE_TRANSACTION_TRACKING_FLAG:
		{
			DRM_CLIENT_TEST_LOG("Get DRM_DATA_TYPE_TRANSACTION_TRACKING_FLAG");

			int transtrk_flag = 0;
			ret = drm_get_data(data_type, NULL, (void*)&transtrk_flag);
			DRM_CLIENT_TEST_LOG("ret=0x%x", ret);
			if (DRM_RETURN_SUCCESS == ret) {
				DRM_CLIENT_TEST_LOG("transtrk_flag = %d", transtrk_flag);
			} else {
				DRM_CLIENT_TEST_LOG("Get Transaction Tracking Flag failed!!, "
						"ret = 0x%x", ret);
			}

			break;
		}

		case DRM_DATA_TYPE_TRANSACTION_TRACKING_ID:
		{
			DRM_CLIENT_TEST_LOG("Get DRM_DATA_TYPE_TRANSACTION_TRACKING_ID");
			drm_transaction_id_info_s transaction_id_info={"",0};
			ret = drm_get_data(data_type,(void*)file_path,(void*)&transaction_id_info);
			DRM_CLIENT_TEST_LOG("ret=0x%x",ret);
			if(DRM_RETURN_SUCCESS == ret){
				DRM_CLIENT_TEST_LOG("Transaction ID Length =%d",
						transaction_id_info.tr_id_len);
				if(0 != transaction_id_info.tr_id_len){
					DRM_CLIENT_TEST_LOG("Transaction ID  =%s",
							transaction_id_info.tr_id);
				}
			}else{
				DRM_CLIENT_TEST_EXCEPTION("Transaction ID Retrieval FAILED:ret=0x%x",ret);
			}
			break;
		}

		case DRM_DATA_TYPE_DIVX_REGISTRATION_CODE:
		{
			DRM_CLIENT_TEST_LOG("Get DRM_DATA_TYPE_DIVX_REGISTRATION_CODE");

			drm_code_info_s reg_code_info = {"",0};
			ret = drm_get_data(data_type, NULL, (void*) &reg_code_info);
			DRM_CLIENT_TEST_LOG("ret=0x%x", ret);
			if (DRM_RETURN_SUCCESS == ret) {
				DRM_CLIENT_TEST_LOG("Code Length = %d", reg_code_info.code_len);
				if (0 != reg_code_info.code_len) {
					DRM_CLIENT_TEST_LOG("Code = %s", reg_code_info.code);
				}
			} else {
				DRM_CLIENT_TEST_EXCEPTION("Divx Registration Code failed!!");
			}
			break;
		}

		case DRM_DATA_TYPE_DIVX_DEREGISTRATION_CODE:
		{
			DRM_CLIENT_TEST_LOG("Get DRM_DATA_TYPE_DIVX_DEREGISTRATION_CODE");

			drm_code_info_s dereg_code_info = {"",0};
			ret = drm_get_data(data_type, NULL, (void*) &dereg_code_info);
			DRM_CLIENT_TEST_LOG("ret=0x%x", ret);
			if (DRM_RETURN_SUCCESS == ret) {
				DRM_CLIENT_TEST_LOG("Code Length = %d", dereg_code_info.code_len);
				if (0 != dereg_code_info.code_len) {
					DRM_CLIENT_TEST_LOG("Code = %s", dereg_code_info.code);
				}
			} else {
				DRM_CLIENT_TEST_EXCEPTION("Divx Registration Code failed!!");
			}

			break;
		}

		default:
			DRM_CLIENT_TEST_EXCEPTION("Unsupported data type=%d",data_type);
		}

		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_get_data completed");
		break;
	}

	case DRM_CLIENT_TEST_process_request:
	{
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_process_request start");
		char file_path[512] = {0,};
		int ret = DRM_RETURN_SUCCESS;
		drm_request_type_e request_type = DRM_REQUEST_TYPE_NONE;

		DRM_CLIENT_TEST_LOG("Enter the request type to be processed");
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_REQUEST_TYPE_REGISTER_FILE",DRM_REQUEST_TYPE_REGISTER_FILE);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_REQUEST_TYPE_UNREGISTER_FILE",DRM_REQUEST_TYPE_UNREGISTER_FILE);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_REQUEST_TYPE_UNREGISTER_ALL_FILES",DRM_REQUEST_TYPE_UNREGISTER_ALL_FILES);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_REQUEST_TYPE_REGISTER_LICENSE",DRM_REQUEST_TYPE_REGISTER_LICENSE);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL",DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_REQUEST_TYPE_SUBMIT_ROAP_MESSAGE",DRM_REQUEST_TYPE_SUBMIT_ROAP_MESSAGE);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_REQUEST_TYPE_SUBMIT_ROAP_USER_CONSENT",DRM_REQUEST_TYPE_SUBMIT_ROAP_USER_CONSENT);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_REQUEST_TYPE_HTTP_USER_CANCEL",DRM_REQUEST_TYPE_HTTP_USER_CANCEL);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_REQUEST_TYPE_REGISTER_COPY_FILE",DRM_REQUEST_TYPE_REGISTER_COPY_FILE);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_REQUEST_TYPE_REGISTER_MOVE_FILE",DRM_REQUEST_TYPE_REGISTER_MOVE_FILE);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_REQUEST_TYPE_INSERT_EXT_MEMORY",DRM_REQUEST_TYPE_INSERT_EXT_MEMORY);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_REQUEST_TYPE_EXTRACT_EXT_MEMORY",DRM_REQUEST_TYPE_EXTRACT_EXT_MEMORY);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_REQUEST_TYPE_REGISTER_SETAS",DRM_REQUEST_TYPE_REGISTER_SETAS);
		DRM_CLIENT_TEST_LOG(" %d ==> DRM_REQUEST_TYPE_UNREGISTER_SETAS",DRM_REQUEST_TYPE_UNREGISTER_SETAS);

		scanf("%d", (int*)&request_type);
		DRM_CLIENT_TEST_LOG("request_type received=%d",request_type);

		switch(request_type){
		case DRM_REQUEST_TYPE_REGISTER_FILE:
		{
			DRM_CLIENT_TEST_LOG("Request for Register file");
			DRM_CLIENT_TEST_LOG("Enter complete file name with path");
			scanf("%511s", file_path);
			DRM_CLIENT_TEST_LOG("file_path=%s",file_path);

			ret = drm_process_request(request_type,(void*)file_path,NULL);
			DRM_CLIENT_TEST_LOG("ret=0x%x",ret);
			if(DRM_RETURN_SUCCESS == ret){
				DRM_CLIENT_TEST_LOG("Register success:file_path=%s",
						file_path);
			}else{
				DRM_CLIENT_TEST_EXCEPTION("Register FAILED:ret=0x%x file_path=%s",
						ret,file_path);
			}
			break;
		}

		case DRM_REQUEST_TYPE_UNREGISTER_FILE:
		{
			DRM_CLIENT_TEST_LOG("Request for Un-register file");
			drm_unregister_info_s unregister_info={"",0};
			DRM_CLIENT_TEST_LOG("Enter complete file name with path");
			scanf("%255s", unregister_info.file_path);

			DRM_CLIENT_TEST_LOG("Enter 1 if you want to remove License also");
			DRM_CLIENT_TEST_LOG("Enter 0 if you don't want to remove License");
			scanf("%d", &unregister_info.remove_license);
			DRM_CLIENT_TEST_LOG("file_path=%s remove_license=%d",
					unregister_info.file_path,unregister_info.remove_license);

			ret = drm_process_request(request_type,(void*)&unregister_info,NULL);
			DRM_CLIENT_TEST_LOG("ret=0x%x",ret);
			if(DRM_RETURN_SUCCESS == ret){
				DRM_CLIENT_TEST_LOG("Un-register success:file_path=%s",
						unregister_info.file_path);
			}else{
				DRM_CLIENT_TEST_EXCEPTION("Un-register FAILED:ret=0x%x "
						"file_path=%s",ret,unregister_info.file_path);
			}
			break;
		}

		case DRM_REQUEST_TYPE_UNREGISTER_ALL_FILES:
		{
			DRM_CLIENT_TEST_LOG("Request for Un-register all files");
			ret = drm_process_request(request_type,NULL,NULL);
			DRM_CLIENT_TEST_LOG("ret=0x%x",ret);
			if(DRM_RETURN_SUCCESS == ret){
				DRM_CLIENT_TEST_LOG("Un-register All files success");
			}else{
				DRM_CLIENT_TEST_EXCEPTION("Un-register All files FAILED:"
						"ret=0x%x",ret);
			}
			break;
		}

		case DRM_REQUEST_TYPE_REGISTER_LICENSE:
		{
			DRM_CLIENT_TEST_LOG("Request for Register License");
			drm_register_lic_info_s lic_req_info={"",0,};
			drm_register_lic_resp_s lic_resp_info={""};
			struct stat stat_buf = { 0 };
			FILE *fp = NULL;
			unsigned int read_len=0;
			char *tempPath = NULL;

			DRM_CLIENT_TEST_LOG("Enter LICENSE file (*.dr/*.drc) with path");
			scanf("%511s", file_path);
			DRM_CLIENT_TEST_LOG("file_path=%s",file_path);

			if (0 == stat(file_path, &stat_buf)) {
				lic_req_info.lic_data_len = stat_buf.st_size;
				DRM_CLIENT_TEST_LOG("file_path=%s file_size=%u",file_path,
						lic_req_info.lic_data_len);
			} else {
				DRM_CLIENT_TEST_EXCEPTION("stat failed:error=%s file_path=%s",
						strerror(errno),file_path);
				break;
			}

			fp = fopen(file_path,"r");
			if(NULL == fp){
				DRM_CLIENT_TEST_EXCEPTION("fopen failed:error=%s file_path=%s",
						strerror(errno),file_path);
				break;
			}

			memset(lic_req_info.lic_data,0x0,sizeof(lic_req_info.lic_data));
			read_len = fread(lic_req_info.lic_data,1,lic_req_info.lic_data_len,fp);
			DRM_CLIENT_TEST_LOG("read_len=%u lic_req_info.lic_data_len=%u",
					read_len,lic_req_info.lic_data_len);

			fclose(fp);

			tempPath = strrchr((char *)file_path, '.');
			if(strncmp(tempPath, ".dr", 2) == 0
				|| strncmp(tempPath, ".drc", 3) == 0){
				DRM_CLIENT_TEST_LOG("DRM v1 License file");

				lic_req_info.lic_version = DRM_OMA_DRMV1_RIGHTS;
				lic_req_info.roap_init_src = DRM_ROAP_INIT_FROM_UNKNOWN;
				lic_req_info.operation_callback.callback = test_operation_cb;

				ret = drm_process_request(request_type,(void*)&lic_req_info,
						(void*)&lic_resp_info);
				DRM_CLIENT_TEST_LOG("ret=0x%x",ret);
				if(DRM_RETURN_SUCCESS == ret){
					DRM_CLIENT_TEST_LOG("Register License success");
					DRM_CLIENT_TEST_LOG("CID=%s",lic_resp_info.cid);
				}else{
					DRM_CLIENT_TEST_EXCEPTION("Register License FAILED:"
							"ret=0x%x",ret);
				}
			}

			break;
		}

		case DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL:
		{
			DRM_CLIENT_TEST_LOG("Request for Initiator URL processing");

			drm_initiator_info_s initiator_info = {"",0,};
			drm_web_server_resp_data_s ws_resp_data = {"",};

			/* Get the input parameters */
			DRM_CLIENT_TEST_LOG("Enter the initiator URL");
			scanf("%512s", initiator_info.initiator_url);
			initiator_info.initiator_url_len = strlen(initiator_info.initiator_url);
			initiator_info.operation_callback.callback = test_operation_cb;

			ret = drm_process_request(request_type, (void*) &initiator_info,
					(void*) &ws_resp_data);
			if (DRM_RETURN_SUCCESS == ret) {
				DRM_CLIENT_TEST_LOG("Server Error Code = %d",
						ws_resp_data.result_code);
				DRM_CLIENT_TEST_LOG("Content URL = %s",
						ws_resp_data.content_url);
			} else {
				DRM_CLIENT_TEST_EXCEPTION("Submit Initiator URL Failed!!, ret = 0x%x", ret);
			}

			break;
		}

		case DRM_REQUEST_TYPE_SUBMIT_ROAP_MESSAGE:
		{
			DRM_CLIENT_TEST_LOG("DRM_REQUEST_TYPE_SUBMIT_ROAP_MESSAGE");
			drm_submit_roap_message_info_s message_info;
			memset(&message_info,0x0,sizeof(drm_submit_roap_message_info_s));
			ret = drm_process_request(request_type,(void *)&message_info,NULL);
			if (DRM_RETURN_SUCCESS == ret) {
				DRM_CLIENT_TEST_LOG("SUBMIT_ROAP_MESSAGE success");
			} else {
				DRM_CLIENT_TEST_EXCEPTION("SUBMIT_ROAP_MESSAGE Failed!!, ret = 0x%x", ret);
			}
			break;
		}

		case DRM_REQUEST_TYPE_SUBMIT_ROAP_USER_CONSENT:
		{
			DRM_CLIENT_TEST_LOG("DRM_REQUEST_TYPE_SUBMIT_ROAP_USER_CONSENT");
			drm_submit_roap_user_consent_info_s user_consent_info;
			memset(&user_consent_info,0x0,sizeof(drm_submit_roap_user_consent_info_s));
			ret = drm_process_request(request_type,(void *)&user_consent_info,NULL);
			if (DRM_RETURN_SUCCESS == ret) {
				DRM_CLIENT_TEST_LOG("SUBMIT_ROAP_USER_CONSENT success");
			} else {
				DRM_CLIENT_TEST_EXCEPTION("SUBMIT_ROAP_USER_CONSENT Failed!!, ret = 0x%x", ret);
			}
			break;
		}

		case DRM_REQUEST_TYPE_HTTP_USER_CANCEL:
		{
			DRM_CLIENT_TEST_LOG("DRM_REQUEST_TYPE_HTTP_USER_CANCEL");
			drm_http_user_cancel_info_s user_cancel_info;
			memset(&user_cancel_info,0x0,sizeof(drm_http_user_cancel_info_s));
			ret = drm_process_request(request_type,(void *)&user_cancel_info,NULL);
			if (DRM_RETURN_SUCCESS == ret) {
				DRM_CLIENT_TEST_LOG("HTTP_USER_CANCEL success");
			} else {
				DRM_CLIENT_TEST_EXCEPTION("HTTP_USER_CANCEL Failed!!, ret = 0x%x", ret);
			}
			break;
		}

		case DRM_REQUEST_TYPE_REGISTER_COPY_FILE:
		{
			DRM_CLIENT_TEST_LOG("DRM_REQUEST_TYPE_REGISTER_COPY_FILE");
			drm_register_copy_file_info_s copy_file_info;
			memset(&copy_file_info,0x0,sizeof(drm_register_copy_file_info_s));

			DRM_CLIENT_TEST_LOG("Enter Source file with path");
			scanf("%255s", copy_file_info.src_file_path);
			DRM_CLIENT_TEST_LOG("src_file_path=%s",copy_file_info.src_file_path);

			DRM_CLIENT_TEST_LOG("Enter Destination file with path");
			scanf("%255s", copy_file_info.dest_file_path);
			DRM_CLIENT_TEST_LOG("dest_file_path=%s",copy_file_info.dest_file_path);

			ret = drm_process_request(request_type,(void *)&copy_file_info,NULL);
			if (DRM_RETURN_SUCCESS == ret) {
				DRM_CLIENT_TEST_LOG("REGISTER_COPY_FILE success");
			} else {
				DRM_CLIENT_TEST_EXCEPTION("REGISTER_COPY_FILE Failed!!, ret = 0x%x", ret);
			}
			break;
		}

		case DRM_REQUEST_TYPE_REGISTER_MOVE_FILE:
		{
			DRM_CLIENT_TEST_LOG("DRM_REQUEST_TYPE_REGISTER_MOVE_FILE");
			drm_register_copy_file_info_s copy_file_info;
			memset(&copy_file_info,0x0,sizeof(drm_register_copy_file_info_s));

			DRM_CLIENT_TEST_LOG("Enter Source file with path");
			scanf("%255s", copy_file_info.src_file_path);
			DRM_CLIENT_TEST_LOG("src_file_path=%s",copy_file_info.src_file_path);

			DRM_CLIENT_TEST_LOG("Enter Destination file with path");
			scanf("%255s", copy_file_info.dest_file_path);
			DRM_CLIENT_TEST_LOG("dest_file_path=%s",copy_file_info.dest_file_path);

			ret = drm_process_request(request_type,(void *)&copy_file_info,NULL);
			if (DRM_RETURN_SUCCESS == ret) {
				DRM_CLIENT_TEST_LOG("REGISTER_MOVE_FILE success");
			} else {
				DRM_CLIENT_TEST_EXCEPTION("REGISTER_MOVE_FILE Failed!!, ret = 0x%x", ret);
			}
			break;
		}

		case DRM_REQUEST_TYPE_INSERT_EXT_MEMORY:
		{
			DRM_CLIENT_TEST_LOG("DRM_REQUEST_TYPE_INSERT_EXT_MEMORY");
			ret = drm_process_request(request_type,NULL,NULL);
			if (DRM_RETURN_SUCCESS == ret) {
				DRM_CLIENT_TEST_LOG("INSERT_EXT_MEMORY success");
			} else {
				DRM_CLIENT_TEST_EXCEPTION("INSERT_EXT_MEMORY Failed!!, ret = 0x%x", ret);
			}
			break;
		}

		case DRM_REQUEST_TYPE_EXTRACT_EXT_MEMORY:
		{
			DRM_CLIENT_TEST_LOG("DRM_REQUEST_TYPE_EXTRACT_EXT_MEMORY");
			ret = drm_process_request(request_type,NULL,NULL);
			if (DRM_RETURN_SUCCESS == ret) {
				DRM_CLIENT_TEST_LOG("INSERT_EXT_MEMORY success");
			} else {
				DRM_CLIENT_TEST_EXCEPTION("INSERT_EXT_MEMORY Failed!!, ret = 0x%x", ret);
			}
			break;
		}

		case DRM_REQUEST_TYPE_REGISTER_SETAS:
		{
			DRM_CLIENT_TEST_LOG("DRM_REQUEST_TYPE_REGISTER_SETAS");
			drm_register_setas_info_s setas_info;
			memset(&setas_info,0x0,sizeof(drm_register_setas_info_s));

			DRM_CLIENT_TEST_LOG("Enter file name with path to be set");
			scanf("%255s", setas_info.file_path);
			DRM_CLIENT_TEST_LOG("file_path=%s",setas_info.file_path);

			DRM_CLIENT_TEST_LOG("Enter SETAS Category");
			DRM_CLIENT_TEST_LOG("Enter=%d -> DRM_SETAS_WALLPAPER",DRM_SETAS_WALLPAPER);
			DRM_CLIENT_TEST_LOG("Enter=%d -> DRM_SETAS_RINGTONE",DRM_SETAS_RINGTONE);
			scanf("%d", (int*)&setas_info.setas_cat);
			DRM_CLIENT_TEST_LOG("setas_cat=%d",setas_info.setas_cat);

			ret = drm_process_request(request_type,(void *)&setas_info,NULL);
			if (DRM_RETURN_SUCCESS == ret) {
				DRM_CLIENT_TEST_LOG("REGISTER_SETAS success");
			} else {
				DRM_CLIENT_TEST_EXCEPTION("REGISTER_SETAS Failed!!, ret = 0x%x", ret);
			}
			break;
		}

		case DRM_REQUEST_TYPE_UNREGISTER_SETAS:
		{
			DRM_CLIENT_TEST_LOG("DRM_REQUEST_TYPE_UNREGISTER_SETAS");
			drm_unregister_setas_info_s setas_info;
			memset(&setas_info,0x0,sizeof(drm_unregister_setas_info_s));

			DRM_CLIENT_TEST_LOG("Enter file name with path to be set");
			scanf("%255s", setas_info.file_path);
			DRM_CLIENT_TEST_LOG("file_path=%s",setas_info.file_path);

			DRM_CLIENT_TEST_LOG("Enter SETAS Category");
			DRM_CLIENT_TEST_LOG("Enter=%d -> DRM_SETAS_WALLPAPER",DRM_SETAS_WALLPAPER);
			DRM_CLIENT_TEST_LOG("Enter=%d -> DRM_SETAS_RINGTONE",DRM_SETAS_RINGTONE);
			scanf("%d", (int*)&setas_info.setas_cat);
			DRM_CLIENT_TEST_LOG("setas_cat=%d",setas_info.setas_cat);

			ret = drm_process_request(request_type,(void *)&setas_info,NULL);
			if (DRM_RETURN_SUCCESS == ret) {
				DRM_CLIENT_TEST_LOG("UNREGISTER_SETAS success");
			} else {
				DRM_CLIENT_TEST_EXCEPTION("UNREGISTER_SETAS Failed!!, ret = 0x%x", ret);
			}
			break;
		}

		default:
			DRM_CLIENT_TEST_EXCEPTION("Unsupported request_type=%d",request_type);
		}
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_process_request completed");
		break;
	}

	case DRM_CLIENT_TEST_print_return_code_values:
	{
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_print_return_code_values Start");
		DRM_CLIENT_TEST_LOG("DRM_RETURN_SUCCESS=%d=0x%x",DRM_RETURN_SUCCESS,DRM_RETURN_SUCCESS);
		DRM_CLIENT_TEST_LOG("DRM_RETURN_INVALID_ARG=%d=0x%x",DRM_RETURN_INVALID_ARG,DRM_RETURN_INVALID_ARG);
		DRM_CLIENT_TEST_LOG("DRM_RETURN_INSUFFICIENT_MEMORY=%d=0x%x",DRM_RETURN_INSUFFICIENT_MEMORY,DRM_RETURN_INSUFFICIENT_MEMORY);
		DRM_CLIENT_TEST_LOG("DRM_RETURN_PARSING_ERROR=%d=0x%x",DRM_RETURN_PARSING_ERROR,DRM_RETURN_PARSING_ERROR);
		DRM_CLIENT_TEST_LOG("DRM_RETURN_DB_ERROR=%d=0x%x",DRM_RETURN_DB_ERROR,DRM_RETURN_DB_ERROR);
		DRM_CLIENT_TEST_LOG("DRM_RETURN_FILE_ERROR=%d=0x%x",DRM_RETURN_FILE_ERROR,DRM_RETURN_FILE_ERROR);
		DRM_CLIENT_TEST_LOG("DRM_RETURN_COMMUNICATION_ERROR=%d=0x%x",DRM_RETURN_COMMUNICATION_ERROR,DRM_RETURN_COMMUNICATION_ERROR);
		DRM_CLIENT_TEST_LOG("DRM_RETURN_INTERNAL_ERROR=%d=0x%x",DRM_RETURN_INTERNAL_ERROR,DRM_RETURN_INTERNAL_ERROR);
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_print_return_code_values Completed");
		break;
	}

	case DRM_CLIENT_TEST_MAX:
	{
		DRM_CLIENT_TEST_LOG("DRM_CLIENT_TEST_MAX");
		DRM_CLIENT_TEST_LOG("SUCCESS");
		return 0;
	}

	default:
		DRM_CLIENT_TEST_EXCEPTION("Wrong choice=%d",option);
		goto ERR;
	}

	DRM_CLIENT_TEST_LOG("SUCCESS");
	return 1;

ERR:
	DRM_CLIENT_TEST_EXCEPTION("test_case:Error:Exit from DRM CLIENT Test utility");
	return 0;
}

int main(int argc, char* argv[])
{
	int pid = getpid();
	int choice = DRM_CLIENT_TEST_NONE;
	DRM_CLIENT_TEST_LOG("main:pid=[%d]", pid);

	do {
		DRM_CLIENT_TEST_LOG("choice=%d -> DRM_CLIENT_TEST_NONE",DRM_CLIENT_TEST_NONE);
		DRM_CLIENT_TEST_LOG("choice=%d -> DRM_CLIENT_TEST_is_drm_file",DRM_CLIENT_TEST_is_drm_file);
		DRM_CLIENT_TEST_LOG("choice=%d -> DRM_CLIENT_TEST_get_file_type",DRM_CLIENT_TEST_get_file_type);
		DRM_CLIENT_TEST_LOG("choice=%d -> DRM_CLIENT_TEST_get_license_status",DRM_CLIENT_TEST_get_license_status);
		DRM_CLIENT_TEST_LOG("choice=%d -> DRM_CLIENT_TEST_get_content_info",DRM_CLIENT_TEST_get_content_info);
		DRM_CLIENT_TEST_LOG("choice=%d -> DRM_CLIENT_TEST_get_file_info",DRM_CLIENT_TEST_get_file_info);
		DRM_CLIENT_TEST_LOG("choice=%d -> DRM_CLIENT_TEST_get_constraint_info",DRM_CLIENT_TEST_get_constraint_info);
		DRM_CLIENT_TEST_LOG("choice=%d -> DRM_CLIENT_TEST_is_action_allowed",DRM_CLIENT_TEST_is_action_allowed);
		DRM_CLIENT_TEST_LOG("choice=%d -> DRM_CLIENT_TEST_get_data",DRM_CLIENT_TEST_get_data);
		DRM_CLIENT_TEST_LOG("choice=%d -> DRM_CLIENT_TEST_process_request",DRM_CLIENT_TEST_process_request);
		DRM_CLIENT_TEST_LOG("choice=%d -> DRM_CLIENT_TEST_print_return_code_values",DRM_CLIENT_TEST_print_return_code_values);
		DRM_CLIENT_TEST_LOG("choice=%d -> Exit from TEST Script",DRM_CLIENT_TEST_MAX);
		DRM_CLIENT_TEST_LOG("Enter Your choice:1 to %d:Use choice no-%d to exit the test-program",DRM_CLIENT_TEST_MAX, DRM_CLIENT_TEST_MAX);
		scanf("%3d", &choice);
	} while (1 == test_case(choice));

	DRM_CLIENT_TEST_LOG("Exiting process=[%d] from main", pid);
	return 0;
}
