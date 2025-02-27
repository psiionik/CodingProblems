package CombinationSum2


final class Soln3$_ {
def args = Soln3_sc.args$
def scriptPath = """CombinationSum2/Soln3.sc"""
/*<script>*/
import scala.collection.mutable.ListBuffer
import scala.util.control.Breaks._
import scala.annotation.tailrec

@tailrec
def innerLoop(candidate_list: List[Int], outer_loop_var: Int): Unit = {
    candidate_list match {
        case Nil => return
        case x :: xs => {
            println(x)
            innerLoop(xs, outer_loop_var)
        }
    }
}

@tailrec
def outerLoop(orig_candidate_list: List[Int], candidate_list: List[Int]): Unit = {
    candidate_list match {
        case Nil => return
        case x :: xs => {
            innerLoop(orig_candidate_list, x)
            outerLoop(orig_candidate_list, xs)
        }
    }
}

@tailrec
def insertionSortInner(sorted_list_so_far: List[Int], value_to_sort: Int, accumulator: List[Int]): List[Int] = {
    sorted_list_so_far match {
        case Nil => List(value_to_sort) 
        case x :: xs if value_to_sort <= x => accumulator.reverse ++ (value_to_sort :: x :: xs)  
        case x :: xs => insertionSortInner(xs, value_to_sort, x :: accumulator)
    }
}

@tailrec
def insertionSort(list_to_sort: List[Int], sorted_acc_list: List[Int]): List[Int] = {
    list_to_sort match {
        case Nil => sorted_acc_list
        case x :: xs => insertionSort(xs, insertionSortInner(sorted_acc_list, x, Nil))
    } 
}

// Trying out Tail Recursion to solve the problem
object Solution3 {
    def combinationSum2(candidates: Array[Int], target: Int): List[List[Int]] = {
        val sorted_candidates = candidates.filter((candidate) => candidate <= target).sorted.toList
        println(sorted_candidates.mkString(" "))

        @tailrec 
        def backtrack(sorted_candidates: List[Int], accumulated_value: Int, stack_frames: List[], generated_list: List[Int], solution: List[List[Int]]): List[List[Int]] = {
            solution match {
                case _ if accumulated_value == target => generated_list :: solution 
                case _ if accumulated_value > target => solution
                case _ =>
                    
                    // Want to advance the list until we reach the last occurrence of the number of the current index
                    sorted_candidates match {
                        case head :: tail if head == tail.head => {
                            println(tail.mkString(" "))
                            backtrack(tail, accumulated_value, generated_list, solution)
                        }
                        case _ => solution
                    }
                    // val distinct_sorted_candidates = sorted_candidates.flatMap((item) => {
                    //     List(List(item))
                    // })

                    // distinct_sorted_candidates match {
                    //     case Nil => solution
                    //     case head :: tail if head == tail.head => 
                    //     case head :: tail => 
                    //     case _ => solution
                    // }
            }
        }

        return backtrack(sorted_candidates, 0, Nil, Nil)
    }

    // def combinationSum2(candidates: Array[Int], target: Int): List[List[Int]] =
    //     backtrack(candidates.sorted, List.empty, List.empty, target, List.empty)

    // @tailrec
    // def backtrack(candidates: Array[Int], solution: List[Int], remainders: List[(List[Int], Array[Int], Int)], target: Int, results: List[List[Int]]): List[List[Int]] = {
    //     solution match {
    //     case _ if target == 0 && remainders.isEmpty => {
    //         solution :: results
    //     } 
    //     case _ if target == 0 =>
    //         val res = solution :: results
    //         val (s, candidates, target) = remainders.head
    //         backtrack(candidates, s, remainders.tail, target, res)
    //     case _ =>
    //         val indexOfPotentialCandidates = candidates.indices.toList
    //         .flatMap {
    //             case 0                                       => List(0)
    //             case i if candidates(i) != candidates(i - 1) => List(i)
    //             case _                                       => List.empty
    //         }
    //         .filter { v =>
    //             candidates(v) <= target
    //         }
            
    //         indexOfPotentialCandidates match {
    //         case index :: xs =>
    //             val v = candidates(index)

    //             val extraRemainders = xs.map { index =>
    //             val v = candidates(index)
    //             ((v :: solution), candidates.drop(index + 1), target - v)
    //             } ++ remainders

    //             backtrack(candidates = candidates.drop(index + 1), solution = v :: solution, remainders = extraRemainders, target - v, results)
    //         case _ if remainders.isEmpty => 
    //             results
    //         case _ =>
    //             val (solution, candidates, target) = remainders.head
    //             backtrack(candidates, solution, remainders.tail, target, results)
    //         }
    //     }
    // }
}

/*</script>*/ /*<generated>*//*</generated>*/
}

object Soln3_sc {
  private var args$opt0 = Option.empty[Array[String]]
  def args$set(args: Array[String]): Unit = {
    args$opt0 = Some(args)
  }
  def args$opt: Option[Array[String]] = args$opt0
  def args$: Array[String] = args$opt.getOrElse {
    sys.error("No arguments passed to this script")
  }

  lazy val script = new Soln3$_

  def main(args: Array[String]): Unit = {
    args$set(args)
    val _ = script.hashCode() // hashCode to clear scalac warning about pure expression in statement position
  }
}

export Soln3_sc.script as `Soln3`

