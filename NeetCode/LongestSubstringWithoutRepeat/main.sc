import $file.Soln1, Soln1.Solution1
import $file.SolnOpt, SolnOpt.SolutionOpt
// import $file.Soln2, Soln2.Solution2

def testCase1(f: (String) => Int): Unit = {
    val s = "abcabcbb" 

    val res = f(s)
    println(res)

    val actual = 3

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (String) => Int): Unit = {
    val s = "bbbbb" 

    val res = f(s)
    println(res)

    val actual = 1

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase3(f: (String) => Int): Unit = {
    val s = "pwwkew" 

    val res = f(s)
    println(res)

    val actual = 3

    assert(res == actual, "Test Case 3 Failed!")
}

def runTestCases(f: (String) => Int): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
    // testCase4(f)
    // testCase5(f)
    // testCase6(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.lengthOfLongestSubstring)
}

@main def mainSolOpt() = {
    runTestCases(SolutionOpt.lengthOfLongestSubstring)
}

// @main def mainSol2() = {
//     runTestCases(Solution2.canAttendMeetings)
// }
