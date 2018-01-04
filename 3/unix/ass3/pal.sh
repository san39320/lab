echo "enter the string"
read string
n=$(echo string|wc -c)
((n=n-1))
i=1
((mid=n/2))
flag=0
echo $mid
while [ $i -le $mid ]
do
	a=$(echo $string|cut -c $i)
	b=$(echo $string|cut -c $n)
	if [[ $a != $b ]]
		then
		echo "string is not palindrome "
		exit
	fi
	((i=i+1))
	((n=n-1))
done
echo "string is palindrome"

