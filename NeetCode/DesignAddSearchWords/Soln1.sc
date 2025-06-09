/* 
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

 */

import scala.collection.mutable.HashMap
import scala.util.control.Breaks.*

object Solution1 {
    /**
     * Your WordDictionary object will be instantiated and called as such:
     * val obj = new WordDictionary()
     * obj.addWord(word)
     * val param_2 = obj.search(word)
     */

    class TrieNode(value: Char, end_word: Boolean) {
        var _value = value
        var _children = new HashMap[Char, TrieNode]()
        var _end_word = end_word

        override def toString(): String = {
            return "Node: " + _value.toString + " Children: " + _children.foldLeft("")((acc, item) => acc + " " + item._1.toString)
        }
    }

    class WordDictionary() {
        var root = new TrieNode('0', false)

        def addWord(word: String): Unit = {
            var temp = root 

            for (char <- word)
            do 
                if temp._children.contains(char)
                then
                    temp = temp._children(char)
                else
                    val new_node = new TrieNode(char, false)
                    temp._children.addOne((char, new_node))
                    temp = temp._children(char)

            temp._end_word = true
        }

        def search(word: String): Boolean = {
            def dfs(word: String, curr_node: TrieNode, char_index: Int): Boolean = {
                if char_index == word.length
                then
                    return curr_node._end_word

                if word(char_index) == '.'
                then
                    var has_word = false
                    breakable {
                        for ((_, child_node) <- curr_node._children)
                        do
                            has_word = has_word || dfs(word, child_node, char_index + 1)

                            if has_word
                            then
                                break()
                    }

                    return has_word
                else
                    if curr_node._children.contains(word(char_index))
                    then
                        return dfs(word, curr_node._children(word(char_index)), char_index + 1)
                    else
                        return false
            }

            return dfs(word, root, 0)
        }
    }
}