class maxheap:
    def __init__(self):
        self.a = [None] * 50
        self.count = 0
        ### heapify
    def arrayheap(self,a):
        for i in range(0, len(a)):
            self.a[i + 1] = a[i]
        self.count = len(a)
        for i in range(int(self.count / 2), 0, -1):
            self.heapify(i)
    def heapify(self,i):
        if (i <= self.count) and ((2*i) <= self.count):
            if (self.a[2 * i + 1] != None) and (self.a[2 * i] > self.a[2 * i + 1]):
                if self.a[i] > self.a[2 * i + 1]:
                    self.a[i],self.a[2*i+1] = self.a[2 * i+1],self.a[i]
                    self.heapify(2*i+1)
            elif self.a[2*i] != None:
                if self.a[i] > self.a[2 * i]:
                    self.a[i],self.a[2*i] = self.a[2 * i],self.a[i]
                    self.heapify(2*i)
    def insertheap(self,k):
        self.count=self.count+1
        self.a[self.count]=k
        self.bottomtopbalance(self.count)
    def bottomtopbalance(self,i):
        if (self.a[i//2] != None) and (self.a[i//2] > self.a[i] ):
            self.a[i],self.a[i//2]=self.a[i//2],self.a[i]
            self.bottomtopbalance(i//2)
        else:
            return
    def extractmax(self):
        temp=self.a[1]
        self.a[1]=self.a[self.count]
        self.a[self.count ] = None
        self.count=self.count-1
        self.heapify(1)
        return temp
    def display(self):
        print("heap contains",self.a)
    def maximum(self):
        print("the minimum is",self.a[1])
def main():
    a = [1, 2, 7, 8, 3, 4, 9, 70, 13, 15, 20]
    d = maxheap()
    d.arrayheap(a)
    d.insertheap(5)
    print("the extracted min element ",d.extractmax())
    print("the extracted min element ",d.extractmax())
    d.display()
    d.maximum()

if __name__ == '__main__':
    main()
