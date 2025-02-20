error id: _empty_/
file://<WORKSPACE>/CombinationSum2/soln1.scala
empty definition using pc, found symbol in pc: _empty_/
semanticdb not found
|empty definition using fallback
non-local guesses:
	 -

Document text:

```scala
import scala.collection.mutable.ListBuilder

// def combinationSum2(candidates: Array[Int], target: Int): List[List[Int]] = {
//     var res: List[List[Int]] = List()
//     var checker: Set[List[Int]] = Set()

//     def recurse(candidates: Array[Int], target: Int, current_index: Int, accumulated_value: Int, generated_list: List[Int]): Unit = {
//         if accumulated_value == target
//         then
//             val sorted_generated_list = generated_list.sortWith((s, l) => l > s)
//             if !checker.contains(sorted_generated_list) 
//             then
//                 res = res ::: List(sorted_generated_list)
//                 checker = checker ++ Set(sorted_generated_list) 
//             else 
//                 return

//         var new_list: List[Int] = generated_list 

//         for (i <- Range(current_index, candidates.length))
//         do 
//             // Step 1: Add the current value into the accumulated list
//             new_list = new_list ::: List(candidates(i))

//             // Step 2: Recurse using the new index and accumulated list
//             recurse(candidates, target, i + 1, accumulated_value + candidates(i), new_list)

//             // Step 3: Remove the most recently added value in the accumulated list
//             new_list = new_list.dropRight(1)
//     }

//     recurse(candidates, target, 0, 0, Nil)

//     return res
// }

def combinationSum2(candidates: Array[Int], target: Int): List[List[Int]] = {
    var res: List[List[Int]] = List()
    var checker: Set[List[Int]] = Set()

    def recurse(candidates: Array[Int], target: Int, current_index: Int, accumulated_value: Int, generated_list: ListBuilder[Int]): Unit = {
        if accumulated_value == target
        then
            val sorted_generated_list = generated_list.toList.sortWith((s, l) => l > s)
            if !checker.contains(sorted_generated_list) 
            then
                res = res ::: List(sorted_generated_list)
                checker = checker ++ Set(sorted_generated_list) 
            else 
                return

        for (i <- Range(current_index, candidates.length))
        do 
            // Step 1: Add the current value into the accumulated list
            generated_list += candidates(i)

            // Step 2: Recurse using the new index and accumulated list
            recurse(candidates, target, i + 1, accumulated_value + candidates(i), generated_list)

            // Step 3: Remove the most recently added value in the accumulated list
            generated_list -= generated_list.remove(generated_list.length - 1)
    }

    recurse(candidates, target, 0, 0, List.newBuilder[Int])

    return res
}

def testCase1(): Unit = {
    val candidates = Array(10,1,2,7,6,1,5)
    val target = 8

    val res = combinationSum2(candidates, target)
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

    val res = combinationSum2(candidates, target)
    println(res)

    val actual: List[List[Int]] = List(
        List(1, 2, 2),
        List(5)
    )

    for (i <- actual.indices)
    do
        for (j <- actual(i).indices)
        do
            assert(res(i)(j) == actual(i)(j), "Test Case 2 Failed!")
}

def runTestCases(): Unit = {
    testCase1()
    testCase2()
}

@main def main() = {
    runTestCases()
}    
```

#### Short summary: 

empty definition using pc, found symbol in pc: _empty_/