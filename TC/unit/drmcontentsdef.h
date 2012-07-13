/*
 *  drm-client TCs
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
 * @file 		drmcontentsdef.h
 * @brief       DRM TC Content MACROs.
 * @author      Mahendra Kumar Prajapat (mahendra.p@samsung.com)
 * @author      Harsha Shekar (h.shekar@samsung.com)
 * @version     0.1
 * @history     0.1: DRM TC Content MACROs
 */

#ifndef __DRM_CONTENTS_DEF_H__
#define __DRM_CONTENTS_DEF_H__

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus */

#include "drm_client.h"

#define FILE_PATH_MAX_SIZE (256)
/* Modify path to local tc_data on target */
#define DRM_CONTENT_PATH "/path/to/tc_data"

/*
 * Valid File paths
 */
#define FILE_PATH_VALID_FILE_OMA_1	DRM_CONTENT_PATH"/flourish_count5.dcf"
#define FILE_PATH_VALID_FILE_OMA_2	DRM_CONTENT_PATH"/download.jpg.dm-849344490.odf"
#define FILE_PATH_VALID_FILE_OMA_3	DRM_CONTENT_PATH"/4931_D2_AacpMetaDummy.o4a"
#define FILE_PATH_VALID_FILE_OMA_4	DRM_CONTENT_PATH"/4941_D2_VideoH264AACDummy.o4v"
#define FILE_PATH_VALID_FILE_OMA_5	DRM_CONTENT_PATH"/barimage_interval.dcf"
#define FILE_PATH_VALID_FILE_OMA_6	DRM_CONTENT_PATH"/MonkeyMadness_startend_time.dcf"
#define FILE_PATH_VALID_FILE_OMA_7	DRM_CONTENT_PATH"/pbarimage_timedcount.dcf"
#define FILE_PATH_VALID_FILE_OMA_8	DRM_CONTENT_PATH"/cupcake_play.dcf"

/*
 * This file will be generated as a part of DM to DCF conversion test-case
 */
#define FILE_PATH_VALID_FILE_OMA_9	DRM_CONTENT_PATH"/image_cd.dcf"

#define FILE_PATH_VALID_FILE_OMA_10	DRM_CONTENT_PATH"/3001_D1_Aac.dcf"

#define FILE_PATH_VALID_FILE_OMA_11	DRM_CONTENT_PATH"/temp/flourish_count5.dcf"

/*
 * This file will be generated as a part of DM to DCF conversion test-case
 */
#define FILE_PATH_VALID_FILE_OMA_12	DRM_CONTENT_PATH"/1202_F1_Jpg.dcf"


#define FILE_PATH_VALID_FILE_PR_1	DRM_CONTENT_PATH"/Jazz_Audio_OPLs0.pya"
#define FILE_PATH_VALID_FILE_PR_2	DRM_CONTENT_PATH"/MD_h264_V4AES.pyv"
#define FILE_PATH_VALID_FILE_PR_3	DRM_CONTENT_PATH"/ExpirationAudio1.pya"

#define FILE_PATH_VALID_FILE_PR_ENV_1	DRM_CONTENT_PATH"/krishna.eny"
#define FILE_PATH_VALID_FILE_PR_ENV_2	DRM_CONTENT_PATH"/jazz_audio_opls0.pye"


#define FILE_PATH_VALID_FILE_DIVX_1		DRM_CONTENT_PATH"/V19_HD720p10_ICT_00.avi"

/*
 * Invalid File paths
 */
#define INVALID_POINTER_OBJECT			NULL
#define FILE_PATH_INVALID_FILE_NULL		NULL
#define FILE_PATH_INVALID_FILE_EMPTY	""

#define FILE_PATH_INVALID_FILE_OMA_1	DRM_CONTENT_PATH"/flourish_count5.dr"
#define FILE_PATH_INVALID_FILE_OMA_2	DRM_CONTENT_PATH"/Flower1.jpg"
#define FILE_PATH_INVALID_FILE_OMA_3	DRM_CONTENT_PATH"/image_cd.dm"

#define FILE_PATH_INVALID_FILE_PR_1		DRM_CONTENT_PATH"/clr_jazz_AAC.asf"
#define FILE_PATH_INVALID_FILE_PR_2		DRM_CONTENT_PATH"/jazz.wma"

#define FILE_PATH_INVALID_FILE_PR_ENV_1		DRM_CONTENT_PATH"/krishna.jpg"

#define FILE_PATH_INVALID_FILE_DIVX_1		DRM_CONTENT_PATH"/sine_wave.avi"

