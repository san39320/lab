def calculatesemister(a):
	incomingcount=[0 for i in range(len(a))]
	sourcevertices=[]
	for i in range(len(a)):
		for j in range(len(a[i])):
			incomingcount[a[i][j]]+=1
	for i in range(len(incomingcount)):
		if incomingcount[i]==0:
			sourcevertices.append(i)
	semister=0
	while(sourcevertices!=[]):
		semister+=1
		for k in range(len(sourcevertices)):
			i=sourcevertices.pop()
			for j in a[i]:
				incomingcount[j]-=1
				if incomingcount[j]==0:
					sourcevertices.append(j)
	return semister
def main():
	n=5
	a=[[] for i in range(6)]
	a[0].append(1)
	a[0].append(2)
	a[1].append(3)
	a[3].append(4)
	a[3].append(5)
	semister=calculatesemister(a)
	print(semister)
if __name__ == '__main__':
	main()
