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
 * @file 		drm_client_types.h
 * @brief       DRM Client API macros, structures & enum declaration file.
 * @author      Mahendra Kumar Prajapat (mahendra.p@samsung.com)
 * @author      Harsha Shekar (h.shekar@samsung.com)
 * @version     0.1
 * @history     0.1: First version of DRM Client API macros,
 * 				structures & enum declarations.
 */

#ifndef __DRM_CLIENT_TYPES_H__
#define __DRM_CLIENT_TYPES_H__

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus */

#include <time.h>

#include "tizen_error.h"


/******************************************************************/

/*
 * Maximum Length of Author field
 */
#define DRM_MAX_LEN_AUTHOR 		(64)

/*
 * Maximum Length of Copyright field
 */
#define DRM_MAX_LEN_COPYRIGHT 	(64)

/*
 * Maximum Length of Description field
 */
#define DRM_MAX_LEN_DESCRIPTION (256)

/*
 * Maximum Length of Icon URI field
 */
#define DRM_MAX_LEN_ICON_URI 	(256)

/*
 * Maximum Length of Info URL field
 */
#define DRM_MAX_LEN_INFO_URL 	(256)

/*
 * Maximum Length of Content URL field
 */
#define DRM_MAX_LEN_CONTENT_URL (512)

/*
 * Maximum Length of Rights URL field
 */
#define DRM_MAX_LEN_RIGHTS_URL 	(256)

/*
 * Maximum Length of Title field
 */
#define DRM_MAX_LEN_TITLE 		(256)

/*
 * Maximum Length of MIME (Content Type) field
 */
#define DRM_MAX_LEN_MIME 		(64)

/*
 * Maximum Length of Content ID field
 */
#define DRM_MAX_LEN_CID 		(256)

/*
 * Maximum Length of Individual Identity field
 */
#define DRM_MAX_LEN_INDIVIDUAL_IDENTITY (64)

/*
 * Maximum Length of System Identity field
 */
#define DRM_MAX_LEN_SYSTEM_IDENTITY	(64)

/*
 * Maximum Length of original filename for PlayReady envelope
 */
#define DRM_MAX_LEN_FILEPATH 	(256)

/**
* Maximum length of Transaction ID of the DCF
*/
#define DRM_MAX_SIZE_TRANSACTION_ID		(17)

/**
* Maximum length of DivX code (Registration / De-registration code )
*/
#define DRM_MAX_SIZE_DIVX_CODE		(16)

/**
* Maximum length of License Data
*/
#define DRM_MAX_LEN_LICENSE_DATA 	(3000)

/**
* Maximum length of Initiator URL
*/
#define DRM_MAX_LEN_INITIATOR_URL 	(512)

/**
* Maximum length of IP Address
*/
#define DRM_MAX_LEN_IP_ADDR 		(64)

/*
 * Max length of APP ID
 */
#define DRM_MAX_LEN_APP_ID 		(15)

/*
 * Max length of User ID
 */
#define DRM_MAX_LEN_USER_GUID 	(15)

/*
 * Max length of Device ID
 */
#define DRM_MAX_LEN_DEVICE_ID 	(15)

/*
 * Max length of Order ID
 */
#define DRM_MAX_LEN_ORDER_ID 	(23)

/*
 * Max length of Service ID
 */
#define DRM_MAX_LEN_SERVICE_ID	(31)

/*
 * Max length of Account ID
 */
#define DRM_MAX_LEN_ACCOUNT_ID 	(31)

/****************************************************************/

/**
 * @enum drm_result_e
 * @brief DRM Return values.
 */
typedef enum {
	/**< Success */
	DRM_RETURN_SUCCESS = 0,
	/**< Invalid Argument */
	DRM_RETURN_INVALID_ARG = TIZEN_ERROR_INVALID_PARAMETER,
	/**< Insufficient Memory */
	DRM_RETURN_INSUFFICIENT_MEMORY = TIZEN_ERROR_OUT_OF_MEMORY,
	/**< Parsing Error */
	DRM_RETURN_PARSING_ERROR = TIZEN_ERROR_DRM_CLASS | 0x01,
	/**< DB Error */
	DRM_RETURN_DB_ERROR = TIZEN_ERROR_DRM_CLASS | 0x02,
	/**< File Error */
	DRM_RETURN_FILE_ERROR = TIZEN_ERROR_DRM_CLASS | 0x03,
	/**< Communication Error */
	DRM_RETURN_COMMUNICATION_ERROR = TIZEN_ERROR_DRM_CLASS | 0x04,
	/**< Internal Error */
	DRM_RETURN_INTERNAL_ERROR = TIZEN_ERROR_UNKNOWN
} drm_result_e;

