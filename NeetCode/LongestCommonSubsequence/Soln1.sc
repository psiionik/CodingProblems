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
}