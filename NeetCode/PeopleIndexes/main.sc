import $file.Soln1, Soln1.Solution1

def testCase1(f: (List[List[String]] => List[Int])): Unit = {
    // TEST CASE 1
    val favoriteCompanies = List(
        List("leetcode, google, facebook"),
        List("google", "microsoft"),
        List("google", "facebook"),
        List("google"),
        List("amazon")
    )
    
    val res = f(favoriteCompanies)
    val expected = List(0, 1, 4)

    assert(res.length == expected.length, "Test Case 1 Failed, mismatched lengths!")

    for (i <- Range(0, expected.length))
    do 
        assert(res(i) == expected(i), "Test Case 1 Failed, Incorrect Elements!")
}

// def testCase2(f: (Node => Node)): Unit = {
//     // TEST CASE 2

//     val list_of_nodes = Array[Int | Null](3,5,1,6,2,0,8,null,null,7,4)
//     val root = Solution1.parseTreeNodeList(list_of_nodes, 0)
//     val p = root.left
//     val q = root.left.right.right

//     val res = f(root, p, q)
//     println(res)

//     val expected = root.left

//     assert(res == expected, "Test Case 2 Failed!")
// }

def runTestCases(f: (List[List[String]] => List[Int])): Unit = {
    testCase1(f)
    // testCase2(f)
}


@main def mainSol1() = {
    runTestCases(Solution1.peopleIndexes)
}