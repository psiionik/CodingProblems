/* 
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
 */

object Solution1 {
    def trap(height: Array[Int]): Int = {
        var res = 0
        val l_to_r = Array.fill(height.length)(0)
        val r_to_l = Array.fill(height.length)(0)

        l_to_r(0) = height(0)
        r_to_l(height.length - 1) = height(height.length - 1)

        for (index <- Range(1, height.length))
        do
            l_to_r(index) = Math.max(l_to_r(index - 1), height(index))

        for (index <- Range(height.length - 2, -1, -1))
        do
            r_to_l(index) = Math.max(r_to_l(index + 1), height(index))

        for (index <- Range(1, height.length - 1))
        do 
            if (height(index) <= Math.min(l_to_r(index - 1), r_to_l(index - 1)) && height(index) <= Math.min(l_to_r(index + 1), r_to_l(index + 1)))
            then
                res += Math.min(Math.min(l_to_r(index - 1), r_to_l(index - 1)), Math.min(l_to_r(index + 1), r_to_l(index + 1))) - height(index)

        res 
    }
}