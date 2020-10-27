class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def allPossibleFBT(N):
    N -= 1
    if N == 0: return [TreeNode(0)]
    ret = []
    for l in range(1, min(20, N), 2):
        for left in allPossibleFBT(l):
            
            for right in allPossibleFBT(N - l):
                root = TreeNode(0)
                root.left = left
                root.right = right
                ret += [root]
    return ret

def main():
    n = 7
    x = allPossibleFBT(n)
#     for i in x:
#        print(i.val)
main()