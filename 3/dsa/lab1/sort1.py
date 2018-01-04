n=int(input("enter the number of elements"))
print("enter the elements to be sorted")
a=[None]*n
for i in range(0,n):
	a[i]=int(input())
for i in range(0,n):
	min=i
	for j in range(i+1,n):
		if a[j]<a[min]:
			min=j

	if a[i]>a[min]:
		temp=a[i]
		a[i]=a[min]
		a[min]=temp
print(a)