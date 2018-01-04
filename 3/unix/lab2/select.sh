#!/bin/bash
select k in month year who1 whoiam cal1 tty1 quit
do
	case $k in 
		month)m=`date +%m`
			  echo $m;;
		year)yr=`date +%Y`
			cal $yr;;
		who1) who;;
		whoiam) whoami;;
		cal1) cal;;
		tty1) tty;;
		quit)echo "bye bye"
			exit;;
		
		*)echo "invalid";;
	esac
done
		
		