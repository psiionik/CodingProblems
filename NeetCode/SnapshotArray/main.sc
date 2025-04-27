import $file.Soln1, Soln1.Solution1
// import $file.Soln2, Soln2.Solution2
// import $file.SolnOpt, SolnOpt.SolutionOpt

def testCase1(): Unit = {
    val snapshot_array: Solution1.SnapshotArray  = new Solution1.SnapshotArray(5)

    println(snapshot_array._data.mkString(" "))
}

def testCase1Opt(): Unit = {
    println("test")
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

def runTestCases(): Unit = {
    testCase1()
    // testCase1Opt()
    // testCase2()
    // testCase3()
    // testCase4()
    // testCase5()
}

@main def mainSol1() = {
    runTestCases()
}

// @main def mainSol2() = {
//     runTestCases(Solution2.canAttendMeetings)
// }

// @main def mainSolOpt() = {
//     runTestCases()
// }

