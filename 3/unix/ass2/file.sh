#!/bin/bash
a=0
b=0
for i in `ls`
do
	if test -f $i
		then
		((a=a+1))
	fi
	if test -d $i 
		then
		((b=b+1))
	fi
done
echo "files : $a directories : $b "
i=0
echo "------FILES------"
for i in `ls`
do
	if test -f $i
		then
		echo $i
	fi
done
echo "-------directories--------"
i=0
for i in `ls`
do
	if test -d $i 
		then
		echo $i
	fi
done