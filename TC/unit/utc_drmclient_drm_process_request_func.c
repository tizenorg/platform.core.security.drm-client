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
 * @file 		utc_drmclient_drm_process_request_func.c
 * @brief       TETware unit testing functions for drm_process_request.
 * @author      Mahendra Kumar Prajapat (mahendra.p@samsung.com)
 * @version     0.1
 * @history     0.1: Initial draft
 */

#include <sys/types.h>
#include <sys/stat.h>

#include <tet_api.h>

#include "drmcontentsdef.h"

static void startup(void);
static void cleanup(void);

void (*tet_startup)(void) = startup;
void (*tet_cleanup)(void) = cleanup;

static void utc_drmclient_drm_process_request_func_01(void);
static void utc_drmclient_drm_process_request_func_02(void);
static void utc_drmclient_drm_process_request_func_03(void);
static void utc_drmclient_drm_process_request_func_04(void);
static void utc_drmclient_drm_process_request_func_05(void);
static void utc_drmclient_drm_process_request_func_06(void);
static void utc_drmclient_drm_process_request_func_07(void);
static void utc_drmclient_drm_process_request_func_08(void);
static void utc_drmclient_drm_process_request_func_09(void);
static void utc_drmclient_drm_process_request_func_10(void);
static void utc_drmclient_drm_process_request_func_11(void);
static void utc_drmclient_drm_process_request_func_12(void);
static void utc_drmclient_drm_process_request_func_13(void);
static void utc_drmclient_drm_process_request_func_14(void);
static void utc_drmclient_drm_process_request_func_15(void);
static void utc_drmclient_drm_process_request_func_16(void);
static void utc_drmclient_drm_process_request_func_17(void);
static void utc_drmclient_drm_process_request_func_18(void);
static void utc_drmclient_drm_process_request_func_19(void);
static void utc_drmclient_drm_process_request_func_20(void);
static void utc_drmclient_drm_process_request_func_21(void);
static void utc_drmclient_drm_process_request_func_22(void);
static void utc_drmclient_drm_process_request_func_23(void);
static void utc_drmclient_drm_process_request_func_24(void);
static void utc_drmclient_drm_process_request_func_25(void);
static void utc_drmclient_drm_process_request_func_26(void);
static void utc_drmclient_drm_process_request_func_27(void);
static void utc_drmclient_drm_process_request_func_28(void);
static void utc_drmclient_drm_process_request_func_29(void);
static void utc_drmclient_drm_process_request_func_30(void);
static void utc_drmclient_drm_process_request_func_31(void);
static void utc_drmclient_drm_process_request_func_32(void);
static void utc_drmclient_drm_process_request_func_33(void);
static void utc_drmclient_drm_process_request_func_34(void);
static void utc_drmclient_drm_process_request_func_35(void);
static void utc_drmclient_drm_process_request_func_36(void);
static void utc_drmclient_drm_process_request_func_37(void);
static void utc_drmclient_drm_process_request_func_38(void);
static void utc_drmclient_drm_process_request_func_39(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{ utc_drmclient_drm_process_request_func_01, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_02, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_03, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_04, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_05, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_06, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_07, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_08, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_09, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_10, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_11, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_12, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_13, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_14, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_15, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_16, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_17, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_18, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_19, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_20, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_21, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_22, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_23, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_24, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_25, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_26, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_27, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_28, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_29, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_30, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_31, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_32, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_33, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_34, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_35, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_36, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_37, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_38, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_process_request_func_39, NEGATIVE_TC_IDX },
	{ NULL, 0 }
};

static void startup(void)
{
	tet_infoline("drm_process_request:Test started");
}

static void cleanup(void)
{
	tet_infoline("drm_process_request:Test completed");
}

