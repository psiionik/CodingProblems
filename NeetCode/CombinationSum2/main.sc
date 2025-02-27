import $file.Soln1, Soln1.Solution1
import $file.Soln2, Soln2.Solution2 
import $file.Soln3, Soln3.Solution3

def testCase1(f: (Array[Int], Int) => List[List[Int]]): Unit = {
    val candidates = Array(10,1,2,7,6,1,5)
    val target = 8

    val res = f(candidates, target)
    println(res)

    val actual: List[List[Int]] = List(
        List(1, 1, 6),
        List(1, 2, 5),
        List(1, 7),
        List(2, 6)
    )

    for (i <- actual.indices)
    do
        for (j <- actual(i).indices)
        do
            assert(res(i)(j) == actual(i)(j), "Test Case 1 Failed!")

}

def testCase2(f: (Array[Int], Int) => List[List[Int]]): Unit = {
    val candidates = Array(2,5,2,1,2)
    val target = 5

    val res = f(candidates, target)
    println(res)

    val actual: List[List[Int]] = List(
        List(1, 2, 2),
        List(5)
    )

    for (i <- actual.indices)
    do
        for (j <- actual(i).indices)
        do
            assert(res(i)(j) == actual(i)(j), "Test Case 2 Failed!")
}

def testCase3(f: (Array[Int], Int) => List[List[Int]]): Unit = {
    val candidates = Array(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1)
    val target = 30 

    val res = f(candidates, target)
    println(res)

    // val actual: List[List[Int]] = List(
    //     List(1, 2, 2),
    //     List(5)
    // )

    // for (i <- actual.indices)
    // do
    //     for (j <- actual(i).indices)
    //     do
    //         assert(res(i)(j) == actual(i)(j), "Test Case 2 Failed!")
}

def runTestCases(f: (Array[Int], Int) => List[List[Int]]): Unit = {
    testCase1(f)
    // testCase2(f)
    // testCase3(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.combinationSum2)
}

@main def mainSol2() = {
    runTestCases(Solution2.combinationSum2)
}

@main def mainSol3() = {
    runTestCases(Solution3.combinationSum2)
}