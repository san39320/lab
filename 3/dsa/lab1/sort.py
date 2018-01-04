n=int(input("enter the number of elements"))
print("enter the elements to be sorted")
a=[]
for i in range(0,n):
	b=int(input())
	a.append(b)
for i in range(0,n):
	for j in range(0,n-i-1):
		if a[j]>a[j+1]:
			temp=a[j]
			a[j]=a[j+1]
			a[j+1]=temp
print(a)