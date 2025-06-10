/* 
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

 */

import scala.collection.mutable.HashMap

object Solution1 {
    def groupAnagrams(strs: Array[String]): List[List[String]] = {
        var res = List[List[String]]()
        val counter = new HashMap[String, List[String]]()

        for (str <- strs)
        do 
            val sorted_str = str.sorted
            if counter.contains(sorted_str)
            then
                counter(sorted_str) = str :: counter(sorted_str)
            else
                counter(sorted_str) = List(str)

        for ((_, value) <- counter)
        do
            res = res ++ List(value)

        res
    }
}