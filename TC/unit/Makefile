CC ?= gcc

TARGETS = 	utc_drmclient_drm_is_drm_file_func \
			utc_drmclient_drm_process_request_func \
			utc_drmclient_drm_get_file_type_func \
			utc_drmclient_drm_get_license_status_func \
			utc_drmclient_drm_get_content_info_func \
			utc_drmclient_drm_get_file_info_func \
			utc_drmclient_drm_get_constraint_info_func \
			utc_drmclient_drm_is_action_allowed_func \
			utc_drmclient_drm_get_data_func

PKGS = drm-client

LDFLAGS = `pkg-config --libs $(PKGS)`
LDFLAGS += $(TET_ROOT)/lib/tet3/tcm_s.o
LDFLAGS += -L$(TET_ROOT)/lib/tet3 -ltcm_s
LDFLAGS += -L$(TET_ROOT)/lib/tet3 -lapi_s

CFLAGS = -I. `pkg-config --cflags $(PKGS)`
CFLAGS += -I$(TET_ROOT)/inc/tet3
CFLAGS += -Wall

all: $(TARGETS)

$(TARGETS): %: %.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf $(TARGETS) ../results ../tet_tmp_dir
