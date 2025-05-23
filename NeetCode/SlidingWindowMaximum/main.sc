import $file.Soln1, Soln1.Solution1
// import $file.Soln2, Soln2.Solution2 
// import $file.Soln3, Soln3.Solution3

def testCase1(f: (Array[Int], Int) => Array[Int]): Unit = {
    val nums = Array(1,3,-1,-3,5,3,6,7)
    val k = 3

    val res = f(nums, k)
    println(res.mkString(" "))

    val actual = Array(3,3,5,5,6,7)

    assert(res.length == actual.length, "Test Case 1 Failed! Not same length!")

    for (i <- actual.indices)
    do
        assert(res(i) == actual(i), "Test Case 1 Failed! One element was not the same as the answer!")
}

def testCase2(f: (Array[Int], Int) => Array[Int]): Unit = {
    val nums = Array(1)
    val k = 1

    val res = f(nums, k)
    println(res.mkString(" "))

    val actual = Array(1)

    assert(res.length == actual.length, "Test Case 2 Failed! Not same length!")

    for (i <- actual.indices)
    do
        assert(res(i) == actual(i), "Test Case 2 Failed! One element was not the same as the answer!")
}

// def testCase3(f: (Array[Int], Int) => Array[Int]): Unit = {
//     val prerequisites = Array[Array[Int]]()
//     val numCourses = 1

//     val res = f(numCourses, prerequisites)
//     println(res.mkString(" "))

//     val actual = Array(0)

//     for (i <- actual.indices)
//     do
//         assert(res(i) == actual(i), "Test Case 2 Failed!")
// }

// def testCase4(f: (Array[Int], Int) => Array[Int]): Unit = {
//     val prerequisites = Array[Array[Int]]()
//     val numCourses = 2

//     val res = f(numCourses, prerequisites)
//     println(res.mkString(" "))

//     val actual = Array(1, 0)

//     for (i <- actual.indices)
//     do
//         assert(res(i) == actual(i), "Test Case 4 Failed!")
// }

def runTestCases(f: (Array[Int], Int) => Array[Int]): Unit = {
    testCase1(f)
    testCase2(f)
//     testCase3(f)
//     testCase4(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.maxSlidingWindow)
}

// @main def mainSol2() = {
//     runTestCases(Solution2.combinationSum2)
// }

// @main def mainSol3() = {
//     runTestCases(Solution3.combinationSum2)
// }
