class m:
    def __init__(self,a=None,size=None):
        self.array=a
        self.size=size
    def mergesort(self,low,high):
        if low<high:
            mid=(low+high)//2
            self.mergesort(low,mid)
            self.mergesort(mid+1,high)
            self.merge(low,mid,high)
    def merge(self,low,mid,high):
        l=0
        r=0
        L=[None for i in range(mid-low+1)]
        R=[None for i in range(high-(mid+1)+1)]
        for i in range(low,mid+1):
            L[l]=self.array[i]
            l+=1
        for i in range(mid+1,high+1):
            R[r]=self.array[i]
            r+=1
        l=0
        r=0
        i=low
        while ( (l < len(L)) & (r<len(R)) ):
            if L[l]>R[r]:
                self.array[i]=R[r]
                r+=1
            else:
                self.array[i]=L[l]
                l+=1
            i+=1
        while l<len(L):
            self.array[i]=L[l]
            i+=1
            l+=1
        while r<(len(R)):
            self.array[i]=R[r]
            i=i+1
            r=r+1
    def display(self):
        for i in range(self.size):
            print(self.array[i],end=" ")
def main():
    print("enter the array elements")
    a=list(map(int,input().split()))
    n=m(a,len(a))
    n.mergesort(0,n.size-1)
    n.display()
if __name__ == '__main__':
    main()