/**
 * @enum drm_bool_type_e
 * @brief DRM Bool values.
 */
typedef enum {
	DRM_FALSE = 0,			     /**< false */
	DRM_TRUE = 1,			     /**< true */
	DRM_UNKNOWN = 0xFFFFFFFF	     /**< error */
} drm_bool_type_e;

/**
 * @enum drm_file_type_e
 * @brief DRM file types.
 */
typedef enum {
	DRM_TYPE_UNDEFINED,				/**< For initialization purpose */
	DRM_TYPE_OMA_V1,				/**< OMA DRM v1 file */
	DRM_TYPE_OMA_V2,				/**< OMA DRM v2 file */
	DRM_TYPE_PLAYREADY,				/**< PlayReady file */
	DRM_TYPE_PLAYREADY_ENVELOPE,	/**< PlayReady Envelope file */
	DRM_TYPE_DIVX,					/**< DivX file */
	DRM_TYPE_OMA_PD,				/**< Progressive Download file */
	DRM_TYPE_PIFF,					/**< PIFF file */
	DRM_TYPE_SAPPS					/**< Samsung Apps */
} drm_file_type_e;

/**
 * @enum drm_permission_type_e
 * @brief DRM Permission types.
 */
typedef enum {
	DRM_PERMISSION_TYPE_NONE,				/**< For initialization purpose */
	DRM_PERMISSION_TYPE_ANY,				/**< Any permission */
	DRM_PERMISSION_TYPE_PLAY,				/**< Play Permission */
	DRM_PERMISSION_TYPE_COLLABORATIVE_PLAY, /**< Collaborative Play
											(e.g gaming application) */

	DRM_PERMISSION_TYPE_DISPLAY,			/**< Display Permission */
	DRM_PERMISSION_TYPE_EXECUTE,			/**< Execute Permission */
	DRM_PERMISSION_TYPE_PRINT,				/**< Print Permission */
	DRM_PERMISSION_TYPE_EXPORT_COPY,		/**< Export-copy permission */
	DRM_PERMISSION_TYPE_EXPORT_MOVE			/**< Export-move permission */
} drm_permission_type_e;

/**
 * @enum drm_license_status_e
 * @brief DRM License status.
 */
typedef enum {
	DRM_LICENSE_STATUS_UNDEFINED,	/**< For initialization purpose */
	DRM_LICENSE_STATUS_VALID,		/**< Valid License */
	DRM_LICENSE_STATUS_FUTURE_USE,	/**< License for future use */
	DRM_LICENSE_STATUS_EXPIRED,		/**< Expired License */
	DRM_LICENSE_STATUS_NO_LICENSE,	/**< No License */
} drm_license_status_e;

/**
 * @enum drm_action_type_e
 * @brief DRM Action types.
 */
typedef enum {
	DRM_ACTION_UNDEFINED,		/**< for initialization purpose */
	DRM_IS_FORWARDING_ALLOWED,	/**< if a file can be forwarded */
	DRM_HAS_VALID_SETAS_STATUS,	/**< if a file can be SETAS */
	DRM_IS_DEVICE_ACTIVATED,		/**< if a device is DIVX activated */
	DRM_IS_VALID_SECURE_CLOCK	/**< if Secure Clock is set */
} drm_action_type_e;

/**
 * @enum drm_method_type_e
 * @brief DRM method types.
 */
typedef enum {
	DRM_METHOD_TYPE_UNDEFINED,			/**< For initialization purpose */
	DRM_METHOD_TYPE_FORWARD_LOCK,		/**< OMA DRM forward lock */
	DRM_METHOD_TYPE_COMBINED_DELIVERY,	/**< OMA DRM Combined Delivery */
	DRM_METHOD_TYPE_SEPARATE_DELIVERY	/**< OMA DRM Separate Delivery
										& OMA DRM v2 */
}drm_method_type_e;

/**
 * @enum drm_rights_version_e
 * @brief DRM Rights Version.
 */
typedef enum {
	DRM_OMA_DRMV1_RIGHTS,		/**< OMA DRM v1 */
	DRM_OMA_DRMV2_RIGHTS,		/**< OMA DRM v2 */
	DRM_UNDEFINED_RIGHTS = 3		/**< dummy */
} drm_rights_version_e;

