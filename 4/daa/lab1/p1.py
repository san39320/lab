def matchingalgorithm(n,menpreflist,womenpreflist):
	menpair=[None for i in range(n)]
	womenpair=[None for i in range(n)]
	mencount=[-1 for i in range(n)]
	menlist=[i for i in range(n)]
	while(len(menlist)):
		m=menlist.pop(0)
		mencount[m]+=1
		w=menpreflist[m][mencount[m]]
		if(womenpair[w]==None):
			menpair[m]=w
			womenpair[w]=m
		elif(womenpreflist[w][womenpair[w]]>womenpreflist[w][m]):
			m1=womenpair[w]
			menlist.append(m1)
			menpair[m]=w
			womenpair[w]=m
		else:
			menlist.append(m)
	return menpair,womenpair
def makedictionary(line):
	dictionary={}
	for i,word in enumerate(line.split()):
		dictionary[word]=i
	return dictionary

def main():
	n=5        
	menpreflist=[[i for i in range(n)] for i in range(n)]
	womenpreflist=[[i for i in range(n)] for i in range(n)]	
	lin=0
	with open("input.txt","r") as f:
		for line in f:
			lin+=1
			if(lin==1):
				menname=makedictionary(line)
			elif(lin == 2):
				womenname=makedictionary(line)
			elif(lin<=len(menname)+2):
				for i,word in enumerate(line.split()):
					if(i!=0):
						menpreflist[lin-3][i-1]=womenname[word]
			else:
				for i,word in enumerate(line.split()):
					if(i!=0):
						womenpreflist[lin-8][menname[word]]=menname[word]
	menpair,womenpair=matchingalgorithm(len(menname),menpreflist,womenpreflist)
	for i in range(5):
		print(list(menname.keys())[list(menname.values()).index(i)],list(womenname.keys())[list(womenname.values()).index(menpair[i])])
if __name__ == '__main__':
	main()