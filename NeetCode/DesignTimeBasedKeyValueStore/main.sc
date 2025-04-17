import $file.Soln1, Soln1.Solution1
import $file.Soln2, Soln2.Solution2
// import $file.SolnOpt, SolnOpt.SolutionOpt

def testCase1(): Unit = {
    val time_map: Solution1.TimeMap = new Solution1.TimeMap()
    time_map.set("foo", "bar", 1)
    println(time_map.get("foo", 1))
    println(time_map.get("foo", 3))
    time_map.set("foo", "bar2", 4)
    println(time_map.get("foo", 4))
    println(time_map.get("foo", 5))
}

def testCase1_Sol2(): Unit = {
    val time_map: Solution2.TimeMap = new Solution2.TimeMap()
    time_map.set("foo", "bar", 1)
    println(time_map.get("foo", 1))
    println(time_map.get("foo", 3))
    time_map.set("foo", "bar2", 4)
    println(time_map.get("foo", 4))
    println(time_map.get("foo", 5))
}

// def testCase1Opt(): Unit = {
//     val hit_counter: SolutionOpt.HitCounter  = new SolutionOpt.HitCounter()
//     println(hit_counter.hit(1))
//     println(hit_counter.hit(2))
//     println(hit_counter.hit(3))
//     println(hit_counter.getHits(4))
//     println(hit_counter.hit(300))
//     println(hit_counter.getHits(300))
//     println(hit_counter.getHits(301))
// }

def testCase2(f: (Array[Int]) => Int): Unit = {
    val nums = Array(1, 2, 3, 1)

    val res = f(nums)
    println(res)

    val actual = 4 

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase3(f: (Array[Int]) => Int): Unit = {
    val nums = Array(1, 2, 3)

    val res = f(nums)
    println(res)

    val actual = 3 

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase4(f: (Array[Int]) => Int): Unit = {
    val nums = Array(2)

    val res = f(nums)
    println(res)

    val actual = 2 

    assert(res == actual, "Test Case 2 Failed!")
}

def testCase5(f: (Array[Int]) => Int): Unit = {
    val nums = Array(1000, 2, 6, 10, 2002)

    val res = f(nums)
    println(res)

    val actual = 2008 

    assert(res == actual, "Test Case 2 Failed!")
}

def runTestCases(): Unit = {
    // testCase1()
    testCase1_Sol2()
    // testCase1Opt()
    // testCase2()
    // testCase3()
    // testCase4()
    // testCase5()
}

@main def mainSol1() = {
    runTestCases()
}

@main def mainSol2() = {
    runTestCases()
}

// @main def mainSolOpt() = {
//     runTestCases()
// }