/**
 * @enum drm_constraint_identity_type_e
 * @brief DRM Constraint Identity type.
 */
typedef enum {
	DRM_CONSTRAINT_IDENTITY_TYPE_NONE,		/**< For initialization */
	DRM_CONSTRAINT_IDENTITY_TYPE_IMEI,		/**< IMEI */
	DRM_CONSTRAINT_IDENTITY_TYPE_IMSI,		/**< IMSI */
	DRM_CONSTRAINT_IDENTITY_TYPE_MSISDN,	/**< MS-ISDN */
	DRM_CONSTRAINT_IDENTITY_TYPE_WIM		/**< WIM
											(Wireless/WAP Identity Module ) */
} drm_constraint_identity_type_e;

/**
 * @enum drm_setas_category_e
 * @brief DRM SETAS type.
 */
typedef enum {
	DRM_SETAS_NONE = -1,			/**< No set as operation */
	DRM_SETAS_WALLPAPER = 0,		/**< Set As Wallpaper */
	DRM_SETAS_RINGTONE = 2,			/**< Set As Ringtone */
} drm_setas_category_e;

/**
 * @enum drm_data_type_e
 * @brief DRM Requested Data types.
 */
typedef enum {
	/* For initialization purpose */
	DRM_DATA_TYPE_NONE = -1,

	/* Secure Clock Information */
	DRM_DATA_TYPE_SECURE_CLOCK = 0,

	/* Transaction Tracking flag status information */
	DRM_DATA_TYPE_TRANSACTION_TRACKING_FLAG,

	/* Transaction Tracking ID information */
	DRM_DATA_TYPE_TRANSACTION_TRACKING_ID,

	/* DivX Registration Code information */
	DRM_DATA_TYPE_DIVX_REGISTRATION_CODE,

	/* DivX De-registration Code information */
	DRM_DATA_TYPE_DIVX_DEREGISTRATION_CODE,
} drm_data_type_e;

/**
 * @enum drm_request_type_e
 * @brief DRM Request types.
 */
typedef enum {
	/* For initialization purpose */
	DRM_REQUEST_TYPE_NONE = -1,

	/* Request to Register DRM file in DB */
	DRM_REQUEST_TYPE_REGISTER_FILE = 0,

	/* Request to Un-register DRM file from DB */
	DRM_REQUEST_TYPE_UNREGISTER_FILE,

	/* Request to Un-register All DRM files from DB */
	DRM_REQUEST_TYPE_UNREGISTER_ALL_FILES,

	/* Request to Register / install License into DB */
	DRM_REQUEST_TYPE_REGISTER_LICENSE,

	/* Request to start Initiator processing for PlayReady */
	DRM_REQUEST_TYPE_SUBMIT_INITIATOR_URL,

	/* Submit Roap Message */
	DRM_REQUEST_TYPE_SUBMIT_ROAP_MESSAGE,

	/* Submit Roap User Consent */
	DRM_REQUEST_TYPE_SUBMIT_ROAP_USER_CONSENT,

	/* HTTP User Cancel */
	DRM_REQUEST_TYPE_HTTP_USER_CANCEL,

	/* Register Copy File */
	DRM_REQUEST_TYPE_REGISTER_COPY_FILE,

	/* Register Move File */
	DRM_REQUEST_TYPE_REGISTER_MOVE_FILE,

	/* Insert External Memory */
	DRM_REQUEST_TYPE_INSERT_EXT_MEMORY,

	/* Extract External Memory */
	DRM_REQUEST_TYPE_EXTRACT_EXT_MEMORY,

	/* Register SetAs */
	DRM_REQUEST_TYPE_REGISTER_SETAS,

	/* Unregister SetAs */
	DRM_REQUEST_TYPE_UNREGISTER_SETAS

} drm_request_type_e;

/**
 * @enum drm_roap_init_src_e
 * @brief DRM ROAP initialization source.
 */
typedef enum{
	/**< dummy */
   DRM_ROAP_INIT_FROM_UNKNOWN,

   /**< roap is initialized from browser*/
   DRM_ROAP_INIT_FROM_BROWSER,

   /**< roap is initialized from DRM content */
   DRM_ROAP_INIT_FROM_CONTENT,

   /**< roap is initialized from WAPPUSH */
   DRM_ROAP_INIT_FROM_WAPPUSH
} drm_roap_init_src_e;

/**
 * @enum	drm_operation_type_e
 * @brief	DRM operation type.
 */
