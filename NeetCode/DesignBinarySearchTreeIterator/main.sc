import $file.Soln1, Soln1.Solution1
import $file.Soln1, Soln1.Solution1.BSTIterator
import $file.Soln1, Soln1.Solution1.TreeNode

def testCase1(): Unit = {
    val rl = TreeNode(9)
    val rr = TreeNode(20)
    val r = TreeNode(15, rl, rr)
    val l = TreeNode(3)
    val root = TreeNode(7, l, r)

    val bst_it = BSTIterator(root)

    println(bst_it.next())
    println(bst_it.next())
    println(bst_it.hasNext())
    println(bst_it.next())
    println(bst_it.hasNext())
    println(bst_it.next())
    println(bst_it.hasNext())
    println(bst_it.next())
    println(bst_it.hasNext())
}

def runTestCases(): Unit = {
    testCase1()
}

@main def mainSol1() = {
    runTestCases()
}


