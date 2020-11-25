#!/bin/sh

gitignore=.gitignore
for file in `ls -1`
do
	if [ -z "$file" -o ! -d $file ]; then
		echo "file $file is not dir"
		continue
	fi
	exe=$file/$file
	if [ ! -f "$exe" ]; then
		echo "file $exe is not exist"
		continue
	fi
	if [ ! -x "$exe" ]; then
		echo "file $exe is not exe"
	else
		echo "dealing file $exe ..."
	fi
	ret=`grep $exe $gitignore`
	if [ -z "$ret" ]; then
		echo "add $exe to $gitignore"
		echo $exe >> $gitignore
		git rm $exe
	fi
done