typedef enum {
	/* License Acquisition Operation */
	DRM_OPERATION_TYPE_LICENSE_ACQ,

	/* Join Domain Operation */
	DRM_OPERATION_TYPE_JOIN_DOMAIN,

	/* Leave Domain Operation */
	DRM_OPERATION_TYPE_LEAVE_DOMAIN,

	/* Metering Operation */
	DRM_OPERATION_TYPE_METERING_INFO,

	/* Unknown Operation type */
	DRM_OPERATION_TYPE_UNKNOWN
} drm_operation_type_e;

/**
 * @enum	drm_operation_status_e
 * @brief	DRM operation status.
 */
typedef enum {
	/** DRM operation is started */
	DRM_OPERATION_STATUS_STARTED,

	/** DRM operation is in Progress */
	DRM_OPERATION_STATUS_INPROGRESS,

	/** DRM operation is Completed */
	DRM_OPERATION_STATUS_COMPLETED,

	/** During DRM operation, additional operation is to be performed */
	DRM_OPERATION_STATUS_ADDITIONAL_INFO,

	/** An error occurred with respect to DRM operation */
	DRM_OPERATION_STATUS_ERROR
} drm_operation_status_e;

/**
 * @enum drm_web_server_result_code_e
 * @brief DRM Return values.
 */
typedef enum {
	/** No server Error */
	DRM_RESULT_CODE_NONE,

	/** Device Certificate is revoked.
	 * User shall be informed that their device needs to be updated.
	 */
	DRM_RESULT_CODE_DEVCERT_REVOKED,

	/** Indicates a server problem.Device shall silently retry 3 times.
	 *  If failure persists, user shall be informed about a server failure
	 *  and to try again later
	 */
	DRM_RESULT_CODE_INTERNAL_ERROR,

	/** Means an invalid protocol message.
	 * This shall never happen unless there's been a "man in the middle"
	 * attack. Device shall perform a retry.
	 */
	DRM_RESULT_CODE_INVALID_MESSAGE,

	/** Means that the device limit has been reached for this domain and
	 * therefore the device cannot join this Domain.
	 * The application on the device shall provide the appropriate
	 * response to the end user.
	 */
	DRM_RESULT_CODE_DEVICE_LIMIT_REACHED,

	/** Indicates that the device shall join a Domain and then
	 * retry license acquisition.
	 */
	DRM_RESULT_CODE_DOMAIN_REQUIRED,

	/** Indicates that the device shall renew the Domain Certificate
	 * for this Domain. The device shall join Domain and then retry
	 * license acquisition.
	 */
	DRM_RESULT_CODE_RENEW_DOMAIN,

	/** Device shall leave Domain */
	DRM_RESULT_CODE_NOT_A_MEMBER,

	/** Means that device is not using correct protocol, most likely
	 * because server has been updated since device was manufactured.
	 * The device shall notify user to check for updates or fail gracefully.
	 */
	DRM_RESULT_CODE_PROTOCOL_VERSION_MISMATCH,

	/** User shall always be authenticated before making license acquisitions.
	 *  If this error happens, device shall notify user to contact
	 *  customer service.
	 */
	DRM_RESULT_CODE_UNKNOWN_ACCOUNTID,

	/** Device shall follow redirect. */
	DRM_RESULT_CODE_PROTOCOL_REDIRECT,

	/** Service specific Server errors */
	DRM_RESULT_CODE_SERVICE_SPECIFIC,
} drm_web_server_result_code_e;

/**
 * @enum drm_initiator_type
 * @brief DRM Initiator type.
 */
typedef enum {
	DRM_INITIATOR_TYPE_NONE = -1,
	DRM_INITIATOR_TYPE_INITIATOR_URL = 0,
	DRM_INITIATOR_TYPE_LICENSE_ACQ,
	DRM_INITIATOR_TYPE_JOIN_DOMAIN,
	DRM_INITIATOR_TYPE_LEAVE_DOMAIN
} drm_initiator_type;

/**
 * @struct drm_content_info_s
 * @brief DRM content info structure.
 */
