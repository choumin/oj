#!/bin/sh
src_file=`pwd`
src_file=${src_file##*/}
dest_file=$src_file
ver=`date +%F-%k-%M`
dest_file=$dest_file-$ver
mv $src_file.c ./version/$dest_file.c
cp ./version/$src_file.c ./$src_file.c
 
