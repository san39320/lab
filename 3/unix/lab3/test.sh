basic=5
dp=`echo "0.5 * $basic" | bc`
echo "scale=2;`expr $basic\*0.5`"|bc