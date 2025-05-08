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

    def getDirections(root: TreeNode, startValue: Int, destValue: Int): String = {
        def dfs(node: TreeNode, find_value: Int, path_string: StringBuilder): Boolean = {
            if node == null
            then
                return false
            else
                if node.value == find_value
                then
                    return true 
                else
                    path_string += 'L'
                    if dfs(node.left, find_value, path_string)
                    then
                        return true
                    path_string.delete(path_string.length() - 1, path_string.length())

                    path_string += 'R'
                    if dfs(node.right, find_value, path_string)
                    then 
                        return true
                    path_string.delete(path_string.length() - 1, path_string.length())

                    return false
        }

        val start_builder = StringBuilder()
        val dest_builder = StringBuilder()

        dfs(root, startValue, start_builder)
        dfs(root, destValue, dest_builder)

        var index = 0
        while (index < start_builder.length() && index < dest_builder.length() && start_builder(index) == dest_builder(index)) {
            index+=1            
        }

        val path_start_slice = start_builder.slice(index, start_builder.length())
        val path_dest_slice = dest_builder.slice(index, dest_builder.length())

        var start_convert = ""
        for (i <- Range(0, path_start_slice.length()))
        do 
            start_convert += "U"

        return start_convert + path_dest_slice.toString()
    }
}