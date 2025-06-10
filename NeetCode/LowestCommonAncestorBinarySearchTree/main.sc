import $file.Soln1, Soln1.Solution1
import $file.Soln1, Soln1.Solution1.TreeNode

def testCase1(f: (TreeNode, TreeNode, TreeNode) => TreeNode): Unit = {
    // TEST CASE 1
    val list_of_nodes = Array[Int | Null](6,2,8,0,4,7,9,null,null,3,5)

    val root = Solution1.parseTreeNodeList(list_of_nodes, 0)
    val p = root.left 
    val q = root.right

    val res = f(root, p, q)
    println(res)

    val expected = root 

    assert(res == expected, "Test Case 1 Failed!")
}

def testCase2(f: (TreeNode, TreeNode, TreeNode) => TreeNode): Unit = {
    // TEST CASE 2

    val list_of_nodes = Array[Int | Null](6,2,8,0,4,7,9,null,null,3,5)
    val root = Solution1.parseTreeNodeList(list_of_nodes, 0)
    val p = root.left
    val q = root.left.right

    val res = f(root, p, q)
    println(res)

    val expected = root.left

    assert(res == expected, "Test Case 2 Failed!")
}

def runTestCases(f: (TreeNode, TreeNode, TreeNode) => TreeNode): Unit = {
    testCase1(f)
    testCase2(f)
}


@main def mainSol1() = {
    runTestCases(Solution1.lowestCommonAncestor)
}