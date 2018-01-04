#!/bin/bash
echo "enter the basic"
read basic
dp=`echo ".5 * $basic " | bc`
b=`echo " $basic + $dp " | bc`

da=`echo " .35 * $b " | bc`

hra=`echo " .08 * $b " | bc`

ma=`echo " .03 * $b " | bc`

pf=`echo " .1 * $b " | bc`

salary=`echo " $basic + $dp + $da + $hra + $ma - $pf " | bc`
echo "salary is $salary" 
