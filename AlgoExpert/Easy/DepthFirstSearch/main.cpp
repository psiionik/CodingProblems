#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <iostream>
#include <fstream>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std; 

// Do not edit the class below except
// for the depthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> depthFirstSearch(vector<string> *array) {
     helper(this, array);
     return *array;
  }

  void helper(Node *node, vector<string> *array) {
    if (node -> children.size() == 0) {
        array -> push_back(node -> name);
        return;
      } 

    array -> push_back(node -> name);
    for (int i = 0; i < node->children.size(); i++) {
        helper(node -> children[i], array);
    }

    return;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }

  void pushNode(Node *node) {
      children.push_back(node);
  }
};

void generateTree(Node *root, unordered_map<string, string> split) {
    root -> name = "A";
    unordered_set<string> seen; 
    queue<Node*> bfs_queue;
    bfs_queue.push(root);

    while (bfs_queue.size() > 0) {
        Node *node = bfs_queue.front();
        bfs_queue.pop();
        seen.insert(node -> name);
        string children_token = split.at(node -> name);

        if (children_token != "") {
            string delimiter = ",";
            string token;
            size_t start = 0;
            size_t end = children_token.find(delimiter);
            while (end != string::npos) {
                token = children_token.substr(start, end - start);
                start = end + 1;
                end = children_token.find(delimiter, start);

                if (seen.find(token) == seen.end()) {
                    Node *insert = new Node(token);
                    node -> pushNode(insert);
                    bfs_queue.push(insert);
                    seen.insert(token);
                }
            }
        } else {
            continue;
        }
    }
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    string line;
    unordered_map<string, string> split1;
    ifstream inputfile("input.txt");

    if (inputfile.is_open()) {
      while (getline(inputfile, line)) {
          string delimiter1 = " ";
          size_t start = 0;
          size_t end  = line.find(delimiter1);
          int count = 1;
          string token;
          string one = "";
          string two = "";
          while (end != string::npos) {
              token = line.substr(start, end - start);
              start = end + delimiter1.length();
              end = line.find(delimiter1, start);

              if (count == 1)
                one = token;
              if (count == 2)
                  two = token;
              count++;
          }

          split1.emplace(one, two);
        }
      inputfile.close();
    }
    
    Node root = Node("-");
    
    generateTree(&root, split1);
    
    vector<string> result;
    root.depthFirstSearch(&result);

    for (int i = 0; i < result.size(); i++) {
        cout << result.at(i) << " ";
    }
    cout << endl;

    return 0;
}
