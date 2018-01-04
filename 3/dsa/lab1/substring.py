a=input("enter a string   ")
b=input("string to replace   ")
c=input("replaced with   ")
d=len(a)
e=len(b)
f=len(c)
i=0
while i<d:
	if b[0]==a[i]:
		flag=1
		for j in range(1,e):
			if  b[j]!=a[i+j]:
				flag=0
		if flag==1:	
			a=a[:i]+c+a[i+e:]
			i=i+f
			if e>f:
				d=d-e-f
			else:
				d=d+f-e 
		else:
			i=i+1    
	else:
		i=i+1	
print (a)



