class Node:
	def __init__(self):
		self.distance=None
		self.color="White"
		self.pred=None
		self.start=None
		self.end=None

class Graph:
	def __init__(self,n):
		
		self.edges=[]
		self.count=0
		self.vertex=[Node() for i in range(n)]
		self.adj_list=[]
		self.time=1

	def insert(self,x):
		self.edges.append(x)
		self.count+=1
	def search(self,x):
		for i in range(self.count):
			if self.edges[i]==x:
				return True
		return False

	def adjacency_matrix(self,n):
		adj_matrix=[[0 for x in range(n)] for y in range(n)]
		for i in range(n):
			for j in range(n):
				if i!=j:
					x=[i,j]
					y=[j,i]
					if self.search(x)==True or self.search(y)==True:
						adj_matrix[i][j]=1
		for i in range(n):
			adj=[]
			for j in range(n):
				if adj_matrix[i][j]==1:
					adj.append(j)
			self.adj_list.append(adj)
	
	def DFS(self,u):

		print(self.adj_list)
		self.vertex[u].color="Grey";
		self.vertex[u].pred=None
		self.vertex[u].start=self.time
		self.time+=1

		stack=[]
		stack.append(u)

		while len(stack):
				node=stack[len(stack)-1]
				if self.vertex[node].color=="White":
					self.vertex[node].color="Grey"
					if self.vertex[node].start==None:
							self.vertex[node].start=self.time
							self.time+=1
			
				for v in self.adj_list[node]:
					if self.vertex[v].color=="White":
						stack.append(v)
						if self.vertex[v].start==None:
							self.vertex[v].start=self.time
							self.time+=1
				node=stack.pop()
				self.vertex[node].color="Black"
				if self.vertex[node].end==None:
					self.vertex[node].end=self.time
					print(self.vertex[node].end)
					self.time+=1
		
		for i in range(5):
			self.display(i)
			print( )

	def display(self,i):
			print("Vertex:",i)
			#print("Distance: ",self.vertex[i].distance)
			print("Start time: ",self.vertex[i].start)
			print("End time: ",self.vertex[i].end)

def main():
	n=5
	t=Graph(n)
	x=[0,1]
	t.insert(x)
	x=[0,2]
	t.insert(x)
	x=[1,2]
	t.insert(x)
	x=[1,3]
	t.insert(x)
	x=[1,4]
	t.insert(x)
	x=[2,3]
	t.insert(x)
	s=int(input("Enter a source vertex"))
	t.adjacency_matrix(n)
	t.DFS(s)

if __name__=='__main__':
	main()
	