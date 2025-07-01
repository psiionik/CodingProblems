import $file.Soln1, Soln1.Solution1

def testCase1(f: (Array[Int]) => Int): Unit = {
    val nums = Array(100,4,200,1,3,2)

    val res = f(nums)
    println(res)

    val actual = 4

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (Array[Int]) => Int): Unit = {
    val nums = Array(0,3,7,2,5,8,4,6,0,1)

    val res = f(nums)
    println(res)

    val actual = 9

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase3(f: (Array[Int]) => Int): Unit = {
    val nums = Array(1,0,1,2)

    val res = f(nums)
    println(res)

    val actual = 3

    assert(res == actual, "Test Case 3 Failed!")
}

def runTestCases(f: (Array[Int]) => Int): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
}

@main def mainSol1() = {
    // runTestCases(Solution1.longestConsecutive)
    runTestCases(Solution1.longestConsecutiveUF)
}
