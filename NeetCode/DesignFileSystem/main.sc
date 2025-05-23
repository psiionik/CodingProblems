import $file.Soln1, Soln1.Solution1
import $file.Soln1, Soln1.Solution1.FileSystem
// import $file.Soln2, Soln2.Solution2
// import $file.SolnOpt, SolnOpt.SolutionOpt

def testCase1(): Unit = {
    val file_system = new FileSystem()
    println(file_system.createPath("/a", 1))
    println(file_system.get("/a"))
}

// def testCase1_Sol2(): Unit = {
//     val time_map: Solution2.TimeMap = new Solution2.TimeMap()
//     time_map.set("foo", "bar", 1)
//     println(time_map.get("foo", 1))
//     println(time_map.get("foo", 3))
//     time_map.set("foo", "bar2", 4)
//     println(time_map.get("foo", 4))
//     println(time_map.get("foo", 5))
// }

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


def runTestCases(): Unit = {
    testCase1()
    // testCase1_Sol2()
    // testCase1Opt()
    // testCase2()
    // testCase3()
    // testCase4()
    // testCase5()
}

@main def mainSol1() = {
    runTestCases()
}

// @main def mainSol2() = {
//     runTestCases()
// }

// @main def mainSolOpt() = {
//     runTestCases()
// }

