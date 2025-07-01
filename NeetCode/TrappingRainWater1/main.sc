import $file.Soln1, Soln1.Solution1

def testCase1(f: (Array[Int]) => Int): Unit = {
    val height = Array(0,1,0,2,1,0,1,3,2,1,2,1)

    val res = f(height)
    println(res)

    val actual = 6 

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (Array[Int]) => Int): Unit = {
    val height = Array(0,2,0,3,1,0,1,3,2,1)

    val res = f(height)
    println(res)

    val actual = 9 

    assert(res == actual, "Test Case 2 Failed!")
}

def runTestCases(f: (Array[Int]) => Int): Unit = {
    testCase1(f)
    testCase2(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.trap)
}
