import $file.Soln1, Soln1.Solution1
import $file.Soln2, Soln2.Solution2

def testCase1(f: (Array[Int], Int) => List[List[Int]]): Unit = {
    val candidates = Array(2, 3, 6, 7)
    val target = 7

    val res = f(candidates, target)
    println(res)

    val actual: List[List[Int]] = List(
        List(2, 2, 3),
        List(7)
    )

    for (i <- actual.indices)
    do
        for (j <- actual(i).indices)
        do
            assert(res(i)(j) == actual(i)(j), "Test Case 1 Failed!")

}

def testCase2(f: (Array[Int], Int) => List[List[Int]]): Unit = {
    val candidates = Array(2, 3, 5)
    val target = 8

    val res = f(candidates, target)
    println(res)

    val actual: List[List[Int]] = List(
        List(2, 2, 2, 2),
        List(2, 3, 3),
        List(3, 5)
    )

    for (i <- actual.indices)
    do
        for (j <- actual(i).indices)
        do
            assert(res(i)(j) == actual(i)(j), "Test Case 2 Failed!")
}

def testCase3(f: (Array[Int], Int) => List[List[Int]]): Unit = {
    val candidates = Array(2)
    val target = 1 

    val res = f(candidates, target)
    println(res)

    val actual: List[List[Int]] = Nil 

    for (i <- actual.indices)
    do
        for (j <- actual(i).indices)
        do
            assert(res(i)(j) == actual(i)(j), "Test Case 3 Failed!")
}

def runTestCases(f: (Array[Int], Int) => List[List[Int]]): Unit = {
    testCase1(f)
    testCase2(f)
    testCase3(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.combinationSum)
}

@main def mainSol2() = {
    runTestCases(Solution2.combinationSum)
}