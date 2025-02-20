error id: `<none>`.
file://<WORKSPACE>/DiameterBinaryTree/soln.scala
empty definition using pc, found symbol in pc: `<none>`.
empty definition using semanticdb
|empty definition using fallback
non-local guesses:
	 -

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

def diameterOfBinaryTreeSol1(root: TreeNode): Int = {

    // Base Case
    if (root.left == null && root.right == null) return 1;

    // Recurse on left side
    val left_depth = if root.left != null then diameterOfBinaryTreeSol1(root.left) else 0

    // Recurse on right side
    val right_depth = if root.right != null then diameterOfBinaryTreeSol1(root.right) else 0

    // Want to add the left and right side and return it
    return left_depth + right_depth
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

empty definition using pc, found symbol in pc: `<none>`.