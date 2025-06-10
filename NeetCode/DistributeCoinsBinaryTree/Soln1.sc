/**
 * You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. 
 * There are n coins in total throughout the whole tree. 
 * In one move, we may choose two adjacent nodes and move one coin from one node to another. 
 * A move may be from parent to child, or from child to parent.
 * Return the minimum number of moves required to make every node have exactly one coin.
 * 
 * Input: root = [3,0,0]
 * Output: 2
 * 
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

    def distributeCoins(root: TreeNode): Int = {
        var amount_of_moves = 0
        def dfs(node: TreeNode): Int = {
            if node == null
            then
                return 0
            
            val left_subtree_amount = dfs(node.left)
            val right_subtree_amount = dfs(node.right)
            amount_of_moves += Math.abs(left_subtree_amount) + Math.abs(right_subtree_amount)

            return (node.value - 1) + left_subtree_amount + right_subtree_amount
        }

        dfs(root)
        amount_of_moves
    }
}