error id: `<init>`.
file://<WORKSPACE>/DiameterBinaryTree/main.sc
empty definition using pc, found symbol in pc: `<init>`.
semanticdb not found
|empty definition using fallback
non-local guesses:
	 -

Document text:

```scala
import $file.Soln1, Soln1.Solution1

def testCase1(): Unit = {
    // TEST CASE 1
    val node_5 = new TreeNode(5)
    val node_4 = new TreeNode(4)
    val node_3 = new TreeNode(3)
    val node_2 = new TreeNode(2, node_4, node_5)
    val node_1 = new TreeNode(1, node_2, node_3)

    val res = diameterOfBinaryTree(node_1)
    println(res)

    assert(res == 3, "Test Case 1 Failed!")
}

def testCase2(): Unit = {
    val node_2 = new TreeNode(2)
    val node_1 = new TreeNode(1, node_2, null)

    val res = diameterOfBinaryTree(node_1)
    println(res)

    assert(res == 1, "Test Case 2 Failed!")
}

def testCase3(): Unit = {
    diameterOfBinaryTree_testCase1_Sol1()
    diameterOfBinaryTree_testCase2_Sol1()
}

@main def mainSol1() = {
    runTestCases(Solution1.combinationSum2)
}

@main def mainSol2() = {
    runTestCases(Solution2.combinationSum2)
}
```

#### Short summary: 

empty definition using pc, found symbol in pc: `<init>`.