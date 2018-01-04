class graphmatrix:
    def __init__(self,x):
        self.x=x
        self.adjlist = [[] for j in range(int(self.x))]
        self.indexlink=[None for i in range(int(x))]
        self.time=0
        self.vlist=[]
    def insert(self,x,y):
        self.adjlist[x].append(y)
        self.adjlist[y].append(x)
    def linknode(self):
        for i in range(int(self.x)):
            self.indexlink[i]=indexstatus(i)
    def display(self):
        print("adjacency list is")
        for i in range(int(self.x)):
            print(i,"-->",self.adjlist[i])
    def dfs(self,u):
        self.vlist.append(u)
        self.time = self.time + 1
        self.indexlink[u].start=self.time

        self.indexlink[u].color = "grey"
        for v in self.adjlist[u]:
            if self.indexlink[v].color=="white":
                self.dfs(v)
                self.indexlink[v].pre = self.indexlink[u]
        self.indexlink[u].color = "black"
        self.time = self.time + 1
        self.indexlink[u].end = self.time

        print("vertex",u,"start=",self.indexlink[u].start,"end=",self.indexlink[u].end)





class indexstatus:
    def __init__(self,i):
        self.i=i
        self.color="white"
        self.start=None
        self.end=None
        self.pre=None
def main():
    print("enter the number of vertices")

    a=input()
    print("enter the number of edges")
    b=int(input())
    d=graphmatrix(a)
    for i in range(b):
        print("enter the edge endpoints")
        x=int(input())
        y=int(input())
        d.insert(x,y)

    d.linknode()

    print("enter the sourse vertex")
    c = int(input())
    d.dfs(c)
    print("order of visiting is",d.vlist)

if __name__ == '__main__':
    main()