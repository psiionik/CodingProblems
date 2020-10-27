"""
Implement a stack that has the following methods:

push(val), which pushes an element onto the stack
pop(), which pops off and returns the topmost element of the stack. If there are no elements in the stack,
then it should throw an error or return null.
max(), which returns the maximum value in the stack currently.
If there are no elements in the stack, then it should throw an error or return null.
Each method should run in constant time.
"""

"""
Solution 1, Use an array and just implement simple push and pop methods. To take care of getting the max of the list in constant
time, something additional must be added to push and pop. Have a second stack that holds just the maxes seen so far.
When pushing, if there is a new max, push to the second stack. When popping, if the value to be popped is the current max in the
second stack, then set the new max to the new thing in the second stack.
To get the max, just look at the top of the second stack.
"""

class Stack:
    def __init__(self):
        self.stack = []
        self.running_max = []
        self.current_max = 0

    def push(self, val):
        self.stack.append(val)
        if (len(self.running_max) <= 0):
            self.current_max = val
            self.running_max.append(val)
        else:
            if(val > self.running_max[-1]):
                self.current_max = val
                self.running_max.append(val)

    def pop(self):
        if (len(self.stack) <= 0):
            return None
        value_to_remove = self.stack[-1]
        if(value_to_remove == self.current_max):
            self.running_max.pop()
            if (len(self.running_max) <= 0):
                self.current_max = 0
            else:
                self.current_max = self.running_max[-1]
        return self.stack.pop()

    def getMax(self):
        if(len(self.stack) <= 0):
            return None
        else:
            if(len(self.running_max) <= 0):
                return None
            else:
                return self.running_max[-1]

def main():

    stack = Stack()
    stack.push(10)
    stack.push(2)
    stack.push(303033)
    print(stack.getMax())
    print(stack.pop())
    print(stack.getMax())
    print(stack.pop())
    print(stack.getMax())
    print(stack.pop())
    print(stack.getMax())


main()