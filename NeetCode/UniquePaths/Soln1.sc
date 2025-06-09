object Solution1 {
    def uniquePaths(m: Int, n: Int): Int = {
        val grid = Array.fill[Array[Int]](m)(Array.fill[Int](n)(1))

        for (i <- Range(1, m))
        do 
            for (j <- Range(1, n))
            do 
                grid(i)(j) = grid(i - 1)(j) + grid(i)(j - 1)

        grid(m-1)(n-1)
    }
}