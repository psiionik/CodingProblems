import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.PriorityQueue
import scala.collection.mutable.HashMap
import scala.util.control.Breaks.*

object Solution1 {
    def medianSlidingWindow(nums: Array[Int], k: Int): Array[Double] = {
        val max_heap = PriorityQueue[Int]()(Ordering.Int)
        val min_heap = PriorityQueue[Int]()(Ordering.Int.reverse)
        val visited = HashMap[Int, Int]()
        val res = ArrayBuffer[Double]()

        var i = 0
        while (i < k) {
            max_heap.enqueue((nums(i)))
            i += 1
        }

        for (j <- Range(0, k / 2))
        do 
            min_heap.enqueue((max_heap.head))
            max_heap.dequeue()

        breakable {
            while (true) {
                if k % 2 == 0
                then
                    res.addOne((max_heap.head.toDouble + min_heap.head.toDouble) * 0.5)
                else
                    res.addOne((max_heap.head))

                if i >= nums.length
                then
                    break()

                val out_num = nums(i - k)
                val in_num = nums(i)
                var balance = 0
                i += 1

                if out_num <= max_heap.head
                then
                    balance += -1
                else
                    balance += 1
                
                if visited.contains(out_num)
                then
                    visited(out_num) += 1
                else
                    visited(out_num) = 1

                if (!(max_heap.isEmpty) && in_num <= max_heap.head)
                then
                    balance += 1
                    max_heap.enqueue((in_num))
                else
                    balance -= 1
                    min_heap.enqueue((in_num))

                if balance < 0
                then
                    max_heap.enqueue((min_heap.dequeue()))
                    balance += 1

                if balance > 0
                then
                    min_heap.enqueue((max_heap.dequeue()))
                    balance -= 1

                while (visited.contains(max_heap.head)) {
                    visited(max_heap.head) -= 1
                    max_heap.dequeue()
                }

                while (visited.contains(min_heap.head)) {
                    visited(min_heap.head) -= 1
                    min_heap.dequeue()
                }
            }
        }

        res.toArray
    }
}
