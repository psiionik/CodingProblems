import $file.Soln1, Soln1.Solution1

def testCase1(f: (Int, Array[Array[Int]], Array[Array[Int]]) => Array[Boolean]): Unit = {
    val n = 3
    val edgeList = Array(
        Array(0, 1, 2),
        Array(1, 2, 4),
        Array(2, 0, 8),
        Array(1, 0, 16),
    )
    val queries = Array(
        Array(0, 1, 2),
        Array(0, 2, 5),
    )

    val actual = f(n, edgeList, queries)
    println(actual.mkString(" "))
    val expected = Array(false, true) 

    assert(actual.sameElements(expected), "Test Case 1 Failed!")
}

def testCase2(f: (Int, Array[Array[Int]], Array[Array[Int]]) => Array[Boolean]): Unit = {
    val n = 5
    val edgeList = Array(
        Array(0, 1, 10),
        Array(1, 2, 5),
        Array(2, 3, 9),
        Array(3, 4, 13),
    )
    val queries = Array(
        Array(0, 4, 14),
        Array(1, 4, 13),
    )

    val actual = f(n, edgeList, queries)
    println(actual.mkString(" "))
    val expected = Array(true, false) 

    assert(actual.sameElements(expected), "Test Case 2 Failed!")
}

def testCase3(f: (Int, Array[Array[Int]], Array[Array[Int]]) => Array[Boolean]): Unit = {
    val n = 2
    val edgeList = Array(
        Array(0, 1, 10),
    )
    val queries = Array(
        Array(0, 1, 14),
    )

    val actual = f(n, edgeList, queries)
    println(actual.mkString(" "))
    val expected = Array(true) 

    assert(actual.sameElements(expected), "Test Case 3 Failed!")
}

def testCase4(f: (Int, Array[Array[Int]], Array[Array[Int]]) => Array[Boolean]): Unit = {
    val n = 10 
    val edgeList = Array(
        Array(0, 1, 10),
        Array(1, 2, 1),
        Array(2, 5, 100),
    )
    val queries = Array(
        Array(0, 5, 110),
        Array(0, 9, 4),
    )

    val actual = f(n, edgeList, queries)
    println(actual.mkString(" "))
    val expected = Array(true, false) 

    assert(actual.sameElements(expected), "Test Case 4 Failed!")
}

def testCase5(f: (Int, Array[Array[Int]], Array[Array[Int]]) => Array[Boolean]): Unit = {
    val n = 10 
    val edgeList = Array(
        Array(0, 1, 10),
        Array(1, 2, 1),
        Array(2, 5, 100),
        Array(9, 0, 25),
    )
    val queries = Array(
        Array(0, 5, 110),
        Array(0, 9, 4),
        Array(1, 9, 30),
    )

    val actual = f(n, edgeList, queries)
    println(actual.mkString(" "))
    val expected = Array(true, false, true) 

    assert(actual.sameElements(expected), "Test Case 5 Failed!")
}

def runTestCases(f: (Int, Array[Array[Int]], Array[Array[Int]]) => Array[Boolean]): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
    testCase4(f)
    testCase5(f)
}


@main def mainSol1() = {
    runTestCases(Solution1.distanceLimitedPathsExist)
}