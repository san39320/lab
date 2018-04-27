class Graph:
    def __init__(self,n):
        self.n=n
        self.g=[[]for i in range(self.n)]
        self.grev=[[]for i in range(self.n)]
        self.visited=[False for i in range(n)]
        self.sccvisited=[False for i in range(n)]
        self.soursestack=[]
    def addEdge(self,a,b):
        self.g[a].append(b)
        self.grev[b].append(b)
    def dfsforreverese(self,v):
        self.visited[v]=True
        for u in self.grev[v]:
            if(self.visited[u]==False):   
                self.dfsforreverese(u)
        self.soursestack.append(v)
    def dfsscc(self,v):
        self.sccvisited[v]=True
        print(v)
        for u in self.g[v]:
            #print("in loop",self.g[v])
            if(self.sccvisited[u]==False):
                self.dfsscc(u)
        #self.soursestack.append(v)
    def scc(self):
        for i in range(self.n):
            if self.visited[i]==False:
                self.dfsforreverese(i)
        print("hhi")
        while(self.soursestack!=[]):
            #print("hello",self.soursestack)
            s=self.soursestack.pop(len(self.soursestack)-1)
            if(self.sccvisited[s]==False):
                print("component")
                self.dfsscc(s)
def main():
    g=Graph(5)
    g.addEdge(1, 0)
    g.addEdge(0, 2)
    g.addEdge(2, 1)
    g.addEdge(0, 3)
    g.addEdge(3, 4)
    g.scc()
if __name__ == '__main__':
    main()