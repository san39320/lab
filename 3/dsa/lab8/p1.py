class graphmatrix:
    def __init__(self,x):
        self.x=x
        self.adj=[[0 for i in range(int(self.x))]for j in range(int(self.x))]
        self.adjlist = [[] for j in range(int(self.x))]
    def insert(self,x,y):
        self.adj[x][y]=1
        self.adj[y][x]=1
        self.adjlist[x].append(y)
        self.adjlist[y].append(x)
    def display(self):
        print("adjacency matrix")
        for i in range(int(self.x)):
            for j in range(int(self.x)):
                print(self.adj[i][j],end=" ")
            print()
        print("adjacency list is")
        for i in range(int(self.x)):
            print(i,"-->",self.adjlist[i])
def main():
    print("enter the number of vertices")
    a=input()
    d=graphmatrix(a)
    ch=1
    while ch!='#':
        print("enter the edge endpoints")
        x=int(input())
        y=int(input())
        d.insert(x,y)
        print("enter # to exit entering edge end points");
        ch=input()
    d.display()
if __name__ == '__main__':
    main()






