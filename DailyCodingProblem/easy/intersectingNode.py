"""
Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
"""

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None

"""
Solution 1, Find the difference in the length and then increase the pointer from the head of that longer list by that difference amount.
Loop through and keep incrementing, checking if the node is the same object to find the intersecting node. This will take O(M + N) time
and O(1) space.
"""

def intersecting_node_sol1(A, B):
    length_a = 0
    length_b = 0

    pointerA = A
    pointerB = B
    while (pointerA != None):
        length_a +=1
        pointerA = pointerA.next

    while (pointerB != None):
        length_b +=1
        pointerB = pointerB.next

    pointerA = A
    pointerB = B

    difference = length_a - length_b

    if (difference > 0):
        while(difference > 0):
            difference -= 1
            pointerA = pointerA.next
    
    if (difference < 0):
        while(difference < 0):
            difference += 1
            pointerB = pointerB.next

    while(pointerA != pointerB):
        pointerA = pointerA.next
        pointerB = pointerB.next

    return pointerA


def main():
    Anode = Node(3)
    Anode.next = Node(7)
    Anode.next.next = Node(234234)
    Anode.next.next.next = Node(5)
    Anode.next.next.next.next = Node(10)

    Bnode = Node(99)
    Bnode.next = Node(1)
    Bnode.next.next = Anode.next.next.next
    Bnode.next.next.next = Anode.next.next.next.next

    print(intersecting_node_sol1(Anode, Bnode).value)

main()