#!/bin/bash

docs_dir=`pwd`
cd ../../../../
ssdk_top=`pwd`
cd ${docs_dir}

DOCS_VERSION=$1
doxyfile=$2
modules=$3
tests=$4
DOCS_OUTPUT_DIR=${docs_dir}/StellarESDK_Doc_${DOCS_VERSION}



cd ${ssdk_top}
temp=`echo ${ssdk_top} | sed 's/\/c/C:/'`
ssdk_top_w=`echo ${temp} | sed 's/\//\\\\/g'`
INPUT_MODULES=
for module in ${modules} ; do
  module_path=`find Modules -type d -name ${module}`
  module_path_w=`echo ${module_path} | sed 's/\//\\\\/g'`
  INPUT_MODULES="${INPUT_MODULES} ${ssdk_top_w}\\${module_path_w}"
done
for module in ${tests} ; do
  module_path=`find Projects -type d -name ${module}`
  module_path_w=`echo ${module_path} | sed 's/\//\\\\/g'`
  INPUT_MODULES="${INPUT_MODULES} ${ssdk_top_w}\\${module_path_w}"
done
cd ${docs_dir}

# Export variables used in doxyfile
export DOCS_VERSION
export INPUT_MODULES
export DOCS_OUTPUT_DIR

# Add documentation tools to PATH
PATH=${ssdk_top}/Tools/HostTools/Docs/Doxygen/bin:${ssdk_top}/Tools/HostTools/Docs/Graphviz/bin:${PATH}
export PATH

# Run doxygen
doxygen.exe ${doxyfile}
