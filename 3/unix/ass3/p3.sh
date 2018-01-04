echo "enter two file names"
read name1
read name2
if test -f $name1
	then
	if test -f $name2
		then
		cat $name1 >> $name2
		echo "appended sucsessfully"
	else
		echo "they are not files"
	fi
fi