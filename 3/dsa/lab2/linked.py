class LinkedList:
    """Defines a Singly Linked List.

    attributes: head
    """
    
    def __init__(self):
        """Create a new list with a Sentinel Node"""
        self.head=ListNode();

    def insert(self,x,p):
        """Insert element x in the position after p"""
        print("inserting",x,"at given position")
        temp=ListNode()
        temp.value=x
        temp.next=p.next
        p.next=temp


    def delete(self,p):
        """Delete the node following node p in the linked list."""
        print("deleting node at given position")
        temp=p.next
        p.next=temp.next

    def printlist(self):
        """ Print all the elements of a list in a row."""
        print("List is")
        temp=self.head.next
        while temp!=None:
            print(temp.value)
            temp=temp.next
        



    def insertAtIndex(self,x,i):
        """Insert value x at list position i. (The position of the first element is taken to be 0.)"""
        ''' i will stop at one position priror'''
        t=0
        temp=self.head
        while(t<i):
            temp=temp.next
            t=t+1
        '''normal insert pos'''
        p=temp
        temp=ListNode()
        temp.value=x
        temp.next=p.next
        p.next=temp

    def search(self,x):
        """Search for value x in the list. Return a reference to the first node with value x; return None if no such node is found."""
        temp=self.head.next
        while temp!=None:
            if temp.value==x:
                print("element found")
                return temp
            temp=temp.next
        return None

    def len(self):
        """Return the length (the number of elements) in the Linked List."""
        len=0
        temp=self.head.next
        while temp!=None:
            len=len+1
            temp=temp.next
        return len

        

    def isEmpty(self):
        """Return True if the Linked List has no elements, False otherwise."""
        if self.head.next==None:
            return True
        else:
            return False


class ListNode:
    """Represents a node of a Singly Linked List.

    attributes: value, next. 
    """
    def __init__(self,val=None,nxt=None):
        self.value=val
        self.next=nxt

def main():
    L = LinkedList()
    L.insert(10,L.head)

    L.printlist()
    L.insert(12,L.head.next)
    L.printlist()
    L.insert(2,L.head)
    L.printlist()
    print('Size of L is ',L.len())
    L.delete(L.head)
    L.printlist()
    
    L.delete(L.head.next)
    L.printlist()
    print('List is empty?',L.isEmpty())
    print('Size of L is ',L.len())
    L.delete(L.head)
    print('List is empty?',L.isEmpty())
    print('Size of L is ',L.len())
    L.insertAtIndex(2,0)
    L.insertAtIndex(1,0)
    L.insertAtIndex(4,2)
    L.insertAtIndex(3,2)
    L.printlist()
    print(L.search(3))
    

if __name__ == '__main__':
    main()
