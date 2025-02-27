class LinkedList:
    def __init__(self):
        self.head = Node(None)
        self.tail = Node(None)
        self.current = self.head
        self.head.next = self.tail

    def appendToTail(self, value):
        newNode = Node(value)
        if(self.head.next == self.tail):
            self.head.next = newNode
            self.current = newNode
            self.current.prev = self.head
            self.current.next = self.tail
            self.tail.prev = self.current
        else:
            while(self.current.next != self.tail):
                self.current = self.current.next
            self.current.next = newNode
            self.current.next.prev = self.current
            self.tail.prev = self.current.next
            self.current.next.next = self.tail

    def find(self, value):
        iterNode = self.head
        while(iterNode.next != self.tail):
            if(iterNode.value == value):
                return iterNode
            iterNode = iterNode.next
        return None

    def delete(self, value):
        iterNode = self.head
        while(iterNode.next != self.tail):
            if(iterNode.value == value):
                iterNode.next.prev = iterNode.prev
                iterNode.prev.next = iterNode.next
                break
            iterNode = iterNode.next
    

    def __iter__(self):
        self.currentIterator = self.head.next
        return self
    
    def __next__(self):
        if(self.currentIterator.next != None):
            node = self.currentIterator
            self.currentIterator = self.currentIterator.next
            return node
        raise StopIteration


class Node:
    def __init__(self, value):
        self.next = None
        self.prev = None
        self.value = value
        
def solution(D, A):
    result = [-1]*len(A)
    s = LinkedList()
    if(len(A) == 0):
        return result
    
    if(len(A) == 1):
        result.append(-1)
        return result
    count = 0
    i = 0
    s.appendToTail(i)
    while(count < len(A) -1):
        i = A.index(i)
        s.appendToTail(i)
        count +=1
    
    counter = 0
    pointer = s.head.next
    while(pointer.next != None):
        counter = 0
        temp = pointer
        while(counter < D):
           
            temp = temp.prev
            if(temp == None):
                break
            counter += 1
        if (temp != None):
            if(temp.value != None):
                result[pointer.value] = temp.value
        else:
            result[pointer.value] = -1
        pointer = pointer.next
        
    return result


def main():
    a= [-1, 0, 4, 2, 1]
    x = solution(3, a)
    print(x)

main()