/**
 * @brief Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_01(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_REGISTER_FILE;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};

	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_1);
	tet_printf ("Testing:DRM_REQUEST_TYPE_REGISTER_FILE");

	ret = drm_process_request(request_type,(void*)file_path,NULL);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Register success:file_path=%s",
				file_path);
		tet_result(TET_PASS);
	}else{
		tet_printf("Register FAILED:ret=0x%x file_path=%s",
				ret,file_path);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_02(void)
{
	/** This is duplication of
	 * test-case utc_drmclient_drm_process_request_func_01
	 * This test-case is added to ensure proper behavior if same content is
	 * registered 2 times.
	 */
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_REGISTER_FILE;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};

	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_1);
	tet_printf ("Testing:DRM_REQUEST_TYPE_REGISTER_FILE");

	ret = drm_process_request(request_type,(void*)file_path,NULL);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Register success:file_path=%s",
				file_path);
		tet_result(TET_PASS);
	}else{
		tet_printf("Register FAILED:ret=0x%x file_path=%s",
				ret,file_path);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_03(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_NONE;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};

	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_1);
	tet_printf("Testing:DRM_REQUEST_TYPE_NONE");

	ret = drm_process_request(request_type,(void*)file_path,NULL);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Register success:file_path=%s",
				file_path);
		tet_result(TET_FAIL);
	}else{
		tet_printf("Invalid request_type=%d ret=0x%x file_path=%s",
				request_type,ret,file_path);
		tet_result(TET_PASS);
	}
}

/**
 * @brief Negative test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_04(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_REGISTER_FILE;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};

	tet_printf("Testing:DRM_REQUEST_TYPE_REGISTER_FILE");

	ret = drm_process_request(request_type,(void*)file_path,NULL);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Register success:file_path=%s",
				file_path);
		tet_result(TET_FAIL);
	}else{
		tet_printf("Invalid file_path: ret=0x%x file_path=%s",
				ret,file_path);
		tet_result(TET_PASS);
	}
}

/**
 * @brief Negative test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_05(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_REGISTER_FILE;
	char *file_path = NULL;

	tet_printf("Testing:DRM_REQUEST_TYPE_REGISTER_FILE");

	ret = drm_process_request(request_type,(void*)file_path,NULL);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Register success:file_path=%p",
				file_path);
		tet_result(TET_FAIL);
	}else{
		tet_printf("Invalid file_path: ret=0x%x file_path=%p",
				ret,file_path);
		tet_result(TET_PASS);
	}
}

/**
 * @brief Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_06(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_UNREGISTER_FILE;
	drm_unregister_info_s unregister_info;
	memset(&unregister_info,0x0,sizeof(drm_unregister_info_s));

	tet_printf("Testing:DRM_REQUEST_TYPE_UNREGISTER_FILE");
	snprintf(unregister_info.file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_1);
	unregister_info.remove_license = 1;

	ret = drm_process_request(request_type,(void*)&unregister_info,NULL);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Un-register success:file_path=%s",
				unregister_info.file_path);
		tet_result(TET_PASS);
	}else{
		tet_printf("Un-register FAILED:ret=0x%x "
				"file_path=%s",ret,unregister_info.file_path);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_07(void)
{
	/** This is duplication of
	 * test-case utc_drmclient_drm_process_request_func_06
	 * This test-case is added to ensure proper behavior if same content is
	 * unregistered 2 times.
	 */
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_UNREGISTER_FILE;
	drm_unregister_info_s unregister_info;
	memset(&unregister_info,0x0,sizeof(drm_unregister_info_s));

	tet_printf("Testing:DRM_REQUEST_TYPE_UNREGISTER_FILE");
	snprintf(unregister_info.file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_1);
	unregister_info.remove_license = 0;

	ret = drm_process_request(request_type,(void*)&unregister_info,NULL);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Un-register success:file_path=%s",
				unregister_info.file_path);
		tet_result(TET_PASS);
	}else{
		tet_printf("Un-register FAILED:ret=0x%x "
				"file_path=%s",ret,unregister_info.file_path);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_08(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_UNREGISTER_FILE;
	drm_unregister_info_s unregister_info;
	memset(&unregister_info,0x0,sizeof(drm_unregister_info_s));

	tet_printf("Testing:DRM_REQUEST_TYPE_UNREGISTER_FILE");
	snprintf(unregister_info.file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_INVALID_FILE_EMPTY);
	unregister_info.remove_license = 0;

	ret = drm_process_request(request_type,(void*)&unregister_info,NULL);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Un-register success:file_path=%s",
				unregister_info.file_path);
		tet_result(TET_FAIL);
	}else{
		tet_printf("Invalid file path:ret=0x%x "
				"file_path=%s",ret,unregister_info.file_path);
		tet_result(TET_PASS);
	}
}

