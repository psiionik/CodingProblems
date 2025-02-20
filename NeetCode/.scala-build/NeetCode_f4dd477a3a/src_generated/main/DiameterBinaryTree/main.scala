package DiameterBinaryTree


final class main$_ {
def args = main_sc.args$
def scriptPath = """DiameterBinaryTree/main.sc"""
/*<script>*/
import $file.Soln1, Soln1.Solution1
import $file.Soln1, Soln1.Solution1.TreeNode

def testCase1(f: (TreeNode) => Int): Unit = {
    // TEST CASE 1
    val node_5 = new TreeNode(5)
    val node_4 = new TreeNode(4)
    val node_3 = new TreeNode(3)
    val node_2 = new TreeNode(2, node_4, node_5)
    val node_1 = new TreeNode(1, node_2, node_3)

    val res = f(node_1)
    println(res)

    assert(res == 3, "Test Case 1 Failed!")
}

def testCase2(f: (TreeNode) => Int): Unit = {
    val node_2 = new TreeNode(2)
    val node_1 = new TreeNode(1, node_2, null)

    val res = f(node_1)
    println(res)

    assert(res == 1, "Test Case 2 Failed!")
}

def runTestCases(f: (TreeNode) => Int): Unit = {
    testCase1(f)
    testCase2(f)
}


@main def mainSol1() = {
    runTestCases(Solution1.diameterOfBinaryTree)
}
/*</script>*/ /*<generated>*//*</generated>*/
}

object main_sc {
  private var args$opt0 = Option.empty[Array[String]]
  def args$set(args: Array[String]): Unit = {
    args$opt0 = Some(args)
  }
  def args$opt: Option[Array[String]] = args$opt0
  def args$: Array[String] = args$opt.getOrElse {
    sys.error("No arguments passed to this script")
  }

  lazy val script = new main$_

  def main(args: Array[String]): Unit = {
    args$set(args)
    val _ = script.hashCode() // hashCode to clear scalac warning about pure expression in statement position
  }
}

export main_sc.script as `main`

