import $file.Soln1, Soln1.PeekingIterator

def testCase1(): Unit = {
    val pk = new PeekingIterator(Iterator(1, 2, 3))
    println(pk.next())
    println(pk.peek())
    println(pk.next())
    println(pk.next())
    println(pk.hasNext())
}

def runTestCases(): Unit = {
    testCase1()
}

@main def mainSol1() = {
    runTestCases()
}


