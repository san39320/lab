class Graph:
    def __init__(self,n):
        self.n=n
        self.adjacencylist=[[]for i in range(n)]
        self.weight=[[1000 for i in range(n)] for j in range(n)]
    def weight1(self,i,j,w):
        self.weight[i][j]=w
    def floyd(self):
        w=self.weight
        for i in range(n):
            w[i][i]=0
        path=[[[[0]for i in range(n)]for j in range(n)]for k in range(n)]
        for k in range(self.n):
            for i in range(self.n):
                for j in range(self.n):
                    temp=w[i][j]
                    w[i][j]=min(w[i][j],w[i][k]+w[k][j])
                    if(w[i][j]==temp):
                        path[k][i][j]=path[k-1][i][j]
                    else:
                        path[k][i][j]=path[k-1][k-1][j]
                    if(k==self.n-1):
                        print("from",i,"to",j,"dis",w[i][j])
        
def main():
    n=4
    g=Graph(n)
    g.adjacencylist[0].append(1)
    g.adjacencylist[0].append(2)
    g.adjacencylist[1].append(3)
    g.adjacencylist[2].append(1)
    g.adjacencylist[1].append(3)
    g.weight1(0,1,1)
    g.weight1(0,2,3)
    g.weight1(1,2,2)
    g.weight1(3,1,4)
    g.weight1(2,3,1)
    g.floyd()
if __name__ == '__main__':
    main()