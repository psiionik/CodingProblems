object Solution1 {
    def rob(nums: Array[Int]): Int = {
        if nums.length == 1 then return nums(0)

        var one_to_len2_2 = 0
        var one_to_len2_1 = 0

        var two_to_len1_2 = 0
        var two_to_len1_1 = 0

        for (i <- Range(0, nums.length))
        do 
            val current_value = nums(i)

            // Calculating the first circle
            if (0 <= i) && (i <= (nums.length - 2))
            then
                val temp1 = Math.max(current_value + one_to_len2_2, one_to_len2_1)
                one_to_len2_2 = one_to_len2_1
                one_to_len2_1 = temp1

            // Calculating the second circle 
            if (1 <= i) && (i <= (nums.length - 1))
            then
                val temp2 = Math.max(current_value + two_to_len1_2, two_to_len1_1)
                two_to_len1_2 = two_to_len1_1 
                two_to_len1_1 = temp2

        Math.max(two_to_len1_1, one_to_len2_1)
    }
}