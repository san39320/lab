#!/bin/bash
principal=0
rate=0
time1=0
echo "enter the principal"
read principle
echo "enter the rate of interest"
read rate
echo "enter the time"
read time1
echo "simple interest is `expr $principle \* $rate \* $time1 / 1000 `"
rad=0
echo "enter the radius"
read rad
area=`expr $rad\*$rad\*22`
echo "area is" 
echo "scale=2;`expr $area/7 ` "|bc