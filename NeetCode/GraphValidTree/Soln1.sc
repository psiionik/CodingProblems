object Solution1 {
    def validTree(n: Int, edges: Array[Array[Int]]): Boolean = {
        def find(representatives: Array[Int], node: Int): Int = {
            if (representatives(node) == node)
            then
                return node
            else
                representatives(node) = find(representatives, representatives(node))
                return representatives(node) 
        }

        def union(representatives: Array[Int], sizes: Array[Int], u: Int, v: Int): Boolean = {
            val u_parent = find(representatives, u)
            val v_parent = find(representatives, v)

            if u_parent == v_parent
            then
                return false 
            else
                if sizes(u_parent) < sizes(v_parent)
                then
                    representatives(u_parent) = v_parent
                    sizes(v_parent) += sizes(u_parent)
                    return true 
                else
                    representatives(v_parent) = u_parent
                    sizes(u_parent) += sizes(v_parent)
                    return true 
        }

        val representatives_arr_1 = Array.fill(n)(0).zipWithIndex.map {
            case (element, index) =>
                index 
        }
        val sizes_arr = Array.fill(n)(1)

        if (edges.length != (n-1)) then return false

        val cycle_det_stat_1 = edges.foldLeft(true)((status, edge) => status && union(representatives_arr_1, sizes_arr, edge(0), edge(1)))

        cycle_det_stat_1
    }
}