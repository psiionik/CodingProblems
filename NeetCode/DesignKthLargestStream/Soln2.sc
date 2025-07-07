/**
 * Your TimeMap object will be instantiated and called as such:
 * val obj = new TimeMap()
 * obj.set(key,value,timestamp)
 * val param_2 = obj.get(key,timestamp)
 */

import scala.collection.mutable.HashMap
import scala.collection.mutable.ArrayBuffer

object Solution2 {
    class TimeMap() {
        private var time_map = new HashMap[String, ArrayBuffer[(Int, String)]]

        // Want to add a key to a HashMap of values where each key points to a
        // Array of values. Since we were given that the timestamps are guaranteed
        // to come in sorted order, we don't need to maintain any sorting in the Array as it will already be sorted
        def set(key: String, value: String, timestamp: Int): Unit = {
            if (!time_map.contains(key))
            then
                // If the key is not already in the map, then add it and initialize a new Array with it added on

                // Initialize the array and add it to the hash map
                val array_buffer = ArrayBuffer[(Int, String)]()
                array_buffer += ((timestamp, value))
                time_map += (key -> array_buffer)
            else
                // If the key is already in the map then we want to append it to the end of the HashMap
                time_map(key) += ((timestamp, value))
        }
        
        // Overall, the idea is to binary search through the HashMap for the minimum timestamp value that is equal to
        // or greater than the timestamp that is given
        def get(key: String, timestamp: Int): String = {
            // Luckily we have a HashMap that stores the given key so if we don't find
            // the key in the hashmap, there is no need to do a binary search
            if (!time_map.contains(key)) then ""
            else
                // If the key is not in the map then perform binary search to find the 
                // minimum possible value "k" that is greater than or equal to the passed in timestamp value
                val arr = time_map(key).toArray

                if (timestamp < time_map(key)(0)._1)
                then
                    return ""

                // Set the bounds of the search space, in this case it would be the entire array
                var left = 0
                var right = arr.length

                while (left < right)
                do
                    var mid = (left + (right - left)) / 2

                    // Split based on the condition the given timestamp and the value of the midpoint of the array
                    if (arr(mid)._1 > timestamp)
                    then
                        right = mid
                    else
                        left = mid + 1

                if (right == 0 && timestamp < arr(0)._1)
                then
                    return ""

                // return the value at "left" since we want the minimum value
                arr(right - 1)._2
        }
    }
}