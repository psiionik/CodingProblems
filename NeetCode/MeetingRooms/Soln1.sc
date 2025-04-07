import scala.util.boundary

object Solution1 {
    def canAttendMeetings(intervals: Array[Array[Int]]): Boolean = {
        if intervals.length < 2 then
            return true

        var ret = true
        boundary {
            intervals.sortBy(tup => tup(0)).sliding(2).foreach(m => { 
                if m(0)(1) > m(1)(0) then
                    ret = false
                    boundary.break(ret)
            })
        }
        return ret 
    }
}