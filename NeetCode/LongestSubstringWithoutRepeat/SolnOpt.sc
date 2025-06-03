import scala.collection.mutable.HashMap

object SolutionOpt {
    def lengthOfLongestSubstring(s: String): Int = {
        var char_index_counter = new HashMap[Char, Int]()
        var left_pointer = 0
        var right_pointer = 0
        var max_so_far = 0
       
        while (right_pointer < s.length) {
            if char_index_counter.contains(s(right_pointer))
            then
                left_pointer = Math.max(char_index_counter(s(right_pointer)), left_pointer)
            
            max_so_far = Math.max(max_so_far, right_pointer - left_pointer + 1)
            char_index_counter.addOne((s(right_pointer), right_pointer + 1))
            right_pointer += 1
        }

        max_so_far
    }
}