/* 
Given an array of integers nums which is sorted in ascending order, and an integer target, 
write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.
 */

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