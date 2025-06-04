import $file.Soln1, Soln1.Solution1
// import $file.SolnOpt, SolnOpt.SolutionOpt
// import $file.Soln2, Soln2.Solution2

def testCase1(f: (Array[Array[Char]]) => Int): Unit = {
    val matrix = Array(
        Array('1','0','1','0','0'),
        Array('1','0','1','1','1'),
        Array('1','1','1','1','1'),
        Array('1','0','0','1','0')
    ) 

    val res = f(matrix)
    println(res)

    val actual = 4

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (Array[Array[Char]]) => Int): Unit = {
    val matrix = Array(
        Array('0', '1'),
        Array('1', '0')
    ) 

    val res = f(matrix)
    println(res)

    val actual = 1

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase3(f: (Array[Array[Char]]) => Int): Unit = {
    val matrix = Array(
        Array('0')
    ) 

    val res = f(matrix)
    println(res)

    val actual = 0

    assert(res == actual, "Test Case 3 Failed!")
}

def runTestCases(f: (Array[Array[Char]]) => Int): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.maximalSquare)
}

// @main def mainSolOpt() = {
//     runTestCases(SolutionOpt.rob)
// }