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
 * @file 		utc_drmclient_drm_get_data_func.c
 * @brief       TETware unit testing functions for drm_get_data.
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

static void utc_drmclient_drm_get_data_func_01(void);
static void utc_drmclient_drm_get_data_func_02(void);
static void utc_drmclient_drm_get_data_func_03(void);
static void utc_drmclient_drm_get_data_func_04(void);
static void utc_drmclient_drm_get_data_func_05(void);
static void utc_drmclient_drm_get_data_func_06(void);
static void utc_drmclient_drm_get_data_func_07(void);
static void utc_drmclient_drm_get_data_func_08(void);
static void utc_drmclient_drm_get_data_func_09(void);
static void utc_drmclient_drm_get_data_func_10(void);
static void utc_drmclient_drm_get_data_func_11(void);
static void utc_drmclient_drm_get_data_func_12(void);
static void utc_drmclient_drm_get_data_func_13(void);
static void utc_drmclient_drm_get_data_func_14(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{ utc_drmclient_drm_get_data_func_01, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_data_func_02, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_get_data_func_03, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_get_data_func_04, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_get_data_func_05, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_data_func_06, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_get_data_func_07, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_data_func_08, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_get_data_func_09, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_get_data_func_10, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_get_data_func_11, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_data_func_12, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_get_data_func_13, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_data_func_14, NEGATIVE_TC_IDX },
	{ NULL, 0 }
};

static void startup(void)
{
	tet_infoline("drm_get_data:Test started");
}

static void cleanup(void)
{
	tet_infoline("drm_get_data:Test completed");
}

/**
 * @brief Positive test case of drm_get_data()
 */
static void utc_drmclient_drm_get_data_func_01(void)
{
	drm_data_type_e data_type = DRM_DATA_TYPE_SECURE_CLOCK;
	drm_secure_clock_data_s secure_clock_info={0};
	int ret = DRM_RETURN_INTERNAL_ERROR;

	tet_printf ("Testing:DRM_DATA_TYPE_SECURE_CLOCK");
	ret = drm_get_data(data_type,NULL,(void*)&secure_clock_info);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret
			&& 1 == secure_clock_info.is_secure_clock_set){
		tet_printf("Secure Clock is SET:ret=0x%x",ret);
		tet_printf("Secure Time:"
				"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
				secure_clock_info.secure_clock.tm_year,
				secure_clock_info.secure_clock.tm_mon,
				secure_clock_info.secure_clock.tm_mday,
				secure_clock_info.secure_clock.tm_hour,
				secure_clock_info.secure_clock.tm_min,
				secure_clock_info.secure_clock.tm_sec);
		tet_result(TET_PASS);
	}else if(DRM_RETURN_SUCCESS == ret
			&& 0 == secure_clock_info.is_secure_clock_set){
		tet_printf("Secure Clock is NOT SET:ret=0x%x",ret);
		tet_result(TET_PASS);
	}else{
		tet_printf("Secure Clock Retrieval FAILED:ret=0x%x",ret);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_get_data()
 */
static void utc_drmclient_drm_get_data_func_02(void)
{
	drm_data_type_e data_type = DRM_DATA_TYPE_NONE;
	drm_secure_clock_data_s secure_clock_info={0};
	int ret = DRM_RETURN_INTERNAL_ERROR;

	tet_printf ("Testing:DRM_DATA_TYPE_SECURE_CLOCK");
	ret = drm_get_data(data_type,NULL,(void*)&secure_clock_info);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret
			&& 1 == secure_clock_info.is_secure_clock_set){
		tet_printf("Secure Clock is SET:ret=0x%x",ret);
		tet_printf("Secure Time:"
				"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
				secure_clock_info.secure_clock.tm_year,
				secure_clock_info.secure_clock.tm_mon,
				secure_clock_info.secure_clock.tm_mday,
				secure_clock_info.secure_clock.tm_hour,
				secure_clock_info.secure_clock.tm_min,
				secure_clock_info.secure_clock.tm_sec);
		tet_result(TET_FAIL);
	}else if(DRM_RETURN_SUCCESS == ret
			&& 0 == secure_clock_info.is_secure_clock_set){
		tet_printf("Secure Clock is NOT SET:ret=0x%x",ret);
		tet_result(TET_FAIL);
	}else{
		tet_printf("Passing Invalid data_type=%d",data_type);
		tet_result(TET_PASS);
	}
}

/**
 * @brief Negative test case of drm_get_data()
 */
