import $file.Soln1, Soln1.Solution1
import $file.Soln1, Soln1.Solution1.TreeNode

def testCase1(f: (TreeNode, Int, Int) => String): Unit = {
    // TEST CASE 1
    val ll = TreeNode(3, null, null)
    val l = TreeNode(1, ll, null)
    val rl = TreeNode(6, null, null)
    val rr = TreeNode(4, null, null)
    val r = TreeNode(2, rl, rr)
    val root = TreeNode(5, l, r)

    val res = f(root, 3, 6)
    println(res)

    val expected = "UURL"

    assert(res == expected, "Test Case 1 Failed!")
}

def testCase2(f: (TreeNode, Int, Int) => String): Unit = {
    // TEST CASE 1
    val l = TreeNode(1, null, null)
    val root = TreeNode(2, l, null)

    val res = f(root, 2, 1)
    println(res)

    val expected = "L"

    assert(res == expected, "Test Case 2 Failed!")
}

def runTestCases(f: (TreeNode, Int, Int) => String): Unit = {
    testCase1(f)
    testCase2(f)
}


@main def mainSol1() = {
    runTestCases(Solution1.getDirections)
}