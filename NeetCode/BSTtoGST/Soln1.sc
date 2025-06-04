/**
 * Definition for a binary tree node.
 * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
 *   var value: Int = _value
 *   var left: TreeNode = _left
 *   var right: TreeNode = _right
 * }
 */
object Solution1 {

    class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
        var value: Int = _value
        var left: TreeNode = _left
        var right: TreeNode = _right

        override def toString(): String = {
            return "Node Value: " + value.toString
        } 
    }

    def convertBSTToArray(node: TreeNode, current_index: Int, res_arr: Array[Option[Int]]): Unit = {
        if current_index >= res_arr.length
        then
            return

        if node == null
        then
            res_arr(current_index) = None
        else
            res_arr(current_index) = Some(node.value)

            convertBSTToArray(node.left, (current_index * 2) + 1, res_arr)
            convertBSTToArray(node.right, (current_index * 2) + 2, res_arr)
    }

    def parseBST(arr: Array[Option[Int]], current_index: Int): TreeNode = {
        if current_index < arr.length
        then
            arr(current_index) match
                case None => null
                case Some(value) =>
                    val left_node = parseBST(arr, (current_index * 2) + 1)
                    val right_node = parseBST(arr, (current_index * 2) + 2)

                    new TreeNode(value, left_node, right_node)
        else
            null
    }

    def bstToGst(root: TreeNode): TreeNode = {
        def dfs(node: TreeNode, acc: Int): Int = {
            node match
                case null =>
                    acc 
                case _: TreeNode => 
                    val value_right_subtree = dfs(node.right, acc)
                    node.value += value_right_subtree
                    val value_left_subtree = dfs(node.left, node.value)

                    value_left_subtree
        }

        dfs(root, 0)
        root
    }
}