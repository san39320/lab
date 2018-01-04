n=1
until test $n -gt 10
do
	echo $n
	n=`expr $n + 1`
done
m=1
while test $m -le 10
do
	echo $m
	m=`expr $m + 1 `
done