#!/bin/bash
if [ $# -eq 0 ]
	then
	echo "error-number missing from command line arguement"
	echo "syntax: $0 number"
	echo "used to print multiplication table for given number"
n=$1
for i in 1 2 3 4 5 6 7 8 9 10
do
	echo "$1 * $i=`expr $1 * $i `"
done