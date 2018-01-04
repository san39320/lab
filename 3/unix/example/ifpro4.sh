#!/bin/bash
osch=0
echo "1.linux(red hat)"
echo "2.unix(sun os)"
echo "select the choice of OS 1 or 2?"
read osch
if [ $osch -eq 1 ]
	then
	echo "you like linux (red hat)"
elif [ $osch -eq 2 ];then
	echo "you like unix(sun os)"
else
	echo "what you dont like unix/linux"
fi