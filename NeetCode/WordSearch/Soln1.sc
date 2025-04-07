import scala.collection.mutable._
import scala.util.boundary

object Solution1 {
    def exist(board: Array[Array[Char]], word: String): Boolean = {

        def bfs(board: Array[Array[Char]], word: String, i: Int, j: Int): Boolean = {
            val visited = Set((i * board(i).length) + j)
            var queue = Queue((i, j, 0, visited))

            while (!queue.isEmpty) {
                val tup = queue.dequeue() 

                if (tup._3 == (word.length - 1)) then 
                    return true

                for (row <- Range(tup._1 - 1, tup._1 + 2)) {
                    for (col <- Range(tup._2 - 1, tup._2 + 2)) {
                        if (0 <= row)
                            && (row < board.length) 
                            && (0 <= col) 
                            && (col < board(row).length) 
                            && (!(row != tup._1 && col != tup._2))
                            && !(tup._4 contains (row * board(row).length + col)) 
                            && (board(row)(col) == word(tup._3 + 1)) then
                                queue.enqueue(
                                    (row, col, tup._3 + 1, tup._4 ++ Set(row * board(row).length + col))
                                )
                    }
                }
            }

            return false
        }

        var ret = false
        boundary {
            for (i <- Range(0, board.length)) {
                for (j <- Range(0, board(i).length)) {
                    if word(0) == board(i)(j) then
                            ret = bfs(board, word, i, j)

                            if ret then boundary.break(ret)
                }
            }
        }

        return ret 
    }
}
