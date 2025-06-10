import $file.Soln1, Soln1.Solution1

def testCase1(f: (String, String) => Int): Unit = {
    val text1 = "abcde"
    val text2 = "ace"

    val res = f(text1, text2)
    println(res)

    val actual = 3

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (String, String) => Int): Unit = {
    val text1 = "abc"
    val text2 = "abc"

    val res = f(text1, text2)
    println(res)

    val actual = 3

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase3(f: (String, String) => Int): Unit = {
    val text1 = "abc"
    val text2 = "def"

    val res = f(text1, text2)
    println(res)

    val actual = 0

    assert(res == actual, "Test Case 3 Failed!")
}

def runTestCases(f: (String, String) => Int): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.longestCommonSubsequence)
}
