#!/bin/sh
#set -v
#set -x

#echo $#
[ $# -ne 2 ] && echo "Usage: $0 -c|-cpp oj_name" && exit -1
#echo $1
if [ "$1" != "-c" -a "$1" != "-cpp" ]; then
	echo "Usage: $0 -c|-cpp oj_name" && exit -1
fi

filename=$2
filename=${filename#*./}
echo "mkdir ./$filename and ./$filename/version"
mkdir $filename
mkdir ./$filename/version

if [ "$1" = "-c" ]; then
	echo "cp oj_model.c makefile_c to ./$filename/"
	echo "cp ./$filename/$filename.c to ./$filename/version/"
	cp ./oj_model.c ./$filename/$filename.c
	cp ./makefile_c ./$filename/makefile
	cp ./$filename/$filename.c ./$filename/version/

elif [ "$1" = "-cpp" ]; then
	echo "cp oj_model.cpp makefile_cpp to ./$filename/"
	echo "cp ./$filename/$filename.cpp to ./$filename/version/"
	cp ./oj_model.cpp ./$filename/$filename.cpp
	cp ./makefile_cpp ./$filename/makefile
	cp ./$filename/$filename.cpp ./$filename/version/
fi

echo "change target main to $filename in ./$filename/makefile"
sed -i "" "s/main/$filename/g" ./$filename/makefile

echo "cp version_control.sh to ./$filename"
cp ./version_control.sh ./$filename/

echo "touch ./$filename/input.txt"
touch ./$filename/input.txt
