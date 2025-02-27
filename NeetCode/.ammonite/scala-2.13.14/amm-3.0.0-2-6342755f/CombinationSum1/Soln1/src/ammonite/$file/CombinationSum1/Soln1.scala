
package ammonite
package $file.CombinationSum1
import _root_.ammonite.interp.api.InterpBridge.{
  value => interp
}
import _root_.ammonite.interp.api.InterpBridge.value.{
  exit,
  scalaVersion
}
import _root_.ammonite.interp.api.IvyConstructor.{
  ArtifactIdExt,
  GroupIdExt
}
import _root_.ammonite.compiler.CompilerExtensions.{
  CompilerInterpAPIExtensions,
  CompilerReplAPIExtensions
}
import _root_.ammonite.runtime.tools.{
  browse,
  grep,
  time,
  tail
}
import _root_.ammonite.compiler.tools.{
  desugar,
  source
}
import _root_.mainargs.{
  arg,
  main
}
import _root_.ammonite.repl.tools.Util.{
  PathRead
}
import _root_.ammonite.repl.ReplBridge.value.{
  codeColorsImplicit
}


object Soln1{
/*<script>*/import scala.collection.mutable.ListBuffer

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
}/*</script>*/ /*<generated>*/
def $main() = { _root_.scala.Iterator[String]() }
  override def toString = "Soln1"
  /*</generated>*/
}
