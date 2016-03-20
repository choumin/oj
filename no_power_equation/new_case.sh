#!/bin/sh
[ $# -ne 1 ] && echo "Usage: $0 number" && exit -1
number=$1
len=${#number}
i=0
while [[ $i -lt $len ]] 
do
 bit=${number:$i:1}
 sum=$[sum+bit]
 i=$i+1
done
tmp=$[number+sum]
let ret=number*tmp
echo $ret && echo $ret > ./input.txt