/** Valid RO file paths
 *
 */
#define FILE_PATH_VALID_RO_FILE_OMA_1	DRM_CONTENT_PATH"/flourish_count5.dr"
#define FILE_PATH_VALID_RO_FILE_OMA_2	DRM_CONTENT_PATH"/3001_D1_Aac_3Counts.drc"

/** Invalid RO file paths
 *
 */
#define FILE_PATH_INVALID_RO_FILE_OMA_1	DRM_CONTENT_PATH"/flourish_count5.dcf"

/*
 * Valid License Initiators
 */
/* Jazz_Audio_OPLs0.pya */
#define LICENSE_INITIATOR_VALID_PR_FILE 			"http://playready.directtaps.net/pr/initiator.aspx?p=0&contentid=ZVXWl75xFUOdCY/tO8bLCA==&type=license&content=http://131.107.149.211/pr/media/1044/Jazz_Audio_OPLs0.pya"

/* DomainTestVideo1.pyv */
#define LICENSE_INITIATOR_VALID_PR_FILE_1			"http://playready.directtaps.net/pr/initiator.aspx?p=0&contentid=ybubwBx/XUidiUX3zdMRTg==&type=license&content=http://131.107.149.211/pr/media/1044/DomainTestVideo1.pyv"

/* DomainTestVideo1.pyv */
#define JOIN_DOMAIN_INITIATOR_VALID_PR_FILE_1		"http://playready.directtaps.net/pr/initiator.aspx?p=0&type=JOIN"

/* DomainTestVideo1.pyv */
#define LEAVE_DOMAIN_INITIATOR_VALID_PR_FILE_1		"http://playready.directtaps.net/pr/initiator.aspx?p=0&type=LEAVE"

/* DomainTestVideo1.pyv */
#define METERING_INITIATOR_VALID_PR_FILE_1			"http://playready.directtaps.net/pr/initiator.aspx?p=0&contentid=ybubwBx/XUidiUX3zdMRTg==&type=metering&content=http://131.107.149.211/pr/media/1044/DomainTestVideo1.pyv"

/* ExpirationAudio1.pya */
#define LICENSE_INITIATOR_VALID_PR_FILE_2			"http://playready.directtaps.net/pr/initiator.aspx?p=0&contentid=qTNJyCKLmUCdGpx1ZHQ0Aw==&type=license&content=http://131.107.149.211/pr/media/1044/ExpirationAudio1.pya"

/* MD_h264_V4AES.pyv */
#define LICENSE_INITIATOR_VALID_PR_FILE_3			"http://playready.directtaps.net/pr/initiator.aspx?p=0&contentid=ewIUg21KrEecS3qu8m9EMQ==&type=license&content=http://131.107.149.211/pr/media/1044/MD_h264_V4AES.pyv"

/* jazz_wma_Domain_No_Copy.pya */
#define LICENSE_INITIATOR_VALID_PR_FILE_4			"http://playready.directtaps.net/pr/initiator.aspx?p=1&contentid=fXZukDZR4kKMOIbSE+MuPg==&type=license&content=http://131.107.149.211/pr/media/1207/jazz_wma_Domain_No_Copy.pya"

/*
 * Invalid License Initiators
 */
#define INVALID_LICENSE_INITIATOR_PR_FILE_1			"http://playready.directtaps.net/prxx/initiatorxxxx.aspx?p=0&contentid=ZVXWl75xFUOdCY/tO8bLCA==&type=license&content=http://131.107.149.211/pr/media/1044/Jazz_Audio_OPLs0.pya"
#define INVALID_JOIN_DOMAIN_INITIATOR_1				"http://playready.directtaps.net/prxx/initiatorxxxx.aspx?p=0&type=JOIN"
#define INVALID_LEAVE_DOMAIN_INITIATOR_1			"http://playready.directtaps.net/prxx/initiatorxxxx.aspx?p=0&type=LEAVE"
#define INVALID_METERING_INITIATOR_1				"http://playready.directtaps.net/prxx/initiatorxxxx.aspx?p=0&contentid=ybubwBx/XUidiUX3zdMRTg==&type=metering&content=http://131.107.149.211/pr/media/1044/DomainTestVideo1.pyv"
#define INVALID_LICENSE_INITIATOR_PR_FILE_2			"http://playready.directtaps.net/pr/initiator.aspx?p=0&contentid=ZVXWl75xFUOdCY/tO8bLCA==&type=license&content=http://131.107.149.211/prxx/media/1044/Jazz_Audio_OPLs0xxxx.pya"


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __DRM_CONTENTS_DEF_H__ */
