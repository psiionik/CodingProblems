import scala.collection.immutable.HashMap
import scala.util.control.Breaks._

object Solution1 {

/**
 * Your FileSystem object will be instantiated and called as such:
 * val obj = new FileSystem()
 * val param_1 = obj.createPath(path,value)
 * val param_2 = obj.get(path)
*/

    class TrieNode(node_str: String, value: Int) {
        var _node_str = node_str 
        var _value = value 
        var _children: HashMap[String, TrieNode] = new HashMap()
    }

    class FileSystem() {
        val root = new TrieNode("/", -1)

        def createPath(path: String, value: Int): Boolean = {
            var curr_node = root
            val path_split_string = path.split("/")
            var res = true

            if path_split_string.length <= 1
            then
                return false

            breakable {
                for (curr_path <- path_split_string.slice(1, path_split_string.length - 1))
                do
                    if curr_node._children.isDefinedAt(curr_path)
                    then
                        curr_node = curr_node._children(curr_path)
                    else
                        res = false 
                        break()
            }

            if !res
            then 
                return res
            
            val last_path_string = path_split_string(path_split_string.length - 1)

            if curr_node._children.isDefinedAt(last_path_string)
            then
                return false
            
            curr_node._children = curr_node._children + (last_path_string -> TrieNode(last_path_string, value))
            return true 
        }

        def get(path: String): Int = {
            var curr_node = root
            val path_split_string = path.split("/")
            var res = true

            if path_split_string.length <= 1
            then
                return -1 

            breakable {
                for (path_string <- path_split_string.slice(1, path_split_string.length))
                do
                    if curr_node._children.isDefinedAt(path_string)
                    then
                        curr_node = curr_node._children(path_string)
                    else
                        res = false
                        break()
            }

            if !res
            then
                return -1
            else
                return curr_node._value                
        }
    }
}
