# Notes on Branch Sum

# Tree Traversal, Recursive Helper

## Approach 1, Go through all nodes in a DFS traversal, keeping track of sum so far and list of sums

Go through all of the nodes in a DFS traversal, specifically a prefix traversal. At each node, you want to recursively add that node's value to the accumulating sum and branch off the to the left and right child if they exist. At the leaf nodes, you append that leaf node's value to the running sum and append that sum to the list of sums. This requires a recursive helper function that keeps track of 3 parameters:
1. The tree
2. The list you are building
3. The running sum

At each node, recursively call the left and right and add the node's value to the running sum

### Time Complexity

$O(n)$ - Have to visit every single node to get all the branch sums.

### Space Complexity

$O(n)$ - At each recursive call, will have at most $log(n)$ space used on the call stack since going down a subtree gets rid of the other half of the subtree until that first subtree returns and removes its context from the callstack. Also, the list of branch sums are approximately $n/2$ which asymtotically is $n$ so the space complexity comes out to be linear.