n=6
d= [[[0 for k in range(n)] for j in range(n)] for i in range(n)]
bt= [[[2000 for k in range(n)] for j in range(n)] for i in range(n)]
#p=int(input("enter no. of edges"))
#print("enter edges in u v edge length")
d[0]=[[0,float('Inf'),float('Inf'),float('Inf'),-1,float('Inf')],
    [1,0,float('Inf'),2,float('Inf'),float('Inf')],[float('Inf'),2,0,float('Inf'),float('Inf'),-8],[-4,float('Inf'),float('Inf'),0,3,float('Inf')],[float('Inf'),7,float('Inf'),float('Inf'),0,float('Inf')],[float('Inf'),5,10,float('Inf'),float('Inf'),0]]
bt[0]=[[0,float('Inf'),float('Inf'),float('Inf'),0,float('Inf')],[1,1,float('Inf'),1,float('Inf'),float('Inf')],
    [float('Inf'),2,2,float('Inf'),float('Inf'),2],[3,float('Inf'),float('Inf'),3,3,float('Inf')],[float('Inf'),4,float('Inf'),float('Inf'),4,float('Inf')],[float('Inf'),5,5,float('Inf'),float('Inf'),5]]
for k in range(1,n):
    for i in range(n):
        for j in range(n):
            d[k][i][j]=min(d[k-1][i][j],(d[k-1][i][k-1]+d[k-1][k-1][j]))
for i in range(n):
    print(d[n-1])        

for k in range(1,n):
    for i in range(n):
        for j in range(n):

            if d[k][i][j]==d[k-1][i][j]:
                bt[k][i][j]=bt[k-1][i][j]
            else:
                bt[k][i][j]=bt[k-1][k-1][j]

print("hi")
for i in range(n):
    print(bt[i])               

