/* 
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
 */

import scala.collection.mutable.Queue
import scala.util.boundary, boundary.break

object Solution1 {
    enum Direction:
        case Right, Down, Left, Up

    class FSM(_direction: Direction = Direction.Right) {
        var dir = _direction

        def getCurrentState(): Direction = {
            dir
        }

        def changeState(): Unit = {
            dir match
                case Direction.Right => dir = Direction.Down
                case Direction.Down => dir = Direction.Left
                case Direction.Left => dir = Direction.Up
                case Direction.Up => dir = Direction.Right
        }
    }

    def spiralOrder(matrix: Array[Array[Int]]): List[Int] = {
        // Function to get a potential neighbor based on bounds checking, and if it is visited yet
        // This fucntion grabs a neighbor in a specific ordering (Right => Down => Left => Up)
        def grabNeighbors(num_rows: Int, num_cols: Int, r: Int, c: Int, visited: Array[Array[Int]], curr_dir: Direction): Option[(Int, Int)] = {
            curr_dir match
                case Direction.Right if (c + 1 < num_cols && visited(r)(c + 1) == 0) => Some((r, c + 1))
                case Direction.Down if (r + 1 < num_rows && visited(r + 1)(c) == 0) => Some((r + 1, c))
                case Direction.Left if (c - 1 >= 0 && visited(r)(c - 1) == 0) => Some((r, c - 1))
                case Direction.Up if (r - 1 >= 0 && visited(r - 1)(c) == 0) => Some((r - 1, c))
                case _ => None
        }

        var res = List[Int]()
        val dir_fsm = FSM()

        // Constraints of the problem mentioned that the matrix dimensions will always have at least one row / one column
        val n = matrix.length
        val m = matrix(0).length

        // Memory structure to hold which cells we have visited
        val visited = Array.fill[Array[Int]](n)(Array.fill[Int](m)(0))

        // Initializing the queue and adding the starting element and mark as visited
        var q = Queue[(Int, Int)]()
        q.enqueue((0, 0))
        visited(0)(0) = 1

        // Loop until we have traversed throughout the entire memory structure
        while (!q.isEmpty) {
            // Remove the first element in the queue
            val (row, col) = q.dequeue()

            // Add the contents of the matrix into the resulting list
            res = matrix(row)(col) :: res

            boundary {
                for (_ <- 0 until 4) {
                    grabNeighbors(n, m, row, col, visited, dir_fsm.getCurrentState()) match
                        case None => dir_fsm.changeState()
                        case Some(value) =>
                            // If we get a valid neighbor then add it to the queue and mark as visited
                            q.enqueue(value)
                            visited(value(0))(value(1)) = 1
                            break()
                }
            }
       }

        res.reverse
    }
}