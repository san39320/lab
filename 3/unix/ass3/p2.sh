echo "enter the file name or directory name"
read name
if test -f $name 
	then
	vim $name

elif test -d $name
	then
	ls $name

else
	echo "invalid name"
fi