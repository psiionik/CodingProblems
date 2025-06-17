import $file.Soln1, Soln1.Solution1
import $file.Soln1, Soln1.Solution1.TreeNode

def testCase1(f: (TreeNode, Int) => TreeNode): Unit = {
    val ll = TreeNode(2)
    val lr = TreeNode(4)
    val l = TreeNode(3, ll, lr)
    val rr = TreeNode(7)
    val r = TreeNode(6, null, rr)
    val root = TreeNode(5, l, r)

    val key = 3
    val res = f(root, key)
    println(res)

    val expected = root 
    assert(res == expected, "Test Case 1 Failed!")
}

def runTestCases(f: (TreeNode, Int) => TreeNode): Unit = {
    testCase1(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.deleteNode)
}
