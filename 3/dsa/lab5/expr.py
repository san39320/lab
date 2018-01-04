class BinaryTreeNode:
	def __init__(self,parent=None,rchild=None,lchild=None,value=None,height=None):
		self.parent=parent
		self.rchild=rchild
		self.lchild=lchild
		self.key=value
		self.height=height
class Exp:
	def __init__(self):
		self.root=BinaryTreeNode()
		self.ptr=self.root
	def isoperator(self,i):
		if ((i == '+')|(i=='-')|(i=='*')|(i=='/')):
			return True
		else:
			return False
	def insert(self,tmp,val,flag):
			z=BinaryTreeNode()
			z.key=val
			z.parent=tmp

			if flag==1:
				tmp.lchild=z
			else:
				tmp.rchild=z
			return z

	def express(self,str):
		str1=list(str)
		for i in str:
			if i is '(':         #flag =1 left 0 right
				addr=self.insert(self.ptr,None,1)
				self.ptr=addr
			elif self.isoperator(i):
				self.ptr=self.ptr.parent
				self.ptr.key=i
				addr=self.insert(self.ptr,None,0)
				self.ptr=addr
			elif ((ord(i)>48)&(ord(i)<57)):
				self.ptr.key=i
			else:
				pass
	def preorder(self,x):
		
		if x == None:
			return
			
		else:
			
			temp1=x.rchild
			temp2=x.lchild
			print(x.key,end=' ')
			self.preorder(temp2)
			self.preorder(temp1)
	def postorder(self,x):
		
		if x == None:
			return
			
		else:
			
			temp1=x.rchild
			temp2=x.lchild
			self.postorder(temp2)
			self.postorder(temp1)
			print(x.key,end=' ')
	
	def isleaf(self,x):
		if ((x.lchild==None) & (x.rchild==None)):
			return True
		return False
	def apply(self,op,opp1,opp2):
		if op=='+':
			res=int(opp1)+int(opp2)
			return res
		elif op=='-':
			res=int(opp1)-int(opp2)
			return res
		elif op=='*':
			res=int(opp1)*int(opp2)
			return res
		elif op=='/':
			res=int(opp1)/int(opp2)
			return res
	def eval(self,x):
		if self.isleaf(x):
			return x.key
		else:
			op1=self.eval(x.lchild)
			op2=self.eval(x.rchild)
			result=self.apply(x.key,op1,op2)
			return result



def main():
	str=input("enter the expression")
	"""str="(4*(2+(3*2))"  """
	e=Exp()
	e.express(str)
	print("prefix expression")
	e.preorder(e.root)
	print("\npostfix expression")
	e.postorder(e.root)
	b=e.eval(e.root)
	print("\nevaluatd answer is",b)

if __name__ == '__main__':
		main()


