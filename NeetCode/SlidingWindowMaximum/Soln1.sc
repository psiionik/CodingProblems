import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.PriorityQueue

object Solution1 {
    def maxSlidingWindow(nums: Array[Int], k: Int): Array[Int] = {
        var max_heap = PriorityQueue[(Int, Int)]()(Ordering.by((_: (Int, Int))._1))
        var res = new ArrayBuffer[Int]()

        for (index <- 0 to (k - 1))
        do 
            max_heap.enqueue((nums(index), index))

        res += (max_heap.head._1)

        for (right_index <- Range(k, nums.length))
        do
            while(!(max_heap.isEmpty) && max_heap.head._2 < (right_index - (k - 1))) {
                max_heap.dequeue()
            }

            max_heap.enqueue((nums(right_index), right_index))

            res += (max_heap.head._1)

        res.toArray    
    }
}
