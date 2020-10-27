"""
In a row of trees, the i-th tree produces fruit with type tree[i].

You start at any tree of your choice, then repeatedly perform the following steps:

Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.

Note that you do not have any choice after the initial choice of starting tree:
you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?
"""

def totalFruit(tree):
    j = 0
    dic = {}
    maxlen = -float('inf')
    for i in range(len(tree)):
        if tree[i] not in dic:
            dic[tree[i]] = 1
        else:
            dic[tree[i]] += 1
        while len(dic) > 2:
            dic[tree[j]] -= 1
            if dic[tree[j]] == 0:
                del dic[tree[j]]
            j += 1
        maxlen = max(maxlen, i-j+1)
    return maxlen if maxlen != -float('inf') else 0
    

def main():

    # Test 1: Should return 5
    tree = [3,3,3,1,2,1,1,2,3,3,4]

    # Test 2: Should return 5
    # tree = [0,1,6,6,4,4,6]

    print(totalFruit(tree))

main()