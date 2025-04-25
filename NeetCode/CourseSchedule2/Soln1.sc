import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.Queue

object Solution1 {
    def findOrder(numCourses: Int, prerequisites: Array[Array[Int]]): Array[Int] = {
        val res = ArrayBuffer[Int]()
        val indeg_arr = Array.fill(numCourses)(0) 
        val dag: Array[List[Int]] = Array.fill(numCourses)(List.empty[Int])

        // Fill up the indeg array and the dag by looping through the prereqs
        for (i <- Range(0, prerequisites.length))
        do
            val class_to_take = prerequisites(i)(0)
            val required_class = prerequisites(i)(1)

            indeg_arr(class_to_take) += 1
            dag(required_class) = class_to_take :: dag(required_class)

        // Run topological sort by using a queue and adding nodes that have an indegree of 0
        val queue = Queue[Int]()

        // Add all of the nodes that have an indegree of 0
        for ((el,index) <- indeg_arr.view.zipWithIndex)
        do 
            if (el == 0)
            then
                queue.enqueue(index)

        // Main BFS loop for popping off of the elements in the queue and subtracting its child's
        // indegree by 1. If there are any elements that have an indegree of 0, then add it to the queue
        while (!queue.isEmpty) {
            val node = queue.dequeue()
            // Subtract the indegree of the currently popped node by 1 to make sure we mark it as "visited"
            // indeg_arr(node) -= 1

            // Add this class to the resulting array
            res += (node)

            // Loop through all of the child of this node and subtract 1 from indegree.
            // If the indegree reaches 0 then add it to the queue
            for (child_node <- dag(node))
            do 
                indeg_arr(child_node) -= 1
                if (indeg_arr(child_node) == 0)
                then
                    queue.enqueue(child_node)
        }

        if indeg_arr.sum != 0
        then
            Array.empty[Int]
        else
            res.toArray
    }
}
