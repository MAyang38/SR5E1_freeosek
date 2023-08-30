#!/bin/bash

ssdk_root=$1
ssdk_prj=$2
version=$4
cd ${ssdk_root}
relNote_path=${ssdk_prj}/releaseNote
modules_file=${relNote_path}/$3

echo -e "Generating ${relNote_path}/SESDK_${version}_ReleaseNote.txt....."
echo -e "*************************************************************************" > ${relNote_path}/SESDK_${version}_ReleaseNote.txt
echo -e "*                        SESDK_${version} Release Note                       *" >> ${relNote_path}/SESDK_${version}_ReleaseNote.txt
echo -e "*************************************************************************" >> ${relNote_path}/SESDK_${version}_ReleaseNote.txt
echo "" >> ${relNote_path}/SESDK_${version}_ReleaseNote.txt

tail -n +2 $modules_file | while IFS=,  read -r mod tag1 tag2_w
do
    tag2=`echo ${tag2_w} | sed 's/\\r//'`
    let "i = i + 1"
    pushd $mod > /dev/null
    cwd=`pwd`
    module=`basename ${cwd}`
    if [[ ${tag1} == VER* ]] && [[ ${tag2} == VER* ]]; then
	  echo -e "*** ${module} *** From ${tag1} To ${tag2} " >> ${relNote_path}/SESDK_${version}_ReleaseNote.txt
      echo "" >> ${relNote_path}/SESDK_${version}_ReleaseNote.txt
      ( git log --pretty="format: # %b" ${tag1}..${tag2} | sed '/Signed\-off\-by\:/d' ) >> ${relNote_path}/SESDK_${version}_ReleaseNote.txt
    fi
    if [[ ${tag1} != VER* ]] && [[ ${tag2} == VER* ]]; then
	  echo -e "*** ${module} *** To ${tag2} " >> ${relNote_path}/SESDK_${version}_ReleaseNote.txt
      echo "" >> ${relNote_path}/SESDK_${version}_ReleaseNote.txt
      ( git log --pretty="format: # %b" ${tag2} | sed '/Signed\-off\-by\:/d' ) >> ${relNote_path}/SESDK_${version}_ReleaseNote.txt
    fi
	popd > /dev/null
done

echo Done.