import $file.Soln1, Soln1.Solution1

def testCase1(f: (Int, Array[Array[Int]]) => Boolean): Unit = {
    val n = 5
    val edges = Array(
        Array(0, 1),
        Array(0, 2),
        Array(0, 3),
        Array(1, 4)
    )

    val actual = f(n, edges)
    println(actual)
    val expected = true

    assert(actual == expected, "Test Case 1 Failed!")
}

def testCase2(f: (Int, Array[Array[Int]]) => Boolean): Unit = {
    val n = 5
    val edges = Array(
        Array(0, 1),
        Array(1, 2),
        Array(2, 3),
        Array(1, 3),
        Array(1, 4)
    )

    val actual = f(n, edges)
    val expected = false
    println(actual)

    assert(actual == expected, "Test Case 2 Failed!")
}

def testCase3(f: (Int, Array[Array[Int]]) => Boolean): Unit = {
    val n = 4
    val edges = Array(
        Array(0, 1),
        Array(2, 3),
    )

    val actual = f(n, edges)
    val expected = false
    println(actual)

    assert(actual == expected, "Test Case 3 Failed!")
}

def testCase4(f: (Int, Array[Array[Int]]) => Boolean): Unit = {
    val n = 4
    val edges = Array(
        Array(0, 1),
        Array(2, 3),
        Array(0, 3)
    )

    val actual = f(n, edges)
    val expected = true
    println(actual)

    assert(actual == expected, "Test Case 4 Failed!")
}

def runTestCases(f: (Int, Array[Array[Int]]) => Boolean): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
    testCase4(f)
}


@main def mainSol1() = {
    runTestCases(Solution1.validTree)
}