/* 
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
 

Constraints:

0 <= nums.length <= 105


 */

import scala.collection.mutable.HashSet
import scala.collection.mutable.HashMap

object Solution1 {
    def longestConsecutive(nums: Array[Int]): Int = {
        var hash_set = HashSet[Int]()
        var max_so_far = 0

        for (num <- nums)
        do 
            hash_set.add(num)


        for (num <- hash_set)
        do 
            if (!hash_set.contains(num - 1))
            then
                var current_count = 1
                var current_num = num

                while (hash_set.contains(current_num + 1)) {
                    current_num += 1
                    current_count += 1
                }

                max_so_far = Math.max(max_so_far, current_count)

        max_so_far 
    }

    def longestConsecutiveUF(nums: Array[Int]): Int = {
        def find(u: Int, representatives: Array[Int]): Int = {
            if u == representatives(u)
            then
                return u

            val parent = find(representatives(u), representatives)
            representatives(u) = parent
            return parent
        }

        def union(u: Int, v: Int, representatives: Array[Int], ranks: Array[Int]): Unit = {
            val parent_u = find(u, representatives)
            val parent_v = find(v, representatives)

            if (parent_u != parent_v)
            then
                if (ranks(parent_u) > ranks(parent_v))
                then
                    representatives(parent_v) = parent_u
                    ranks(parent_u) += ranks(parent_v)
                else
                    representatives(parent_u) = parent_v
                    ranks(parent_v) += ranks(parent_u) 
        }

        var hash_map = HashMap[Int, Int]()
        var representatives = Array.fill[Int](nums.length)(0)
        var ranks = Array.fill[Int](nums.length)(1)

        for (i <- 0 until representatives.length)
        do 
            representatives(i) = i

        for (i <- 0 until nums.length)
        do 
            if (!hash_map.contains(nums(i)))
            then

                if (hash_map.contains(nums(i) - 1))
                then
                    union(i, hash_map(nums(i) - 1), representatives, ranks)

                if (hash_map.contains(nums(i) + 1))
                then
                    union(i, hash_map(nums(i) + 1), representatives, ranks)

                hash_map.addOne((nums(i), i))
        
        var max_so_far = 0
        for (i <- 0 until representatives.length)
        do
            if (representatives(i) == i && ranks(i) > max_so_far)
            then
                max_so_far = ranks(i)

        max_so_far
    }
}
















