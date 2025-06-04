object Solution1 {
    def maximalSquare(matrix: Array[Array[Char]]): Int = {
        val height = matrix.length
        val width = matrix(0).length
        var dp = Array.fill[Array[Int]](height + 1)(Array.fill[Int](width + 1)(0))
        var max_so_far = 0

        for (row_index <- Range(1, height + 1))
        do 
            for (col_index <- Range(1, width + 1))
            do 
                if (matrix(row_index - 1)(col_index - 1) == '1')
                then
                    dp(row_index)(col_index) = Math.min(
                        Math.min(
                            dp(row_index - 1)(col_index - 1),
                            dp(row_index - 1)(col_index)
                        ),
                        dp(row_index)(col_index - 1)
                    ) + 1

                    max_so_far = Math.max(max_so_far, dp(row_index)(col_index))


        max_so_far * max_so_far
    }
}