typedef struct {
	/**< Author of original content */
	char author[DRM_MAX_LEN_AUTHOR];

	/**< Copyright information */
	char copyright[DRM_MAX_LEN_COPYRIGHT];

	/**< Content information */
	char description[DRM_MAX_LEN_DESCRIPTION];

	char icon_uri[DRM_MAX_LEN_ICON_URI];			/**< Icon URI */
	char info_url[DRM_MAX_LEN_INFO_URL];			/**< Information URL */
	char content_url[DRM_MAX_LEN_CONTENT_URL];	/**< Content URL */
	char rights_url[DRM_MAX_LEN_RIGHTS_URL];		/**< Rights URL */
	char title[DRM_MAX_LEN_TITLE];				/**< Content Title */

	/**< Original MIME type */
	char mime_type[DRM_MAX_LEN_MIME];
	char content_id[DRM_MAX_LEN_CID];			/**< Content ID */

} drm_content_info_s;

/**
 * @struct drm_file_oma_info_s
 * @brief DRM (OMA)file info structure.
 */
typedef struct {
	drm_rights_version_e version;	/**< OMA DRM Rights Version */
	drm_method_type_e method; 		/**< OMA DRM Method type */
}drm_file_oma_info_s;

/**
 * @struct drm_file_pr_env_info_s
 * @brief DRM (PlayReady Envelope)file info structure.
 */
typedef struct {
	/**< Original content file name inside Playready - Envelope Contents */
	char org_file_name[DRM_MAX_LEN_FILEPATH];

	/**< Original content file size inside Playready - Envelope Contents */
	unsigned int org_file_size;
}drm_file_pr_env_info_s;

/**
 * @struct drm_file_sapps_info_s
 * @brief DRM (SAPPS)file info structure.
 */
typedef struct {
	char content_id[DRM_MAX_LEN_CID];			/**< Content ID */
	char rights_url[DRM_MAX_LEN_RIGHTS_URL];	/**< Rights URL */
} drm_file_sapps_info_s;

/**
 * @struct drm_file_info_s
 * @brief DRM file info structure.
 */
typedef struct {
	drm_file_oma_info_s oma_info;		/**< OMA DRM file info */
	drm_file_pr_env_info_s pr_env_info;	/**< PlayReady
												Envelope file info */
	drm_file_sapps_info_s sapps_info;	/**< SAPPS file info */
} drm_file_info_s;

/**
 * @struct drm_constraint_type_s
 * @brief DRM Constraint type structure.
 */
typedef struct {
	int is_unlimited;		/**< Unlimited constraints */
	int is_count;			/**< Count constraint present/not present */
	int is_datetime;		/**< Datetime constraint present/not present */
	int is_interval;		/**< Interval constraint present/not present */
	int is_timedcount;		/**< TimedCount constraint present/not present */
	int is_accumulated;		/**< Accumulated constraint present/not present */
	int is_individual;		/**< Individual constraint present/not present */
	int is_system;			/**< System constraint present/not present */
} drm_constraint_type_s;

/**
 * @struct drm_constraint_info_s
 * @brief DRM Constraint info structure.
 */
typedef struct {

	/**< Constraint type*/
	drm_constraint_type_s const_type;

	/**< Original Count */
	int original_count;

	/**< Remaining Count */
	int remaining_count;

	/**< Start Time */
	/*
	 * As per definition of struct tm:-
	 * int    tm_sec   seconds [0,61]
	 * int    tm_min   minutes [0,59]
	 * int    tm_hour  hour [0,23]
	 * int    tm_mday  day of month [1,31]
	 * int    tm_mon   month of year [0,11]
	 * int    tm_year  years since 1900
	 * int    tm_wday  day of week [0,6] (Sunday = 0)
	 * int    tm_yday  day of year [0,365]
	 * int    tm_isdst daylight savings flag
	 *
	 */

	/* if tm_year = 109 then it means actual year = 109 + 1900 = 2009
	 * if tm_mon = 0 then it means actual month = 0 + 1 = 1 = January
	 * if tm_mon = 1 then it means actual month = 1 + 1 = 2 = Feb
	 * Other parameters doesn't need any manipulation
	 * if tm_mday = 5 then it means day of the month = 5
	 */
	struct tm start_time;

	/**< End time */
	/*
	 * As per definition of struct tm:-
	 * int    tm_sec   seconds [0,61]
	 * int    tm_min   minutes [0,59]
	 * int    tm_hour  hour [0,23]
	 * int    tm_mday  day of month [1,31]
	 * int    tm_mon   month of year [0,11]
	 * int    tm_year  years since 1900
	 * int    tm_wday  day of week [0,6] (Sunday = 0)
	 * int    tm_yday  day of year [0,365]
	 * int    tm_isdst daylight savings flag
	 *
	 */

	/* if tm_year = 109 then it means actual year = 109 + 1900 = 2009
	 * if tm_mon = 0 then it means actual month = 0 + 1 = 1 = January
	 * if tm_mon = 1 then it means actual month = 1 + 1 = 2 = Feb
	 * Other parameters doesn't need any manipulation
	 * if tm_mday = 5 then it means day of the month = 5
	 */
	struct tm end_time;

	/**< Interval Time */
	/*
	 * In interval time calculation, no need to manipulate it.
	 * e.g if tm_year = 109 then it means actual year = 109.
	 * It means license constraint says that content can be consumed in 109 years.
	 *
	 * e.g:-
	 * tm_year = 1
	 * tm_mon = 0
	 * tm_mday = 0
	 * tm_hour = 1
	 * tm_min = 10
	 * tm_sec = 40
	 *
	 * It means content has validity for 1 year, 1 hour, 1 minute & 40 seconds.
	 */
	struct tm interval_time;

	/**< Timed original count */
	int timed_original_count;

	/**< Timed Remaining count */
	int timed_remaining_count;

	/**< Timer attribute of Timed-count constraint */
	int timed_count_timer;

	/**< Accumulated original time in seconds */
	int accumulated_original_seconds;

	/**< Accumulated remaining time in seconds */
	int accumulated_remaining_seconds;

	/**< individual identity type */
	drm_constraint_identity_type_e individual_identity_type;

	/**< individual identity */
	char individual_id[DRM_MAX_LEN_INDIVIDUAL_IDENTITY];

	/**< system identity type */
	drm_constraint_identity_type_e system_identity_type;

	/**< system identity */
	char system_id[DRM_MAX_LEN_SYSTEM_IDENTITY];
} drm_constraint_info_s;

