echo "enter the unix marks"
read m1
echo "enter the java marks"
read m2
echo "enter the dsa marks"
read m3
((avg=((m1+m2+m3))/3))
echo $avg
if [ $avg -ge 70 ]
	then
	echo "distinction"
	elif [[ ( $avg -ge 60 ) && ( $avg -lt 70 ) ]]
	then
		#statements
		echo "First class"
	elif [[ ( $avg -ge 50 ) && ( $avg -lt 60 ) ]]
	then
		#statements
		echo "Second class"	
	elif [[ ( $avg -ge 40 ) && ( $avg -lt 50 ) ]]
	then
		#statements
		echo "Third class"
	else
		echo "fail"
fi