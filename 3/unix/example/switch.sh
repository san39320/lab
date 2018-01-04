#!/bin/bash
if [ -z $1 ]
	then
	echo "***unknown vehicle***"
elif [ -n $1 ];then
	rental=$1
fi
case $rental in 
	"car") echo "for $rental Rs.20 /km ";;
	"van") echo "for $rental Rs.10  /km";;
	"jeep") echo "for $rental Rs.5 /km";;
	"bycycle") echo "for $rental Rs.20 paisa /km";;
    *) echo "sorry i cannot get a $rental for u";;
esac