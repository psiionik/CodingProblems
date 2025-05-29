import $file.Soln1, Soln1.Solution1
import $file.Soln1, Soln1.Solution1.MyCircularQueue

def testCase1(): Unit = {
    val circular_queue = new MyCircularQueue(3)
    println(circular_queue.enQueue(1)) // return True
    println(circular_queue.enQueue(2)) // return True
    println(circular_queue.enQueue(3)) // return True
    println(circular_queue.enQueue(4)) // return False
    println(circular_queue.Rear())     // return 3
    println(circular_queue.isFull())   // return True
    println(circular_queue.deQueue())  // return True
    println(circular_queue.enQueue(4)) // return True
    println(circular_queue.Rear())     // return 4
}

def runTestCases(): Unit = {
    testCase1()
}

@main def mainSol1() = {
    runTestCases()
}


