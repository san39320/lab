echo "enter the time"
read a
read b

if [[ ( $a -ge 0 ) && ( $a -lt 12 ) ]]
	then
	echo "good morning"
elif [[ ( $a -ge 12 ) && ( $a -lt 18 ) ]]; then
	echo "good afternoon"
elif [[ ( $a -ge 18 ) && ( $a -lt 19 ) ]]
	then
	echo "good evening"
else
	echo "good night"
fi