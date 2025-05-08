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
    }

    def maxPathSum(root: TreeNode): Int = {
        var max_so_far = Int.MinValue
        def dfs(node: TreeNode): Int = {
            if node == null
            then
                0
            else
                val left_val = dfs(node.left)
                val right_val = dfs(node.right)
                val curr_val = node.value

                max_so_far = max_so_far.max(left_val.max(0) + right_val.max(0) + curr_val)
                (left_val + curr_val).max(right_val + curr_val) 
        }

        dfs(root)
        max_so_far
    }
}