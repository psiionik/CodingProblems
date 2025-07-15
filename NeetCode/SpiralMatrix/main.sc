import $file.Soln1, Soln1.Solution1

def testCase1(f: (Array[Array[Int]]) => List[Int]): Unit = {
    val matrix = Array(
        Array(1, 2, 3),
        Array(4, 5, 6),
        Array(7, 8, 9)
    )

    val res = f(matrix)
    println(res)

    val actual = List(1, 2, 3, 6, 9, 8, 7, 4, 5) 

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (Array[Array[Int]]) => List[Int]): Unit = {
    val matrix = Array(
        Array(1, 2, 3, 4),
        Array(5, 6, 7, 8),
        Array(9, 10, 11, 12)
    )

    val res = f(matrix)
    println(res)

    val actual = List(1,2,3,4,8,12,11,10,9,5,6,7) 

    assert(res == actual, "Test Case 2 Failed!")
}

def runTestCases(f: (Array[Array[Int]]) => List[Int]): Unit = {
    testCase1(f)
    testCase2(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.spiralOrder)
}
