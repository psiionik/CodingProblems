/* 
Given an integer array nums, return true if you can partition the array into two subsets
such that the sum of the elements in both subsets is equal or false otherwise.
 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
 */

object Solution1 {
    def canPartition(nums: Array[Int]): Boolean = {
        var total_sum = 0
        for (num <- nums)
        do 
            total_sum += num
        
        if total_sum % 2 == 1
        then
            return false

        val subset_sum = total_sum / 2
        val n = nums.length
        val dp = Array.fill[Array[Boolean]](n + 1)(Array.fill[Boolean](subset_sum + 1)(false))
        dp(0)(0) = true

        for (i <- Range(1, n + 1))
        do 
            val curr_value = nums(i - 1)
            for (j <- Range(0, subset_sum + 1))
            do 
                if j < curr_value
                then
                    dp(i)(j) = dp(i - 1)(j)
                else
                    dp(i)(j) = dp(i - 1)(j) || dp(i - 1)(j - curr_value)

        dp(n)(subset_sum)
    }

    def canPartitionOpt(nums: Array[Int]): Boolean = {
        if nums.length == 0
        then
            return false

        var total_sum = 0
        for (num <- nums)
        do 
            total_sum += num
        
        if total_sum % 2 == 1
        then
            return false

        val subset_sum = total_sum / 2
        val n = nums.length
        var dp = Array.fill[Boolean](subset_sum + 1)(false)
        dp(0) = true

        for (i <- Range(1, n + 1))
        do 
            val curr_value = nums(i - 1)
            for (j <- Range(subset_sum, curr_value - 1, -1))
            do 
                dp(j) = dp(j) || dp(j - curr_value)

        dp(subset_sum)
    }
}