#!/bin/bash
echo "enter the two numbers"
read a
read b
echo "enter the operator"
read c
case $c in 
	"+") echo "scale=2;`expr $a+$b`"|bc;;
    "-") echo "scale=2;`expr $a-$b`"|bc;;
    "*") echo "scale=2;`expr $a\*$b`"|bc;;
    "/") echo "scale=2;`expr $a/$b`"|bc;;
    "%") echo "scale=2;`expr $a%$b`"|bc;;
	*) echo "invalid operation"
esac