# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def mergeTrees(t1: 'TreeNode', t2: 'TreeNode') -> 'TreeNode':
    if(t1 == None):
        return t2
    if(t2 == None):
        return t1
    
    if(t1 != None and t2 != None):
        t1.val = t1.val + t2.val

    if(t1.left == None and t2.left != None):
        t1.left = TreeNode(0)
    if(t1.right == None and t2.right != None):
        t1.right = TreeNode(0)


    mergeTrees(t1.left, t2.left)
    mergeTrees(t1.right, t2.right)

    return t1
    

