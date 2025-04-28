object Solution1 {
    def distanceLimitedPathsExist(n: Int, edgeList: Array[Array[Int]], queries: Array[Array[Int]]): Array[Boolean] = {
        def find(representatives: Array[Int], node: Int): Int = {
            if representatives(node) == node
            then
                return node
            else
                representatives(node) = find(representatives, representatives(node))
                return representatives(node)
        }

        def union(representatives: Array[Int], ranks: Array[Int], u: Int, v: Int): Unit = {
            val u_root = find(representatives, u)
            val v_root = find(representatives, v)

            if u_root == v_root
            then
                return
            else
                if ranks(u_root) <= ranks(v_root)
                then
                    representatives(u_root) = v_root
                    ranks(v_root) += ranks(u_root)
                else
                    representatives(v_root) = u_root
                    ranks(u_root) += ranks(v_root)
        }

        def connected(representatives: Array[Int], p: Int, q: Int): Boolean = {
            return find(representatives, p) == find(representatives, q)
        }

        val ret = Array.fill(queries.length)(false)
        val representatives_arr = Array.fill(n)(0).zipWithIndex.map((ele, ind) => ind)
        val ranks = Array.fill(n)(1)

        val edge_list_sorted = edgeList.sortBy(edge => (edge(0), edge(1), edge(2))._3)
        val queries_sorted = queries.zipWithIndex.map {
            case (arr, index) =>
                Array(arr(0), arr(1), arr(2), index)
        }.sortBy(q => (q(0), q(1), q(2), q(3))._3)

        var edges_index = 0
        for (query <- queries_sorted)
        do 
            val p = query(0)
            val q = query(1)
            val query_dist = query(2)
            val query_index = query(3)

            while (edges_index < edge_list_sorted.length) && (edge_list_sorted(edges_index)(2) < query_dist)
            do 
                val u = edge_list_sorted(edges_index)(0)
                val v = edge_list_sorted(edges_index)(1)

                union(representatives_arr, ranks, u, v)
                edges_index+=1

            ret(query_index) = connected(representatives_arr, p, q)

        ret
    }
}