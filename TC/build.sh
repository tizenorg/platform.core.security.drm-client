#!/bin/sh

#Modify path to local TETware folder
export TET_INSTALL_PATH=/path/to/TETware
if [ ! -d "$TET_INSTALL_PATH" ]; then
	echo "TET_INSTALL_PATH = $TET_INSTALL_PATH doesn't exist"
	echo "Modify this script build.sh with tetware directory"
	exit
fi

export TET_TARGET_PATH=$TET_INSTALL_PATH/tetware-target
export PATH=$TET_TARGET_PATH/bin:$PATH
export LD_LIBRARY_PATH=$TET_TARGET_PATH/lib/tet3:$LD_LIBRARY_PATH
export TET_ROOT=$TET_TARGET_PATH

export TET_SUITE_ROOT=`pwd`
#FILE_NAME_EXTENSION=`date +%s`

RESULT_DIR=results
#HTML_RESULT=$RESULT_DIR/build-tar-result-$FILE_NAME_EXTENSION.html
#JOURNAL_RESULT=$RESULT_DIR/build-tar-result-$FILE_NAME_EXTENSION.journal

DATE=$(date +'%Y.%m.%d_%H.%M')
HTML_RESULT=$RESULT_DIR/drm_tc_build_result_$DATE.html
JOURNAL_RESULT=$RESULT_DIR/drm_tc_build_result_$DATE.journal

mkdir -p $RESULT_DIR

tcc -c -p ./
tcc -b -j $JOURNAL_RESULT -p ./

# Log Levels
# LOG_LEVEL=3 prints only tet_infoline
# LOG_LEVEL=7 prints only tet_infoline & tet_printf
LOG_LEVEL=7
grw -c $LOG_LEVEL -f chtml -o $HTML_RESULT $JOURNAL_RESULT

# Copy the results outside drm-client
echo "Copy the results outside drm-client & in folder drm_tc_results_client"
mkdir -p ../../drm_tc_results_client
cp $RESULT_DIR/drm_tc_build_result_$DATE.html ../../drm_tc_results_client/
