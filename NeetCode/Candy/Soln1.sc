object Solution1 {
    def candy(ratings: Array[Int]): Int = {
        var dp = Array.fill[Int](ratings.length)(1)
        var res = 0

        for (i <- Range(1, ratings.length))
        do 
            if (ratings(i) > ratings(i - 1))
            then
                dp(i) = Math.max(dp(i), dp(i - 1) + 1)

        for (i <- Range(ratings.length - 2, -1, -1))
        do
            if (ratings(i) > ratings(i + 1))
            then
                dp(i) = Math.max(dp(i), dp(i + 1) + 1)

            res += dp(i)

        res + dp(dp.length - 1)
    }
}