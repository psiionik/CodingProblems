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

        override def toString(): String = {
            return "Node: " + value.toString()
        }
    }

    def parseTreeNodeList(list_of_nodes: Array[Int | Null], curr_index: Int): TreeNode = {
        if curr_index >= list_of_nodes.length || list_of_nodes(curr_index) == null
        then
            return null

        val node = TreeNode(list_of_nodes(curr_index).nn, null, null)
        node.left = parseTreeNodeList(list_of_nodes, curr_index * 2 + 1)
        node.right = parseTreeNodeList(list_of_nodes, curr_index * 2 + 2)

        return node
    }

    def lowestCommonAncestor(root: TreeNode, p: TreeNode, q: TreeNode): TreeNode = {
        if root == null
        then
            return null

        if root.value == p.value || root.value == q.value
        then
            return root

        val left = lowestCommonAncestor(root.left, p, q)
        val right = lowestCommonAncestor(root.right, p, q)

        if left == null
        then
            return right
        else if right == null
        then
            return left
        else
            return root
    }
}