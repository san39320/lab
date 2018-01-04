class BinaryTreeNode:
	def __init__(self,parent=None,rchild=None,lchild=None,value=None,lheight=0,rheight=0):
		self.parent=parent
		self.rchild=rchild
		self.lchild=lchild
		self.key=value
class OrderedDict:
	
	def __init__(self):
		self.root=BinaryTreeNode()
	"""def search(self,k,temp):
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
			return x.rchild"""

	#######avl avl
	def preorder(self,x):
		if x == None:
			return
		else:
			temp1=x.rchild
			temp2=x.lchild
			print(x.key)
			self.preorder(temp2)
			self.preorder(temp1)
	def heightt(self,x):
		if(x==None):
			return 0
		else:
			lh=self.heightt(x.lchild)
			rh=self.heightt(x.rchild)
			if(lh>rh):
				return lh+1
			else:
				return rh+1
	def isleft(self,m,n):
		if m.lchild==n:
			return True
		else:
			return False
	def findcase(self,temp,temp1,temp2):
		if temp.lchild==temp1:
			if temp1.lchild==temp2:
				return 1  #left left
			else:
				return 3	#left right

		else:
			if temp1.rchild==temp:   #right right
				return 2
			else:
				return 4	#right left

	def maxDeapth(self,node):
		if node is None:
			return 0;

		else:
			lheight = self.maxDeapth(node.lchild)
			rheight = self.maxDeapth(node.rchild)
			if (lheight > rheight):
				return lheight + 1
			else:
				return rheight + 1

	def rotate(self,o,z,y,x):
		if o == 1:
			z.lchild=y.rchild
			if y.rchild is not None:
				y.rchild.parent=z
			y.rchild=z
			y.parent=z.parent
			z.parent=y
		elif o == 2:
			z.rchild=y.lchild
			if y.lchild is not None:
				y.lchild.parent=z
			y.lchild=z
			y.parent=z.parent
			z.parent=y
		elif o == 3 :
			y.rchild=x.lchild
			if x.lchild is not None:
				x.lchild.parent=y
			x.lchild=y
			y.parent=x
			z.lchild=x
			x.parent=z

			z.lchild=y.rchild
			if y.rchild is not None:
				y.rchild.parent=z
			y.rchild=z
			y.parent=z.parent
			z.parent=y
		elif o==4:



























			




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

			#finding for z    x,y,z are temp,temp1,temp2
			f=True
			temp=z.parent
			imbal=None
			while f:
				#print("hi ",temp.lheight,temp.rheight)
				
				diff=self.maxDeapth(temp.lchild)-self.maxDeapth(temp.rchild)
				if(abs(diff)>1):
					imbal=temp
					f=False
				else:
					temp=temp.parent
				if temp==None:
					f=False
			#if there is imbalance
			temp=imbal
			if imbal!=None:
				if(z.key>temp.key):
					temp1=temp.rchild
				else:
					temp1=temp.lchild
				if(z.key>temp1.key):
					temp2=temp1.rchild
				else:
					temp2=temp1.lchild

				#finding the case
				o=self.findcase(temp,temp1,temp2)
				print("this case",o)
				self.rotate(o,temp,temp1,temp2)








def main():
	d=OrderedDict()
	d.insert(5)
	d.insert(3)
	d.insert(2)

	d.preorder(d.root)

if __name__ == '__main__':
	main()




