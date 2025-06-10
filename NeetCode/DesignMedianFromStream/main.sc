import $file.Soln1, Soln1.Solution1
import $file.Soln1, Soln1.Solution1.MedianFinder

def testCase1(): Unit = {
    val median_finder = new MedianFinder()
    median_finder.addNum(1)
    median_finder.addNum(2)
    println(median_finder.findMedian())
    median_finder.addNum(3)
    println(median_finder.findMedian())

    println(median_finder.min_heap.dequeueAll)
    println(median_finder.max_heap.dequeueAll)
}

def runTestCases(): Unit = {
    testCase1()
}

@main def mainSol1() = {
    runTestCases()
}
