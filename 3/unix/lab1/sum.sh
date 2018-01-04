#!/bin/bash
echo "enter the number"
read n
ans=0
if test $n -ge 0
	then
		for((i=1;i<=n;i++))
		do
		ans=`echo $ans+$i|bc`
		done
		echo "sum upto number is $ans"
	else
		echo"number is negetive"
fi
