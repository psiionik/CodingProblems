object Solution2 {
    def canAttendMeetings(intervals: Array[Array[Int]]): Boolean = {
        if intervals.length < 2 
        then
            true
        else
            val x = intervals.sortBy(tup => tup(0)).sliding(2).dropWhile()
            println(x)
            false
    }
}