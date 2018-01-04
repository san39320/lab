select k in adding delete find1 display exit1
do
	case $k in 
		"adding") echo "enter the name|rollno|sem|m1|m2|m3 pair"
				read name;read address;read sem;read m1;read m2;read m3;
				if [ $address -gt 0 ]
					then
				echo $name"|"$address"|"$sem"|"$m1"|"$m2"|"$m3 | cat >> student.lst
			else
				echo "enter valid data i.e roll no >0"
			fi;;
		"delete")echo "enter the name of student to be deleted"
				read name
				grep -v "$name" student.lst | tee student.lst	
						;;
		"find1") echo "enter the name of student to be found"
				read name
				grep -i "$name" student.lst
				;;
		"display") cat student.lst ;;
		"exit1") exit;;
		*)echo "invalid option";;
	esac
done