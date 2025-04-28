/**
 * Your SnapshotArray object will be instantiated and called as such:
 * val obj = new SnapshotArray(length)
 * obj.set(index,`val`)
 * val param_2 = obj.snap()
 * val param_3 = obj.get(index,snap_id
 * )
 */

import scala.collection.mutable.ArrayBuffer

object Solution1 {
    class SnapshotArray(_length: Int) {
        val length = _length 
        var _snap_idx: Int = 0
        var _data: ArrayBuffer[Int] = ArrayBuffer.fill(length) {0}
        
        def set(index: Int, `val`: Int): Unit = {
            _data((_snap_idx * length) + index) = `val`
        }

        def snap(): Int = {
            _data ++= ArrayBuffer.fill(length)(0)

            _snap_idx += 1
            _snap_idx - 1
        }

        def get(index: Int, snap_id: Int): Int = {
            _data((snap_id * length) + index)
        }

    }
}