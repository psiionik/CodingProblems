import $file.Soln1, Soln1.Solution1

def testCase1(f: (Array[String]) => List[List[String]]): Unit = {
    val strs = Array("eat","tea","tan","ate","nat","bat")

    val res = f(strs)
    println(res)

    val actual = List(
        List("bat"),
        List("nat", "tan"),
        List("ate", "eat", "tea")
    )

    assert(res == actual, "Test Case 1 Failed!")
}

def runTestCases(f: (Array[String]) => List[List[String]]): Unit = {
    testCase1(f)
}

@main def mainSol1() = {
    runTestCases(Solution1.groupAnagrams)
}