def postfix(exp):
	s=[]
	exp=exp.split()
	l=len(exp)
	i=0
	
	while i<l :
		if exp[i].isdigit():
			s.append(int(exp[i]))

		elif exp[i]=='+':
			temp1=s.pop()
			temp2=s.pop()
			
			s.append(int(temp2)+int(temp1))	
		elif exp[i]=='-':
			temp1=s.pop()
			temp2=s.pop()
			s.append(int(temp2)-int(temp1))			
		elif exp[i]=='*':
			temp1=s.pop()
			temp2=s.pop()
			s.append(int(temp2)*int(temp1))
		elif exp[i]=='/':
			temp1=s.pop()
			temp2=s.pop()
			s.append(int(temp2)/int(temp1))
		i=i+1
	result=s.pop()
	return result
def main():
	exp='2 2 3 * 4 / - '

	
	temp=postfix(exp)
	print(temp)
if __name__ == '__main__':
	main()