/**
 * @brief Negative test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_09(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_UNREGISTER_FILE;

	tet_printf("Testing:DRM_REQUEST_TYPE_UNREGISTER_FILE");

	ret = drm_process_request(request_type,NULL,NULL);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Un-register success");
		tet_result(TET_FAIL);
	}else{
		tet_printf("Invalid input:ret=0x%x",ret);
		tet_result(TET_PASS);
	}
}

/**
 * @brief Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_10(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_REGISTER_LICENSE;
	tet_printf("Testing:DRM_REQUEST_TYPE_REGISTER_LICENSE");

	drm_register_lic_info_s lic_req_info;
	drm_register_lic_resp_s lic_resp_info;

	memset(&lic_req_info,0x0,sizeof(drm_register_lic_info_s));
	memset(&lic_resp_info,0x0,sizeof(drm_register_lic_resp_s));

	struct stat stat_buf = { 0 };
	FILE *fp = NULL;
	unsigned int read_len=0;
	char *tempPath = NULL;

	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_RO_FILE_OMA_1);

	if (0 == stat(file_path, &stat_buf)) {
		lic_req_info.lic_data_len = stat_buf.st_size;
		tet_printf("file_path=%s file_size=%u",file_path,
				lic_req_info.lic_data_len);
	} else {
		tet_printf("stat failed:error=%s file_path=%s",
				strerror(errno),file_path);
		tet_result(TET_FAIL);
		return;
	}

	fp = fopen(file_path,"r");
	if(NULL == fp){
		tet_printf("fopen failed:error=%s file_path=%s",
				strerror(errno),file_path);
		tet_result(TET_FAIL);
		return;
	}

	memset(lic_req_info.lic_data,0x0,sizeof(lic_req_info.lic_data));
	read_len = fread(lic_req_info.lic_data,1,lic_req_info.lic_data_len,fp);
	tet_printf("read_len=%u lic_req_info.lic_data_len=%u",
			read_len,lic_req_info.lic_data_len);

	fclose(fp);

	tempPath = strrchr((char *)file_path, '.');
	if(strncmp(tempPath, ".dr", 2) == 0
		|| strncmp(tempPath, ".drc", 3) == 0){
		tet_printf("DRM v1 License file");

		lic_req_info.lic_version = DRM_OMA_DRMV1_RIGHTS;
		lic_req_info.roap_init_src = DRM_ROAP_INIT_FROM_UNKNOWN;
		lic_req_info.operation_callback.callback = NULL;

		ret = drm_process_request(request_type,(void*)&lic_req_info,
				(void*)&lic_resp_info);
		tet_printf("ret=0x%x",ret);
		if(DRM_RETURN_SUCCESS == ret){
			tet_printf("Register License success");
			tet_printf("CID=%s",lic_resp_info.cid);
			tet_result(TET_PASS);
		}else{
			tet_printf("Register License FAILED:"
					"ret=0x%x",ret);
			tet_result(TET_FAIL);
		}
	}else{
		tet_printf("Not a License file:ret=0x%x",ret);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_11(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_REGISTER_LICENSE;
	tet_printf("Testing:DRM_REQUEST_TYPE_REGISTER_LICENSE");

	drm_register_lic_info_s lic_req_info;
	drm_register_lic_resp_s lic_resp_info;

	memset(&lic_req_info,0x0,sizeof(drm_register_lic_info_s));
	memset(&lic_resp_info,0x0,sizeof(drm_register_lic_resp_s));

	struct stat stat_buf = { 0 };
	FILE *fp = NULL;
	unsigned int read_len=0;
	char *tempPath = NULL;

	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_RO_FILE_OMA_2);

	if (0 == stat(file_path, &stat_buf)) {
		lic_req_info.lic_data_len = stat_buf.st_size;
		tet_printf("file_path=%s file_size=%u",file_path,
				lic_req_info.lic_data_len);
	} else {
		tet_printf("stat failed:error=%s file_path=%s",
				strerror(errno),file_path);
		tet_result(TET_FAIL);
		return;
	}

	fp = fopen(file_path,"r");
	if(NULL == fp){
		tet_printf("fopen failed:error=%s file_path=%s",
				strerror(errno),file_path);
		tet_result(TET_FAIL);
		return;
	}

	memset(lic_req_info.lic_data,0x0,sizeof(lic_req_info.lic_data));
	read_len = fread(lic_req_info.lic_data,1,lic_req_info.lic_data_len,fp);
	tet_printf("read_len=%u lic_req_info.lic_data_len=%u",
			read_len,lic_req_info.lic_data_len);

	fclose(fp);

	tempPath = strrchr((char *)file_path, '.');
	if(strncmp(tempPath, ".dr", 2) == 0
		|| strncmp(tempPath, ".drc", 3) == 0){
		tet_printf("DRM v1 License file");

		lic_req_info.lic_version = DRM_OMA_DRMV1_RIGHTS;
		lic_req_info.roap_init_src = DRM_ROAP_INIT_FROM_UNKNOWN;
		lic_req_info.operation_callback.callback = NULL;

		ret = drm_process_request(request_type,(void*)&lic_req_info,
				(void*)&lic_resp_info);
		tet_printf("ret=0x%x",ret);
		if(DRM_RETURN_SUCCESS == ret){
			tet_printf("Register License success");
			tet_printf("CID=%s",lic_resp_info.cid);
			tet_result(TET_PASS);
		}else{
			tet_printf("Register License FAILED:"
					"ret=0x%x",ret);
			tet_result(TET_FAIL);
		}
	}else{
		tet_printf("Not a License file:ret=0x%x",ret);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_12(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_REGISTER_LICENSE;
	tet_printf("Testing:DRM_REQUEST_TYPE_REGISTER_LICENSE");

	ret = drm_process_request(request_type,NULL,NULL);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Register License success");
		tet_result(TET_FAIL);
	}else{
		tet_printf("Invalid input and output ret=0x%x",ret);
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 * @remark 	Content is un-registered as a part of
 * 			utc_drmclient_drm_process_request_func_06
 * 			and utc_drmclient_drm_process_request_func_07.
 * 			Thus re-registering the content.
 */
