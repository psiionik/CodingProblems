import $file.Soln1, Soln1.Solution1
import $file.Soln1, Soln1.Solution1.TreeNode
// import $file.SolnOpt, SolnOpt.SolutionOpt
// import $file.Soln2, Soln2.Solution2

def testCase1(f: (TreeNode) => Int): Unit = {
    val l = TreeNode(0)
    val r = TreeNode(0)
    val root = TreeNode(3, l, r)

    val res = f(root)
    println(res)

    val actual = 2

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (TreeNode) => Int): Unit = {
    val l = TreeNode(3)
    val r = TreeNode(0)
    val root = TreeNode(0, l, r)

    val res = f(root)
    println(res)

    val actual = 3

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase3(f: (TreeNode) => Int): Unit = {
    val ll = TreeNode(4)
    val lr = TreeNode(0)
    val l = TreeNode(0, ll, lr)
    val rl = TreeNode(1)
    val rr = TreeNode(0)
    val r = TreeNode(2, rl, rr)
    val root = TreeNode(0, l, r)

    val res = f(root)
    println(res)

    val actual = 6

    assert(res == actual, "Test Case 3 Failed!")
}

def runTestCases(f: (TreeNode) => Int): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.distributeCoins)
}