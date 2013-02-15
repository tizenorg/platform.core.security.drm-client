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
 * @file 		utc_drmclient_drm_get_license_status_func.c
 * @brief       TETware unit testing functions for drm_get_license_status.
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

static void utc_drmclient_drm_get_license_status_func_01(void);
static void utc_drmclient_drm_get_license_status_func_02(void);
static void utc_drmclient_drm_get_license_status_func_03(void);
static void utc_drmclient_drm_get_license_status_func_04(void);
static void utc_drmclient_drm_get_license_status_func_05(void);
static void utc_drmclient_drm_get_license_status_func_06(void);
static void utc_drmclient_drm_get_license_status_func_07(void);
static void utc_drmclient_drm_get_license_status_func_08(void);
static void utc_drmclient_drm_get_license_status_func_09(void);
static void utc_drmclient_drm_get_license_status_func_10(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{ utc_drmclient_drm_get_license_status_func_01, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_license_status_func_02, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_license_status_func_03, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_license_status_func_04, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_license_status_func_05, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_license_status_func_06, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_license_status_func_07, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_get_license_status_func_08, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_get_license_status_func_09, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_get_license_status_func_10, NEGATIVE_TC_IDX },
	{ NULL, 0 }
};

static void startup(void)
{
	tet_infoline("drm_get_license_status:Test started");
	tet_infoline("OMA DRM Content should be registered");
	tet_infoline("RO must be installed to get valid License status");
}

static void cleanup(void)
{
	tet_infoline("drm_get_license_status:Test completed");
}

/**
 * @brief Positive test case of drm_get_license_status()
 */
static void utc_drmclient_drm_get_license_status_func_01(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_license_status_e license_status = DRM_LICENSE_STATUS_UNDEFINED;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_PLAY;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_1);

	ret = drm_get_license_status(file_path,perm_type,&license_status);
	if(DRM_RETURN_SUCCESS == ret ){
			tet_infoline("drm_get_license_status PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_license_status FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_get_license_status()
 */
static void utc_drmclient_drm_get_license_status_func_02(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_license_status_e license_status = DRM_LICENSE_STATUS_UNDEFINED;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_DISPLAY;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_2);

	ret = drm_get_license_status(file_path,perm_type,&license_status);
	if(DRM_RETURN_SUCCESS == ret ){
			tet_infoline("drm_get_license_status PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_2);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_license_status FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_2);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_get_license_status()
 */
static void utc_drmclient_drm_get_license_status_func_03(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_license_status_e license_status = DRM_LICENSE_STATUS_UNDEFINED;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_PLAY;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_3);

	ret = drm_get_license_status(file_path,perm_type,&license_status);
	if(DRM_RETURN_SUCCESS == ret ){
			tet_infoline("drm_get_license_status PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_3);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_license_status FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_3);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_get_license_status()
 */
static void utc_drmclient_drm_get_license_status_func_04(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_license_status_e license_status = DRM_LICENSE_STATUS_UNDEFINED;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_PLAY;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_4);

	ret = drm_get_license_status(file_path,perm_type,&license_status);
	if(DRM_RETURN_SUCCESS == ret ){
			tet_infoline("drm_get_license_status PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_4);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_license_status FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_4);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_get_license_status()
 */
static void utc_drmclient_drm_get_license_status_func_05(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_license_status_e license_status = DRM_LICENSE_STATUS_UNDEFINED;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_PLAY;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_PR_1);

	ret = drm_get_license_status(file_path,perm_type,&license_status);
	if(DRM_RETURN_SUCCESS == ret ){
			tet_infoline("drm_get_license_status PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_1);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_license_status FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_1);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_get_license_status()
 */
static void utc_drmclient_drm_get_license_status_func_06(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_license_status_e license_status = DRM_LICENSE_STATUS_UNDEFINED;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_PLAY;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_PR_2);

	ret = drm_get_license_status(file_path,perm_type,&license_status);
	if(DRM_RETURN_SUCCESS == ret ){
			tet_infoline("drm_get_license_status PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_2);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_license_status FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_2);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_get_license_status()
 */

static void utc_drmclient_drm_get_license_status_func_07(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_license_status_e license_status = DRM_LICENSE_STATUS_UNDEFINED;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_NONE;

	ret = drm_get_license_status(FILE_PATH_INVALID_FILE_NULL,perm_type,&license_status);
	if(DRM_RETURN_SUCCESS != ret){
			tet_infoline("drm_get_license_status PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_NULL);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_license_status FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_NULL);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_get_license_status()
 */

static void utc_drmclient_drm_get_license_status_func_08(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_license_status_e license_status = DRM_LICENSE_STATUS_UNDEFINED;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_NONE;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};

	ret = drm_get_license_status(file_path,perm_type,&license_status);
	if(DRM_RETURN_SUCCESS != ret){
			tet_infoline("drm_get_license_status PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_EMPTY);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_license_status FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_EMPTY);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_get_license_status()
 */

static void utc_drmclient_drm_get_license_status_func_09(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_license_status_e license_status = DRM_LICENSE_STATUS_UNDEFINED;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_NONE;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_INVALID_FILE_DIVX_1);

	ret = drm_get_license_status(file_path,perm_type,INVALID_POINTER_OBJECT);
	if(DRM_RETURN_SUCCESS != ret){
			tet_infoline("drm_get_license_status PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_DIVX_1);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_license_status FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_DIVX_1);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_get_license_status()
 */

static void utc_drmclient_drm_get_license_status_func_10(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_license_status_e license_status = DRM_LICENSE_STATUS_UNDEFINED;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_NONE;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_INVALID_FILE_OMA_2);

	ret = drm_get_license_status(file_path,perm_type,&license_status);
	if(DRM_RETURN_SUCCESS != ret){
			tet_infoline("drm_get_license_status PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_OMA_2);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_license_status FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_OMA_2);
			tet_printf ("ret = 0x%x license_status=%d",ret,license_status);
			tet_result(TET_FAIL);
	}
}
