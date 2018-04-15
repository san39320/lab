class minheap:
	def __init__(self):
		self.a = [None] * 50
		self.count = 0
		### heapify
	def arrayheap(self,a=None):
		if a != None:
			for i in range(0, len(a)):
				self.a[i + 1] = a[i]
			self.count = len(a)
		for i in range(int(self.count / 2), 0, -1):
			self.heapify(i)
	def heapify(self,i):#top to bottom
		if (i <= self.count) and ((2*i) <= self.count):
			if (self.a[2 * i + 1] != None) and (self.a[2 * i].dist > self.a[2 * i + 1].dist):
				if self.a[i].dist > self.a[2 * i + 1].dist:
					self.a[i],self.a[2*i+1] = self.a[2 * i+1],self.a[i]
					self.heapify(2*i+1)
			elif self.a[2*i] != None:
				if self.a[i].dist > self.a[2 * i].dist:
					self.a[i],self.a[2*i] = self.a[2 * i],self.a[i]
					self.heapify(2*i)
	def insertheap(self,k):
		self.count=self.count+1
		self.a[self.count]=k
		self.bottomtopbalance(self.count)
	def bottomtopbalance(self,i):
		if (self.a[i//2] != None) and (self.a[i//2].dist > self.a[i].dist ):
			self.a[i],self.a[i//2]=self.a[i//2],self.a[i]
			self.bottomtopbalance(i//2)
		else:
			return
	def extractmin(self):
		temp=self.a[1]
		self.a[1]=self.a[self.count]
		self.a[self.count ] = None
		self.count=self.count-1
		self.heapify(1)
		return temp

class graphmatrix:
	def __init__(self,x):
		self.x=x
		self.adjlist = [[] for j in range(self.x)]
		self.indexlink=[indexstatus(i) for i in range(self.x)]
		self.edgeweight=[[ 100000 for i in range(self.x)] for i in range(self.x)]
	def insert(self,x,y,z):
		self.adjlist[x].append(y)
		self.adjlist[y].append(x)
		self.edgeweight[x][y]=z
		self.edgeweight[y][x]=z
	def display(self):
		print("adjacency list is")
		for i in range(int(self.x)):
			print(i,"-->",self.adjlist[i])
	def dijkstra(self):
		print("enter the sourse vertex")
		s = int(input())
		self.indexlink[s].dist=0
		d=minheap()
		d.arrayheap(self.indexlink)
		while d.count>0:
			w=d.extractmin()
			for i in self.adjlist[w.i]:
				if(self.indexlink[i].dist>self.indexlink[w.i].dist+self.edgeweight[w.i][i]):
					self.indexlink[i].dist = self.indexlink[w.i].dist + self.edgeweight[w.i][i]
					self.indexlink[i].pre=self.indexlink[w.i]
					#no proper logic to heapbalance here
			d.arrayheap()
	def display(self):
		print("enter the destnation")
		d=int(input())
		print("vertex",d,"sortest distance from source is",self.indexlink[d].dist,"path is ",end=' ')
		self.path(self.indexlink[d])
		# for i in range(int(self.x)):
		# 	print("vertex",i,"sortest distance from source is",self.indexlink[i].dist,"path is ",end=' ')
		# 	self.path(self.indexlink[i])

	def path(self,pointer):
		while(pointer!=None):
			print(pointer.i,end=' ')
			pointer=pointer.pre
		print()
class indexstatus:
	def __init__(self,i):
		self.i=i
		self.dist=100000
		self.pre=None
def main():
	a=8	#vertises
	b=12 #edges
	d=graphmatrix(a)
	edgelist=[[1,2,40],[1,4,40],[4,3,40],[2,3,40],[1,5,40],[4,8,40],[3,7,40],[2,6,40],[5,6,120],[6,7,120],[7,8,120],[8,5,120]]
	for i in range(b):
		d.insert(edgelist[i][0]-1,edgelist[i][1]-1,edgelist[i][2])
	d.dijkstra()
	d.display()

if __name__ == '__main__':
	main()