import $file.Soln1, Soln1.Solution1
import $file.Soln1, Soln1.Solution1.TreeNode
// import $file.SolnOpt, SolnOpt.SolutionOpt
// import $file.Soln2, Soln2.Solution2

def testCase1(f: (TreeNode) => TreeNode): Unit = {
    val nums = Array[Option[Int]](Some(4), Some(1), Some(6), Some(0), Some(2), Some(5), Some(7), None, None, None, Some(3), None, None, None, Some(8)) 
    val root = Solution1.parseBST(nums, 0)

    val res = f(root)

    val res_arr = Array.fill[Option[Int]](nums.length)(None)
    Solution1.convertBSTToArray(res, 0, res_arr)
    println(res_arr.mkString(" "))

    val actual = Array[Option[Int]](Some(30), Some(36), Some(21), Some(36), Some(35), Some(26), Some(15), None, None, None, Some(33), None, None, None, Some(8))

    assert(res_arr.corresponds(actual)(_.getOrElse(-1) == _.getOrElse(-1)), "Test Case 1 Failed! Elements are not the same")
}

def testCase2(f: (TreeNode) => TreeNode): Unit = {
    val nums = Array[Option[Int]](Some(0), None, Some(1)) 
    val root = Solution1.parseBST(nums, 0)

    val res = f(root)

    val res_arr = Array.fill[Option[Int]](nums.length)(None)
    Solution1.convertBSTToArray(res, 0, res_arr)
    println(res_arr.mkString(" "))

    val actual = Array[Option[Int]](Some(1), None, Some(1))

    assert(res_arr.corresponds(actual)(_.getOrElse(-1) == _.getOrElse(-1)), "Test Case 2 Failed! Elements are not the same")
}

def runTestCases(f: (TreeNode) => TreeNode): Unit = {
    testCase1(f)
    testCase2(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.bstToGst)
}

// @main def mainSolOpt() = {
//     runTestCases(SolutionOpt.rob)
// }

