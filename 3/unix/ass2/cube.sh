i=1

while [ $i -lt 1000 ]
do	
	a=$i
	ans=0
	while [ $a -gt 0 ]
	do	
		((b=a%10))
		((ans=ans+b*b*b))
		((a=a/10))
	done
	if [ $ans -eq $i ]
		then
		echo "$i"
	fi
	((i=i+1))
done




	