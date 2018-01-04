printf "enter password"
stty -echo
read p
stty echo
printf "password uid $p"
