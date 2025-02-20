error id: mkString.
file://<WORKSPACE>/CombinationSum2/soln1.scala
empty definition using pc, found symbol in pc: mkString.
empty definition using semanticdb
found definition using fallback; symbol mkString
Document text:

```scala
import scala.collection.mutable.LinkedList


def combinationSum2(candidates: Array[Int], target: Int): List[List[Int]] = {
    val res: List[List[Int]] = List()
    val checker: Set[Array[Int]] = Set()

    def recurse(candidates: Array[Int], target: Int, current_index: Int, accumulated_value: Int, generated_list: ArrayDeque[Int]): Unit = {
        if accumulated_value == target
        then
            if !checker.contains(generated_list.toArray()) then res ::: generated_list.toArray().toList() else return

        generated_list += candidates(0)

        println(generated_list.toArray().mkString(" "))
    }

    recurse(candidates, target, 0, 0, new ArrayDeque[Int]())

    return res
}

def testCase1(): Unit = {
    val candidates = Array(10,1,2,7,6,1,5)
    val target = 8

    val res = combinationSum2(candidates, 8)
    println(res)

    val actual: List[List[Int]] = List(
        List(1, 1, 6),
        List(1, 2, 5),
        List(1, 7),
        List(2, 6)
    )

    for (i <- actual.indices)
    do
        for (j <- actual(i).indices)
        do
            assert(res(i)(j) == actual(i)(j), "Test Case 1 Failed!")

}

def testCase2(): Unit = {
    val candidates = Array(2,5,2,1,2)
    val target = 5

    val res = combinationSum2(candidates, 8)
    println(res)

    val actual: List[List[Int]] = List(
        List(1, 1, 2),
        List(5)
    )

    for (i <- actual.indices)
    do
        for (j <- actual(i).indices)
        do
            assert(res(i)(j) == actual(i)(j), "Test Case 1 Failed!")
}

def runTestCases(): Unit = {
    // testCase1()
    testCase2()
}

@main def main() = {
    runTestCases()
}    
```

#### Short summary: 

empty definition using pc, found symbol in pc: mkString.