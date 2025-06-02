import scala.collection.mutable.HashMap

object Solution1 {
    def lengthOfLongestSubstring(s: String): Int = {
        var max_length_so_far = 0
        var counter = new HashMap[Char, Int]()
        var right_pointer = 0
        var left_pointer = 0

        while (right_pointer < s.length) {
            if !counter.contains(s(right_pointer))
            then
                counter.addOne((s(right_pointer), 1))
            else
                counter(s(right_pointer)) += 1

            while (counter(s(right_pointer)) > 1) {
                counter(s(left_pointer)) -= 1
                left_pointer += 1
            }

            right_pointer += 1
            max_length_so_far = Math.max(max_length_so_far, (right_pointer - left_pointer))
        }

        max_length_so_far
    }
}