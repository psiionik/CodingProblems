/*
    In this problem you have a network of computers in a house that are all connected together.
    Certain computers in this network can talk to other computers in the network and can be
    represented as having an "edge" from one computer to another.

    One functionality of these computers is that they can communicate with each other, sending data packets
    or distributing load between multiple computers in the network. Often times there is one computer
    in the network that knows what other computer in the network it wants to communicate with.
    To reduce the latency as much as possible, given the "edges" between the computers you want to be 
    able to find the shortest path cost from a specific computer to the computer it is trying to communicate with.

    The objective of this problem is to find shortest path cost from two computers in this graph.
    The given inputs is a list of pair of pairs where the first item in the pair denotes an edge between the two
    computers and the second item in the first pair denotes the cost of traveling that edge. Also given is the total
    number of computers in the network.

    Ex. input: [((0, 1), 2), ((1, 2), 3)] -> this means that there is an edge between (0, 1) with cost 2 and an edge between (1, 2) with cost 3
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

#define INF INT_MAX

int shortestFlow(std::vector<std::pair<std::pair<int, int>, int>>&edges,
                 int number_of_nodes) {

    // Initializing the memory to store shortest paths 
    int memory[number_of_nodes];
    memory[number_of_nodes - 1] = 0;

    // Creating the graph, representing it as an adjacency matrix
    std::vector<std::vector<int>> graph(number_of_nodes, std::vector<int>(number_of_nodes, INF));
    
    // Filling out the adjacency matrix with the edges
    for (int edge_ind = 0; edge_ind < edges.size(); edge_ind++) {
       int v1 = edges.at(edge_ind).first.first;
       int v2 = edges.at(edge_ind).first.second;
       int capacity = edges.at(edge_ind).second;

       graph[v1][v2] = capacity;
    }
    
    // Looping through from the end, calculating the shortest flow as we go
    for (int node_ind = number_of_nodes - 2; node_ind >= 0; node_ind--) {
        // Want to initialize the current node's distance to the end node
        // with INF
        memory[node_ind] = INF;

        for (int child_node_ind = 0; child_node_ind < number_of_nodes;
             child_node_ind++) {
          if (graph[node_ind][child_node_ind] == INF) {
                continue;
          }
          memory[node_ind] = std::min(memory[node_ind], graph[node_ind][child_node_ind] + memory[child_node_ind]);
        }
    }

  return memory[0]; 
}

void Test_Example1_Successful() {
    int number_of_nodes = 8;
    std::vector<std::pair<std::pair<int, int>, int>> edges {
        std::make_pair(std::make_pair(0, 1), 1), 
        std::make_pair(std::make_pair(0, 2), 2), 
        std::make_pair(std::make_pair(0, 3), 5), 
        std::make_pair(std::make_pair(1, 4), 4), 
        std::make_pair(std::make_pair(1, 5), 11), 
        std::make_pair(std::make_pair(2, 4), 9), 
        std::make_pair(std::make_pair(2, 5), 5), 
        std::make_pair(std::make_pair(2, 6), 16), 
        std::make_pair(std::make_pair(3, 6), 2), 
        std::make_pair(std::make_pair(4, 7), 18), 
        std::make_pair(std::make_pair(5, 7), 13), 
        std::make_pair(std::make_pair(6, 7), 2) 
    };

  int result = shortestFlow(edges, number_of_nodes);
  int actual = 9;
  std::string result_message = result == actual ? "passed" : "failed"; 

  std::cout << "Test 1: " << result_message << std::endl;
}

void Test_Example2_Successful() {
    int number_of_nodes = 12;
    std::vector<std::pair<std::pair<int, int>, int>> edges {
      std::make_pair(std::make_pair(0, 1), 9),
      std::make_pair(std::make_pair(0, 2), 7),
      std::make_pair(std::make_pair(0, 3), 5),
      std::make_pair(std::make_pair(1, 4), 3),
      std::make_pair(std::make_pair(1, 5), 5),
      std::make_pair(std::make_pair(1, 6), 6),
      std::make_pair(std::make_pair(2, 5), 4),
      std::make_pair(std::make_pair(2, 6), 5),
      std::make_pair(std::make_pair(2, 7), 7),
      std::make_pair(std::make_pair(3, 6), 2),
      std::make_pair(std::make_pair(3, 7), 7),
      std::make_pair(std::make_pair(4, 8), 5),
      std::make_pair(std::make_pair(4, 9), 2),
      std::make_pair(std::make_pair(5, 9), 4),
      std::make_pair(std::make_pair(5, 10), 8),
      std::make_pair(std::make_pair(6, 9), 5),
      std::make_pair(std::make_pair(6, 10), 3),
      std::make_pair(std::make_pair(7, 10), 7),
      std::make_pair(std::make_pair(8, 11), 6),
      std::make_pair(std::make_pair(9, 11), 4),
      std::make_pair(std::make_pair(10, 11), 2)
    };

    int result = shortestFlow(edges, number_of_nodes);
    int actual = 12;
    std::string result_message = result == actual ? "passed" : "failed"; 

    std::cout << "Test 2: " << result_message << std::endl;
}

int main() {
    Test_Example1_Successful();
    Test_Example2_Successful();
    return 0;
}
