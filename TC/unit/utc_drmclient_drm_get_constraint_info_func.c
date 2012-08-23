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
 * @file 		utc_drmclient_drm_get_constraint_info_func.c
 * @brief       TETware unit testing functions for drm_get_constraint_info.
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

static void utc_drmclient_drm_get_constraint_info_func_01(void);
static void utc_drmclient_drm_get_constraint_info_func_02(void);
static void utc_drmclient_drm_get_constraint_info_func_03(void);
static void utc_drmclient_drm_get_constraint_info_func_04(void);
/* Disabled below test-cases due to network & other dependencies */
#if 0
static void utc_drmclient_drm_get_constraint_info_func_05(void);
static void utc_drmclient_drm_get_constraint_info_func_06(void);
static void utc_drmclient_drm_get_constraint_info_func_07(void);
static void utc_drmclient_drm_get_constraint_info_func_08(void);
#endif
static void utc_drmclient_drm_get_constraint_info_func_09(void);
static void utc_drmclient_drm_get_constraint_info_func_10(void);
static void utc_drmclient_drm_get_constraint_info_func_11(void);
static void utc_drmclient_drm_get_constraint_info_func_12(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{ utc_drmclient_drm_get_constraint_info_func_01, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_constraint_info_func_02, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_constraint_info_func_03, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_constraint_info_func_04, POSITIVE_TC_IDX },
	/* Disabled below test-cases due to network & other dependencies */
#if 0
	{ utc_drmclient_drm_get_constraint_info_func_05, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_constraint_info_func_06, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_constraint_info_func_07, POSITIVE_TC_IDX },
	{ utc_drmclient_drm_get_constraint_info_func_08, POSITIVE_TC_IDX },
#endif
	{ utc_drmclient_drm_get_constraint_info_func_09, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_get_constraint_info_func_10, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_get_constraint_info_func_11, NEGATIVE_TC_IDX },
	{ utc_drmclient_drm_get_constraint_info_func_12, NEGATIVE_TC_IDX },
	{ NULL, 0 }
};

static void startup(void)
{
	tet_infoline("drm_get_constraint_info:Test started");
	tet_infoline("OMA DRM Content should be registered");
	tet_infoline("RO must be installed to get valid constraint information");
}

static void cleanup(void)
{
	tet_infoline("drm_get_constraint_info:Test completed");
}

/**
 * @brief Positive test case of drm_get_constraint_info()
 */
