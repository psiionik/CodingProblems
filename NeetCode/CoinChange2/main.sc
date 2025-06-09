import $file.Soln1, Soln1.Solution1

def testCase1(f: (Int, Array[Int]) => Int): Unit = {
    val amount = 5
    val coins = Array(1, 2, 5)

    val res = f(amount, coins)
    println(res)

    val actual = 4

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (Int, Array[Int]) => Int): Unit = {
    val amount = 3
    val coins = Array(2)

    val res = f(amount, coins)
    println(res)

    val actual = 0

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase3(f: (Int, Array[Int]) => Int): Unit = {
    val amount = 10
    val coins = Array(10)

    val res = f(amount, coins)
    println(res)

    val actual = 1

    assert(res == actual, "Test Case 3 Failed!")
}

def runTestCases(f: (Int, Array[Int]) => Int): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.change)
}