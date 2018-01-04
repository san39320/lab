class BinaryTreeNode:
	def __init__(self,parent=None,rchild=None,lchild=None,value=None,height=None):
		self.parent=parent
		self.rchild=rchild
		self.lchild=lchild
		self.key=value
		self.height=height
class OrderedDict:
	def __init__(self):
		self.root=BinaryTreeNode()
	def search(self,k,temp):
		if temp==None:
			return None
		elif k==temp.key:
			return temp
		elif k<temp.key:
			temp=temp.lchild
			return self.search(k,temp)
		else:
			temp=temp.rchild
			return self.search(k,temp)
	
	def minimum(self,temp):   #retyrns minimum rlrment address passing root
		while temp.lchild!=None:
			temp=temp.lchild
		return temp
	def maximum(self,temp):   #returns maximum element address passing root
		while temp.rchild!=None:
			temp=temp.rchild
		return temp
	def successor(self,k):   #adress of smallest key > = x.key
		x=self.search(k,self.root)
		if x.rchild!=None:
			x=x.rchild
			return self.minimum(x)
		y=x.parent
		while (x!=y.lchild) & (y!=None):
			x=y
			y=y.parent
		return y

	def predeccessor(self,k):
		x=self.search(k,self.root)
		if x.lchild!=None:
			x=x.lchild
			return self.maximum(x)
		y=x.parent
		while ((x==y.lchild) & (y!=None)):
			x=y
			y=x.parent
		return y

	def insert(self,k):
		x=self.root
		if x.key==None:
			x.key=k
		else:


			z=BinaryTreeNode()
			z.key=k
			y=x.parent
			while x!=None:
				y=x
				if k<x.key:
					y=x
					x=x.lchild
				else:
					y=x
					x=x.rchild
			z.parent=y
			if k<y.key:
				y.lchild=z
			else:
				y.rchild=z



	def children(self,x):
		if((x.lchild==None)&(x.rchild==None)):
			return 0
		elif((x.lchild!=None)&(x.rchild!=None)):
			return 1
		else:
			return 1
	def onechild(self,x):
		if x.lchild!=None:
			return x.lchild
		else:
			return x.rchild



	def delete(self,k):
		s=self.search(k,self.root)
		t=self.children(s)
		if s!= None:
			if(t==0):
				u=s.parent
				if u.lchild==s:
					u.lchild=None
				else:
					u.rchild=None
				print(k,"deleted successfully")
			elif(t==1):
				child=self.onechild(s)
				p=s.parent
				if p.lchild==s:
					p.lchild=child
					child.parent=p
				else:
					p.rchild=child
					child.parent=p
				s.parent=None
				s.lchild=None
				s.rchild=None
			elif(t==2):
				pre=predecessor(s)
				s.key=pre.key
				pre.key=None
				self.delete(None)



		else:
			print("element not found")

	def preorder(self,x):
		if x == None:
			return
		else:
			temp1=x.rchild
			temp2=x.lchild
			print(x.key)
			self.preorder(temp2)
			self.preorder(temp1)
			


def main():
	d=OrderedDict()     

	"""str=input("enter the keys")
	str=str.split()
	print(len(str),str)
	for i in (0,len(str)):
		d.insert(int(str[i]))"""
	d.insert(10)
	d.insert(5)
	d.insert(3)
	d.insert(8)
	d.insert(14)
	d.insert(11)
	d.insert(6)
	d.insert(7)
	print("start")
	d.preorder(d.root)
	print("end")
	y=d.predeccessor(5)
	print("predecessor",y.key)
	y=d.successor(5)
	print("successor",y.key)
	print("search for key 11")
	j=d.search(11,d.root)
	print("found at address",j)
	d.delete(7)
	d.preorder(d.root)


if __name__ == '__main__':
	main()