static void utc_drmclient_drm_get_data_func_03(void)
{
	drm_data_type_e data_type = DRM_DATA_TYPE_SECURE_CLOCK;
	int ret = DRM_RETURN_INTERNAL_ERROR;

	tet_printf ("Testing:DRM_DATA_TYPE_SECURE_CLOCK");
	ret = drm_get_data(data_type,NULL,NULL);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Returned Success:ret=0x%x",ret);
		tet_result(TET_FAIL);
	}else{
		tet_printf("Passing Invalid output parameter");
		tet_result(TET_PASS);
	}
}

/**
 * @brief Negative test case of drm_get_data()
 */
static void utc_drmclient_drm_get_data_func_04(void)
{
	drm_data_type_e data_type=DRM_DATA_TYPE_NONE;
	int ret = DRM_RETURN_INTERNAL_ERROR;

	tet_printf ("Testing:DRM_DATA_TYPE_SECURE_CLOCK");
	ret = drm_get_data(data_type,NULL,NULL);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Returned Success:ret=0x%x data_type=%d",ret,data_type);
		tet_result(TET_FAIL);
	}else{
		tet_printf("Passing Invalid data_type=%d",data_type);
		tet_result(TET_PASS);
	}
}

/**
 * @brief Positive test case of drm_get_data()
 */
static void utc_drmclient_drm_get_data_func_05(void)
{
	drm_data_type_e data_type = DRM_DATA_TYPE_TRANSACTION_TRACKING_FLAG;
	int ret = DRM_RETURN_INTERNAL_ERROR;
	int transtrk_flag = 0;

	tet_printf ("Testing:DRM_DATA_TYPE_TRANSACTION_TRACKING_FLAG");
	ret = drm_get_data(data_type, NULL, (void*)&transtrk_flag);
	tet_printf("ret=0x%x", ret);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("transtrk_flag = %d", transtrk_flag);
		tet_result(TET_PASS);
	} else {
		tet_printf("Get Transaction Tracking Flag failed!!, "
				"ret = 0x%x", ret);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_get_data()
 */
static void utc_drmclient_drm_get_data_func_06(void)
{
	drm_data_type_e data_type = DRM_DATA_TYPE_TRANSACTION_TRACKING_FLAG;
	int ret = DRM_RETURN_INTERNAL_ERROR;

	tet_printf ("Testing:DRM_DATA_TYPE_TRANSACTION_TRACKING_FLAG");
	ret = drm_get_data(data_type, NULL,NULL);
	tet_printf("ret=0x%x", ret);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("Returned Success");
		tet_result(TET_FAIL);
	} else {
		tet_printf("Invalid output:ret = 0x%x", ret);
		tet_result(TET_PASS);
	}
}

/**
 * @brief Positive test case of drm_get_data()
 */
static void utc_drmclient_drm_get_data_func_07(void)
{
	drm_data_type_e data_type = DRM_DATA_TYPE_TRANSACTION_TRACKING_ID;
	int ret = DRM_RETURN_INTERNAL_ERROR;

	tet_printf("Testing:DRM_DATA_TYPE_TRANSACTION_TRACKING_ID");
	drm_transaction_id_info_s transaction_id_info;
	memset(&transaction_id_info,0x0,sizeof(drm_transaction_id_info_s));

	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_3);

	ret = drm_get_data(data_type,(void*)file_path,(void*)&transaction_id_info);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Transaction ID Length =%d file_path=%s",
				transaction_id_info.tr_id_len,file_path);
		if(0 != transaction_id_info.tr_id_len){
			tet_printf("Transaction ID  =%s",
					transaction_id_info.tr_id);
		}
		tet_result(TET_PASS);
	}else{
		tet_printf("Transaction ID Retrieval FAILED:ret=0x%x file_path=%s",
				ret,file_path);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_get_data()
 */
static void utc_drmclient_drm_get_data_func_08(void)
{
	drm_data_type_e data_type = DRM_DATA_TYPE_TRANSACTION_TRACKING_ID;
	int ret = DRM_RETURN_INTERNAL_ERROR;

	tet_printf("Testing:DRM_DATA_TYPE_TRANSACTION_TRACKING_ID");
	drm_transaction_id_info_s transaction_id_info;
	memset(&transaction_id_info,0x0,sizeof(drm_transaction_id_info_s));

	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_INVALID_FILE_EMPTY);

	ret = drm_get_data(data_type,(void*)file_path,(void*)&transaction_id_info);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Transaction ID Length =%d file_path=%s",
				transaction_id_info.tr_id_len,file_path);
		if(0 != transaction_id_info.tr_id_len){
			tet_printf("Transaction ID  =%s",
					transaction_id_info.tr_id);
		}
		tet_result(TET_FAIL);
	}else{
		tet_printf("Invalid Input:ret=0x%x file_path=%s",
				ret,file_path);
		tet_result(TET_PASS);
	}
}

/**
 * @brief Negative test case of drm_get_data()
 */
