import $file.Soln1, Soln1.Solution1
import $file.Soln1, Soln1.Solution1.Trie

def testCase1(): Unit = {
    val prefix_trie = new Trie()
    prefix_trie.insert("apple")
    println(prefix_trie.search("apple"))
    println(prefix_trie.search("app"))
    println(prefix_trie.startsWith("app"))
    prefix_trie.insert("app")
    println(prefix_trie.search("app"))
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

def runTestCases(): Unit = {
    testCase1()
    // testCase2(f)
}


@main def mainSol1() = {
    runTestCases()
}