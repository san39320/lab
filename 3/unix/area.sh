#!/bin/bash
echo "enter the principal"
read principal
echo "enter the rate"
read rate
echo "enter the time"
read time1
z=`echo $principal\*$rate\*$time1/100|bc`
echo $z
echo "enter the radius"
read radius
area=`echo 3.14\*$radius\*$radius|bc`
echo "area is $area"
