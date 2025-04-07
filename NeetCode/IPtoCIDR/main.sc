import $file.Soln1, Soln1.Solution1
// import $file.Soln2, Soln2.Solution2
// import $file.SolnOpt, SolnOpt.SolutionOpt

def testCase1(f: (String, Int) => List[String]): Unit = {
    val ip = "255.0.0.7"
    val n = 10

    val res = f(ip, n)
    println(res)

    val actual = Array("255.0.0.7/32","255.0.0.8/29","255.0.0.16/32") 

    for (index <- Range(0, res.length))
    do 
        assert(res(index) == actual(index), "Test Case 1 Failed!")
}

def testCase2(f: (String, Int) => List[String]): Unit = {
    val ip = "117.145.102.62"
    val n = 8 

    val res = f(ip, n)
    println(res)

    val actual = Array("117.145.102.62/31","117.145.102.64/30","117.145.102.68/31") 

    for (index <- Range(0, res.length))
    do 
        assert(res(index) == actual(index), "Test Case 1 Failed!")
}


def runTestCases(f: (String, Int) => List[String]): Unit = {
    testCase1(f)
    // testCase2(f)
    // testCase3(f)
    // testCase4(f)
    // testCase5(f)
    // testCase6(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.ipToCIDR)
}

// @main def mainSol2() = {
//     runTestCases(Solution2.canAttendMeetings)
// }

// @main def mainSolOpt() = {
//     runTestCases(SolutionOpt.rob)
// }