
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


object Soln1{
/*<script>*/import scala.collection.mutable.ListBuffer

object Solution1 {
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

        def recurse(candidates: Array[Int], target: Int, current_index: Int, accumulated_value: Int, generated_list: ListBuffer[Int]): Unit = {
            if accumulated_value == target
            then
                val sorted_generated_list = generated_list.toList.sortWith((s, l) => l > s)
                if !checker.contains(sorted_generated_list) 
                then
                    res = res ::: List(sorted_generated_list)
                    checker = checker ++ Set(sorted_generated_list) 
                    return
                else 
                    return
            else if accumulated_value > target
            then
                return

            for (i <- Range(current_index, candidates.length))
            do 
                // Step 1: Add the current value into the accumulated list
                generated_list += candidates(i)

                // Step 2: Recurse using the new index and accumulated list
                recurse(candidates, target, i + 1, accumulated_value + candidates(i), generated_list)

                // Step 3: Remove the most recently added value in the accumulated list
                generated_list.remove(generated_list.length - 1)
        }

        recurse(candidates, target, 0, 0, ListBuffer[Int]())

        return res
    }
}
/*</script>*/ /*<generated>*/
def $main() = { _root_.scala.Iterator[String]() }
  override def toString = "Soln1"
  /*</generated>*/
}
