import $file.Soln1, Soln1.Solution1
// import $file.SolnOpt, SolnOpt.SolutionOpt
// import $file.Soln2, Soln2.Solution2

def testCase1(f: (Array[Int]) => Int): Unit = {
    val ratings = Array(1, 0, 2)

    val res = f(ratings)
    println(res)

    val actual = 5

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (Array[Int]) => Int): Unit = {
    val ratings = Array(1, 2, 2)

    val res = f(ratings)
    println(res)

    val actual = 4

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase3(f: (Array[Int]) => Int): Unit = {
    val ratings = Array(0, 1, 2, 3, 4, 5)

    val res = f(ratings)
    println(res)

    val actual = 21

    assert(res == actual, "Test Case 3 Failed!")
}

def testCase4(f: (Array[Int]) => Int): Unit = {
    val ratings = Array(29,51,87,87,72,12)

    val res = f(ratings)
    println(res)

    val actual = 12

    assert(res == actual, "Test Case 4 Failed!")
}

def runTestCases(f: (Array[Int]) => Int): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
    testCase4(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.candy)
}

// @main def mainSolOpt() = {
//     runTestCases(SolutionOpt.rob)
// }