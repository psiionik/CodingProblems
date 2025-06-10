import $file.Soln1, Soln1.Solution1

def testCase1(f: (Array[Int]) => Boolean): Unit = {
    val nums = Array(1, 5, 11, 5) 

    val res = f(nums)
    println(res)

    val actual = true 

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (Array[Int]) => Boolean): Unit = {
    val nums = Array(1, 2, 3, 5) 

    val res = f(nums)
    println(res)

    val actual = false 

    assert(res == actual, "Test Case 2 Failed!")
}

def runTestCases(f: (Array[Int]) => Boolean): Unit = {
    testCase1(f)
    testCase2(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.canPartition)
}
