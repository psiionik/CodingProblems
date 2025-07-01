import $file.Soln1, Soln1.Solution1

def testCase1(f: (Array[Int], Int) => Array[Double]): Unit = {
    val nums = Array(1,3,-1,-3,5,3,6,7)
    val k = 3

    val res = f(nums, k)
    println(res.mkString(" "))

    val actual = Array(1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000)

    assert(res.length == actual.length, "Test Case 1 Failed! Not same length!")

    for (i <- actual.indices)
    do
        assert(res(i) == actual(i), "Test Case 1 Failed! One element was not the same as the answer!")
}

def runTestCases(f: (Array[Int], Int) => Array[Double]): Unit = {
    testCase1(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.medianSlidingWindow)
}

