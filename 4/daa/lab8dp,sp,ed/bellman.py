class graphmatrix:
    def __init__(self,x):
        self.x=x
        self.incoming = [[] for j in range(self.x)]
        self.edgeweight=[[100000 for i in range(self.x)]for j in range(self.x)]
        self.T=[[100000 for i in range(self.x)]for j in range(self.x)]
    def insert(self,x,y,z):
        self.incoming[y].append(x)
        self.edgeweight[x][y]=z
    def bellmanford(self):
        print("enter the sourse vertex")
        s = int(input())
        self.T[s][0]=0
        flag=0 #check negative edge cycle
        for k in range(1,self.x):
            for v in range(self.x):
                self.T[v][k]=self.T[v][k-1]
                for u in self.incoming[v]:
                    if(self.T[v][k]>self.T[u][k-1]+self.edgeweight[u][v]):
                        self.T[v][k]=self.T[u][k-1]+self.edgeweight[u][v]
                        if(k==(self.x-1)):
                            flag=1
        if(flag==0):
            des=int(input("eneter the sedtination"))
            print("shortest distance",self.T[des][self.x-1])
        else:
            print("negetive cycle exists")
def main():
    print("enter the number of vertices")
    a=int(input())
    print("enter the number of edges")
    b=int(input())
    d=graphmatrix(a)
    for i in range(b):
        print("enter the edge endpoints")
        x=int(input("x"))
        y=int(input("y"))
        w=int(input("weight"))
        d.insert(x,y,w)
    d.bellmanford()
if __name__ == '__main__':
    main()