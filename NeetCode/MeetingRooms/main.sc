import $file.Soln1, Soln1.Solution1
import $file.Soln2, Soln2.Solution2

def testCase1(f: (Array[Array[Int]]) => Boolean): Unit = {
    val intervals = Array(
        Array(0, 30),
        Array(5, 10),
        Array(15, 20)
    )

    val res = f(intervals)
    println(res)

    val actual = false 

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (Array[Array[Int]]) => Boolean): Unit = {
    val intervals = Array(
        Array(7, 10),
        Array(2, 4),
    )

    val res = f(intervals)
    println(res)

    val actual = true 

    assert(res == actual, "Test Case 2 Failed!")
}

def runTestCases(f: (Array[Array[Int]]) => Boolean): Unit = {
    testCase1(f)
    testCase2(f)
    // testCase3(f)
    // testCase4(f)
    // testCase5(f)
    // testCase6(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.canAttendMeetings)
}

@main def mainSol2() = {
    runTestCases(Solution2.canAttendMeetings)
}
