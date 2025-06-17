import $file.Soln1, Soln1.Solution1

def testCase1(f: (Int, Array[Int]) => Int): Unit = {
    val target = 7
    val nums = Array(2, 3, 1, 2, 4, 3)

    val res = f(target, nums)
    println(res)

    val actual = 2

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (Int, Array[Int]) => Int): Unit = {
    val target = 4
    val nums = Array(1, 4, 4)

    val res = f(target, nums)
    println(res)

    val actual = 1

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase3(f: (Int, Array[Int]) => Int): Unit = {
    val target = 11
    val nums = Array(1,1,1,1,1,1,1,1)

    val res = f(target, nums)
    println(res)

    val actual = 0

    assert(res == actual, "Test Case 3 Failed!")
}

def runTestCases(f: (Int, Array[Int]) => Int): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.minSubArrayLen)
}
