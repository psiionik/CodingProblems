import scala.collection.immutable.HashMap
import scala.util.control.Breaks._

object Solution1 {

    class TrieNode(node_char: Char, is_word: Boolean) {
        var _node_char = node_char 
        var _is_word = is_word
        var _children: HashMap[Char, TrieNode] = new HashMap()
    }

    class Trie() {
        val root = new TrieNode('\u0000', false)

        def insert(word: String): Unit = {
            var curr_node = root 

            for (char <- word)
            do 
                if curr_node._children.isDefinedAt(char)
                then
                    curr_node = curr_node._children(char)
                else
                    curr_node._children = curr_node._children + (char -> new TrieNode(char, false))
                    curr_node = curr_node._children(char)

            curr_node._is_word = true
        }

        def search(word: String): Boolean = {
            var curr_node = root
            var is_word = true

            breakable {
                for (char <- word)
                do 
                    if curr_node._children.isDefinedAt(char)
                    then
                        curr_node = curr_node._children(char)
                    else
                        is_word = false
                        break()
            }
            
            if curr_node._is_word && is_word
            then
                return true
            else
                return false
        }

        def startsWith(prefix: String): Boolean = {
            var curr_node = root
            var is_prefix = true

            breakable {
                for (char <- prefix)
                do 
                    if curr_node._children.isDefinedAt(char)
                    then
                        curr_node = curr_node._children(char)
                    else
                        is_prefix = false
                        break()
            }

            return is_prefix
        }
    }
}