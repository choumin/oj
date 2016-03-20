#!/bin/sh
[ $# -ne 2 ] && echo "Usage : $0 src_pro dest_pro" && exit -1
[[ ! -d $1 ]] && echo "src_pro doesn't exist" && exit -1 
src=$1
src=${src#./}
src=${src%/}
dst=$2
dst=${dst#./}
dst=${dst%/}
mv $src $dst
for file in `find ./$dst -name "*.c*"`
do
	dst_file=${file/$src/$dst}
	mv $file $dst_file
	sed -i "" "s/$src/$dst/g" makefile
done