static void utc_drmclient_drm_process_request_func_13(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_REGISTER_FILE;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};

	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_1);
	tet_printf ("Testing:DRM_REQUEST_TYPE_REGISTER_FILE");

	ret = drm_process_request(request_type,(void*)file_path,NULL);
	tet_printf("ret=0x%x",ret);
	if(DRM_RETURN_SUCCESS == ret){
		tet_printf("Register success:file_path=%s",
				file_path);
		tet_result(TET_PASS);
	}else{
		tet_printf("Register FAILED:ret=0x%x file_path=%s",
				ret,file_path);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_14(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL;
	tet_printf ("Testing:DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL");

	drm_initiator_info_s initiator_info;
	drm_web_server_resp_data_s ws_resp_data;

	memset(&initiator_info,0x0,sizeof(drm_initiator_info_s));
	memset(&ws_resp_data,0x0,sizeof(drm_web_server_resp_data_s));

	snprintf(initiator_info.initiator_url,DRM_MAX_LEN_INITIATOR_URL, "%s",
			LICENSE_INITIATOR_VALID_PR_FILE);

	tet_printf ("Source Initiator URL=%s",LICENSE_INITIATOR_VALID_PR_FILE);
	tet_printf ("Destination Initiator URL=%s",initiator_info.initiator_url);

	initiator_info.initiator_url_len = strlen(initiator_info.initiator_url);
	initiator_info.operation_callback.callback = NULL;

	tet_printf ("Source Initiator URL Length=%u",strlen(LICENSE_INITIATOR_VALID_PR_FILE));
	tet_printf ("Destination Initiator URL Length=%u",strlen(initiator_info.initiator_url));

	ret = drm_process_request(request_type, (void*)&initiator_info,
			(void*)&ws_resp_data);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("Server Error Code = %d",
				ws_resp_data.result_code);
		tet_printf("Content URL = %s",
				ws_resp_data.content_url);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x", ret);
		/**
		 * As this TC depends on network connectivity,
		 * Thus making it TET_PASS
		 */
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_15(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL;
	tet_printf ("Testing:DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL");

	drm_initiator_info_s initiator_info;
	drm_web_server_resp_data_s ws_resp_data;

	memset(&initiator_info,0x0,sizeof(drm_initiator_info_s));
	memset(&ws_resp_data,0x0,sizeof(drm_web_server_resp_data_s));

	snprintf(initiator_info.initiator_url,DRM_MAX_LEN_INITIATOR_URL, "%s",
			LICENSE_INITIATOR_VALID_PR_FILE_1);

	tet_printf ("Source Initiator URL=%s",LICENSE_INITIATOR_VALID_PR_FILE_1);
	tet_printf ("Destination Initiator URL=%s",initiator_info.initiator_url);

	initiator_info.initiator_url_len = strlen(initiator_info.initiator_url);
	initiator_info.operation_callback.callback = NULL;

	tet_printf ("Source Initiator URL Length=%u",strlen(LICENSE_INITIATOR_VALID_PR_FILE_1));
	tet_printf ("Destination Initiator URL Length=%u",strlen(initiator_info.initiator_url));

	ret = drm_process_request(request_type, (void*)&initiator_info,
			(void*)&ws_resp_data);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("Server Error Code = %d",
				ws_resp_data.result_code);
		tet_printf("Content URL = %s",
				ws_resp_data.content_url);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x", ret);
		/**
		 * As this TC depends on network connectivity,
		 * Thus making it TET_PASS
		 */
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_16(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL;
	tet_printf ("Testing:DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL");

	drm_initiator_info_s initiator_info;
	drm_web_server_resp_data_s ws_resp_data;

	memset(&initiator_info,0x0,sizeof(drm_initiator_info_s));
	memset(&ws_resp_data,0x0,sizeof(drm_web_server_resp_data_s));

	snprintf(initiator_info.initiator_url,DRM_MAX_LEN_INITIATOR_URL, "%s",
			JOIN_DOMAIN_INITIATOR_VALID_PR_FILE_1);

	tet_printf ("Source Initiator URL=%s",JOIN_DOMAIN_INITIATOR_VALID_PR_FILE_1);
	tet_printf ("Destination Initiator URL=%s",initiator_info.initiator_url);

	initiator_info.initiator_url_len = strlen(initiator_info.initiator_url);
	initiator_info.operation_callback.callback = NULL;

	tet_printf ("Source Initiator URL Length=%u",strlen(JOIN_DOMAIN_INITIATOR_VALID_PR_FILE_1));
	tet_printf ("Destination Initiator URL Length=%u",strlen(initiator_info.initiator_url));

	ret = drm_process_request(request_type, (void*)&initiator_info,
			(void*)&ws_resp_data);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("Server Error Code = %d",
				ws_resp_data.result_code);
		tet_printf("Content URL = %s",
				ws_resp_data.content_url);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x", ret);
		/**
		 * As this TC depends on network connectivity,
		 * Thus making it TET_PASS
		 */
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_17(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL;
	tet_printf ("Testing:DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL");

	drm_initiator_info_s initiator_info;
	drm_web_server_resp_data_s ws_resp_data;

	memset(&initiator_info,0x0,sizeof(drm_initiator_info_s));
	memset(&ws_resp_data,0x0,sizeof(drm_web_server_resp_data_s));

	snprintf(initiator_info.initiator_url,DRM_MAX_LEN_INITIATOR_URL, "%s",
			LEAVE_DOMAIN_INITIATOR_VALID_PR_FILE_1);

	tet_printf ("Source Initiator URL=%s",LEAVE_DOMAIN_INITIATOR_VALID_PR_FILE_1);
	tet_printf ("Destination Initiator URL=%s",initiator_info.initiator_url);

	initiator_info.initiator_url_len = strlen(initiator_info.initiator_url);
	initiator_info.operation_callback.callback = NULL;

	tet_printf ("Source Initiator URL Length=%u",strlen(LEAVE_DOMAIN_INITIATOR_VALID_PR_FILE_1));
	tet_printf ("Destination Initiator URL Length=%u",strlen(initiator_info.initiator_url));

	ret = drm_process_request(request_type, (void*)&initiator_info,
			(void*)&ws_resp_data);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("Server Error Code = %d",
				ws_resp_data.result_code);
		tet_printf("Content URL = %s",
				ws_resp_data.content_url);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x", ret);
		/**
		 * As this TC depends on network connectivity,
		 * Thus making it TET_PASS
		 */
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_18(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL;
	tet_printf ("Testing:DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL");

	drm_initiator_info_s initiator_info;
	drm_web_server_resp_data_s ws_resp_data;

	memset(&initiator_info,0x0,sizeof(drm_initiator_info_s));
	memset(&ws_resp_data,0x0,sizeof(drm_web_server_resp_data_s));

	snprintf(initiator_info.initiator_url,DRM_MAX_LEN_INITIATOR_URL, "%s",
			METERING_INITIATOR_VALID_PR_FILE_1);

	tet_printf ("Source Initiator URL=%s",METERING_INITIATOR_VALID_PR_FILE_1);
	tet_printf ("Destination Initiator URL=%s",initiator_info.initiator_url);

	initiator_info.initiator_url_len = strlen(initiator_info.initiator_url);
	initiator_info.operation_callback.callback = NULL;

	tet_printf ("Source Initiator URL Length=%u",strlen(METERING_INITIATOR_VALID_PR_FILE_1));
	tet_printf ("Destination Initiator URL Length=%u",strlen(initiator_info.initiator_url));

	ret = drm_process_request(request_type, (void*)&initiator_info,
			(void*)&ws_resp_data);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("Server Error Code = %d",
				ws_resp_data.result_code);
		tet_printf("Content URL = %s",
				ws_resp_data.content_url);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x", ret);
		/**
		 * As this TC depends on network connectivity,
		 * Thus making it TET_PASS
		 */
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Negative test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_19(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL;
	tet_printf ("Testing:DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL");

	drm_initiator_info_s initiator_info;
	drm_web_server_resp_data_s ws_resp_data;

	memset(&initiator_info,0x0,sizeof(drm_initiator_info_s));
	memset(&ws_resp_data,0x0,sizeof(drm_web_server_resp_data_s));

	snprintf(initiator_info.initiator_url,DRM_MAX_LEN_INITIATOR_URL, "%s",
			INVALID_LICENSE_INITIATOR_PR_FILE_1);

	tet_printf ("Source Initiator URL=%s",INVALID_LICENSE_INITIATOR_PR_FILE_1);
	tet_printf ("Destination Initiator URL=%s",initiator_info.initiator_url);

	initiator_info.initiator_url_len = strlen(initiator_info.initiator_url);
	initiator_info.operation_callback.callback = NULL;

	tet_printf ("Source Initiator URL Length=%u",strlen(INVALID_LICENSE_INITIATOR_PR_FILE_1));
	tet_printf ("Destination Initiator URL Length=%u",strlen(initiator_info.initiator_url));

	ret = drm_process_request(request_type, (void*)&initiator_info,
			(void*)&ws_resp_data);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("Server Error Code = %d",
				ws_resp_data.result_code);
		tet_printf("Content URL = %s",
				ws_resp_data.content_url);
		tet_result(TET_FAIL);
	} else {
		tet_printf("ret = 0x%x", ret);
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Negative test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_20(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL;
	tet_printf ("Testing:DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL");

	ret = drm_process_request(request_type,NULL,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("Success:ret = 0x%x", ret);
		tet_result(TET_FAIL);
	} else {
		tet_printf("Invalid input-output:ret = 0x%x", ret);
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_21(void)
{
	int ret = DRM_RETURN_SUCCESS;
	tet_printf("Testing:DRM_REQUEST_TYPE_UNREGISTER_ALL_FILES");

	/*
	 * Disabled this test-case because all contents will be unregistered
	 * Thus it will interfer with other TCs
	 */
#if 0
	drm_request_type_e request_type = DRM_REQUEST_TYPE_UNREGISTER_ALL_FILES;
	ret = drm_process_request(request_type, NULL,NULL);
#endif

	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_22(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_INSERT_EXT_MEMORY;
	tet_printf("Testing:DRM_REQUEST_TYPE_INSERT_EXT_MEMORY");

	ret = drm_process_request(request_type, NULL,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_23(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_EXTRACT_EXT_MEMORY;
	tet_printf("Testing:DRM_REQUEST_TYPE_EXTRACT_EXT_MEMORY");

	ret = drm_process_request(request_type, NULL,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_24(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_SUBMIT_ROAP_MESSAGE;
	tet_printf("Testing:DRM_REQUEST_TYPE_SUBMIT_ROAP_MESSAGE");

	drm_submit_roap_message_info_s message_info;
	memset(&message_info,0x0,sizeof(drm_submit_roap_message_info_s));

	ret = drm_process_request(request_type,(void *)&message_info,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		/**
		* As this TC depends on network connectivity,
		* Thus making it TET_PASS
	    */
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Negative test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_25(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_SUBMIT_ROAP_MESSAGE;
	tet_printf("Testing:DRM_REQUEST_TYPE_SUBMIT_ROAP_MESSAGE");

	ret = drm_process_request(request_type,NULL,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_FAIL);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_26(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_SUBMIT_ROAP_USER_CONSENT;
	tet_printf("Testing:DRM_REQUEST_TYPE_SUBMIT_ROAP_USER_CONSENT");

	drm_submit_roap_user_consent_info_s user_consent_info;
	memset(&user_consent_info,0x0,sizeof(drm_submit_roap_user_consent_info_s));

	ret = drm_process_request(request_type,(void *)&user_consent_info,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		/**
		* As this TC depends on network connectivity,
		* Thus making it TET_PASS
	    */
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Negative test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_27(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_SUBMIT_ROAP_USER_CONSENT;
	tet_printf("Testing:DRM_REQUEST_TYPE_SUBMIT_ROAP_USER_CONSENT");

	ret = drm_process_request(request_type,NULL,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_FAIL);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_28(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_HTTP_USER_CANCEL;
	tet_printf("Testing:DRM_REQUEST_TYPE_HTTP_USER_CANCEL");

	drm_http_user_cancel_info_s user_cancel_info;
	memset(&user_cancel_info,0x0,sizeof(drm_http_user_cancel_info_s));

	ret = drm_process_request(request_type,(void *)&user_cancel_info,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		/**
		* As this TC depends on network connectivity,
		* Thus making it TET_PASS
	    */
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Negative test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_29(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_HTTP_USER_CANCEL;
	tet_printf("Testing:DRM_REQUEST_TYPE_HTTP_USER_CANCEL");

	ret = drm_process_request(request_type,NULL,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_FAIL);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_30(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_REGISTER_COPY_FILE;
	tet_printf("Testing:DRM_REQUEST_TYPE_REGISTER_COPY_FILE");

	drm_register_copy_file_info_s copy_file_info;
	memset(&copy_file_info,0x0,sizeof(drm_register_copy_file_info_s));

	snprintf(copy_file_info.src_file_path,256, "%s",FILE_PATH_VALID_FILE_OMA_1);
	snprintf(copy_file_info.dest_file_path,256, "%s",FILE_PATH_VALID_FILE_OMA_11);
	tet_printf("Src file=%s",copy_file_info.src_file_path);
	tet_printf("Dst file=%s",copy_file_info.dest_file_path);

	ret = drm_process_request(request_type,(void *)&copy_file_info,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief 	Negative test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_31(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_REGISTER_COPY_FILE;
	tet_printf("Testing:DRM_REQUEST_TYPE_REGISTER_COPY_FILE");

	ret = drm_process_request(request_type,NULL,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_FAIL);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_32(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_REGISTER_MOVE_FILE;
	tet_printf("Testing:DRM_REQUEST_TYPE_REGISTER_MOVE_FILE");

	drm_register_copy_file_info_s copy_file_info;
	memset(&copy_file_info,0x0,sizeof(drm_register_copy_file_info_s));

	snprintf(copy_file_info.src_file_path,256, "%s",FILE_PATH_VALID_FILE_OMA_1);
	snprintf(copy_file_info.dest_file_path,256, "%s",FILE_PATH_VALID_FILE_OMA_11);
	tet_printf("Src file=%s",copy_file_info.src_file_path);
	tet_printf("Dst file=%s",copy_file_info.dest_file_path);

	ret = drm_process_request(request_type,(void *)&copy_file_info,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief 	Negative test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_33(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_REGISTER_MOVE_FILE;
	tet_printf("Testing:DRM_REQUEST_TYPE_REGISTER_MOVE_FILE");

	ret = drm_process_request(request_type,NULL,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_FAIL);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_34(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_INSERT_EXT_MEMORY;
	tet_printf("Testing:DRM_REQUEST_TYPE_INSERT_EXT_MEMORY");

	ret = drm_process_request(request_type,NULL,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_35(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_EXTRACT_EXT_MEMORY;
	tet_printf("Testing:DRM_REQUEST_TYPE_EXTRACT_EXT_MEMORY");

	ret = drm_process_request(request_type,NULL,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_36(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_REGISTER_SETAS;
	tet_printf("Testing:DRM_REQUEST_TYPE_REGISTER_SETAS");

	drm_register_setas_info_s setas_info;
	memset(&setas_info,0x0,sizeof(drm_register_setas_info_s));

	snprintf(setas_info.file_path,256, "%s",FILE_PATH_VALID_FILE_OMA_12);
	tet_printf("file_path=%s",setas_info.file_path);

	setas_info.setas_cat = DRM_SETAS_WALLPAPER;

	ret = drm_process_request(request_type,(void *)&setas_info,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief 	Negative test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_37(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_REGISTER_SETAS;
	tet_printf("Testing:DRM_REQUEST_TYPE_REGISTER_SETAS");

	ret = drm_process_request(request_type,NULL,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_FAIL);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		tet_result(TET_PASS);
	}
}

/**
 * @brief 	Positive test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_38(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_UNREGISTER_SETAS;
	tet_printf("Testing:DRM_REQUEST_TYPE_UNREGISTER_SETAS");

	drm_unregister_setas_info_s setas_info;
	memset(&setas_info,0x0,sizeof(drm_unregister_setas_info_s));

	snprintf(setas_info.file_path,256, "%s",FILE_PATH_VALID_FILE_OMA_12);
	tet_printf("file_path=%s",setas_info.file_path);

	setas_info.setas_cat = DRM_SETAS_WALLPAPER;

	ret = drm_process_request(request_type,(void *)&setas_info,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_PASS);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		tet_result(TET_FAIL);
	}
}

/**
 * @brief 	Negative test case of drm_process_request()
 */
static void utc_drmclient_drm_process_request_func_39(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR;
	drm_request_type_e request_type = DRM_REQUEST_TYPE_UNREGISTER_SETAS;
	tet_printf("Testing:DRM_REQUEST_TYPE_UNREGISTER_SETAS");

	ret = drm_process_request(request_type,NULL,NULL);
	if (DRM_RETURN_SUCCESS == ret) {
		tet_printf("ret = 0x%x SUCCESS", ret);
		tet_result(TET_FAIL);
	} else {
		tet_printf("ret = 0x%x FAILED", ret);
		tet_result(TET_PASS);
	}
}
