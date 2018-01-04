echo "enter the number of data"
read n
for ((i=0;i<n;i++))
do
	echo "enter the name|address pair"
	read name
	read address
	echo $name"|"$address | cat >> book.lst
done
echo "displaying the adress book"
cat book.lst


