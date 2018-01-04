#!/bin/bash
a=$1
b=$2
while [[ ($a -le 0 )  || ( $b -le 0 ) ]]
do
	echo "enter positive number"
	read a
	read b
done
c=$(echo "scale=2;`expr $a/$b`"|bc )
echo "divion value $c "
