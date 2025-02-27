class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value

def constructTree(sequence):
    sequence = sequence[::-1]
    root = Node(sequence[0])
    for index in range(1, len(sequence)):
        helper(root, index, sequence)

    return root

def helper(root, index, sequence):
    if (root == None):
        return Node(sequence[index])

    if (sequence[index] < root.value):
        root.left = helper(root.left, index, sequence)

    if (sequence[index] > root.value):
        root.right = helper(root.right, index, sequence)

    return root


def printPostfix(root):
    if (root.left):
        printPostfix(root.left)
    if (root.right):
        printPostfix(root.right)
    print(root.value)

class BSTNode:
    def __init__(self, val, left=None, right=None):
        self.value = val
        self.left = left
        self.right = right
    
def reconstruct(postorder):
    if not postorder:
        return None
    elif len(postorder) == 1:
        return BSTNode(postorder[0])

    root_val = postorder[-1]
    root = BSTNode(root_val)
    
    for i, val in enumerate(postorder[:-1]):
        if val > root_val:
            left_subtree = reconstruct(postorder[:i])
            right_subtree = reconstruct(postorder[i:-1])
            root.left = left_subtree
            root.right = right_subtree
            return root

    left_subtree = reconstruct(postorder[:-1])
    root.left = left_subtree
    return root

def main():

    # Should return tree with right post order

    sequence = [2, 4, 3, 8, 7, 5]

#    printPostfix(constructTree(sequence))
    printPostfix(reconstruct(sequence))

main()
