import $file.Soln1, Soln1.Solution1

def testCase1(f: (Array[Int], Int) => Int): Unit = {
    val nums = Array(4,5,6,7,0,1,2)
    val target = 0

    val res = f(nums, target)
    println(res)

    val actual = 4

    assert(res == actual, "Test Case 1 Failed!")
}

// def testCase2(f: (Array[Int]) => Int): Unit = {
//     val nums = Array(1)

//     val res = f(nums)
//     println(res)

//     val actual = 1 

//     assert(res == actual, "Test Case 2 Failed!")
// }

// def testCase3(f: (Array[Int]) => Int): Unit = {
//     val nums = Array(5,4,-1,7,8)

//     val res = f(nums)
//     println(res)

//     val actual = 23 

//     assert(res == actual, "Test Case 2 Failed!")
// }

// def testCase4(f: (Array[Int]) => Int): Unit = {
//     val nums = Array(2,-3,4,-2,2,1,-1,4)

//     val res = f(nums)
//     println(res)

//     val actual = 8 

//     assert(res == actual, "Test Case 2 Failed!")
// }

// def testCase5(f: (Array[Int]) => Int): Unit = {
//     val nums = Array(-1)

//     val res = f(nums)
//     println(res)

//     val actual = -1 

//     assert(res == actual, "Test Case 2 Failed!")
// }

def runTestCases(f: (Array[Int], Int) => Int): Unit = {
    testCase1(f)
    // testCase2(f)
    // testCase3(f)
    // testCase4(f)
    // testCase5(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.search)
}
