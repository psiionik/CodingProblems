import $file.Soln1, Soln1.Solution1
import $file.Soln1, Soln1.Solution1.BufferedFileWriter

def testCase1(): Unit = {
    var f = new java.io.File("./tmp/test.txt")
    var write_buffer = new BufferedFileWriter(f, 64)
    val data = Array.fill(64)(0).map((item) => Math.random().toInt.toByte)
    write_buffer.write(data)
}

def testCase2(): Unit = {
    var f = new java.io.File("./tmp/test.txt")
    var write_buffer = new BufferedFileWriter(f, 64)
    val data = Array.fill(63)(0).map((item) => Math.random().toInt.toByte)
    write_buffer.write(data)
}

def runTestCases(): Unit = {
    // testCase1()
    testCase2()
}

@main def mainSol1() = {
    runTestCases()
}