/**
* @struct drm_action_allowed_data_s
* @brief DRM Action Allowed structure.
*/
typedef struct {
	/**< File Path */
	char file_path[DRM_MAX_LEN_FILEPATH];
	/**< Additional input data */
	int data;
}drm_action_allowed_data_s;

/**
* @struct drm_secure_clock_data_s
* @brief DRM secure clock data structure.
*/
typedef struct {
	/** Flag to inform whether secure clock is SET or NOT SET
	 * is_secure_clock_set = 0 => Secure clock NOT SET.
	 * is_secure_clock_set = 1 => Secure clock is SET.
	 */
	int is_secure_clock_set;

	/** Secure clock data */
	struct tm secure_clock;
}drm_secure_clock_data_s;

/**
 * @struct drm_transaction_id_info_s
 * @brief DRM Transaction tracking ID structure.
 */
typedef struct {
	/* transaction ID value*/
	char tr_id[DRM_MAX_SIZE_TRANSACTION_ID];

	/*
	 * length of Transaction ID string.
	 * The value zero(0) indicates that transaction id is not available
	 */
	unsigned int tr_id_len;
}drm_transaction_id_info_s;

/**
 * @struct drm_code_info_s
 * @brief DRM DivX (Registration / De-registration)Code information structure.
 */
typedef struct {
	/** Code */
	char code[DRM_MAX_SIZE_DIVX_CODE];

	/**
	 * length of Code.
	 * The value zero(0) indicates that Code is not available.
	 */
	unsigned int code_len;
}drm_code_info_s;

/**
 * @struct drm_unregister_info_s
 * @brief DRM Unregister Information structure.
 */
typedef struct {
	/** file path to be unregistered */
	char file_path[DRM_MAX_LEN_FILEPATH];

	/*
	 * Flag to inform whether license also need to be removed
	 * remove_license = 0 => Do not remove License.
	 * remove_license = 1 => Remove License.
	 */
	int remove_license;
}drm_unregister_info_s;

/**
 * @struct 	drm_user_operation_info_s
 * @brief 	DRM operation information structure.
 */
typedef struct {
	/** Type of OPERATION */
	drm_operation_type_e operation_type;

	/** Status of OPERATION */
	drm_operation_status_e operation_status;
} drm_user_operation_info_s;

/**
 * Function pointer to handle DRM operation notifications
 *
 * @param[out]	operation_info	operation information .
 * @param[out]	output_data		Output data specific to operation.
 * @return		None
 * @see
 * @since      	0.1
 */
typedef void (*drm_operation_cb)(drm_user_operation_info_s *operation_info,
		void *output_data);

/**
 * @struct 	drm_operation_cb_s
 * @brief 	DRM Operation callback structure.
 * @remark 	Currently one member but new callback can be added depending on
 * 			requirements.
 */
