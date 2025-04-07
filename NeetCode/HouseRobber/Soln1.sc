object Solution1 {
    def rob(nums: Array[Int]): Int = {
        if nums.length == 1
        then 
            return nums(0)

        val mem = Array.fill(nums.length){0}
        mem(0) = nums(0)
        mem(1) = Math.max(nums(1), nums(0))

        for (i <- Range(2, nums.length)) do {
            mem(i) = Math.max(mem(i - 1), nums(i) + mem(i - 2))
        }

        mem(mem.length - 1)
    }
}