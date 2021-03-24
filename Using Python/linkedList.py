# for creating a node
class Node:                                     
    def __init__(self,data=None,next=None):
        self.data = data
        self.next = next

# linked list operations 
class linkedList:
    def __init__(self):
        self.head = None

    # for inserting the list of values 
    def insert_value(self,data_list):
        self.head = None
        for i in data_list:
            self.insert_at_end(i)

    # for inserting value at begining    
    def insert_at_begining(self,data):
        node = Node(data,self.head)
        self.head = node

    # for inserting value at end 
    def insert_at_end(self,data):
        if self.head is None:
            self.head = Node(data,None)
            return
        
        itr = self.head
        while itr.next:
            itr = itr.next

        itr.next = Node(data,None)

    # for getting length of linked list 
    def get_length(self):
        count = 0
        itr = self.head
        while itr:
            count += 1
            itr = itr.next

        return count

    # for inserting value at given index 
    def insert_at_index(self,index,data):
        if index < 0 or index > self.get_length():
            raise Exception("Invalid Index")

        if index == 0:
            self.insert_at_begining(data)
            return

        count = 0
        itr = self.head
        while itr:
            if count == index - 1:
                node = Node(data,itr.next)
                itr.next = node
                break 

            itr = itr.next
            count += 1
    
    # for removing the node 
    def remove_at_index(self,index):
        if index < 0 or index > self.get_length():
            raise Exception("Invalid Index")

        if index == 0:
            self.head = self.head.next
            return

        count = 0
        itr = self.head
        while itr:
            if count == index-1:
                itr.next = itr.next.next

            itr = itr.next
            count += 1
    
    # for printing the linked List
    def print(self):
        if self.head is None:
            print("Linked List is empty")
            return
        itr = self.head
        llstr = ' '
        while itr:
            llstr += str(itr.data)+' --> ' if itr.next else str(itr.data)
            itr = itr.next

        print(llstr)

    # for inserting value after given value 
    def insert_after_value(self,data_after,data_insert):
        if self.head is None:
            return

        itr = self.head
        while itr:
            if itr.data == data_after:
                node = Node(data_insert,itr.next)
                itr.next = node
                break

            itr = itr.next

    # for removing node of given value 
    def remove_by_value(self,data):
        if self.head.data == data:
            self.head = self.head.next
            return

        itr = self.head
        while itr.next:
            if itr.next.data == data:
                itr.next = itr.next.next           
                break 
            itr = itr.next

if __name__== '__main__':
    li = linkedList()
    li.insert_value(['Nasik','Pune','Mumbai','Banglore'])
    li.remove_by_value('Nasik')
    li.print()

