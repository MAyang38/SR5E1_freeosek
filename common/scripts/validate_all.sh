#!/bin/bash

# uncomment the below option to enable bash commands tracing
#set -x

# Get current date and time, to be used as a prefix for log filenames. 
# Output format is "yyyy-mmm-dd_hh-mm" e.g. "2021-Oct-20_11-36"
DATE=`date +%Y-%b-%d_%H-%M`

echo "logs timestamp for this session is: ${DATE}"
echo ""


#######################################
# Variables
#######################################

# edit the follwing variables to set which boards and toolchains 
# are to be tested

# SR5E1 board list
#sr5e1_board_list="evbe7000p evbe7000s"
sr5e1_board_list="evbe7000p"

# Toolchains list
#toolchain="ARM GHS HIGHTEC ARMCLANG"
toolchain="ARM"

# build target default
build_target="Debug"

# set current working directory
MYCWD=$(pwd)

# Append host tools to PATH
export PATH="$MYCWD/../../../../Tools/HostTools/CoreUtils/bin:$PATH"

# Add default GHS compiler PATH
if [ -d /c/ghs/ARM_comp_202114 ]
  then 
    export PATH="/c/ghs/ARM_comp_202114:$PATH"
  else
    export PATH="/c/ghs/comp_202114:$PATH"
fi

mkdir -p "logs"

#create a file to log all the build results
log_summary_file="${MYCWD}/logs/${DATE}_build_report.log"
touch ${log_summary_file}

#create a file for a short summary of the results
shortlog="${MYCWD}/logs/${DATE}_summary.log"
touch ${shortlog}

echo "session summary: ${shortlog}"
echo ""
echo "Build report: ${log_summary_file}"
echo ""

# move to tests directory
cd ../..

# determine test list
test_dirs=`find . -maxdepth 1 | grep TestID`
#test_dirs="./TestID14 ./TestID15"

echo "tests to be built:"
echo "${test_dirs}"
echo ""


#######################################
# Functions
#######################################

#
# get_cmdline 
#
# retrieves the specific command line for each test
#
# parameters:
#   test name
#   build target
# 
function get_cmdline() {

  TESTNAME=$1
  MTARGET=$2

  # default command line
  CMDLINE="make -j4 TARGET_BUILD=${t_build} CONFIG_DEVICE=${device} CONFIG_BOARD=${board} TOOLCHAIN=${tc} ${MTARGET}" 

  # non-default command lines
  # TestID09 (dual core)
  if [ ${TESTNAME} = "./TestID09" ]; then 
    CMDLINE="make -j4 TARGET_BUILD=${t_build} CONFIG_DEVICE=${device} CONFIG_BOARD=${board} TOOLCHAIN=${tc} ${MTARGET}" 
    CMDLINE="make -j4 TARGET_BUILD=${t_build} CONFIG_DEVICE=${device} CONFIG_BOARD=${board} CONFIG_TARGET_CORE=core2 TOOLCHAIN=${tc} ${MTARGET}" 
  fi

  # TestID10 (dual core)
  if [ ${TESTNAME} = "./TestID10" ]; then 
    CMDLINE="make -j4 TARGET_BUILD=${t_build} CONFIG_DEVICE=${device} CONFIG_BOARD=${board} TOOLCHAIN=${tc} build_all" 
  fi

}


#
# do_clean 
#
# called by do_build
# performs the "make clean", calling make with the passed parameters
#
# parameters:
#   test directory
#   
# e.g. do_clean "${testdir}"
#
function do_clean {

	TDIR=$1	# test directory

	# call "make clean" 
	get_cmdline "${TDIR}" "clean" 
	( cd ${TDIR} && while CMD= read -r line ; do `echo $line`; done <<< "${CMDLINE}" ) > ${log_file} 2>&1
	if [ $? != 0 ]; then
	  echo "$(basename ${TDIR}) Clean: FAILED"
	  echo "$(basename ${TDIR}) Clean: FAILED" >> ${mainlog}
	  echo -n "    FAILED" >> ${shortlog}
	else
	  echo -n "    SUCCESS" >> ${shortlog}
	fi
					
}



