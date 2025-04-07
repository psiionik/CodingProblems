object Solution2 {
    def exist(board: Array[Array[Char]], word: String): Boolean = {
      def solve(visited: Set[(Int, Int)], x: Int, y: Int, word_index: Int): Boolean = {
        if word_index == word.length then return true
        List(
          (x - 1, y), // Left
          (x, y - 1), // Up
          (x + 1, y), // Right
          (x, y + 1)  // Down
        )
        .filter((row, col) => board.isDefinedAt((row)) && board(row).isDefinedAt(col) && !(visited contains (row, col)))
        .exists((row, col) => board(row)(col) == word(word_index) && solve(visited incl (row, col), row, col, word_index + 1))
      }
      val board_indices = for { i <- board.indices; j <- board(i).indices } yield (i, j)
      board_indices.exists((x, y) => board(x)(y) == word(0) && solve(Set((x, y)), x, y, 1))
    }
}
