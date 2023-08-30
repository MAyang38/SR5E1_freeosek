#!/bin/bash

pack_dir=`pwd`
cd $1
ssdk_top=`pwd`
pack_name="pack.lst"

input_list="*.mk *.S *.c *.h *.md *.project Makefile *.ld *.E"
exclude_list=pclint\|misra.mk\|pack.mk\|clang.mk

infra="BuildSystem"
basis="Boot Board Clock IRQ MCU SARADC SPI UART DMA GPIO OSAL"
tests="SDKTests"

# Set release file name
release_file=$2

# Cleanup
rm -f ${pack_dir}/${pack_name}
rm -f ${pack_dir}/${pack_name}.a
rm -f ${pack_dir}/${pack_name}.b

# Create temporary file
touch ${pack_dir}/${pack_name}.a


cd ${ssdk_top}

for ext in ${input_list} ; do
  find . -name ${ext} >> ${pack_dir}/${pack_name}.a
done

cd ${pack_dir}

# Create package file list
touch ${pack_dir}/${pack_name}.b

for module in ${infra} ; do
  cat ${pack_dir}/${pack_name}.a | grep ${module} >> ${pack_dir}/${pack_name}.b
done

for module in ${basis} ; do
  cat ${pack_dir}/${pack_name}.a | grep "/"${module}"/" >> ${pack_dir}/${pack_name}.b
done

for module in ${tests} ; do
  cat ${pack_dir}/${pack_name}.a | grep "/"${module}"/" >> ${pack_dir}/${pack_name}.b
done

# Exclude some files
touch ${pack_dir}/${pack_name}
for ext in $3 ; do
  exclude_list=${exclude_list}\|${ext}
done
cat ${pack_dir}/${pack_name}.b | egrep -v -e ${exclude_list} >> ${pack_dir}/${pack_name}

# Remove "./" from the module paths
sed -i 's/\.\///g' ${pack_dir}/${pack_name}

# Retrieve git information
#cd ${ssdk_top}
#all_repos=`repo list -p`
#for val in ${all_repos} ; do
#  repo_name=`basename ${val}`
#  proj_name=`echo ${val} | tr -d '\r' | tr -d '\n'`
#  for module in ${basis} ; do
#    if [ ${repo_name} == ${module} ] ; then
#      echo ${proj_name}
#	  cd ${proj_name}
#	  git log -1 --pretty=%h
#	  git describe --tags
#	  cd ${ssdk_top}
#	fi
#  done
#done
#cd ${pack_dir}


# 7zip seems to be buggy in case of file list (multiple file detected)
# Keep disabled.
#cd ${ssdk_top}
#7z.exe a -y -sfx -spf -ssc ${pack_dir}/release.zip @${pack_dir}/${pack_name}"
#cd ${pack_dir}
 

# Create linux style archive
tar \
	--create \
	--auto-compress \
	--directory=${ssdk_top} \
	--files-from=${pack_dir}/${pack_name} \
	--file=${pack_dir}/${release_file}.tar
