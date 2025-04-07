import $file.Soln1, Soln1.Solution1
import $file.Soln2, Soln2.Solution2

def testCase1(f: (Array[Array[Char]], String) => Boolean): Unit = {
    val board = Array(
        Array('A','B','C','E'),
        Array('S','F','C','S'),
        Array('A','D','E','E')
    )
    val word = "ABCCED"

    val res = f(board, word)
    println(res)

    val actual = true 

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (Array[Array[Char]], String) => Boolean): Unit = {
    val board = Array(
        Array('A','B','C','E'),
        Array('S','F','C','S'),
        Array('A','D','E','E')
    )
    val word = "SEE"

    val res = f(board, word)
    println(res)

    val actual = true 

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase3(f: (Array[Array[Char]], String) => Boolean): Unit = {
    val board = Array(
        Array('A','B','C','E'),
        Array('S','F','C','S'),
        Array('A','D','E','E')
    )
    val word = "ABCB"

    val res = f(board, word)
    println(res)

    val actual = false 

    assert(res == actual, "Test Case 3 Failed!")
}

def testCase4(f: (Array[Array[Char]], String) => Boolean): Unit = {
    val board = Array(
        Array('A','B','C','D'),
        Array('S','A','A','T'),
        Array('A','C','A','E')
    )
    val word = "CAT"

    val res = f(board, word)
    println(res)

    val actual = true 

    assert(res == actual, "Test Case 4 Failed!")
}

def testCase5(f: (Array[Array[Char]], String) => Boolean): Unit = {
    val board = Array(
        Array('A','B','C','D'),
        Array('S','A','A','T'),
        Array('A','C','A','E')
    )
    val word = "BAT"

    val res = f(board, word)
    println(res)

    val actual = false 

    assert(res == actual, "Test Case 5 Failed!")
}

def testCase6(f: (Array[Array[Char]], String) => Boolean): Unit = {
    val board = Array(
        Array('A','B','C','E'),
        Array('S','F','E','S'),
        Array('A','D','E','E')
    )
    val word = "ABCESEEEFS"

    val res = f(board, word)
    println(res)

    val actual = true 

    assert(res == actual, "Test Case 6 Failed!")
}

def runTestCases(f: (Array[Array[Char]], String) => Boolean): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
    testCase4(f)
    testCase5(f)
    testCase6(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.exist)
}

@main def mainSol2() = {
    runTestCases(Solution2.exist)
}
