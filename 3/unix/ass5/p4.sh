i=1
while true
do
	echo -ne "$i\b"
done &
pid=$!            #gives pid of recent process
ps
kill $pid
echo "$pid"
ps          # wait waits untill program is executed completely