static void utc_drmclient_drm_get_constraint_info_func_01(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_constraint_info_s constraint_info;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_PLAY;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_1);

	ret = drm_get_constraint_info(file_path,perm_type,&constraint_info);
	if(DRM_RETURN_SUCCESS == ret ){
			tet_infoline("drm_get_constraint_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x",ret);
			if(constraint_info.const_type.is_unlimited){
				tet_printf("Unlimited:for permission=%d",perm_type);
			}

			if(constraint_info.const_type.is_accumulated){
				tet_printf("Accumulated Constraint is present");
				tet_printf("accumulated_original_seconds=%d",
						constraint_info.accumulated_original_seconds);
				tet_printf("accumulated_remaining_seconds=%d",
						constraint_info.accumulated_remaining_seconds);
			}

			if(constraint_info.const_type.is_count){
				tet_printf("Count Constraint is present");
				tet_printf("original_count=%d",
						constraint_info.original_count);
				tet_printf("remaining_count=%d",
						constraint_info.remaining_count);
			}

			if(constraint_info.const_type.is_datetime){
				tet_printf("DATETIME Constraint is present");
				tet_printf("start_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.start_time.tm_year,
					constraint_info.start_time.tm_mon,
					constraint_info.start_time.tm_mday,
					constraint_info.start_time.tm_hour,
					constraint_info.start_time.tm_min,
					constraint_info.start_time.tm_sec);

				tet_printf("end_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.end_time.tm_year,
					constraint_info.end_time.tm_mon,
					constraint_info.end_time.tm_mday,
					constraint_info.end_time.tm_hour,
					constraint_info.end_time.tm_min,
					constraint_info.end_time.tm_sec);
			}

			if(constraint_info.const_type.is_individual){
				tet_printf("INDIVIDUAL Constraint is present");
				tet_printf("individual_identity_type=%d "
						"individual_id=%s",
						constraint_info.individual_identity_type,
						constraint_info.individual_id);

			}

			if(constraint_info.const_type.is_interval){
				tet_printf("INTERVAL Constraint is present");
				tet_printf("interval_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.interval_time.tm_year,
					constraint_info.interval_time.tm_mon,
					constraint_info.interval_time.tm_mday,
					constraint_info.interval_time.tm_hour,
					constraint_info.interval_time.tm_min,
					constraint_info.interval_time.tm_sec);
			}

			if(constraint_info.const_type.is_system){
				tet_printf("SYSTEM Constraint is present");
				tet_printf("system_identity_type=%d "
						"system_id=%s",
						constraint_info.system_identity_type,
						constraint_info.system_id);
			}

			if(constraint_info.const_type.is_timedcount){
				tet_printf("TIMED-COUNT Constraint is present");
				tet_printf("timed_original_count=%d",
						constraint_info.timed_original_count);

				tet_printf("timed_remaining_count=%d",
						constraint_info.timed_remaining_count);

				tet_printf("timed_count_timer=%d",
										constraint_info.timed_count_timer);
			}

			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_constraint_info");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_get_constraint_info()
 */
static void utc_drmclient_drm_get_constraint_info_func_02(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_constraint_info_s constraint_info;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_DISPLAY;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_5);

	ret = drm_get_constraint_info(file_path,perm_type,&constraint_info);
	if(DRM_RETURN_SUCCESS == ret ){
			tet_infoline("drm_get_constraint_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_5);
			tet_printf ("ret = 0x%x",ret);
			if(constraint_info.const_type.is_unlimited){
				tet_printf("Unlimited:for permission=%d",perm_type);
			}

			if(constraint_info.const_type.is_accumulated){
				tet_printf("Accumulated Constraint is present");
				tet_printf("accumulated_original_seconds=%d",
						constraint_info.accumulated_original_seconds);
				tet_printf("accumulated_remaining_seconds=%d",
						constraint_info.accumulated_remaining_seconds);
			}

			if(constraint_info.const_type.is_count){
				tet_printf("Count Constraint is present");
				tet_printf("original_count=%d",
						constraint_info.original_count);
				tet_printf("remaining_count=%d",
						constraint_info.remaining_count);
			}

			if(constraint_info.const_type.is_datetime){
				tet_printf("DATETIME Constraint is present");
				tet_printf("start_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.start_time.tm_year,
					constraint_info.start_time.tm_mon,
					constraint_info.start_time.tm_mday,
					constraint_info.start_time.tm_hour,
					constraint_info.start_time.tm_min,
					constraint_info.start_time.tm_sec);

				tet_printf("end_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.end_time.tm_year,
					constraint_info.end_time.tm_mon,
					constraint_info.end_time.tm_mday,
					constraint_info.end_time.tm_hour,
					constraint_info.end_time.tm_min,
					constraint_info.end_time.tm_sec);
			}

			if(constraint_info.const_type.is_individual){
				tet_printf("INDIVIDUAL Constraint is present");
				tet_printf("individual_identity_type=%d "
						"individual_id=%s",
						constraint_info.individual_identity_type,
						constraint_info.individual_id);

			}

			if(constraint_info.const_type.is_interval){
				tet_printf("INTERVAL Constraint is present");
				tet_printf("interval_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.interval_time.tm_year,
					constraint_info.interval_time.tm_mon,
					constraint_info.interval_time.tm_mday,
					constraint_info.interval_time.tm_hour,
					constraint_info.interval_time.tm_min,
					constraint_info.interval_time.tm_sec);
			}

			if(constraint_info.const_type.is_system){
				tet_printf("SYSTEM Constraint is present");
				tet_printf("system_identity_type=%d "
						"system_id=%s",
						constraint_info.system_identity_type,
						constraint_info.system_id);
			}

			if(constraint_info.const_type.is_timedcount){
				tet_printf("TIMED-COUNT Constraint is present");
				tet_printf("timed_original_count=%d",
						constraint_info.timed_original_count);

				tet_printf("timed_remaining_count=%d",
						constraint_info.timed_remaining_count);

				tet_printf("timed_count_timer=%d",
										constraint_info.timed_count_timer);
			}

			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_constraint_info");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_5);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_get_constraint_info()
 */
static void utc_drmclient_drm_get_constraint_info_func_03(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_constraint_info_s constraint_info;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_EXECUTE;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_6);

	ret = drm_get_constraint_info(file_path,perm_type,&constraint_info);
	if(DRM_RETURN_SUCCESS == ret ){
			tet_infoline("drm_get_constraint_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_6);
			tet_printf ("ret = 0x%x",ret);
			if(constraint_info.const_type.is_unlimited){
				tet_printf("Unlimited:for permission=%d",perm_type);
			}

			if(constraint_info.const_type.is_accumulated){
				tet_printf("Accumulated Constraint is present");
				tet_printf("accumulated_original_seconds=%d",
						constraint_info.accumulated_original_seconds);
				tet_printf("accumulated_remaining_seconds=%d",
						constraint_info.accumulated_remaining_seconds);
			}

			if(constraint_info.const_type.is_count){
				tet_printf("Count Constraint is present");
				tet_printf("original_count=%d",
						constraint_info.original_count);
				tet_printf("remaining_count=%d",
						constraint_info.remaining_count);
			}

			if(constraint_info.const_type.is_datetime){
				tet_printf("DATETIME Constraint is present");
				tet_printf("start_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.start_time.tm_year,
					constraint_info.start_time.tm_mon,
					constraint_info.start_time.tm_mday,
					constraint_info.start_time.tm_hour,
					constraint_info.start_time.tm_min,
					constraint_info.start_time.tm_sec);

				tet_printf("end_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.end_time.tm_year,
					constraint_info.end_time.tm_mon,
					constraint_info.end_time.tm_mday,
					constraint_info.end_time.tm_hour,
					constraint_info.end_time.tm_min,
					constraint_info.end_time.tm_sec);
			}

			if(constraint_info.const_type.is_individual){
				tet_printf("INDIVIDUAL Constraint is present");
				tet_printf("individual_identity_type=%d "
						"individual_id=%s",
						constraint_info.individual_identity_type,
						constraint_info.individual_id);

			}

			if(constraint_info.const_type.is_interval){
				tet_printf("INTERVAL Constraint is present");
				tet_printf("interval_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.interval_time.tm_year,
					constraint_info.interval_time.tm_mon,
					constraint_info.interval_time.tm_mday,
					constraint_info.interval_time.tm_hour,
					constraint_info.interval_time.tm_min,
					constraint_info.interval_time.tm_sec);
			}

			if(constraint_info.const_type.is_system){
				tet_printf("SYSTEM Constraint is present");
				tet_printf("system_identity_type=%d "
						"system_id=%s",
						constraint_info.system_identity_type,
						constraint_info.system_id);
			}

			if(constraint_info.const_type.is_timedcount){
				tet_printf("TIMED-COUNT Constraint is present");
				tet_printf("timed_original_count=%d",
						constraint_info.timed_original_count);

				tet_printf("timed_remaining_count=%d",
						constraint_info.timed_remaining_count);

				tet_printf("timed_count_timer=%d",
										constraint_info.timed_count_timer);
			}

			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_constraint_info");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_6);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_get_constraint_info()
 */
static void utc_drmclient_drm_get_constraint_info_func_04(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_constraint_info_s constraint_info;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_PLAY;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_8);

	ret = drm_get_constraint_info(file_path,perm_type,&constraint_info);
	if(DRM_RETURN_SUCCESS == ret ){
			tet_infoline("drm_get_constraint_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_8);
			tet_printf ("ret = 0x%x",ret);
			if(constraint_info.const_type.is_unlimited){
				tet_printf("Unlimited:for permission=%d",perm_type);
			}

			if(constraint_info.const_type.is_accumulated){
				tet_printf("Accumulated Constraint is present");
				tet_printf("accumulated_original_seconds=%d",
						constraint_info.accumulated_original_seconds);
				tet_printf("accumulated_remaining_seconds=%d",
						constraint_info.accumulated_remaining_seconds);
			}

			if(constraint_info.const_type.is_count){
				tet_printf("Count Constraint is present");
				tet_printf("original_count=%d",
						constraint_info.original_count);
				tet_printf("remaining_count=%d",
						constraint_info.remaining_count);
			}

			if(constraint_info.const_type.is_datetime){
				tet_printf("DATETIME Constraint is present");
				tet_printf("start_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.start_time.tm_year,
					constraint_info.start_time.tm_mon,
					constraint_info.start_time.tm_mday,
					constraint_info.start_time.tm_hour,
					constraint_info.start_time.tm_min,
					constraint_info.start_time.tm_sec);

				tet_printf("end_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.end_time.tm_year,
					constraint_info.end_time.tm_mon,
					constraint_info.end_time.tm_mday,
					constraint_info.end_time.tm_hour,
					constraint_info.end_time.tm_min,
					constraint_info.end_time.tm_sec);
			}

			if(constraint_info.const_type.is_individual){
				tet_printf("INDIVIDUAL Constraint is present");
				tet_printf("individual_identity_type=%d "
						"individual_id=%s",
						constraint_info.individual_identity_type,
						constraint_info.individual_id);

			}

			if(constraint_info.const_type.is_interval){
				tet_printf("INTERVAL Constraint is present");
				tet_printf("interval_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.interval_time.tm_year,
					constraint_info.interval_time.tm_mon,
					constraint_info.interval_time.tm_mday,
					constraint_info.interval_time.tm_hour,
					constraint_info.interval_time.tm_min,
					constraint_info.interval_time.tm_sec);
			}

			if(constraint_info.const_type.is_system){
				tet_printf("SYSTEM Constraint is present");
				tet_printf("system_identity_type=%d "
						"system_id=%s",
						constraint_info.system_identity_type,
						constraint_info.system_id);
			}

			if(constraint_info.const_type.is_timedcount){
				tet_printf("TIMED-COUNT Constraint is present");
				tet_printf("timed_original_count=%d",
						constraint_info.timed_original_count);

				tet_printf("timed_remaining_count=%d",
						constraint_info.timed_remaining_count);

				tet_printf("timed_count_timer=%d",
										constraint_info.timed_count_timer);
			}

			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_constraint_info");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_8);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}

/* Disabled below test-cases due to network & other dependencies */
#if 0
/**
 * @brief Positive test case of drm_get_constraint_info()
 */
static void utc_drmclient_drm_get_constraint_info_func_05(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_constraint_info_s constraint_info;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_PLAY;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_PR_1);

	ret = drm_get_constraint_info(file_path,perm_type,&constraint_info);
	if(DRM_RETURN_SUCCESS == ret ){
			tet_infoline("drm_get_constraint_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_1);
			tet_printf ("ret = 0x%x",ret);
			if(constraint_info.const_type.is_unlimited){
				tet_printf("Unlimited:for permission=%d",perm_type);
			}

			if(constraint_info.const_type.is_accumulated){
				tet_printf("Accumulated Constraint is present");
				tet_printf("accumulated_original_seconds=%d",
						constraint_info.accumulated_original_seconds);
				tet_printf("accumulated_remaining_seconds=%d",
						constraint_info.accumulated_remaining_seconds);
			}

			if(constraint_info.const_type.is_count){
				tet_printf("Count Constraint is present");
				tet_printf("original_count=%d",
						constraint_info.original_count);
				tet_printf("remaining_count=%d",
						constraint_info.remaining_count);
			}

			if(constraint_info.const_type.is_datetime){
				tet_printf("DATETIME Constraint is present");
				tet_printf("start_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.start_time.tm_year,
					constraint_info.start_time.tm_mon,
					constraint_info.start_time.tm_mday,
					constraint_info.start_time.tm_hour,
					constraint_info.start_time.tm_min,
					constraint_info.start_time.tm_sec);

				tet_printf("end_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.end_time.tm_year,
					constraint_info.end_time.tm_mon,
					constraint_info.end_time.tm_mday,
					constraint_info.end_time.tm_hour,
					constraint_info.end_time.tm_min,
					constraint_info.end_time.tm_sec);
			}

			if(constraint_info.const_type.is_individual){
				tet_printf("INDIVIDUAL Constraint is present");
				tet_printf("individual_identity_type=%d "
						"individual_id=%s",
						constraint_info.individual_identity_type,
						constraint_info.individual_id);

			}

			if(constraint_info.const_type.is_interval){
				tet_printf("INTERVAL Constraint is present");
				tet_printf("interval_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.interval_time.tm_year,
					constraint_info.interval_time.tm_mon,
					constraint_info.interval_time.tm_mday,
					constraint_info.interval_time.tm_hour,
					constraint_info.interval_time.tm_min,
					constraint_info.interval_time.tm_sec);
			}

			if(constraint_info.const_type.is_system){
				tet_printf("SYSTEM Constraint is present");
				tet_printf("system_identity_type=%d "
						"system_id=%s",
						constraint_info.system_identity_type,
						constraint_info.system_id);
			}

			if(constraint_info.const_type.is_timedcount){
				tet_printf("TIMED-COUNT Constraint is present");
				tet_printf("timed_original_count=%d",
						constraint_info.timed_original_count);

				tet_printf("timed_remaining_count=%d",
						constraint_info.timed_remaining_count);

				tet_printf("timed_count_timer=%d",
										constraint_info.timed_count_timer);
			}

			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_constraint_info");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_1);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_get_constraint_info()
 */
static void utc_drmclient_drm_get_constraint_info_func_06(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_constraint_info_s constraint_info;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_PLAY;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_PR_2);

	ret = drm_get_constraint_info(file_path,perm_type,&constraint_info);
	if(DRM_RETURN_SUCCESS == ret ){
			tet_infoline("drm_get_constraint_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_2);
			tet_printf ("ret = 0x%x",ret);
			if(constraint_info.const_type.is_unlimited){
				tet_printf("Unlimited:for permission=%d",perm_type);
			}

			if(constraint_info.const_type.is_accumulated){
				tet_printf("Accumulated Constraint is present");
				tet_printf("accumulated_original_seconds=%d",
						constraint_info.accumulated_original_seconds);
				tet_printf("accumulated_remaining_seconds=%d",
						constraint_info.accumulated_remaining_seconds);
			}

			if(constraint_info.const_type.is_count){
				tet_printf("Count Constraint is present");
				tet_printf("original_count=%d",
						constraint_info.original_count);
				tet_printf("remaining_count=%d",
						constraint_info.remaining_count);
			}

			if(constraint_info.const_type.is_datetime){
				tet_printf("DATETIME Constraint is present");
				tet_printf("start_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.start_time.tm_year,
					constraint_info.start_time.tm_mon,
					constraint_info.start_time.tm_mday,
					constraint_info.start_time.tm_hour,
					constraint_info.start_time.tm_min,
					constraint_info.start_time.tm_sec);

				tet_printf("end_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.end_time.tm_year,
					constraint_info.end_time.tm_mon,
					constraint_info.end_time.tm_mday,
					constraint_info.end_time.tm_hour,
					constraint_info.end_time.tm_min,
					constraint_info.end_time.tm_sec);
			}

			if(constraint_info.const_type.is_individual){
				tet_printf("INDIVIDUAL Constraint is present");
				tet_printf("individual_identity_type=%d "
						"individual_id=%s",
						constraint_info.individual_identity_type,
						constraint_info.individual_id);

			}

			if(constraint_info.const_type.is_interval){
				tet_printf("INTERVAL Constraint is present");
				tet_printf("interval_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.interval_time.tm_year,
					constraint_info.interval_time.tm_mon,
					constraint_info.interval_time.tm_mday,
					constraint_info.interval_time.tm_hour,
					constraint_info.interval_time.tm_min,
					constraint_info.interval_time.tm_sec);
			}

			if(constraint_info.const_type.is_system){
				tet_printf("SYSTEM Constraint is present");
				tet_printf("system_identity_type=%d "
						"system_id=%s",
						constraint_info.system_identity_type,
						constraint_info.system_id);
			}

			if(constraint_info.const_type.is_timedcount){
				tet_printf("TIMED-COUNT Constraint is present");
				tet_printf("timed_original_count=%d",
						constraint_info.timed_original_count);

				tet_printf("timed_remaining_count=%d",
						constraint_info.timed_remaining_count);

				tet_printf("timed_count_timer=%d",
										constraint_info.timed_count_timer);
			}

			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_constraint_info");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_2);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_get_constraint_info()
 */
static void utc_drmclient_drm_get_constraint_info_func_07(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_constraint_info_s constraint_info;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_PLAY;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_PR_3);

	ret = drm_get_constraint_info(file_path,perm_type,&constraint_info);
	if(DRM_RETURN_SUCCESS == ret ){
			tet_infoline("drm_get_constraint_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_3);
			tet_printf ("ret = 0x%x",ret);
			if(constraint_info.const_type.is_unlimited){
				tet_printf("Unlimited:for permission=%d",perm_type);
			}

			if(constraint_info.const_type.is_accumulated){
				tet_printf("Accumulated Constraint is present");
				tet_printf("accumulated_original_seconds=%d",
						constraint_info.accumulated_original_seconds);
				tet_printf("accumulated_remaining_seconds=%d",
						constraint_info.accumulated_remaining_seconds);
			}

			if(constraint_info.const_type.is_count){
				tet_printf("Count Constraint is present");
				tet_printf("original_count=%d",
						constraint_info.original_count);
				tet_printf("remaining_count=%d",
						constraint_info.remaining_count);
			}

			if(constraint_info.const_type.is_datetime){
				tet_printf("DATETIME Constraint is present");
				tet_printf("start_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.start_time.tm_year,
					constraint_info.start_time.tm_mon,
					constraint_info.start_time.tm_mday,
					constraint_info.start_time.tm_hour,
					constraint_info.start_time.tm_min,
					constraint_info.start_time.tm_sec);

				tet_printf("end_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.end_time.tm_year,
					constraint_info.end_time.tm_mon,
					constraint_info.end_time.tm_mday,
					constraint_info.end_time.tm_hour,
					constraint_info.end_time.tm_min,
					constraint_info.end_time.tm_sec);
			}

			if(constraint_info.const_type.is_individual){
				tet_printf("INDIVIDUAL Constraint is present");
				tet_printf("individual_identity_type=%d "
						"individual_id=%s",
						constraint_info.individual_identity_type,
						constraint_info.individual_id);

			}

			if(constraint_info.const_type.is_interval){
				tet_printf("INTERVAL Constraint is present");
				tet_printf("interval_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.interval_time.tm_year,
					constraint_info.interval_time.tm_mon,
					constraint_info.interval_time.tm_mday,
					constraint_info.interval_time.tm_hour,
					constraint_info.interval_time.tm_min,
					constraint_info.interval_time.tm_sec);
			}

			if(constraint_info.const_type.is_system){
				tet_printf("SYSTEM Constraint is present");
				tet_printf("system_identity_type=%d "
						"system_id=%s",
						constraint_info.system_identity_type,
						constraint_info.system_id);
			}

			if(constraint_info.const_type.is_timedcount){
				tet_printf("TIMED-COUNT Constraint is present");
				tet_printf("timed_original_count=%d",
						constraint_info.timed_original_count);

				tet_printf("timed_remaining_count=%d",
						constraint_info.timed_remaining_count);

				tet_printf("timed_count_timer=%d",
										constraint_info.timed_count_timer);
			}

			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_constraint_info");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_PR_3);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Positive test case of drm_get_constraint_info()
 */
static void utc_drmclient_drm_get_constraint_info_func_08(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_constraint_info_s constraint_info;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_PLAY;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_DIVX_1);

	ret = drm_get_constraint_info(file_path,perm_type,&constraint_info);
	if(DRM_RETURN_SUCCESS == ret ){
			tet_infoline("drm_get_constraint_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_DIVX_1);
			tet_printf ("ret = 0x%x",ret);
			if(constraint_info.const_type.is_unlimited){
				tet_printf("Unlimited:for permission=%d",perm_type);
			}

			if(constraint_info.const_type.is_accumulated){
				tet_printf("Accumulated Constraint is present");
				tet_printf("accumulated_original_seconds=%d",
						constraint_info.accumulated_original_seconds);
				tet_printf("accumulated_remaining_seconds=%d",
						constraint_info.accumulated_remaining_seconds);
			}

			if(constraint_info.const_type.is_count){
				tet_printf("Count Constraint is present");
				tet_printf("original_count=%d",
						constraint_info.original_count);
				tet_printf("remaining_count=%d",
						constraint_info.remaining_count);
			}

			if(constraint_info.const_type.is_datetime){
				tet_printf("DATETIME Constraint is present");
				tet_printf("start_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.start_time.tm_year,
					constraint_info.start_time.tm_mon,
					constraint_info.start_time.tm_mday,
					constraint_info.start_time.tm_hour,
					constraint_info.start_time.tm_min,
					constraint_info.start_time.tm_sec);

				tet_printf("end_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.end_time.tm_year,
					constraint_info.end_time.tm_mon,
					constraint_info.end_time.tm_mday,
					constraint_info.end_time.tm_hour,
					constraint_info.end_time.tm_min,
					constraint_info.end_time.tm_sec);
			}

			if(constraint_info.const_type.is_individual){
				tet_printf("INDIVIDUAL Constraint is present");
				tet_printf("individual_identity_type=%d "
						"individual_id=%s",
						constraint_info.individual_identity_type,
						constraint_info.individual_id);

			}

			if(constraint_info.const_type.is_interval){
				tet_printf("INTERVAL Constraint is present");
				tet_printf("interval_time:"
						"Year=%d,Month=%d,Day=%d,Hour=%d, minute=%d, Second=%d",
					constraint_info.interval_time.tm_year,
					constraint_info.interval_time.tm_mon,
					constraint_info.interval_time.tm_mday,
					constraint_info.interval_time.tm_hour,
					constraint_info.interval_time.tm_min,
					constraint_info.interval_time.tm_sec);
			}

			if(constraint_info.const_type.is_system){
				tet_printf("SYSTEM Constraint is present");
				tet_printf("system_identity_type=%d "
						"system_id=%s",
						constraint_info.system_identity_type,
						constraint_info.system_id);
			}

			if(constraint_info.const_type.is_timedcount){
				tet_printf("TIMED-COUNT Constraint is present");
				tet_printf("timed_original_count=%d",
						constraint_info.timed_original_count);

				tet_printf("timed_remaining_count=%d",
						constraint_info.timed_remaining_count);

				tet_printf("timed_count_timer=%d",
										constraint_info.timed_count_timer);
			}

			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_constraint_info");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_DIVX_1);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}
#endif
/**
 * @brief Negative test case of drm_get_constraint_info()
 */

static void utc_drmclient_drm_get_constraint_info_func_09(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_constraint_info_s constraint_info;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_PLAY;

	ret = drm_get_constraint_info(FILE_PATH_INVALID_FILE_NULL,perm_type,&constraint_info);
	if(DRM_RETURN_SUCCESS != ret){
			tet_infoline("drm_get_constraint_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_NULL);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_constraint_info");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_NULL);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_get_constraint_info()
 */

static void utc_drmclient_drm_get_constraint_info_func_10(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_constraint_info_s constraint_info;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_PLAY;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};

	ret = drm_get_constraint_info(file_path,perm_type,&constraint_info);
	if(DRM_RETURN_SUCCESS != ret){
			tet_infoline("drm_get_constraint_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_EMPTY);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_constraint_info");
			tet_printf ("file_path checked is %s",FILE_PATH_INVALID_FILE_EMPTY);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_get_constraint_info()
 */

static void utc_drmclient_drm_get_constraint_info_func_11(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_PLAY;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_1);

	ret = drm_get_constraint_info(file_path,perm_type,INVALID_POINTER_OBJECT);
	if(DRM_RETURN_SUCCESS != ret){
			tet_infoline("drm_get_constraint_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_constraint_info");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_1);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}

/**
 * @brief Negative test case of drm_get_constraint_info()
 */
static void utc_drmclient_drm_get_constraint_info_func_12(void)
{
	int ret = DRM_RETURN_INTERNAL_ERROR ;
	drm_constraint_info_s constraint_info;
	drm_permission_type_e perm_type = DRM_PERMISSION_TYPE_DISPLAY;
	char file_path[FILE_PATH_MAX_SIZE] = {0,};
	snprintf(file_path,FILE_PATH_MAX_SIZE, "%s",FILE_PATH_VALID_FILE_OMA_7);

	ret = drm_get_constraint_info(file_path,perm_type,&constraint_info);
	if(DRM_RETURN_SUCCESS != ret ){
			/* pbarimage_timedcount.dr RO is in wrong format */
			/* Thus it will fail */
			tet_infoline("drm_get_constraint_info PASS!!!");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_7);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_PASS);
	}else{
			tet_infoline("drm_get_constraint_info");
			tet_printf ("file_path checked is %s",FILE_PATH_VALID_FILE_OMA_7);
			tet_printf ("ret = 0x%x",ret);
			tet_result(TET_FAIL);
	}
}
