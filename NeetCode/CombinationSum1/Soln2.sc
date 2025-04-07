import scala.annotation.tailrec

// Trying to use Tail Recursion to generate all combinations 
object Solution2 {
    def combinationSum(candidates: Array[Int], target: Int): List[List[Int]] = {
        val sorted_distinct_candidates = candidates.sorted.distinct.toList

        // Helper function where given a number and a target, generate a list of lists of 
        // all the combinations of that number that is <= to the target
        @tailrec
        def generateCombinations(target: Int, number_to_add: Int, acc: Int, sequences: List[List[Int]]): List[List[Int]] = {
            acc match {
                case y if y >= target => sequences
                case _ =>
                    val new_sequences = (sequences ::: List(number_to_add) :: sequences.map { l =>
                            val l_sum = l.sum + number_to_add
                            l_sum match {
                                case y if y > target => l 
                                case y if y <= target => number_to_add :: l
                            }     
                        }
                    ).distinct

                    generateCombinations(target, number_to_add, acc + number_to_add, new_sequences) 
            }
        }

        // Main recursive function that goes through each of the members in the candidates list and  
        // calls the helper function for that current list member to generate all combinations with that
        // current list member
        @tailrec
        def backtrack(candidates_list: List[Int], sequences: List[List[Int]], target: Int): List[List[Int]] = {
            candidates_list match {
                case Nil => sequences.filter((l) => l.sum == target).map((l) => l.reverse)
                case x :: xs => backtrack(xs, generateCombinations(target, x, 0, sequences), target)
            }
        }

        return backtrack(sorted_distinct_candidates, List.empty, target)
    }
}