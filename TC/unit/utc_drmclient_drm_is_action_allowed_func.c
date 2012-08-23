/*
 * drm-client TCs
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
 * @file 		utc_drmclient_drm_is_action_allowed_func.c
 * @brief       TETware unit testing functions for drm_is_action_allowed.
 * @author      Mahendra Kumar Prajapat (mahendra.p@samsung.com)
 * @version     0.1
 * @history     0.1: Initial draft
 */

#include <tet_api.h>
#include "drmcontentsdef.h"

static void startup(void);
static void cleanup(void);

void (*tet_startup)(void) = startup;
void (*tet_cleanup)(void) = cleanup;

static void utc_drmclient_drm_is_action_allowed_func_01(void);
static void utc_drmclient_drm_is_action_allowed_func_02(void);
static void utc_drmclient_drm_is_action_allowed_func_03(void);
static void utc_drmclient_drm_is_action_allowed_func_04(void);
static void utc_drmclient_drm_is_action_allowed_func_05(void);
static void utc_drmclient_drm_is_action_allowed_func_06(void);
static void utc_drmclient_drm_is_action_allowed_func_07(void);
static void utc_drmclient_drm_is_action_allowed_func_08(void);
static void utc_drmclient_drm_is_action_allowed_func_09(void);
static void utc_drmclient_drm_is_action_allowed_func_10(void);
static void utc_drmclient_drm_is_action_allowed_func_11(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{ utc_drmclient_drm_is_action_allowed_func_01, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_action_allowed_func_02, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_action_allowed_func_03, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_action_allowed_func_04, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_action_allowed_func_05, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_action_allowed_func_06, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_action_allowed_func_07, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_action_allowed_func_08, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_action_allowed_func_09, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_action_allowed_func_10, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_is_action_allowed_func_11, NEGATIVE_TC_IDX },
	{ NULL, 0 }
};

static void startup(void)
{
	tet_infoline("drm_is_action_allowed:Test started");
}

static void cleanup(void)
{
	tet_infoline("drm_is_action_allowed:Test completed");
}

/**
 * @brief Positive test case of drm_is_action_allowed()
 */
