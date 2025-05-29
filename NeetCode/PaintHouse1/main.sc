import $file.Soln1, Soln1.Solution1
// import $file.SolnOpt, SolnOpt.SolutionOpt
// import $file.Soln2, Soln2.Solution2

def testCase1(f: (Array[Array[Int]]) => Int): Unit = {
    val costs = Array(
        Array(17, 2, 17),
        Array(16, 16, 5),
        Array(14, 3, 19)
    ) 

    val res = f(costs)
    println(res)

    val actual = 10

    assert(res == actual, "Test Case 1 Failed!")
}

// def testCase2(f: (Array[Int]) => Int): Unit = {
//     val nums = Array(2, 7, 9, 3, 1)

//     val res = f(nums)
//     println(res)

//     val actual = 12 

//     assert(res == actual, "Test Case 2 Failed!")
// }

// def testCase3(f: (Array[Int]) => Int): Unit = {
//     val nums = Array(1, 1, 3, 3)

//     val res = f(nums)
//     println(res)

//     val actual = 4 

//     assert(res == actual, "Test Case 2 Failed!")
// }

// def testCase4(f: (Array[Int]) => Int): Unit = {
//     val nums = Array(2, 9, 8, 3, 6)

//     val res = f(nums)
//     println(res)

//     val actual = 16 

//     assert(res == actual, "Test Case 2 Failed!")
// }

// def testCase5(f: (Array[Int]) => Int): Unit = {
//     val nums = Array(111)

//     val res = f(nums)
//     println(res)

//     val actual = 111 

//     assert(res == actual, "Test Case 2 Failed!")
// }

// def testCase6(f: (Array[Int]) => Int): Unit = {
//     val nums = Array(1000, 2, 6, 1001, 10)

//     val res = f(nums)
//     println(res)

//     val actual = 2001 

//     assert(res == actual, "Test Case 2 Failed!")
// }

def runTestCases(f: (Array[Array[Int]]) => Int): Unit = {
    testCase1(f)
    // testCase2(f)
    // testCase3(f)
    // testCase4(f)
    // testCase5(f)
    // testCase6(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.minCost)
}

// @main def mainSolOpt() = {
//     runTestCases(SolutionOpt.rob)
// }

// @main def mainSol2() = {
//     runTestCases(Solution2.canAttendMeetings)
// }
