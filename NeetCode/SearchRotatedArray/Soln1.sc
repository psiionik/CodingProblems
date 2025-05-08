object Solution1 {
    def search(nums: Array[Int], target: Int): Int = {
        def binarySearch(nums: Array[Int], left_boundary: Int, right_boundary: Int, target: Int): Int = {
            var left = left_boundary
            var right = right_boundary

            while (left <= right)
            do
                val mid = left + (right - left) / 2

                if nums(mid) == target
                then
                    return mid
                else if (nums(mid) > target)
                then
                    right = mid - 1
                else
                    left = mid + 1

            return -1
        }

        var left = 0
        var right = nums.length - 1

        while (left <= right) {
            val mid = left + (right - left) / 2

            if (nums(mid) > nums(nums.length - 1))
            then
                left = mid + 1
            else
                right = mid - 1
        }

        val answer = binarySearch(nums, 0, left - 1, target) 

        if answer != -1
        then
            return answer
        else
            return binarySearch(nums, left, nums.length - 1, target)
    }
}