import $file.Soln1, Soln1.Solution1

def testCase1(f: (Int) => Int): Unit = {
    val x = 11 

    val res = f(x)
    println(res)

    val actual = 3

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (Int) => Int): Unit = {
    val x = 128 

    val res = f(x)
    println(res)

    val actual = 1

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase3(f: (Int) => Int): Unit = {
    val x = 2147483645 

    val res = f(x)
    println(res)

    val actual = 30 

    assert(res == actual, "Test Case 3 Failed!")
}


def runTestCases(f: (Int) => Int): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.hammingWeight)
    runTestCases(Solution1.hammingWeightOpt)
}