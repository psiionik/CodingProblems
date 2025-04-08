import scala.collection.mutable.Queue

object Solution1 {
    class HitCounter() {
        private val hit_timeout = 300
        private var hit_counter = new Queue[Int]()

        def hit(timestamp: Int): Unit = { 
            while(hit_counter.headOption.exists((i) => (timestamp - hit_timeout) >= i))
            do 
                hit_counter.dequeue()

            hit_counter += timestamp
        }

        def getHits(timestamp: Int): Int = {
            while(hit_counter.headOption.exists((i) => (timestamp - hit_timeout) >= i))
            do 
                hit_counter.dequeue()

            hit_counter.size
        }
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * val obj = new HitCounter()
 * obj.hit(timestamp)
 * val param_2 = obj.getHits(timestamp)
 */