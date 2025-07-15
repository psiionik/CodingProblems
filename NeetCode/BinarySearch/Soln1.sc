object Solution1 {
    def search(nums: Array[Int], target: Int): Int = {
        var res = -1
        var left = 0
        var right = nums.length

        while (left < right) {
            val mid = left + ((right - left) / 2)
            val mid_value = nums(mid)
            if target == mid_value
            then
                res = mid
                left = right
            else if (target > mid_value)
            then
                left = mid + 1
            else
                right = mid
        }

        res
    }
}