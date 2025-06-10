import $file.Soln1, Soln1.Solution1

def testCase1(f: (Int) => List[String]): Unit = {
    val n = 3

    val res = f(n)
    println(res)

    val actual = List("((()))","(()())","(())()","()(())","()()()") 

    assert(res == actual, "Test Case 1 Failed!")
}

def runTestCases(f: (Int) => List[String]): Unit = {
    testCase1(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.generateParenthesis)
}

// @main def mainSolOpt() = {
//     runTestCases(SolutionOpt.rob)
// }