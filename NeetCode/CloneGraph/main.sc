import $file.Soln1, Soln1.Solution1
import $file.Soln1, Soln1.Solution1.Node

def testCase1(f: (Node) => Node): Unit = {
    // TEST CASE 1
    val one = Node(1)
    val two = Node(2)
    val three = Node(3)
    val four = Node(4)

    one.neighbors = one.neighbors :+ ((two))
    one.neighbors = one.neighbors :+ ((four))

    two.neighbors = two.neighbors :+ ((one))
    two.neighbors = two.neighbors :+ ((three))

    three.neighbors = three.neighbors :+ ((two))
    three.neighbors = three.neighbors :+ ((four))

    four.neighbors = four.neighbors :+ ((one))
    four.neighbors = four.neighbors :+ ((three))

    val res = f(one)
    println(res)

    val expected = 1

    assert(res.value == expected, "Test Case 1 Failed!")
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

def runTestCases(f: (Node => Node)): Unit = {
    testCase1(f)
    // testCase2(f)
}


@main def mainSol1() = {
    runTestCases(Solution1.cloneGraph)
}