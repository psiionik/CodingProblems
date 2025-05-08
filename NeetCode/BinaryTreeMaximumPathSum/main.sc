import $file.Soln1, Soln1.Solution1

def testCase1(f: (Solution1.TreeNode) => Int): Unit = {
    val left = Solution1.TreeNode(2, null, null)
    val right = Solution1.TreeNode(3, null, null)
    val root = Solution1.TreeNode(1, left, right)

    val res = f(root)
    println(res)

    val actual: Int = 6
    assert(res == actual, "Test Case 1 Failed!")

}

def testCase2(f: (Solution1.TreeNode) => Int): Unit = {
    val left = Solution1.TreeNode(9, null, null)
    val left_left = Solution1.TreeNode(15, null, null)
    val left_right = Solution1.TreeNode(7, null, null)
    val right = Solution1.TreeNode(20, left_left, left_right)
    val root = Solution1.TreeNode(-10, left, right)

    val res = f(root)
    println(res)

    val actual = 42

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase3(f: (Solution1.TreeNode) => Int): Unit = {
    val left = Solution1.TreeNode(-1, null, null)
    val root = Solution1.TreeNode(2, left, null)

    val res = f(root)
    println(res)

    val actual = 2 

    assert(res == actual, "Test Case 2 Failed!")
}

def runTestCases(f: (Solution1.TreeNode) => Int): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
    // testCase4(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.maxPathSum)
}
