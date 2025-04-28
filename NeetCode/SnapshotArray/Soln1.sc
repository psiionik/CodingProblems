/**
 * Your SnapshotArray object will be instantiated and called as such:
 * val obj = new SnapshotArray(length)
 * obj.set(index,`val`)
 * val param_2 = obj.snap()
 * val param_3 = obj.get(index,snap_id
 * )
 */

import scala.collection.mutable.Map
import scala.collection.mutable.ArrayBuffer

object Solution1 {
    class SnapshotArray(_length: Int) {
        val length = _length 
        var _snap_idx: Int = 0
        var _history_records = Map.empty[Int, ArrayBuffer[(Int, Int)]]

        for (i <- Range(0, length))
        do
            _history_records += (i -> ArrayBuffer.empty[(Int, Int)])
        
        def set(index: Int, `val`: Int): Unit = {
            _history_records(index) += ((_snap_idx, `val`))
        }

        def snap(): Int = {
            _snap_idx += 1
            _snap_idx - 1
        }

        def get(index: Int, snap_id: Int): Int = {
            val record_history = _history_records(index)
            var left = 0
            var right = record_history.length

            while (left < right)
            do 
                val mid = (left + right) / 2

                if record_history(mid)._1 <= snap_id 
                then
                    left = mid + 1
                else
                    right = mid

            record_history(left-1)._2
        }
    }
}