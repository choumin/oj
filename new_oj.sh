#!/bin/sh
[ $# -ne 3 ] && echo "Usage: $0 -c|-cpp oj_name" && exit -1

if 

filename=$1
filename=${filename#*./}
mkdir $filename
cp ./version_control.sh ./$filename/
cp ./oj_model.c ./$filename/$filename.c
cp ./makefile ./$filename/
sed -i "" "s/main/$filename/g" ./$filename/makefile
touch ./$filename/input.txt
mkdir ./$filename/version
cp ./$filename/$filename.c ./$filename/version/
