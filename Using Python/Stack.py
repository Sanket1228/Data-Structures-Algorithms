from collections import deque

class Stack:
    def __init__(self):
        self.container = deque()

    def push(self,data):
        self.container.append(data)
    
    def pop(self):
        return self.container.pop()

    def peek(self):
        return self.container[-1]

    def isEmpty(self):
        return len(self.container) == 0

    def size(self):
        return len(self.container)

    def print_stack(self):
        return (self.container)

    def print_reverse_stack(self,data):
        return (data[::-1])

def reverse_stack_string(s):
    stack = Stack()

    for i in s:
        stack.push(i)

    rstr = ''
    while stack.size() != 0:
        rstr += stack.pop()

    return rstr
    
if __name__ == '__main__':
    # s = Stack()
    # s.push("we will conquere COVID-19")
    # pop = s.pop()
    # rev = s.print_reverse_stack(pop)
    # print(rev)

    string = reverse_stack_string("we will conquere COVID-19")
    print(string)