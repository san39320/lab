a=int(input("enter number to check if prime or not"))
if a<0:
	print ("enter a non negative number")
elif a>0:
	flag=0
	for i in range(2,int(a/2+1)):
		if a%i==0:
			flag=1
	if flag==0:
		print("the number is prime")
	else:
		print ("it is not prime number")
else:
	print("enter a valid number")