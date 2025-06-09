import $file.Soln1, Soln1.Solution1
// import $file.SolnOpt, SolnOpt.SolutionOpt
// import $file.Soln2, Soln2.Solution2

def testCase1(f: (Int, Int) => Int): Unit = {
    val m = 3
    val n = 7

    val res = f(m, n)
    println(res)

    val actual = 28 

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (Int, Int) => Int): Unit = {
    val m = 3
    val n = 2

    val res = f(m, n)
    println(res)

    val actual = 3

    assert(res == actual, "Test Case 2 Failed!")
}

def runTestCases(f: (Int, Int) => Int): Unit = {
    testCase1(f)
    testCase2(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.uniquePaths)
}