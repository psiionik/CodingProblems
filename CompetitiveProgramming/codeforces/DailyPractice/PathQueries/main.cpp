#include <iostream>
#include <vector>
#include <string>
#include <utility>                   // for std::pair
#include <algorithm>                 // for std::for_each
#include <numeric>
#include <boost_1_73_0/boost/graph/adjacency_list.hpp>
#include <boost_1_73_0/boost/tuple/tuple.hpp>
#include <boost_1_73_0/boost/graph/graph_traits.hpp>
#include <boost_1_73_0/boost/graph/dijkstra_shortest_paths.hpp>
#include <boost_1_73_0/boost/config.hpp>

using namespace boost;

std::vector<int> p, rk;

long long res;

int getp(int v){
    if (v == p[v]){
        return v;
    }

    return p[v] = getp(p[v]);
}

long long get(int cnt){
    return cnt * 1ll * (cnt - 1) / 2;
}

void merge(int u, int v){
    u = getp(u);
    v = getp(v);

    if (rk[u] < rk[v]){
        swap(u, v);
    }

    res -= get(rk[u]);
    res -= get(rk[v]);

    rk[u] += rk[v];

    res += get(rk[u]);

    p[v] = u;

    // std::cout << "u: " << u << " v: " << v;
    // std::cout << "p[u]: " << p[u] << " p[v]: " << p[v];
    // std::cout << " rk[u]: " << rk[u] << " rk[v]: " << rk[v] << std::endl;

    // std::vector<int>::iterator at;

    // for (at = p.begin(); at != p.end(); at++){
    //     std::cout << *at << " ";
    // }
    // std::cout << std::endl;
}

int main() {

    int n;
    int m;
    std::cin >> n >> m;

    
    res = 0;
	p = rk = std::vector<int>(n, 1);
	std::iota(p.begin(), p.end(), 0);

    typedef adjacency_list<listS, vecS, bidirectionalS, no_property, property<edge_weight_t, int>> Graph;
    typedef std::pair<int, int> Edge;
    typedef graph_traits<Graph>::vertex_descriptor Vertex;
    typedef property_map<Graph, vertex_index_t>::type IndexMap;
    typedef property_map<Graph, edge_weight_t>::type WeightMap;
    typedef graph_traits<Graph>::vertex_iterator vertex_iter;

    const int num_vertices = n;

    Edge edges[n-1];
    int weights[n-1];

    // add the edges to the graph object
    for (int i = 0; i < n - 1; ++i){
        int u, v, w;
        std::cin >> u >> v >> w;

        edges[i] = Edge(u - 1, v - 1);
        weights[i] = w;
    }

    Graph g(edges, edges + sizeof(edges) / sizeof(Edge), weights, num_vertices);

    std::vector<std::pair<int, int>> queries(m);
    
    for (int j = 0; j < m; j++){
        std::cin >> queries[j].first;
        queries[j].second = j;
    }

    // int pos = 0; 
    graph_traits<Graph>::edge_iterator ei, ei_end;
    // boost::tie(ei, ei_end) = boost::edges(g);
    IndexMap index = get(vertex_index, g);
    WeightMap wm = get(edge_weight, g);
    std::vector<long long> ans(m);


    std::vector<std::pair<int, std::pair<int,int>>> edge_map;

    for (boost::tie(ei, ei_end) = boost::edges(g); ei != ei_end; ++ei){
        std::pair<int, Edge> ed;
        ed.first = wm[*ei];
        ed.second = Edge(index[source(*ei, g)], index[target(*ei, g)]);
        edge_map.push_back(ed);
    }

    std::sort(queries.begin(), queries.end());
    std::sort(edge_map.begin(), edge_map.end());

    int pos = 0;
    for (int i =0; i < m; i++){
        while(pos < n-1 && edge_map.at(pos).first <= queries[i].first){
            int u = edge_map.at(pos).second.first;
            int v = edge_map.at(pos).second.second;
            merge(u, v);
            ++pos;
        }
        ans[queries[i].second] = res;
    }

    for (int i =0; i < m; ++i){
        std::cout << ans[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}

