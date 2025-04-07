
object Solution2 {
    def maxSubArray(nums: Array[Int]): Int = {
        val out_of_range_val = -10000000
        nums.foldLeft((out_of_range_val, out_of_range_val)) { ((acc, num) => {
            acc match {
                case (global_max, curr_max) =>
                    val temp = Math.max(num, curr_max + num)
                    (Math.max(global_max, temp), temp)
            }
        })}._1
    }
}