#!/bin/sh
sed -i "" 's/g++/gcc/g' makefile
sed -i "" 's/.cpp/.c/g' makefile
for file in `find ./ -name "*.cpp"`
do
	c_file=${file%pp}
	
	[ -z "$c_file" ] && continue
	mv $file $c_file
done
sed -i "" 's/.cpp/.c/g' version_control.sh
