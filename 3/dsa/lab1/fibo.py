def fibo(n):
	a=[1,1]
	for i in range(2,n):
		a.insert(i,a[i-2]+a[i-1])
	for i in range(0,n):
		print(a[i])

	
a=int(input("enter the number of terms in fibonaci series"))
if a==1:
	print("1")
elif a==2:
	print("1 1")
else :fibo(a)




