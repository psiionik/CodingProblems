/* 
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

- LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
- int get(int key) Return the value of the key if the key exists, otherwise return -1.
- void put(int key, int value) Update the value of the key if the key exists. Otherwise, 
    add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, 
    evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
 */

import scala.collection.mutable.HashMap

object Solution1 {
    /**
     * Your LRUCache object will be instantiated and called as such:
     * val obj = new LRUCache(capacity)
     * val param_1 = obj.get(key)
     * obj.put(key,value)
     */

    class LRUCache(_capacity: Int) {
        var count = 0
        var capacity = _capacity + 1
        var key_value_store = HashMap[Int, Int]()
        var lru_tracker = List.empty[Int]

        def updateLRUTracker(lru_tracker: List[Int], new_key: Int, at_capacity: Boolean): List[Int] = {
            lru_tracker match
                case Nil => List()
                case head :: Nil if at_capacity => 
                    key_value_store -= head
                    List()
                case head :: next if new_key != head => head :: updateLRUTracker(next, new_key, at_capacity)
                case head :: next => updateLRUTracker(next, new_key, at_capacity)
        }

        def get(key: Int): Int = {
            if key_value_store.contains(key)
            then
                lru_tracker = key :: updateLRUTracker(lru_tracker, key, false)
                key_value_store(key)
            else
                -1
        }

        def put(key: Int, value: Int): Unit = {
            if key_value_store.contains(key) 
            then
                key_value_store(key) = value
            else
                key_value_store(key) = value
                count += 1

            lru_tracker = key :: updateLRUTracker(lru_tracker, key, count == capacity)
            if count == capacity then count -= 1
        }
    }
}