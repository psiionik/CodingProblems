import $file.Soln1, Soln1.Solution1
import $file.Soln1, Soln1.Solution1.MinStack

def testCase1(): Unit = {
    val min_stack = MinStack()
    min_stack.push(-2)
    min_stack.push(0)
    min_stack.push(-3)
    println(min_stack.getMin()) // return -3
    min_stack.pop()
    println(min_stack.top())    // return 0
    println(min_stack.getMin()) // return -2
}

def runTestCases(): Unit = {
    testCase1()
}

@main def mainSol1() = {
    runTestCases()
}


