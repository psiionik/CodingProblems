"""
Given the root to a binary search tree, find the second largest node in the tree.
"""

"""
Solution 1, Traverse through the binary search tree using infix traversal and save the numbers in an array through the recursion.
When all of the recursive functions return, just return the second to last number in the array.
Runtime: O(n), Space: O(n)
"""

"""
Solution 2, Same thing as solution 1, but have two variables to keep track of the max and the second most max and then at the
end of the traversal, return the variable that corresponds to the second most max.
"""


class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def second_largest_bst_sol1(root):
    
    arr = []

    def helper(root):

        if not root or count[0] == 2:
            return
        
        if(root.right):
            helper(root.right)
        count[0] += 1
        if(count[0] == 2):
            val.append(root.value)
            return

        if(root.left):
            helper(root.left)

    count = [0]
    val = []
    helper(root)

    return val[0]

"""
Solution 3, Do a reverse in-order traversal where we first call recursively on the right node. Can keep a counter and once we process
the node, we can increment the counter. Once it hits 2, that means the current node is the second largest, so we stuff it in a variable
and eventually return it. Runtime: O(n) but faster in practice, Space: O(1)
"""


def main():

    # Test 1: Should return 10

    root = Node(5)
    root.left = Node(4)
    root.left.left = Node(2)
    root.left.right = Node(3)
    root.right = Node(6)
    root.right.left = Node(5.5)
    root.right.right = Node(10)
    root.right.right.right = Node(11)

    print(second_largest_bst_sol1(root))

main()