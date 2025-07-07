import $file.Soln1, Soln1.Solution1
import $file.Soln1, Soln1.Solution1.KthLargest

def testCase1(): Unit = {
    val k = 3
    val nums = Array(4, 5, 8, 2)
    val kthLargest = KthLargest(k, nums)

    println(kthLargest.add(3)) // return 4
    println(kthLargest.add(5)) // return 5
    println(kthLargest.add(10)) // return 5
    println(kthLargest.add(9)) // return 8
    println(kthLargest.add(4)) // return 8
}

def testCase2(): Unit = {
    val k = 4
    val nums = Array(7, 7, 7, 7, 8, 3)
    val kthLargest = KthLargest(k, nums)

    println(kthLargest.add(2)) // return 7
    println(kthLargest.add(10)) // return 7
    println(kthLargest.add(9)) // return 7
    println(kthLargest.add(9)) // return 8
}

def runTestCases(): Unit = {
    testCase1()
    testCase2()
}

@main def mainSol1() = {
    runTestCases()
}


