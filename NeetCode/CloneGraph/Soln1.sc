import scala.collection.mutable.Queue

object Solution1 {
    /**
     * Definition for a binary tree node.
     * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
     *   var value: Int = _value
     *   var left: TreeNode = _left
     *   var right: TreeNode = _right
     * }
     */

    class Node(var _value: Int) {
        var value: Int = _value
        var neighbors: List[Node] = List()

        override def toString(): String = {
            return "Node: " + value.toString() + "\nNeighbors: " + neighbors.length
        }
    }

    def cloneGraph(graph: Node): Node = {
        if graph == null
        then
            return null

        val node_list: Array[Node] = Array.fill(101)(null)
        val q: Queue[Node] = Queue()
        q.enqueue(graph)
        node_list(graph.value) = Node(graph.value)

        while (!q.isEmpty) {
            val node = q.dequeue()

            for (neighbor <- node.neighbors)
            do
                if (node_list(neighbor.value) == null)
                then
                    node_list(neighbor.value) = Node(neighbor.value)
                    q.enqueue(neighbor)

                node_list(node.value).neighbors = node_list(node.value).neighbors :+ node_list(neighbor.value)
        }

        return node_list(graph.value)
    }
}