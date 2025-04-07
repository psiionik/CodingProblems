object SolutionOpt {
    def rob(nums: Array[Int]): Int = {
        var window_minus_2 = 0
        var window_minus_1 = 0

        for (num <- nums)
        do 
            var temp = Math.max(window_minus_2 + num, window_minus_1)
            window_minus_2 = window_minus_1
            window_minus_1 = temp

        window_minus_1
    }
}