static void utc_drmclient_drm_get_data_func_09(void)
{
	drm_data_type_e data_type = DRM_DATA_TYPE_TRANSACTION_TRACKING_ID;
	int ret = DRM_RETURN_INTERNAL_ERROR;

	tet_printf("Testing:DRM_DATA_TYPE_TRANSACTION_TRACKING_ID");

	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_3);

	ret = drm_get_data(data_type,(void*)file_path,NULL);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Returned Success:ret=0x%x",ret);
		tet_result(TET_FAIL);
	}else{
		tet_printf("Invalid Output:ret=0x%x file_path=%s",
				ret,file_path);
		tet_result(TET_PASS);
	}
}

/**
 * @brief Negative test case of drm_get_data()
 */
static void utc_drmclient_drm_get_data_func_10(void)
{
	drm_data_type_e data_type = DRM_DATA_TYPE_TRANSACTION_TRACKING_ID;
	int ret = DRM_RETURN_INTERNAL_ERROR;

	tet_printf("Testing:DRM_DATA_TYPE_TRANSACTION_TRACKING_ID");
	drm_transaction_id_info_s transaction_id_info;
	memset(&transaction_id_info,0x0,sizeof(drm_transaction_id_info_s));

	ret = drm_get_data(data_type,NULL,(void*)&transaction_id_info);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Returned Success:ret=0x%x",ret);
		tet_result(TET_FAIL);
	}else{
		tet_printf("Invalid Input:ret=0x%x",ret);
		tet_result(TET_PASS);
	}
}

/**
 * @brief Positive test case of drm_get_data()
 */
static void utc_drmclient_drm_get_data_func_11(void)
{
	drm_data_type_e data_type = DRM_DATA_TYPE_DIVX_REGISTRATION_CODE;
	int ret = DRM_RETURN_INTERNAL_ERROR;

	tet_printf("Testing:DRM_DATA_TYPE_DIVX_REGISTRATION_CODE");

	drm_code_info_s reg_code_info;
	memset(&reg_code_info,0x0,sizeof(drm_code_info_s));

	ret = drm_get_data(data_type, NULL, (void*) &reg_code_info);
	tet_printf("ret=0x%x", ret);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("Code Length = %d", reg_code_info.code_len);
		if (0 != reg_code_info.code_len) {
			tet_printf("Code = %s", reg_code_info.code);
		}
		tet_result(TET_PASS);
	} else {
		tet_printf("Divx Registration Code Retrieval failed!!");
		tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_get_data()
 */
static void utc_drmclient_drm_get_data_func_12(void)
{
	drm_data_type_e data_type = DRM_DATA_TYPE_DIVX_REGISTRATION_CODE;
	int ret = DRM_RETURN_INTERNAL_ERROR;

	tet_printf("Testing:DRM_DATA_TYPE_DIVX_REGISTRATION_CODE");

	ret = drm_get_data(data_type, NULL,NULL);
	tet_printf("ret=0x%x", ret);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("Success:ret=0x%x", ret);
		tet_result(TET_FAIL);
	} else {
		tet_printf("Invalid output:ret=0x%x", ret);
		tet_result(TET_PASS);
	}
}

/**
 * @brief Positive test case of drm_get_data()
 */
static void utc_drmclient_drm_get_data_func_13(void)
{
	drm_data_type_e data_type = DRM_DATA_TYPE_DIVX_DEREGISTRATION_CODE;
	int ret = DRM_RETURN_INTERNAL_ERROR;

	tet_printf("Testing:DRM_DATA_TYPE_DIVX_DEREGISTRATION_CODE");

	drm_code_info_s dereg_code_info;
	memset(&dereg_code_info,0x0,sizeof(drm_code_info_s));
	ret = drm_get_data(data_type, NULL, (void*) &dereg_code_info);
	tet_printf("ret=0x%x", ret);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("Code Length = %d", dereg_code_info.code_len);
		if (0 != dereg_code_info.code_len) {
			tet_printf("Code = %s", dereg_code_info.code);
		}
		tet_result(TET_PASS);
	} else {
		tet_printf("Divx Deregistration Code Retrieval failed!!");
		tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_get_data()
 */
static void utc_drmclient_drm_get_data_func_14(void)
{
	drm_data_type_e data_type = DRM_DATA_TYPE_DIVX_DEREGISTRATION_CODE;
	int ret = DRM_RETURN_INTERNAL_ERROR;

	tet_printf("Testing:DRM_DATA_TYPE_DIVX_DEREGISTRATION_CODE");

	ret = drm_get_data(data_type, NULL,NULL);
	tet_printf("ret=0x%x", ret);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("Success:ret=0x%x", ret);
		tet_result(TET_FAIL);
	} else {
		tet_printf("Invalid output:ret=0x%x", ret);
		tet_result(TET_PASS);
	}
}
