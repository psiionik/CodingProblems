# Notes on Closest Value BST

# Binary Search Tree

## Approach 1, Go through all nodes

Go through all of the nodes in infix traversal and then calculate the difference with the target at the leaf nodes.
When going back up, get the difference from the left subtree and the right subtree and then return the closest value from that corresponding subtree.

### Time Complexity

$O(n)$ - We have to visit every single node and calculate the difference for every node.

### Space Complexity

$O(n)$ - There are N (the number of nodes) recursive calls, so we have to use N memory in the callstack to save the information.

## Approach 2, Store in an array in sorted order and run binary search

Using infix traversal store all the values in an array (this will make it sorted). Run binary search to find the closest values in the sorted array to the target value and brute force find the value that is closest to the target.

### Time Complexity

$O(n)$ - Have to visit every single node to store them in an array

### Space Complexity

$O(n)$ - Have to store N nodes in an additional array.

## Approach 3, Get rid of half of the tree a time

Similar to approach 2 and binary search, compare the target value with the current node to get rid of (on average) half of the tree each iteration. Need a helper function for recursive solution to keep track of closest node value.

3 Cases:
1. If current node is equal to target, return current node
2. If the current node is less than target, recurse to the right
3. If the current node is greater than target, recurse to the right.

On each iteration calculate the absolute difference between the current node and the target and replace the closest node value if the new node's difference is smaller.

Works since if the current node is greater than the target, we know we don't have to check any of the values in the left side of the current node since it is guarenteed to have a greater absolute difference. Similarly on the other side.

### Time Complexity

Average: $O(log(n))$ - On average, get rid of half of the tree at a time since we get rid of having to search half of the tree.

Worst Case: $O(n)$ - In the worst case, there is only one branch and we have to check through all of the nodes to the end to find the closest value.

### Space Complexity

Recursive:
Average: $O(log(n))$ - On average, we will make $log(n)$ recursive calls on the stack so we need to save that much information.

Worst Case: $O(n)$ - In the worst case, we have to make N recursive calls so we have to save N function contexts in the stack.

Iterative:
$O(1)$ - Only need to save a constant number of variables to keep track of the closest value.