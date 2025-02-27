"""
A unival tree is a tree where all of the nodes under it have the same value

Given the root to a binary tree, count the number of unival subtrees

For example, the following has 5 unival subtrees

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
"""

"""
Solution 1, can traverse through the whole tree using DFS and then on the way back, check if the subtree is a unival tree
and if a non-leaf node left and right subtree returns true and their values are the same as that current node, then add one to the count.
If at a leaf node, it is a unival tree so add 1.
"""

# Node helper class to make the tree and test it
class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def count_unival_sol_1(root):
    count = 0
    def recursive_helper(node, running_count):
        running_count_left = 0
        running_count_right = 0
        left_subtree_bool = False
        right_subtree_bool = False

        if(node.left == None and node.right == None):
            return True, 1
        
        if(node.left):
            left_subtree_bool, running_count_left = recursive_helper(node.left, running_count)
        if (node.right):
            right_subtree_bool, running_count_right = recursive_helper(node.right, running_count)

        total_count = running_count_left + running_count_right


        if(left_subtree_bool or right_subtree_bool):
            if(node.left and node.right):
                if(left_subtree_bool and right_subtree_bool and node.left.value == node.value and node.right.value == node.value):
                    total_count += 1
            elif(node.left):
                if(node.left.value == node.value):
                    total_count += 1
                    return True, total_count
            elif(node.right):
                if(node.right.value == node.value):
                    total_count += 1
                    return True, total_count

            return (left_subtree_bool and right_subtree_bool), total_count
        else:
            return False, total_count

    result, result_count = recursive_helper(root, count)
    return result_count


"""
Actual Solution, first make a function that checks if the tree is unival or not and use it to count up all the nodes in a tree.
Function becomes a function that just counts the number of subtrees that use that function. This runs in O(n^2) time since at
each node, we are evaluating everything in the subtree again. Better method is to start at the leaves of the tree and keep track
of the universal subtree count and value as you percolate back up. This evaluates each node once which is O(n) time.
"""

def count_unival_sol_2(root):
    count, _ = helper(root)
    return count

def helper(root):
    if root is None:
        return 0, True
    
    left_count, is_left_unival = helper(root.left)
    right_count, is_right_unival = helper(root.right)
    total_count = left_count + right_count

    if is_left_unival and is_right_unival:
        if (root.left is not None and root.value != root.left.value):
            return total_count, False
        if (root.right is not None and root.value != root.right.value):
            return total_count, False
        return total_count + 1, True

    return total_count, False

def main():
    """
    Test 1: Should return 5
          0
         / \
        1   0
           / \
          1   0
         / \
        1   1
    """
    root_node = Node(0)
    root_node.left = Node(1)
    root_node.right = Node(0)
    root_node.right.right = Node(0)
    root_node.right.left = Node(1)
    root_node.right.left.right = Node(1)
    root_node.right.left.left = Node(1)

    """
    Test 2: Should return 3
      a
     / \
    a   a
        /\
       a  a
           \
            A
    """
    # root_node = Node('a')
    # root_node.left = Node('a')
    # root_node.right = Node('a')
    # root_node.right.left = Node('a')
    # root_node.right.right = Node('a')
    # root_node.right.right.right = Node('A')

    """
    Test 3: Should return 5

      a
     / \
    c   b
        /\
       b  b
           \
            b
    """
    # root_node = Node('a')
    # root_node.left = Node('c')
    # root_node.right = Node('b')
    # root_node.right.left = Node('b')
    # root_node.right.right = Node('b')
    # root_node.right.right.right = Node('b')

    print(count_unival_sol_2(root_node))


main()