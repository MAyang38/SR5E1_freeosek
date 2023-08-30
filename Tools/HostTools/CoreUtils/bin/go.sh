#!/bin/bash
dir_to_go=`go.py $1`

if [[ -d "$dir_to_go" ]]
then
	cd "$dir_to_go"
else
	echo "$dir_to_go"
fi
