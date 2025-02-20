
package ammonite
package $file.CombinationSum2
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


object Soln3{
/*<script>*/import scala.collection.mutable.ListBuffer
import scala.util.control.Breaks._

object Solution3 {
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
/*</script>*/ /*<generated>*/
def $main() = { _root_.scala.Iterator[String]() }
  override def toString = "Soln3"
  /*</generated>*/
}
