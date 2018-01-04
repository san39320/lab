declare -A arr1
declare -A arr2
declare -A arr3
echo "enter row and column size of matrix1"
read m
read n
echo "enter row and column of matrix2"
read o
read p
if [[ ( m -eq o ) && ( n -eq p )  ]]
	then
	echo "enter the elements of first matrix"
	for((i=0;i<m;i++))
	do
	echo "row $i"
		for((j=0;j<n;j++))
		do
			read temp
			((arr1[$i,$j]=$temp))
		
		done
	done
	echo "enter the elements of second matrix"
	for((i=0;i<o;i++))
	do
	echo "row $i"
		for((j=0;j<p;j++))
		do
			read temp
			((arr2[$i,$j]=$temp))
		
		done
	done
	echo "matrix after adding"
	for((i=0;i<o;i++))
	do
	echo "row $i"
		for((j=0;j<p;j++))
		do
			((arr3[$i,$j]=${arr1[$i,$j]}+${arr2[$i,$j]}))
			echo ${arr3[$i,$j]}
		
		done
	done

else
	echo "not possible"
fi