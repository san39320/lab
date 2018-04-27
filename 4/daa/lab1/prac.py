def matching(n,menlist,womenlist):
    menpair=[-1 for i in range(n)]
    womenpair=[-1 for j in range(n)]
    mencount=[0 for i in range(n)]
    menfree=[i for i in range(n)]
    while(len(menfree)!=0):
        m=menfree.pop()
        w=menlist[m][mencount[m]]
        mencount[m]+=1
        if(womenpair[w]==-1):
            womenpair[w]=m
            menpair[m]=w
        elif(womenlist[womenpair[w]]>womenlist[w]):
            m1=womenlist[womenpair[w]]
            menlist[m]=w
            womenlist[w]=m
            menfree.append(m1)
        else:
            menfree.append(m1)
    print(menpair)
    print("aaaa")
def main():
    n=3
    menlist=[[2,0,1],[0,1,2],[1,0,2]]
    womenlist=[[1,0,2],[2,1,0],[0,2,1]]
    for i in range(n):
        temp=womenlist[i]
        for j in range(n):
            womenlist[i][temp[j]]=j

    matching(n,menlist,womenlist)
if __name__ == '__main__':
    main()