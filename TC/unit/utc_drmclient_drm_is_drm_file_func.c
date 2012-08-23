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
 * @file 		utc_drmclient_drm_is_drm_file_func.c
 * @brief       TETware unit testing functions for drm_is_drm_file.
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

static void utc_drmclient_drm_is_drm_file_func_01(void);
static void utc_drmclient_drm_is_drm_file_func_02(void);
static void utc_drmclient_drm_is_drm_file_func_03(void);
static void utc_drmclient_drm_is_drm_file_func_04(void);
static void utc_drmclient_drm_is_drm_file_func_05(void);
static void utc_drmclient_drm_is_drm_file_func_06(void);
static void utc_drmclient_drm_is_drm_file_func_07(void);
static void utc_drmclient_drm_is_drm_file_func_08(void);
static void utc_drmclient_drm_is_drm_file_func_09(void);
static void utc_drmclient_drm_is_drm_file_func_10(void);
static void utc_drmclient_drm_is_drm_file_func_11(void);
static void utc_drmclient_drm_is_drm_file_func_12(void);
static void utc_drmclient_drm_is_drm_file_func_13(void);
static void utc_drmclient_drm_is_drm_file_func_14(void);
static void utc_drmclient_drm_is_drm_file_func_15(void);
static void utc_drmclient_drm_is_drm_file_func_16(void);
static void utc_drmclient_drm_is_drm_file_func_17(void);
static void utc_drmclient_drm_is_drm_file_func_18(void);
static void utc_drmclient_drm_is_drm_file_func_19(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{ utc_drmclient_drm_is_drm_file_func_01, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_02, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_03, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_04, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_05, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_06, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_07, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_08, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_09, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_10, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_11, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_12, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_13, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_14, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_15, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_16, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_17, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_18, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_is_drm_file_func_19, NEGATIVE_TC_IDX },
	{ NULL, 0 }
};

static void startup(void)
{
	tet_infoline("drm_is_drm_file:Test started");
}

static void cleanup(void)
{
	tet_infoline("drm_is_drm_file:Test completed");
}

/**
 * @brief Positive test case of drm_is_drm_file()
 */
static void utc_drmclient_drm_is_drm_file_func_01(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_1);

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS == ret && DRM_TRUE == is_drm_file){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_is_drm_file()
 */
static void utc_drmclient_drm_is_drm_file_func_02(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_2);

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS == ret && DRM_TRUE == is_drm_file){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_2);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_2);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_is_drm_file()
 */
static void utc_drmclient_drm_is_drm_file_func_03(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_3);

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS == ret && DRM_TRUE == is_drm_file){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_3);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_3);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_is_drm_file()
 */
static void utc_drmclient_drm_is_drm_file_func_04(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_4);

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS == ret && DRM_TRUE == is_drm_file){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_4);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_4);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_is_drm_file()
 */
static void utc_drmclient_drm_is_drm_file_func_05(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_PR_1);

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS == ret && DRM_TRUE == is_drm_file){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_is_drm_file()
 */
static void utc_drmclient_drm_is_drm_file_func_06(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_PR_2);

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS == ret && DRM_TRUE == is_drm_file){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_2);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_2);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_is_drm_file()
 */
static void utc_drmclient_drm_is_drm_file_func_07(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_PR_ENV_1);

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS == ret && DRM_TRUE == is_drm_file){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_ENV_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_ENV_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_is_drm_file()
 */
static void utc_drmclient_drm_is_drm_file_func_08(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_PR_ENV_2);

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS == ret && DRM_TRUE == is_drm_file){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_ENV_2);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_ENV_2);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_is_drm_file()
 */
static void utc_drmclient_drm_is_drm_file_func_09(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_DIVX_1);

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS == ret && DRM_TRUE == is_drm_file){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_DIVX_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_DIVX_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_is_drm_file()
 */

static void utc_drmclient_drm_is_drm_file_func_10(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;

	ret = drm_is_drm_file(FILE_PATH_INVALID_FILE_NULL,&is_drm_file);
	if(DRM_RETURN_SUCCESS != ret){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_NULL);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_NULL);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_is_drm_file()
 */

static void utc_drmclient_drm_is_drm_file_func_11(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS != ret){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_EMPTY);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_EMPTY);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_is_drm_file()
 */

static void utc_drmclient_drm_is_drm_file_func_12(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_INVALID_FILE_OMA_1);

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS == ret && DRM_FALSE == is_drm_file){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_is_drm_file()
 */

static void utc_drmclient_drm_is_drm_file_func_13(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_INVALID_FILE_OMA_2);

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS == ret && DRM_FALSE == is_drm_file){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_OMA_2);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_OMA_2);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_is_drm_file()
 */

static void utc_drmclient_drm_is_drm_file_func_14(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_INVALID_FILE_OMA_3);

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS == ret && DRM_FALSE == is_drm_file){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_OMA_3);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_OMA_3);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_is_drm_file()
 */

static void utc_drmclient_drm_is_drm_file_func_15(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_INVALID_FILE_PR_1);

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS == ret && DRM_FALSE == is_drm_file){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_PR_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_PR_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_is_drm_file()
 */

static void utc_drmclient_drm_is_drm_file_func_16(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_INVALID_FILE_PR_2);

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS == ret && DRM_FALSE == is_drm_file){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_PR_2);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_PR_2);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_is_drm_file()
 */

static void utc_drmclient_drm_is_drm_file_func_17(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_INVALID_FILE_PR_ENV_1);

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS == ret && DRM_FALSE == is_drm_file){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_PR_ENV_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_PR_ENV_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_is_drm_file()
 */

static void utc_drmclient_drm_is_drm_file_func_18(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_INVALID_FILE_DIVX_1);

	ret = drm_is_drm_file(file_path,&is_drm_file);
	if(DRM_RETURN_SUCCESS == ret && DRM_FALSE == is_drm_file){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_DIVX_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_DIVX_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_is_drm_file()
 */

static void utc_drmclient_drm_is_drm_file_func_19(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_bool_type_e is_drm_file = DRM_UNKNOWN;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_INVALID_FILE_DIVX_1);

	ret = drm_is_drm_file(file_path,INVALID_POINTER_OBJECT);
	if(DRM_RETURN_SUCCESS != ret){
			tet_infoline("drm_is_drm_file PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_DIVX_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_is_drm_file FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_DIVX_1);
			tet_printf ("ret = 0x%x is_drm_file=%d",ret,is_drm_file);
			tet_result(TET_FAIL);
	}
}
