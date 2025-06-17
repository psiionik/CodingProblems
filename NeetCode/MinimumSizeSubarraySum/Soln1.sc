object Solution1 {
    def minSubArrayLen(target: Int, nums: Array[Int]): Int = {
        var found = false
        var min_len = Int.MaxValue

        var left = 0
        var right = 0
        var sum_left = target

        while (right < nums.length) {
            sum_left -= nums(right)

            while (sum_left <= 0 && left <= right) {
                found = true
                min_len = Math.min(min_len, (right - left) + 1)
                sum_left += nums(left)
                left += 1
            }

            right += 1
        }

        if found 
        then
            min_len
        else
            0
    }
}