static void utc_drmclient_drm_is_action_allowed_func_01(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_bool_type_e is_allowed = DRM_UNKNOWN;
	drm_action_type_e action = DRM_IS_FORWARDING_ALLOWED;
	drm_action_allowed_data_s action_data;
	memset(&action_data,0x0,sizeof(drm_action_allowed_data_s));

	snprintf(action_data.file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_9);

	ret = drm_is_action_allowed(action,&action_data,&is_allowed);
	if(DRM_RETURN_SUCCESS == ret && DRM_FALSE == is_allowed){
			tet_infoline("drm_is_action_allowed PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_9);
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_action_allowed FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_9);
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_is_action_allowed()
 */
static void utc_drmclient_drm_is_action_allowed_func_02(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_bool_type_e is_allowed = DRM_UNKNOWN;
	drm_action_type_e action = DRM_IS_FORWARDING_ALLOWED;
	drm_action_allowed_data_s action_data;
	memset(&action_data,0x0,sizeof(drm_action_allowed_data_s));

	snprintf(action_data.file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_1);

	ret = drm_is_action_allowed(action,&action_data,&is_allowed);
	if(DRM_RETURN_SUCCESS == ret && DRM_TRUE == is_allowed){
			tet_infoline("drm_is_action_allowed PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_action_allowed FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_is_action_allowed()
 */
static void utc_drmclient_drm_is_action_allowed_func_03(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_bool_type_e is_allowed = DRM_UNKNOWN;
	drm_action_type_e action = DRM_IS_FORWARDING_ALLOWED;
	drm_action_allowed_data_s action_data;
	memset(&action_data,0x0,sizeof(drm_action_allowed_data_s));
	snprintf(action_data.file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_2);

	ret = drm_is_action_allowed(action,&action_data,&is_allowed);
	if(DRM_RETURN_SUCCESS == ret && DRM_TRUE == is_allowed){
			tet_infoline("drm_is_action_allowed PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_2);
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_action_allowed FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_2);
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_is_action_allowed()
 */
static void utc_drmclient_drm_is_action_allowed_func_04(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_bool_type_e is_allowed = DRM_UNKNOWN;
	drm_action_type_e action = DRM_IS_FORWARDING_ALLOWED;
	drm_action_allowed_data_s action_data;
	memset(&action_data,0x0,sizeof(drm_action_allowed_data_s));
	snprintf(action_data.file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_3);

	ret = drm_is_action_allowed(action,&action_data,&is_allowed);
	if(DRM_RETURN_SUCCESS == ret && DRM_TRUE == is_allowed){
			tet_infoline("drm_is_action_allowed PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_3);
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_action_allowed FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_3);
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_is_action_allowed()
 */
static void utc_drmclient_drm_is_action_allowed_func_05(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_bool_type_e is_allowed = DRM_UNKNOWN;
	drm_action_type_e action = DRM_IS_FORWARDING_ALLOWED;
	drm_action_allowed_data_s action_data;
	memset(&action_data,0x0,sizeof(drm_action_allowed_data_s));
	snprintf(action_data.file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_4);

	ret = drm_is_action_allowed(action,&action_data,&is_allowed);
	if(DRM_RETURN_SUCCESS == ret && DRM_TRUE == is_allowed){
			tet_infoline("drm_is_action_allowed PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_4);
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_action_allowed FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_4);
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_is_action_allowed()
 */
static void utc_drmclient_drm_is_action_allowed_func_06(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_bool_type_e is_allowed = DRM_UNKNOWN;
	drm_action_type_e action = DRM_HAS_VALID_SETAS_STATUS;
	drm_action_allowed_data_s action_data;
	memset(&action_data,0x0,sizeof(drm_action_allowed_data_s));
	snprintf(action_data.file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_1);
	action_data.data = (int)DRM_SETAS_RINGTONE;

	ret = drm_is_action_allowed(action,&action_data,&is_allowed);
	if(DRM_RETURN_SUCCESS == ret && DRM_FALSE == is_allowed){
			tet_infoline("drm_is_action_allowed PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_action_allowed FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_is_action_allowed()
 */
static void utc_drmclient_drm_is_action_allowed_func_07(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_bool_type_e is_allowed = DRM_UNKNOWN;
	drm_action_type_e action = DRM_HAS_VALID_SETAS_STATUS;
	drm_action_allowed_data_s action_data;
	memset(&action_data,0x0,sizeof(drm_action_allowed_data_s));
	snprintf(action_data.file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_8);
	action_data.data= (int)DRM_SETAS_RINGTONE;

	ret = drm_is_action_allowed(action,&action_data,&is_allowed);
	if(DRM_RETURN_SUCCESS == ret){
			tet_infoline("drm_is_action_allowed PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_8);
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_action_allowed FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_8);
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_is_action_allowed()
 */
static void utc_drmclient_drm_is_action_allowed_func_08(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_bool_type_e is_allowed = DRM_UNKNOWN;
	drm_action_type_e action = DRM_IS_DEVICE_ACTIVATED;

	ret = drm_is_action_allowed(action,NULL,&is_allowed);
	if(DRM_RETURN_SUCCESS == ret){
			tet_infoline("drm_is_action_allowed PASS!!!");
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_action_allowed FAIL!!!");
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_is_action_allowed()
 */
static void utc_drmclient_drm_is_action_allowed_func_09(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_bool_type_e is_allowed = DRM_UNKNOWN;
	drm_action_type_e action = DRM_IS_VALID_SECURE_CLOCK;

	ret = drm_is_action_allowed(action,NULL,&is_allowed);
	if(DRM_RETURN_SUCCESS == ret){
			tet_infoline("drm_is_action_allowed PASS!!!");
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_action_allowed FAIL!!!");
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_is_action_allowed()
 */
static void utc_drmclient_drm_is_action_allowed_func_10(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_bool_type_e is_allowed = DRM_UNKNOWN;
	drm_action_type_e action = DRM_IS_FORWARDING_ALLOWED;

	ret = drm_is_action_allowed(action,NULL,&is_allowed);
	if(DRM_RETURN_SUCCESS != ret){
			tet_infoline("drm_is_action_allowed PASS!!!");
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_action_allowed FAIL!!!");
			tet_printf ("ret = 0x%x is_allowed=%d",ret,is_allowed);
			tet_result(TET_FAIL);
	}
}


/**
 * @brief Negative test case of drm_is_action_allowed()
 */

static void utc_drmclient_drm_is_action_allowed_func_11(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_action_type_e action = DRM_IS_FORWARDING_ALLOWED;
	drm_action_allowed_data_s action_data;
	memset(&action_data,0x0,sizeof(drm_action_allowed_data_s));
	snprintf(action_data.file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_1);

	ret = drm_is_action_allowed(action,&action_data,INVALID_POINTER_OBJECT);
	if(DRM_RETURN_SUCCESS != ret){
			tet_infoline("drm_is_action_allowed PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_action_allowed FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}
