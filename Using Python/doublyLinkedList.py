# creating Node for doubly linked list 
class Node:
    def __init__(self, data=None, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev

# Doubly Linked List 
class DoublyLinkedList:
    def __init__(self):
        self.head = None

    # inserting value at begining 
    def insert_at_begining(self, data):
        if self.head == None:
            node = Node(data, self.head, None)
            self.head = node
        else:
            node = Node(data, self.head, None)
            self.head.prev = node
            self.head = node

    # for getting length of list 
    def get_length(self):
        count = 0
        itr = self.head
        while itr:
            count += 1
            itr = itr.next

        return count

    # for getting last element in list 
    def get_last_element(self):
        itr = self.head
        while itr.next:
            itr = itr.next
        return itr

    # for inserting element at last 
    def insert_at_end(self, data):
        if self.head == None:
            self.head = Node(data, None, None)
            return

        itr = self.head
        while itr.next:
            itr = itr.next

        itr.next = Node(data, None, itr)
 
    # for inserting element at given index 
    def insert_at_index(self, index, data):
        if index < 0 or index > self.get_length():
            raise Exception("Invalid Index")

        if index == 0:
            return self.insert_at_begining(data)

        count = 0
        itr = self.head
        while itr:
            if count == index-1:
                node = Node(data, itr.next, itr)
                if node.next:
                    node.next.prev = node
                itr.next = node
                break
            itr = itr.next
            count += 1

    # for removing value at given index 
    def remove_at_index(self, index):
        if index < 0 or index > self.get_length():
            raise Exception("Invalid Index")

        if index == 0:
            self.head = self.head.next
            self.head.next.prev = None
        
        count = 0
        itr = self.head
        while itr:
            if count == index-1:
                itr.next = itr.next.next
                itr.next.prev = itr
            itr = itr.next
            count += 1

    # for printing the list 
    def print(self):
        if self.head is None:
            print("Your node is empty")
            return

        itr = self.head
        dll = '<-- '

        while itr:
            dll += str(itr.data) + ' <--> '
            itr = itr.next

        print(dll)

    # for inserting values throught list input 
    def insert_values(self, data_list):
        self.head = None
        for i in data_list:
            self.insert_at_end(i)


if __name__ == '__main__':
    dbl = DoublyLinkedList()
    dbl.insert_values([2, 3, 4, 5, 6, 7])
    dbl.remove_at_index(0)
    dbl.print()
