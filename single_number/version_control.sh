#!/bin/sh
function error_exit()
{
 echo "Usage : $1 -o|-r" 
 exit -1
}
[ $# -ne 1 ] && error_exit $0
[ "$1" != "-o" ] && [ "$1" != "-r" ] && error_exit $0

src_file=`pwd`
src_file=${src_file##*/}
dest_file=$src_file
ver=`date +%F-%k-%M`
dest_file=$dest_file-$ver

cp $src_file.c ./version/$dest_file.c
[ "$1" = "-o" ] && cp ./version/$src_file.c ./$src_file.c

