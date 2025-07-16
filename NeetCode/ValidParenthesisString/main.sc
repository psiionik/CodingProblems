import $file.Soln1, Soln1.Solution1

def testCase1(f: (String) => Boolean): Unit = {
    val s = "()" 

    val res = f(s)
    println(res)

    val actual = true 

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (String) => Boolean): Unit = {
    val s = "(*)" 

    val res = f(s)
    println(res)

    val actual = true 

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase3(f: (String) => Boolean): Unit = {
    val s = "(*))" 

    val res = f(s)
    println(res)

    val actual = true 

    assert(res == actual, "Test Case 3 Failed!")
}

def testCase4(f: (String) => Boolean): Unit = {
    val s = "((**)" 

    val res = f(s)
    println(res)

    val actual = true 

    assert(res == actual, "Test Case 4 Failed!")
}

def testCase5(f: (String) => Boolean): Unit = {
    val s = "(((*)" 

    val res = f(s)
    println(res)

    val actual = false

    assert(res == actual, "Test Case 5 Failed!")
}

def runTestCases(f: (String) => Boolean): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
    testCase4(f)
    testCase5(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.checkValidString)
}
