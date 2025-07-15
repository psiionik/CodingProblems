import $file.Soln1, Soln1.Solution1

def testCase1(f: (Array[Int], Int) => Int): Unit = {
    val nums = Array(-1,0,3,5,9,12) 
    val target = 9

    val res = f(nums, target)
    println(res)

    val actual = 4

    assert(res == actual, "Test Case 1 Failed!")
}

def testCase2(f: (Array[Int], Int) => Int): Unit = {
    val nums = Array(-1,0,3,5,9,12) 
    val target = 2

    val res = f(nums, target)
    println(res)

    val actual = -1 

    assert(res == actual, "Test Case 2 Failed!")
}

def runTestCases(f: (Array[Int], Int) => Int): Unit = {
    testCase1(f)
    testCase2(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.search)
}
