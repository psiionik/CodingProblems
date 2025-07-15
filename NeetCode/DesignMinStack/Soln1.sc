/* 
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

- MinStack() initializes the stack object.
- void push(int val) pushes the element val onto the stack.
- void pop() removes the element on the top of the stack.
- int top() gets the top element of the stack.
- int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Constraints:

-2^31 <= val <= 2^31 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
 */

import scala.collection.mutable.Stack

object Solution1 {
    /**
     * Your MinStack object will be instantiated and called as such:
     * val obj = new MinStack()
     * obj.push(`val`)
     * obj.pop()
     * val param_3 = obj.top()
     * val param_4 = obj.getMin()
    */
    
    class MinStack() {
        // Overall idea is to maintain a stack of values of tuples where the first item in the tuple is the corresponding value
        // and the second item is the min element seen thus far
        var stack = Stack[(Int, Int)]()

        def push(`val`: Int): Unit = {
            if stack.isEmpty
            then
                stack.push((`val`, `val`)) 
            else
                val min_so_far = stack.top(1)
                stack.push((`val`, Math.min(`val`, min_so_far)))
        }

        def pop(): Unit = {
            stack.pop() 
        }

        def top(): Int = {
            return stack.top(0)
        }

        def getMin(): Int = {
            return stack.top(1)
        }
    }
}