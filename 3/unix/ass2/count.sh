#!/bin/bash

declare -a z
read -a z
i=0
a=0
b=0
c=0
while [ $i -lt 10 ]
do
	if [ ${z[$i]} -gt 0 ]
		then
		((a=a+1))
		
	fi
	if [ ${z[$i]} -lt 0 ]
		then
		((b=b+1))
	fi
	if [ ${z[$i]} -eq 0 ]
		then
		((c=c+1))
	fi
	((i=i+1))
done
echo "positive: $a negativw: $b zero: $c"

echo ${z[@]} | tr ' ' '\n' | sort -n