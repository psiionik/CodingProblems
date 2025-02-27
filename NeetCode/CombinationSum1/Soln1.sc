import scala.collection.mutable.ListBuffer

object Solution1 {
    def combinationSum(candidates: Array[Int], target: Int): List[List[Int]] = {
        val sorted_candidates = candidates.sorted
        var res: List[List[Int]] = List()

        def backtrack(index: Int, acc_value: Int, generated_list: ListBuffer[Int]): Unit = {
            if acc_value == target
            then
                res = res ::: List(generated_list.toList)     
                return
            else if acc_value > target
            then
                return
            else

                for (i <- Range(index, sorted_candidates.length))
                do 
                    generated_list += sorted_candidates(i)
                    backtrack(i, acc_value + sorted_candidates(i), generated_list)
                    generated_list.remove(generated_list.length - 1)
        }

        backtrack(0, 0, ListBuffer[Int]())

        return res
    }
}