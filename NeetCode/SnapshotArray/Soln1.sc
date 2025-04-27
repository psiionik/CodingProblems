/**
 * Your SnapshotArray object will be instantiated and called as such:
 * val obj = new SnapshotArray(length)
 * obj.set(index,`val`)
 * val param_2 = obj.snap()
 * val param_3 = obj.get(index,snap_id
 * )
 */

object Solution1 {
    class SnapshotArray(_length: Int) {
        var _snap_id: Int = 0
        var _data: Array[(Int, Int)] = Array.fill(_length) {(0, 0)}
        
        def set(index: Int, `val`: Int): Unit = {

        }

        def snap(): Int = {
            1
        }

        def get(index: Int, snap_id: Int): Int = {
            1
        }

    }
}