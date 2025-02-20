error id: _empty_/soln$package.diameterOfBinaryTreeSol1().
file://<WORKSPACE>/DiameterBinaryTree/soln1.scala
empty definition using pc, found symbol in pc: _empty_/soln$package.diameterOfBinaryTreeSol1().
semanticdb not found
|empty definition using fallback
non-local guesses:
	 -diameterOfBinaryTreeSol1.
	 -diameterOfBinaryTreeSol1#
	 -diameterOfBinaryTreeSol1().
	 -scala/Predef.diameterOfBinaryTreeSol1.
	 -scala/Predef.diameterOfBinaryTreeSol1#
	 -scala/Predef.diameterOfBinaryTreeSol1().

Document text:

```scala
/**
 * Definition for a binary tree node.
 * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
 *   var value: Int = _value
 *   var left: TreeNode = _left
 *   var right: TreeNode = _right
 * }
 */

class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
    var value: Int = _value
    var left: TreeNode = _left
    var right: TreeNode = _right
}

def diameterOfBinaryTree(root: TreeNode): Int = {
    var max_so_far = 0
    def recurse(node: TreeNode): Int = {
        // Base Case
        if (node.left == null && node.right == null) return 0

        // Recurse on left side
        val left_depth = if node.left != null then 1 + diameterOfBinaryTree(node.left) else 0

        // Recurse on right side
        val right_depth = if node.right != null then 1 + diameterOfBinaryTree(node.right) else 0

        if (left_depth + right_depth) > max_so_far then 
            max_so_far = left_depth + right_depth
            println(max_so_far)

        // Want to add the left and right side and return it
        return Math.max(left_depth, right_depth) 
    }

    recurse(root)
    return max_so_far
}

def testCase1(): Unit = {
    // TEST CASE 1
    val node_5 = new TreeNode(5)
    val node_4 = new TreeNode(4)
    val node_3 = new TreeNode(3)
    val node_2 = new TreeNode(2, node_4, node_5)
    val node_1 = new TreeNode(1, node_2, node_3)

    val res = diameterOfBinaryTreeSol1(node_1)
    println(res)

    assert(res == 3, "Test Case 1 Failed!")
}

def testCase2(): Unit = {
    val node_2 = new TreeNode(2)
    val node_1 = new TreeNode(1, node_2, null)

    val res = diameterOfBinaryTreeSol1(node_1)
    println(res)

    assert(res == 1, "Test Case 2 Failed!")
}

def runTestCases(): Unit = {
    testCase1()
    testCase2()
}

@main def main() = {
    runTestCases()
}    
```

#### Short summary: 

empty definition using pc, found symbol in pc: _empty_/soln$package.diameterOfBinaryTreeSol1().