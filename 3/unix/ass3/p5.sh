echo "enter file name"
read name
a=$(ls -l $name|cut -c 2-10 )
echo "$i rights $a"
	
