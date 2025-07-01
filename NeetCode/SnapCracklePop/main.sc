import $file.Soln1, Soln1.Solution1

def testCase1(f: (Int, Int) => Unit): Unit = {
    val from = 1
    val to = 100 

    val res = f(nums, k)
    println(res.mkString(" "))

    val actual = Array(3,3,5,5,6,7)

    assert(res.length == actual.length, "Test Case 1 Failed! Not same length!")

    for (i <- actual.indices)
    do
        assert(res(i) == actual(i), "Test Case 1 Failed! One element was not the same as the answer!")
}

def runTestCases(f: (Int, Int) => Unit): Unit = {
    testCase1(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.snapCracklePop)
}