typedef struct {
	/** Callback */
	drm_operation_cb callback;
}drm_operation_cb_s;

/**
 * @struct drm_register_lic_info_s
 * @brief DRM License register Information structure.
 */
typedef struct {
	/** Pointer to license buffer data */
	unsigned char lic_data[DRM_MAX_LEN_LICENSE_DATA];

	/** license buffer data length */
	unsigned int lic_data_len;

	/** license version (OMA DRM v1 or OMA DRM v2) */
	drm_rights_version_e lic_version;

	/** Source of ROAP Initialization */
	drm_roap_init_src_e roap_init_src;

	/** Callback for status update */
	drm_operation_cb_s operation_callback;
}drm_register_lic_info_s;

/**
 * @struct drm_register_lic_resp_s
 * @brief DRM License register Output parameter.
 */
typedef struct {

	/** Content ID */
	char cid[DRM_MAX_LEN_CID];

}drm_register_lic_resp_s;

/**
 * @struct 	drm_custom_data_info_s
 * @brief 	DRM Custom Data Information.
 */
typedef struct {
	char app_id[DRM_MAX_LEN_APP_ID + 1]; 			/** App ID */
	char user_guid[DRM_MAX_LEN_USER_GUID +1]; 	/** User GID */
	char device_id[DRM_MAX_LEN_DEVICE_ID + 1];	 	/** Device ID */
	char order_id[DRM_MAX_LEN_ORDER_ID + 1]; 			/** Order ID */
	char service_id[DRM_MAX_LEN_SERVICE_ID + 1]; 		/** Service ID */
	char account_id[DRM_MAX_LEN_ACCOUNT_ID + 1]; 		/** Account ID */
} drm_custom_data_info_s;

/**
 * @struct drm_initiator_info_s
 * @brief DRM License Initiator Information structure.
 */
typedef struct {
	/** Pointer to Initiator URL */
	char initiator_url[DRM_MAX_LEN_INITIATOR_URL];

	/** Initiator URL length */
	unsigned int initiator_url_len;

	/** Callback for status update */
	drm_operation_cb_s operation_callback;

	/** Initiator Type */
	drm_initiator_type init_type;

	/** Custom Data */
	drm_custom_data_info_s custom_data;
}drm_initiator_info_s;

/**
 * @struct	drm_web_server_resp_data_s
 * @brief	DRM Web Server Response Data After submitting Initiator URL Information.
 */
typedef struct {
    /** Content URL. Application can download content using this URL if available*/
	char content_url[DRM_MAX_LEN_CONTENT_URL];

	/** Server Result Code */
	drm_web_server_result_code_e result_code;
} drm_web_server_resp_data_s;

/**
 * Function pointer to handle DRM Roap Notifications
 *
 * @param[out]	cbParam				Parameter
 * @param[out]	appSessionData		Application Session Data
 * @param[out]	agentSessionData	DRM Agent Session Data
 * @return		None
 * @see
 * @since      	0.1
 */
typedef void (*drm_roap_service_cb) (void *cbParam,    /**<parameter */
					       void *appSessionData,   /**<application session data */
					       void *agentSessionData   /**<DRM agent session data */
	    );

/**
* Type Definition Template
*/
typedef drm_roap_service_cb drm_roap_notify_cb;
/**
* Type Definition Template
*/
typedef drm_roap_service_cb drm_roap_consent_cb;
/**
* Type Definition Template
*/
typedef drm_roap_service_cb drm_roap_result_cb;

/**
 * @struct 	drm_roap_notification_cb_s
 * @brief 	DRM Roap Notification callback structure.
 */
typedef struct {
	drm_roap_notify_cb progressNotify;				    /** Progress Notify */
	drm_roap_consent_cb userConsent;				    /** User Consent */
	drm_roap_result_cb roapResult;				     	/** Roap Result */
} drm_roap_notification_cb_s;

/**
 * Function pointer to handle Start of Content download
 *
 * @param[out]	appSessionData	App Session Data.
 * @return		int
 * @see
 * @since      	0.1
 */
typedef int (*drm_content_start_download_cb) (void *appSessionData);

/**
 * Function pointer to handle Progress of ODF download
 *
 * @param[out]	pData			Data
 * @param[out]	DataLen			Data length
 * @param[out]	appSessionData	App Session Data.
 * @return		int
 * @see
 * @since      	0.1
 */
typedef int (*drm_content_progress_download_cb) (const void *pData,
						    unsigned int DataLen,
						    void *appSessionData);

