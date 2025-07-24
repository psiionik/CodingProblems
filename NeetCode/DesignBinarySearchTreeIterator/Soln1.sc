/* 
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

- BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. 
    The pointer should be initialized to a non-existent number smaller than any element in the BST.
- boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
- int next() Moves the pointer to the right, then returns the number at the pointer.

Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

Example 1:

Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
 
Constraints:

The number of nodes in the tree is in the range [1, 105].
0 <= Node.val <= 106
At most 105 calls will be made to hasNext, and next.

Follow up:

Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the tree?
 */

import scala.collection.mutable.Stack

object Solution1 {
    /**
     * Your BSTIterator object will be instantiated and called as such:
     * val obj = new BSTIterator(root)
     * val param_1 = obj.next()
     * val param_2 = obj.hasNext()
     */

    class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
        var value = _value
        var left = _left
        var right = _right
    }

    class BSTIterator(_root: TreeNode) {
        // The overall idea is that we are going to use a memory structure (Stack) to mimic the call stack that normally gets utilized during recursive
        // calls in In-Order Traversal
        // Basically, we are going to have to store each "frame" of the call stack for each recursive call
        val dfs_stack = Stack[TreeNode]()

        // Dummy pointer to initialize the iterator, -1 is a non-valid value so it can be utilized here
        var pointer = TreeNode(-1)

        // Populate the stack with all of the nodes of the left side of recursion in the BST
        _add_callstack_frames_left(_root)

        // Helper function to add all nodes that would normally be in the recursive call stack frames
        // This is to discretely remember / abstract out the left recursive of the in-order traversal
        def _add_callstack_frames_left(node: TreeNode): Unit = {
            var temp = node
            while (temp != null) {
                dfs_stack.push(temp)
                temp = temp.left
            }
        }

        def next(): Int = {
            if !dfs_stack.isEmpty
            then
                pointer = dfs_stack.pop()
                if pointer.right != null
                then
                    _add_callstack_frames_left(pointer.right)
            
            pointer.value
        }

        def hasNext(): Boolean = {
            !dfs_stack.isEmpty || pointer.right != null
        }
    }
}