from collections import deque

class Queue:
    def __init__(self):
        self.buffer = deque()

    def enqueue(self,data):
        self.buffer.appendleft(data)

    def dequeue(self):
        return self.buffer.pop()
    
    def isEmpty(self):
        return len(self.buffer) == 0

    def sizee(self):
        return len(self.buffer)

    def print_queue(self):
        print(self.buffer)

if __name__ == '__main__':
    q = Queue()
    q.enqueue(5)
    q.enqueue(6)
    q.enqueue(7)
    q.enqueue(8)
    q.print_queue()