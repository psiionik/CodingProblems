package CombinationSum1


final class Soln1$_ {
def args = Soln1_sc.args$
def scriptPath = """CombinationSum1/Soln1.sc"""
/*<script>*/
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
/*</script>*/ /*<generated>*//*</generated>*/
}

object Soln1_sc {
  private var args$opt0 = Option.empty[Array[String]]
  def args$set(args: Array[String]): Unit = {
    args$opt0 = Some(args)
  }
  def args$opt: Option[Array[String]] = args$opt0
  def args$: Array[String] = args$opt.getOrElse {
    sys.error("No arguments passed to this script")
  }

  lazy val script = new Soln1$_

  def main(args: Array[String]): Unit = {
    args$set(args)
    val _ = script.hashCode() // hashCode to clear scalac warning about pure expression in statement position
  }
}

export Soln1_sc.script as `Soln1`

