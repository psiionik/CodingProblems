/* 
Given an array of positive integers nums and a positive integer target,
return the minimal length of a subarray whose sum is greater than or equal to target. 
If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0


 */

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