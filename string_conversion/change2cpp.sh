#!/bin/sh
sed -i "" 's/gcc/g++/g' makefile
sed -i "" 's/.c/.cpp/g' makefile'
for file in `find ./ -name "*.c"`
do 
	mv $file ${file}pp
done
sed -i "" 's/.c/.cpp/g' version_control.sh