#
# do_build 
#
# performs the actual builds, calling make with the passed parameters
#
# parameters:
#   toolchains list
#   boards list
#   test directories list
#   target build (Debug or Release)
#   summary log file
#   make target (clean, build or misra)
#   device name (e.g. sr5e1)
#   
# e.g. do_build "${toolchain}" "${sr5e1_board_list}" "${test_dirs}" debug ${log_summary_file} build sr5e1
#
function do_build {

	tchain=$1	# toolchains list
	b_list=$2	# boards list
	t_dirs=$3	# test directories list
	t_build=$4	# "Debug" or "Release"
	mainlog=$5	# summary log file
	tgt=$6		# "all" or "misra"
	device=$7	# device name  (e.g. "sr5e1")

	for tc in $tchain ; do
		for board in $b_list ; do
			echo "Setup: ${device} ${board} ${tc} ${t_build}"
			echo "Setup: ${device} ${board} ${tc} ${t_build}" >> ${mainlog}
			
			echo "======================================================" >> ${shortlog}
			echo "[${device}] [${board}] [${tc} compiler] [${t_build}]" >> ${shortlog}
			echo "======================================================" >> ${shortlog}
			echo "TestID	     Clean	  Build " >> ${shortlog}
			echo "------------------------------------------------------" >> ${shortlog}
			
			for tst in $t_dirs ; do
				log_file="$MYCWD/logs/${tst}_${t_build}_${device}_${board}_${tgt}_${tc}_${DATE}.log"
				touch ${log_file}
				keep_log=1
				echo -n "$(basename $tst) " >> ${shortlog}

				# call "make clean" first
				do_clean "${tst}"
				
				# now use the correct build target ("all" or "misra")
				get_cmdline "${tst}" "${tgt}"
				echo build command: >> ${log_file}
				echo -e "${CMDLINE}" >> ${log_file}
				echo ""  >> ${log_file}
				( cd ${tst} &&  while CMD= read -r line ; do `echo $line`; done <<< "${CMDLINE}" ) >> ${log_file} 2>&1
				if [ $? == 0 ]; then
				  echo "$(basename $tst) Build: SUCCESS"
				  echo "    SUCCESS" >> ${shortlog}
				  echo "$(basename $tst) Build: SUCCESS" >> ${mainlog}
				  keep_log=0
				else
				  echo "$(basename $tst) Build: FAILED"
				  echo "    FAILED" >> ${shortlog}
				  echo "$(basename $tst) Build: FAILED" >> ${mainlog}
				fi
				grep -i "error" ${log_file} >> ${mainlog}
				# append the contents of "misra.txt" file(s) to log file
				# but only when the make target is misra.
				# some tests may generate more than one "misra.txt" files
				MLOG=`grep -o -e "build.*misra.txt" ${log_file}`
				for MFILE in $MLOG ; do
					if [ -f "${tst}/${MFILE}" -a ${tgt} = misra ]; then
					cat "${tst}/${MFILE}" >> ${mainlog}
					# count misra errors and warnings for shortlog
					NOTE=`cat "${tst}/${MFILE}" | grep " Note " | wc -l`
					INFO=`cat "${tst}/${MFILE}" | grep " Info " | wc -l`
					ERRS=`cat "${tst}/${MFILE}" | grep " Error " | wc -l`
					WARNS=`cat "${tst}/${MFILE}" | grep " Warning " | wc -l`
					echo "  ${MFILE}" >> ${shortlog}
					echo "    misra Errors:   ${ERRS}" >> ${shortlog}
					echo "    misra Warnings: ${WARNS}" >> ${shortlog}
					echo "    misra Notes:    ${NOTE}" >> ${shortlog}
					echo "    misra Infos:    ${INFO}" >> ${shortlog}
					fi
				done
				# remove log file if build is successful
				if [ ${keep_log} == 0 ]; then
					rm ${log_file}
				fi
			done
			echo "" >> ${shortlog}
		done
	done
}


#######################################
# BUILD
#######################################

echo "BUILD test started"
echo ""

echo "Session started: ${DATE}" >> ${log_summary_file} 
echo "" >> ${log_summary_file}

echo "Session started: ${DATE}" >> ${shortlog} 
echo "" >> ${shortlog}

echo "make is:" >> ${log_summary_file}
echo `which make` >> ${log_summary_file}
echo "" >> ${log_summary_file}

echo "path is:" >> ${log_summary_file}
echo $PATH >> ${log_summary_file}
echo "" >> ${log_summary_file}

echo "Build results:" >> ${log_summary_file}
echo "" >> ${log_summary_file}

echo "Build results:" >> ${shortlog}
echo "" >> ${shortlog}


do_build "${toolchain}" "${sr5e1_board_list}" "${test_dirs}" ${build_target} ${log_summary_file} all sr5e1

build_target="Release"

do_build "${toolchain}" "${sr5e1_board_list}" "${test_dirs}" ${build_target} ${log_summary_file} all sr5e1

#######################################
# MISRA
#######################################

#create a file to log all the MISRA results
log_summary_file="${MYCWD}/logs/${DATE}_misra_report.log"
touch ${log_summary_file}

build_target="Debug"

echo ""
echo "MISRA report: ${log_summary_file}"
echo ""
echo "MISRA test started"

echo "Session started: ${DATE}" >> ${log_summary_file} 
echo "" >> ${log_summary_file}

echo "make is:" >> ${log_summary_file}
echo `which make` >> ${log_summary_file}
echo "" >> ${log_summary_file}

echo "path is:" >> ${log_summary_file}
echo $PATH >> ${log_summary_file}
echo "" >> ${log_summary_file}

echo "MISRA check results:" >> ${log_summary_file}
echo "" >> ${log_summary_file}

echo "" >> ${shortlog}
echo "MISRA check results:" >> ${shortlog}
echo "" >> ${shortlog}

do_build "${toolchain}" "${sr5e1_board_list}" "${test_dirs}" ${build_target} ${log_summary_file} misra sr5e1

echo ""
echo "Done."

