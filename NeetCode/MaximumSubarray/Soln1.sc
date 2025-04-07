
object Solution1 {
    def maxSubArray(nums: Array[Int]): Int = {
        var max_seen = nums(0)
        var current_subarray_sum = nums(0)

        for (i <- Range(1, nums.length)) {
            // If the last iteration's subarray window sum is negative then we want to "reset" it
            // and create a new subarray
            if current_subarray_sum < 0 then current_subarray_sum = 0

            // Add the current value being seen to the current subarray
            current_subarray_sum += nums(i)
            
            // Only take the maximum that we have seen in the current subarray with the global max
            max_seen = Math.max(max_seen, current_subarray_sum)
        }

        return max_seen
    }
}