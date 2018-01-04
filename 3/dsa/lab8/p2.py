class graphmatrix:
    def __init__(self,x):
        self.x=x
        self.adjlist = [[] for j in range(int(self.x))]
        self.indexlink=[None for i in range(int(x))]
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
    def bsf(self):
        print("enter the sourse vertex")
        c = int(input())
        self.indexlink[c].dis = 0
        self.indexlink[c].color = "grey"
        a=[c]
        print("vertex=",c,"distance",0)
        while a != [] :
            u=a.pop(0)
            for i in self.adjlist[u]:
                if self.indexlink[i].color=="white":
                    self.indexlink[i].dis = self.indexlink[u].dis+1
                    self.indexlink[i].color = "grey"
                    self.indexlink[i].pre = self.indexlink[u]
                    a.append(i)
                    print("vertex=", i, "distance=",self.indexlink[i].dis)
            self.indexlink[u].color == "black"




class indexstatus:
    def __init__(self,i):
        self.i=i
        self.color="white"
        self.dis=1000000
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
    d.bsf()




if __name__ == '__main__':
    main()
