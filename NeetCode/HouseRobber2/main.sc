import $file.Soln1, Soln1.Solution1
// import $file.Soln2, Soln2.Solution2
// import $file.SolnOpt, SolnOpt.SolutionOpt

def testCase1(f: (Array[Int]) => Int): Unit = {
    val nums = Array(2, 3, 2) 

    val res = f(nums)
    println(res)

    val actual = 3

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (Array[Int]) => Int): Unit = {
    val nums = Array(1, 2, 3, 1)

    val res = f(nums)
    println(res)

    val actual = 4 

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase3(f: (Array[Int]) => Int): Unit = {
    val nums = Array(1, 2, 3)

    val res = f(nums)
    println(res)

    val actual = 3 

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase4(f: (Array[Int]) => Int): Unit = {
    val nums = Array(2)

    val res = f(nums)
    println(res)

    val actual = 2 

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase5(f: (Array[Int]) => Int): Unit = {
    val nums = Array(1000, 2, 6, 10, 2002)

    val res = f(nums)
    println(res)

    val actual = 2008 

    assert(res == actual, "Test Case 2 Failed!")
}

def runTestCases(f: (Array[Int]) => Int): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
    testCase4(f)
    testCase5(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.rob)
}

// @main def mainSol2() = {
//     runTestCases(Solution2.canAttendMeetings)
// }

// @main def mainSolOpt() = {
//     runTestCases(SolutionOpt.rob)
// }

