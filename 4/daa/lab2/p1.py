def solvehonoi(n,s,i,t):
	if n>1:
		solvehonoi(n-1,s,t,i)
		print("Move disk",n,"from",s,"to",t)
		solvehonoi(n-1,i,s,t)
	elif n==1:
		print("move disk",n,"from",s,"to",t)
def main():
	n=3
	solvehonoi(n,"s","i","t")
if __name__ == '__main__':
	main()