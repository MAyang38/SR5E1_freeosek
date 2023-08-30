#!/bin/bash

# uncomment the below option to enable bash commands tracing
#set -x

# SR5E1 board list
sr5e1_board_list="evbe7000p"
#sr5e1_board_list="evbe7000p evbe7000s"

# set current workdir
MYCWD=$(pwd)

# Add host tools to PATH
export PATH="$MYCWD/../../../../Tools/HostTools/CoreUtils/bin:$PATH"
# Add default GHS compiler PATH
export PATH="/c/ghs/comp_202114:$PATH"

rm -fr "logs"
mkdir -p "logs"
cd ../..
test_dirs="$(find . -maxdepth 1 | grep TestID)"

build=debug
device=sr5e1
board_list=$sr5e1_board_list
toolchain="ARM"

echo "Logging is under the directory: logs"
echo ""
for tc in $toolchain ; do
	for board in $board_list ; do
		for tst in $test_dirs ; do
			echo "$(basename $tst) Setup: ${device} ${board} ${tc}"
			log_file="$MYCWD/logs/${tst}_${device}_${board}_${build}_${tc}.log"
			touch ${log_file}
			( cd ${tst} && make -j4 CONFIG_DEVICE=${device} CONFIG_BOARD=${board} TOOLCHAIN=${tc} purge ) > ${log_file} 2>&1
			if [ $? == 0 ]; then
			echo "$(basename $tst) Clean: SUCCESS"
			else
			echo "$(basename $tst) Clean: FAILED"
			echo "$(basename $tst)   Log: $(basename $log_file)"
			fi
			( cd ${tst} && make -j4 CONFIG_DEVICE=${device} CONFIG_BOARD=${board} TOOLCHAIN=${tc} ) >> ${log_file} 2>&1
			if [ $? == 0 ]; then
			echo "$(basename $tst) Build: SUCCESS"
			else
			echo "$(basename $tst) Build: FAILED"
			echo "$(basename $tst)   Log: $(basename $log_file)"
			fi
		done
	done
done

echo Done.
