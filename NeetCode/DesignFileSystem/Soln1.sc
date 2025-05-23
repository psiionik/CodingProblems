/**
 * Your TimeMap object will be instantiated and called as such:
 * val obj = new TimeMap()
 * obj.set(key,value,timestamp)
 * val param_2 = obj.get(key,timestamp)
 */

import scala.collection.mutable.HashMap
import scala.util.boundary

object Solution1 {
    class TimeMap() {
        private var time_map = new HashMap[String, HashMap[Int, String]]()

        // This solution has the benefit of O(1) `set` calls into the design
        def set(key: String, value: String, timestamp: Int): Unit = {
            // Check if the HashMap has the key
            // If not then initialize a new inner HashMap structure to it and add the key/value/timestamp pair
            if !time_map.contains(key)
            then
                time_map += (key -> HashMap(timestamp -> value))

            // If the HashMap already contains the key, then add it to the existing HashMap with that key
            // because the problem mentions that `set` call always has strictly increasing timestamps,
            // we don't need to worry about conflicting keys
            else
                time_map.get(key).map((inner_map) => inner_map += (timestamp -> value))
        }

        def get(key: String, timestamp: Int): String = {
            if !time_map.contains(key)
            then
                return ""
            else
                var return_val = ""
                boundary {
                    // Loop back from the current timestamp to 1 and return the one that is found
                    for (i <- Range(timestamp, 0, -1))
                    do
                        if time_map(key).contains(i)
                        then
                            return_val = time_map(key)(i) 
                            boundary.break()

                }
                return return_val 
        }
        
        // The tradeoff in this solution is that because a HashMap data structure is not ordered
        // you will have to linearly search thoughout the inner HashMap to find the timestamp that is
        // <= the parameter timestamp
        def get2(key: String, timestamp: Int): String = {
            if time_map.contains(key)
            then
                // Want to walk back linearly from the end of the HashMap
                // Create Iterator
                val it: Iterator[(Int, String)] = time_map(key).iterator
                var max_so_far = -1
                var return_val = ""

                while it.hasNext
                do
                    val tup = it.next()

                    if tup._1 <= timestamp && tup._1 >= max_so_far
                    then
                        max_so_far = tup._1
                        return_val = tup._2

                return_val
            else
                ""
        }
    }
}