/**
 * Function pointer to handle Start of ODF download
 *
 * @param[out]	appSessionData	App Session Data.
 * @return		int
 * @see
 * @since      	0.1
 */
typedef int (*drm_content_finish_download_cb) (void *appSessionData);

/**
 * @struct 	drm_roap_notification_cb_s
 * @brief 	DRM Roap Notification callback structure.
 */
typedef struct {
	drm_content_start_download_cb start_download_cb;   		/** Start Download */
	drm_content_progress_download_cb progress_download_cb;  /** Progress Download */
	drm_content_finish_download_cb finish_download_cb; 		/** Finish Download */
} drm_content_download_cb_s;

/**
 * @struct 	drm_appsession_datatype_s
 * @brief 	DRM Application Session Datatype structure.
 */
typedef struct {
	int profileID;									 		/** Profile ID */
	int is_progressive_download;					 		/** Is Progressive Download */
	char pProxyAddress[DRM_MAX_LEN_IP_ADDR];				/** Proxy Address */
	drm_content_download_cb_s content_download_cb;					/** Content Download callback */
	unsigned int size_pData;								/** Size of additional data */
	void *pData;							 				/** Additional Data */
} drm_appsession_datatype_s;

/**
 * @struct 	drm_submit_roap_message_info_s
 * @brief 	DRM Submit Roap Message Info
 */
typedef struct {
    unsigned char* buffer;						/** Buffer that contains Trigger of PDU data */
    unsigned int buff_size;						/** Buffer size */
    drm_roap_notification_cb_s roap_notify;		/** Roap Notification callback */
    drm_roap_init_src_e roap_initiator;			/** Roap Initiator */
    drm_appsession_datatype_s app_session_data;	/** App Session Data */
} drm_submit_roap_message_info_s;

/**
 * @struct 	drm_submit_roap_user_content_info_s
 * @brief 	DRM Submit Roap User Consent Info
 */
typedef struct {
	drm_bool_type_e bConsent;					/** Result of User Consent */

	drm_bool_type_e bAddToTrustedWhiteList;		/** Result of User Consent */

	unsigned int size_agentdata;				/** Size of Agent Data */

	/** Specifies the pointer points to a ROAP session information that is used by DRM.
	 *  Must deliver agentData received through Callback completely intact
	 */
	void *agentdata;
} drm_submit_roap_user_consent_info_s;

/**
 * @struct 	drm_http_user_cancel_info_s
 * @brief 	DRM HTTP User Cancel Info
 */
typedef struct {
	unsigned int size_app_session_data;	/** Size of App Session Data */
	void *app_session_data;				/** App Session Data */
} drm_http_user_cancel_info_s;

/**
 * @struct 	drm_register_copy_file_info_s
 * @brief 	DRM Register Copy file Info.
 */
typedef struct {
	char src_file_path[DRM_MAX_LEN_FILEPATH];	/** Source File Path */
	char dest_file_path[DRM_MAX_LEN_FILEPATH];	/** Destination File Path */
} drm_register_copy_file_info_s;

/**
 * @struct 	drm_register_move_file_info_s
 * @brief 	DRM Register Move file Info.
 */
typedef struct {
	char src_file_path[DRM_MAX_LEN_FILEPATH];	/** Source File Path */
	char dest_file_path[DRM_MAX_LEN_FILEPATH];	/** Destination File Path */
} drm_register_move_file_info_s;

/**
 * @struct 	drm_register_setas_info_s
 * @brief 	DRM Register SetAs Info.
 */
typedef struct {
	char file_path[DRM_MAX_LEN_FILEPATH];	/** Source File Path */
	drm_setas_category_e setas_cat;			/** SetAs Category */
} drm_register_setas_info_s;

/**
 * @struct	drm_register_setas_resp_data_s
 * @brief	DRM Stack Response Data containing the GMT expiry
 * 		time corresponding to a given content
 */
typedef struct {
	struct tm 	time_expiry;						/** Expiry time*/
} drm_register_setas_resp_data_s;
/**
 * @struct 	drm_unregister_setas_info_s
 * @brief 	DRM Unregister SetAs Info.
 */
typedef struct {
	char file_path[DRM_MAX_LEN_FILEPATH];	/** Source File Path */
	drm_setas_category_e setas_cat;			/** SetAs Category */
} drm_unregister_setas_info_s;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /*__DRM_CLIENT_TYPES_H__ */
