for i in `ls`
do 
	a=$(ls -l $i|cut -c 2-3 )
	if [[ $a == rw ]]
		then
		echo $i
	fi
done

#we can use -r and -w also
