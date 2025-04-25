import $file.Soln1, Soln1.Solution1
// import $file.Soln2, Soln2.Solution2 
// import $file.Soln3, Soln3.Solution3

def testCase1(f: (Int, Array[Array[Int]]) => Array[Int]): Unit = {
    val prerequisites = Array(Array(1, 0))
    val numCourses = 2

    val res = f(numCourses, prerequisites)
    println(res.mkString(" "))

    val actual = Array(0, 1)

    for (i <- actual.indices)
    do
        assert(res(i) == actual(i), "Test Case 1 Failed!")
}

def testCase2(f: (Int, Array[Array[Int]]) => Array[Int]): Unit = {
    val prerequisites = Array(
        Array(1, 0),
        Array(2, 0),
        Array(3, 1),
        Array(3, 2)
    )
    val numCourses = 4

    val res = f(numCourses, prerequisites)
    println(res.mkString(" "))

    val actual = Array(0, 2, 1, 3)

    for (i <- actual.indices)
    do
        assert(res(i) == actual(i), "Test Case 2 Failed!")
}

def testCase3(f: (Int, Array[Array[Int]]) => Array[Int]): Unit = {
    val prerequisites = Array[Array[Int]]()
    val numCourses = 1

    val res = f(numCourses, prerequisites)
    println(res.mkString(" "))

    val actual = Array(0)

    for (i <- actual.indices)
    do
        assert(res(i) == actual(i), "Test Case 2 Failed!")
}

def testCase4(f: (Int, Array[Array[Int]]) => Array[Int]): Unit = {
    val prerequisites = Array[Array[Int]]()
    val numCourses = 2

    val res = f(numCourses, prerequisites)
    println(res.mkString(" "))

    val actual = Array(1, 0)

    for (i <- actual.indices)
    do
        assert(res(i) == actual(i), "Test Case 4 Failed!")
}

def runTestCases(f: (Int, Array[Array[Int]]) => Array[Int]): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
    testCase4(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.findOrder)
}

// @main def mainSol2() = {
//     runTestCases(Solution2.combinationSum2)
// }

// @main def mainSol3() = {
//     runTestCases(Solution3.combinationSum2)
// }
