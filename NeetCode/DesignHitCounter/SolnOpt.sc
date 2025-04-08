import scala.collection.mutable.ArrayDeque

object SolutionOpt {
    class HitCounter() {
        private val hit_timeout = 300
        private var total = 0
        private var hit_counter = new ArrayDeque[(Int, Int)]()

        def hit(timestamp: Int): Unit = { 
            if hit_counter.isEmpty
            then
                hit_counter += ((timestamp, 1))
                total += 1
            else if hit_counter.last._1 != timestamp
            then
                hit_counter += ((timestamp, 1))
                total += 1
            else
                val prev_count = hit_counter.last._2
                hit_counter.removeLast()
                hit_counter += ((timestamp, prev_count + 1))
                total += 1
        }

        def getHits(timestamp: Int): Int = {
            while(hit_counter.headOption.exists((i) => (timestamp - hit_timeout) >= i._1))
            do 
                total -= hit_counter.head._2
                hit_counter.removeHead()

            total
        }
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * val obj = new HitCounter()
 * obj.hit(timestamp)
 * val param_2 = obj.getHits(timestamp)
 */