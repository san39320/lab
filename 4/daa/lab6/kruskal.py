class ds:
    def __init__(self,v):
        self.v=v
        self.sets=[0 for i in range(v)]
        self.parent=[i for i in range(v)]
    def findset(self,a):
        if(self.parent[a]==a):
            return a
        else:
            self.parent[a]=self.findset(self.parent[a])
            return(self.parent[a])
    def union(self,a,b):
        aroot=self.findset(a)
        broot=self.findset(b)
        if(aroot!=broot):
            if(self.sets[aroot]>self.sets[broot]):
                self.parent[broot]=aroot
            elif(self.sets[aroot]<self.sets[broot]):
                self.parent[aroot]=broot
            else:
                self.parent[aroot]=broot
                self.sets[broot]=self.sets[broot]+1

def kruskal(edges,v,m):
    #init
    ds1=ds(v)
    #result
    result=[]
    for i in range(m):
        if(ds1.findset(edges[i][0])!=ds1.findset(edges[i][1])):
            result.append([edges[i][0],edges[i][1]])
            ds1.union(edges[i][0],edges[i][1])
    return result

def main():
    v=4
    m=6
    edges=[[None,None,None] for i in range(m)]
    edges[0]=[0,1,3]
    edges[1]=[1,2,2]
    edges[2]=[2,3,5]
    edges[3]=[3,0,4]
    edges[4]=[0,2,1]
    edges[5]=[1,3,7]
    edges=sorted(edges,key=lambda weight:weight[2])
    print(edges)

    result=kruskal(edges,v,m)
    print(result)
if __name__ == '__main__':
    main()