/*
 *  drm-client
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
 * @file 		drm_client_log.h
 * @brief       DRM Client log specific file.
 * @author      Harsha Shekar (h.shekar@samsung.com)
 * @version     0.1
 * @history     0.1: DRM LOG definitions.
 */

#ifndef __DRM_CLIENT_LOG_H__
#define __DRM_CLIENT_LOG_H__

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <linux/unistd.h>
#include <unistd.h>
#include <string.h>

#define drmclientgettid() (long int)syscall(__NR_gettid)
#define DRM_CLIENT_FILENAME(X)   (strrchr((char *)(X), '/') ? (char *)(strrchr((char*)(X), '/') + 1) : ((char *)(X)))

/*
 * Enable this flag to use internal logging mechanism
 */
//#define __DRM_CLIENT_USE_INTERNAL_LOGGING__

#ifdef __DRM_CLIENT_USE_INTERNAL_LOGGING__

/* Use internal logging mechanism */
extern const char *__progname;

#define	DRM_CLIENT_LOG(FMT, ARG...)	do{ \
	fprintf(stderr, "\n [EXE name=%s]:[PID=%ld]:[TID=%ld]:[%s:%s:%d]:", __progname, (long int)getpid(), drmclientgettid(), DRM_CLIENT_FILENAME(__FILE__), __func__, __LINE__);	\
	fprintf(stderr, FMT, ##ARG); \
	fprintf(stderr,"\n"); \
	}while(0);

#define	DRM_CLIENT_EXCEPTION(FMT, ARG...)	do{ \
	fprintf(stderr, "\n [EXE name=%s]:[PID=%ld]:[TID=%ld]:[%s:%s:%d]:[DRM-ERROR-CLIENT]:", __progname, (long int)getpid(), drmclientgettid(), DRM_CLIENT_FILENAME(__FILE__), __func__, __LINE__);	\
	fprintf(stderr, FMT, ##ARG); \
	fprintf(stderr,"\n"); \
	}while(0);

#define DRM_CLIENT_FRQ_LOG DRM_CLIENT_LOG

#else	/*__DRM_CLIENT_USE_INTERNAL_LOGGING__ */

/* Use DLOG logging mechanism */
#include "dlog.h"

/* DRM Client layer debug messages*/
#define TAG_DRM_CLIENT	"DRM_CLIENT"

/* DLOG Level
DEBUG  Debug message. - always compiled into application, but not logged at run time by default on release mode. on debug mode, this message will be logged at run time.
INFO  Information message - Normal operational messages. above of this priority will always be logged.
WARN  Warning messages - not an error, but indication that an error will occur if action is not taken
ERROR  Error message - indicate error.
*/

/* Client layer related logs */
#define DRM_CLIENT_LOG(FMT, ARG...)	 				SLOG(LOG_INFO,  TAG_DRM_CLIENT, "[PID=%ld]:[TID=%ld]:[%s:%s:%d]:"FMT, (long int)getpid(), drmclientgettid(), DRM_CLIENT_FILENAME(__FILE__), __func__, __LINE__,  ##ARG);
#define DRM_CLIENT_FRQ_LOG(FMT, ARG...) 			SLOG(LOG_DEBUG, TAG_DRM_CLIENT, "[PID=%ld]:[TID=%ld]:[%s:%s:%d]:"FMT, (long int)getpid(), drmclientgettid(), DRM_CLIENT_FILENAME(__FILE__), __func__, __LINE__, ##ARG);
#define DRM_CLIENT_EXCEPTION(FMT, ARG...) 			SLOG(LOG_ERROR, TAG_DRM_CLIENT, "[PID=%ld]:[TID=%ld]:[%s:%s:%d]:[DRM-ERROR-CLIENT]"FMT"\n", (long int)getpid(), drmclientgettid(), DRM_CLIENT_FILENAME(__FILE__), __func__, __LINE__, ##ARG);

#endif	/* __DRM_CLIENT_USE_INTERNAL_LOGGING__ */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif	/* __DRM_CLIENT_LOG_H__*/
