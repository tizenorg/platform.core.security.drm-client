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
 * @file 		utc_drmclient_drm_get_content_info_func.c
 * @brief       TETware unit testing functions for drm_get_content_info.
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

static void utc_drmclient_drm_get_content_info_func_01(void);
static void utc_drmclient_drm_get_content_info_func_02(void);
static void utc_drmclient_drm_get_content_info_func_03(void);
static void utc_drmclient_drm_get_content_info_func_04(void);
static void utc_drmclient_drm_get_content_info_func_05(void);
static void utc_drmclient_drm_get_content_info_func_06(void);
static void utc_drmclient_drm_get_content_info_func_07(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{ utc_drmclient_drm_get_content_info_func_01, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_content_info_func_02, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_content_info_func_03, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_content_info_func_04, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_content_info_func_05, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_get_content_info_func_06, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_get_content_info_func_07, NEGATIVE_TC_IDX },
	{ NULL, 0 }
};

static void startup(void)
{
	tet_infoline("drm_get_content_info:Test started");
}

static void cleanup(void)
{
	tet_infoline("drm_get_content_info:Test completed");
}

/**
 * @brief Positive test case of drm_get_content_info()
 */
static void utc_drmclient_drm_get_content_info_func_01(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_content_info_s content_info;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_1);

	ret = drm_get_content_info(file_path,&content_info);
	if(DRM_RETURN_SUCCESS == ret){
			tet_infoline("drm_get_content_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x",ret);
			if('\0' != content_info.author[0]) tet_printf("author=%s",content_info.author);
			if('\0' != content_info.copyright[0]) tet_printf("copyright=%s",content_info.copyright);
			if('\0' != content_info.description[0]) tet_printf("description=%s",content_info.description);
			if('\0' != content_info.icon_uri[0]) tet_printf("icon_uri=%s",content_info.icon_uri);
			if('\0' != content_info.info_url[0]) tet_printf("info_url=%s",content_info.info_url);
			if('\0' != content_info.content_url[0]) tet_printf("content_url=%s",content_info.content_url);
			if('\0' != content_info.rights_url[0]) tet_printf("rights_url=%s",content_info.rights_url);
			if('\0' != content_info.title[0]) tet_printf("title=%s",content_info.title);
			if('\0' != content_info.mime_type[0]) tet_printf("mime_type=%s",content_info.mime_type);
			if('\0' != content_info.content_id[0]) tet_printf("content_id=%s",content_info.content_id);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_content_info FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_get_content_info()
 */
static void utc_drmclient_drm_get_content_info_func_02(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_content_info_s content_info;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_2);

	ret = drm_get_content_info(file_path,&content_info);
	if(DRM_RETURN_SUCCESS == ret){
			tet_infoline("drm_get_content_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_2);
			tet_printf ("ret = 0x%x",ret);
			if('\0' != content_info.author[0]) tet_printf("author=%s",content_info.author);
			if('\0' != content_info.copyright[0]) tet_printf("copyright=%s",content_info.copyright);
			if('\0' != content_info.description[0]) tet_printf("description=%s",content_info.description);
			if('\0' != content_info.icon_uri[0]) tet_printf("icon_uri=%s",content_info.icon_uri);
			if('\0' != content_info.info_url[0]) tet_printf("info_url=%s",content_info.info_url);
			if('\0' != content_info.content_url[0]) tet_printf("content_url=%s",content_info.content_url);
			if('\0' != content_info.rights_url[0]) tet_printf("rights_url=%s",content_info.rights_url);
			if('\0' != content_info.title[0]) tet_printf("title=%s",content_info.title);
			if('\0' != content_info.mime_type[0]) tet_printf("mime_type=%s",content_info.mime_type);
			if('\0' != content_info.content_id[0]) tet_printf("content_id=%s",content_info.content_id);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_content_info FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_2);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_get_content_info()
 */
static void utc_drmclient_drm_get_content_info_func_03(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_content_info_s content_info;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_3);

	ret = drm_get_content_info(file_path,&content_info);
	if(DRM_RETURN_SUCCESS == ret){
			tet_infoline("drm_get_content_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_3);
			tet_printf ("ret = 0x%x",ret);
			if('\0' != content_info.author[0]) tet_printf("author=%s",content_info.author);
			if('\0' != content_info.copyright[0]) tet_printf("copyright=%s",content_info.copyright);
			if('\0' != content_info.description[0]) tet_printf("description=%s",content_info.description);
			if('\0' != content_info.icon_uri[0]) tet_printf("icon_uri=%s",content_info.icon_uri);
			if('\0' != content_info.info_url[0]) tet_printf("info_url=%s",content_info.info_url);
			if('\0' != content_info.content_url[0]) tet_printf("content_url=%s",content_info.content_url);
			if('\0' != content_info.rights_url[0]) tet_printf("rights_url=%s",content_info.rights_url);
			if('\0' != content_info.title[0]) tet_printf("title=%s",content_info.title);
			if('\0' != content_info.mime_type[0]) tet_printf("mime_type=%s",content_info.mime_type);
			if('\0' != content_info.content_id[0]) tet_printf("content_id=%s",content_info.content_id);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_content_info FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_3);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_get_content_info()
 */
static void utc_drmclient_drm_get_content_info_func_04(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_content_info_s content_info;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_4);

	ret = drm_get_content_info(file_path,&content_info);
	if(DRM_RETURN_SUCCESS == ret){
			tet_infoline("drm_get_content_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_4);
			tet_printf ("ret = 0x%x",ret);
			if('\0' != content_info.author[0]) tet_printf("author=%s",content_info.author);
			if('\0' != content_info.copyright[0]) tet_printf("copyright=%s",content_info.copyright);
			if('\0' != content_info.description[0]) tet_printf("description=%s",content_info.description);
			if('\0' != content_info.icon_uri[0]) tet_printf("icon_uri=%s",content_info.icon_uri);
			if('\0' != content_info.info_url[0]) tet_printf("info_url=%s",content_info.info_url);
			if('\0' != content_info.content_url[0]) tet_printf("content_url=%s",content_info.content_url);
			if('\0' != content_info.rights_url[0]) tet_printf("rights_url=%s",content_info.rights_url);
			if('\0' != content_info.title[0]) tet_printf("title=%s",content_info.title);
			if('\0' != content_info.mime_type[0]) tet_printf("mime_type=%s",content_info.mime_type);
			if('\0' != content_info.content_id[0]) tet_printf("content_id=%s",content_info.content_id);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_content_info FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_4);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_get_content_info()
 */

static void utc_drmclient_drm_get_content_info_func_05(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_content_info_s content_info;

	ret = drm_get_content_info(FILE_PATH_INVALID_FILE_NULL,&content_info);
	if(DRM_RETURN_SUCCESS != ret){
			tet_infoline("drm_get_content_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_NULL);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_content_info FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_NULL);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_get_content_info()
 */

static void utc_drmclient_drm_get_content_info_func_06(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_content_info_s content_info;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};

	ret = drm_get_content_info(file_path,&content_info);
	if(DRM_RETURN_SUCCESS != ret){
			tet_infoline("drm_get_content_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_EMPTY);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_content_info FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_EMPTY);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_get_content_info()
 */

static void utc_drmclient_drm_get_content_info_func_07(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_INVALID_FILE_DIVX_1);

	ret = drm_get_content_info(file_path,INVALID_POINTER_OBJECT);
	if(DRM_RETURN_SUCCESS != ret){
			tet_infoline("drm_get_content_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_DIVX_1);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_content_info FAIL!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_DIVX_1);
			tet_printf ("ret =%d",ret);
			tet_result(TET_FAIL);
	}
}
