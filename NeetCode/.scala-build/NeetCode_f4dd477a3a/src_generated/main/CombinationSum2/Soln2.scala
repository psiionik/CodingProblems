package CombinationSum2


final class Soln2$_ {
def args = Soln2_sc.args$
def scriptPath = """CombinationSum2/Soln2.sc"""
/*<script>*/
import scala.collection.mutable.ListBuffer
import scala.util.control.Breaks._

object Solution2 {
    def combinationSum2(candidates: Array[Int], target: Int): List[List[Int]] = {
        var res: List[List[Int]] = List()
        val sorted_candidates = candidates.filter((candidate) => candidate <= target).sorted

        def backtrack(current_index: Int, accumulated_value: Int, generated_list: ListBuffer[Int]): Unit = {
            if accumulated_value == target
            then
                res = res ::: List(generated_list.toList)
                return
            else if (accumulated_value > target) || (current_index >= sorted_candidates.length)
            then
                return
            else
                for (i <- Range(current_index, sorted_candidates.length) if (accumulated_value + sorted_candidates(i) <= target))
                do
                    breakable {
                        // Optimization here is to skip duplicate grouped elements and skipping if adding the next candidate will exceed the target value
                        if (i > current_index && sorted_candidates(i) == sorted_candidates(i - 1)) then break()

                        // Add the current thing to generated list
                        generated_list += sorted_candidates(i)

                        // Recurse with the new item being tried
                        backtrack(i + 1, accumulated_value + sorted_candidates(i), generated_list) 

                        // Backtrack by removing the last item added
                        generated_list.remove(generated_list.length - 1)
                    }
                
                return 
        }

        backtrack(0, 0, ListBuffer[Int]()) 

        return res
    }
}

/*</script>*/ /*<generated>*//*</generated>*/
}

object Soln2_sc {
  private var args$opt0 = Option.empty[Array[String]]
  def args$set(args: Array[String]): Unit = {
    args$opt0 = Some(args)
  }
  def args$opt: Option[Array[String]] = args$opt0
  def args$: Array[String] = args$opt.getOrElse {
    sys.error("No arguments passed to this script")
  }

  lazy val script = new Soln2$_

  def main(args: Array[String]): Unit = {
    args$set(args)
    val _ = script.hashCode() // hashCode to clear scalac warning about pure expression in statement position
  }
}

export Soln2_sc.script as `Soln2`

