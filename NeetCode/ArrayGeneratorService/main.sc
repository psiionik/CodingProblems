import $file.Soln1, Soln1.Solution1

def testCase1(f: (Array[Int], String, Int) => Array[Int]): Unit = {
    val arr = Array(5, 3, 4, 6)
    val state = "1100"
    val m = 5

    val res = f(arr, state, m)
    println(res.mkString(" "))

    val actual = Array(5, 5, 6, 6, 6)

    assert(res.length == actual.length, "Test Case 1 Failed! Not same length!")

    for (i <- actual.indices)
    do
        assert(res(i) == actual(i), "Test Case 1 Failed! One element was not the same as the answer!")
}

def runTestCases(f: (Array[Int], String, Int) => Array[Int]): Unit = {
    testCase1(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.generateArray)
}
