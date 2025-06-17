/**
Given a root node reference of a BST and a key, delete the node with the given key in the BST.
 Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

1. Search for a node to remove.
2. If the node is found, delete the node.

 */

object Solution1 {
    class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
        var value: Int = _value
        var left: TreeNode = _left
        var right: TreeNode = _right

        override def toString(): String = {
            return "Node: " + value.toString
        }
    }

    def successor(node: TreeNode): Int = {
        var temp = node.right
        while (temp.left != null) {
            temp = temp.left
        }
        return temp.value
    }
    
    def predecessor(node: TreeNode): Int = {
        var temp = node.left
        while (temp.right != null) {
            temp = temp.right
        }
        return temp.value
    }

    def deleteNode(root: TreeNode, key: Int): TreeNode = {
        if root == null 
        then
            return null

        if root.value < key
        then
            root.right = deleteNode(root.right, key)
        else if root.value > key
        then
            root.left = deleteNode(root.left, key)
        else
            if root.left == null && root.right == null
            then
                return null
            else if root.right != null
            then
                root.value = successor(root)
                root.right = deleteNode(root.right, root.value)
            else
                root.value = predecessor(root)
                root.left = deleteNode(root.left, root.value)

        return root
    }
}