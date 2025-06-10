/* 
Given two strings text1 and text2, return the length of their longest common subsequence. 
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters 
(can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

 */


object Solution1 {
    def longestCommonSubsequence(text1: String, text2: String): Int = {
        val m = text1.length
        val n = text2.length

        val dp = Array.fill[Array[Int]](m + 1)(Array.fill[Int](n + 1)(0))

        for (i <- Range(1, m+1))
        do 
            for (j <- Range(1, n+1))
            do 
                if text1(i - 1) == text2(j - 1)
                then
                    dp(i)(j) = dp(i - 1)(j - 1) + 1
                else
                    dp(i)(j) = Math.max(dp(i - 1)(j), dp(i)(j - 1))

        dp(m)(n)
    }

    def longestCommonSubsequenceOpt(text1: String, text2: String): Int = {
        val m = text1.length
        val n = text2.length

        var prev_row = Array.fill[Int](n + 1)(0)
        var curr_row = Array.fill[Int](n + 1)(0)

        for (i <- Range(1, m+1))
        do 
            for (j <- Range(1, n+1))
            do 
                if text1(i - 1) == text2(j - 1)
                then
                    curr_row(j) = prev_row(j - 1) + 1
                else
                    curr_row(j) = Math.max(prev_row(j), curr_row(j - 1))

            val temp = curr_row
            prev_row = curr_row
            curr_row = temp

        curr_row(n)
    }
}