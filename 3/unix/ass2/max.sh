#!/bin/bash
i=0
declare -a z
echo "enter five numbers"
read -a z
a=-1000
b=1000

echo "enter five numbers"
while [ $i -lt 5 ]
do
	if [ ${z[$i]} -gt $a ]
		then
		a=${z[$i]}
	fi
	if [ ${z[$i]} -lt $b ]
		then
		b=${z[$i]}
	fi
	((i=i+1))
done
i=0

while [ $i -lt 5 ]
do
	d=${z[$i]}
	j=0
	c=0
	while [ $j -lt 5 ]
	do
		if [ $d -eq ${z[$j]} ]
		then
		((c=c+1))
		fi
		((j=j+1))
	done

	echo "$d is repeated $c times"

	((i=i+1))
done
echo "maximum is $a minimum is $b "
