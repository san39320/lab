sort -n a.txt > b.txt &
a=$(ps|wc -l)
((a=a-2))
ps
jobs
echo "number of processes is $a "

