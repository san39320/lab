def returnindex(a,n):
	for i in range(0,n):
		flag=0
		if a[i]==i:
			print("index is",i)
			flag=1
	if flag==0:
		print("not found")

def returnindex1(a,start,end,count):
	mid=(start+end)//2;
	if start<=end:
		if a[mid]==mid:
			count=count+1
			print("index is",mid)
			print("count is",count)
			return 1;
		elif a[mid]>mid:
			count=count+1
			return returnindex1(a,start,mid-1,count)
		else:
			count=count+1
			return returnindex1(a,mid+1,end,count)
def main():
	a=[-3,-2,-1,0,2,3,4,5,8]
	#returnindex(a,5)
	print("array is",a)
	count=0
	b=returnindex1(a,0,8,count)
	if(b!=1):
		print("no elements matching the condition")
if __name__ == '__main__':
	main()