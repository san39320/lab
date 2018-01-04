def fact(n):
	fact=1
	for i in range(1,n+1):
		fact=fact*i
	return fact
def fact1(n):
	if n==0 :
		return 1;
	else:
		return (n*fact1(n-1))
a=int(input("enter a number "))
b=fact(a)
c=fact1(a)
print ("factorial using iteration is",b)
print ("factorial using recursion is",c)