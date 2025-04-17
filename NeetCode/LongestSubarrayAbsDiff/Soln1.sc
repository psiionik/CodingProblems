import scala.collection.mutable.PriorityQueue

object Solution1 {
    def longestSubarray(nums: Array[Int], limit: Int): Int = {
        val min_heap = PriorityQueue[(Int, Int)]()(Ordering.by((_: (Int, Int))._1).reverse)
        val max_heap = PriorityQueue[(Int, Int)]()(Ordering.by((_: (Int, Int))._1))

        var max_so_far = 0
        var left = 0
        var right = 0

        while (right < nums.length) {
            min_heap.enqueue((nums(right), right))
            max_heap.enqueue((nums(right), right))

            val greatest = max_heap.head._1
            val least = min_heap.head._1

            if (Math.abs(greatest - least) <= limit)
            then
                max_so_far = Math.max(max_so_far, (right - left) + 1)
            else
                while(Math.abs(max_heap.head._1 - min_heap.head._1) > limit) {
                    left = Math.min(min_heap.head._2, max_heap.head._2) + 1

                    while(min_heap.head._2 < left) {
                        min_heap.dequeue()
                    }

                    while(max_heap.head._2 < left) {
                        max_heap.dequeue()
                    }
                }

            right += 1
        }

        max_so_far
    }
}