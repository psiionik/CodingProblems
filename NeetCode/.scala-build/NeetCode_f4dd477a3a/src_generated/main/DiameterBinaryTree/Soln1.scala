package DiameterBinaryTree


final class Soln1$_ {
def args = Soln1_sc.args$
def scriptPath = """DiameterBinaryTree/Soln1.sc"""
/*<script>*/
object Solution1 {
    /**
     * Definition for a binary tree node.
     * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
     *   var value: Int = _value
     *   var left: TreeNode = _left
     *   var right: TreeNode = _right
     * }
     */

    class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
        var value: Int = _value
        var left: TreeNode = _left
        var right: TreeNode = _right
    }

    def diameterOfBinaryTree(root: TreeNode): Int = {
        var max_so_far = 0
        def recurse(node: TreeNode): Int = {
            // Base Case
            if (node.left == null && node.right == null) return 0

            // Recurse on left side
            val left_depth = if node.left != null then 1 + recurse(node.left) else 0

            // Recurse on right side
            val right_depth = if node.right != null then 1 + recurse(node.right) else 0

            max_so_far = Math.max(max_so_far, left_depth + right_depth)

            // Want to add the left and right side and return it
            return Math.max(left_depth, right_depth) 
        }

        recurse(root)
        return max_so_far
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

