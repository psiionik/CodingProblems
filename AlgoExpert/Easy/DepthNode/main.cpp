#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Node {
    public:
        int value;
        string id;
        string left;
        string right;

    Node() {

    }

    Node(int value, string id, string left, string right) {
        this -> value = value;
        this -> id = id;
        this -> left = left;
        this -> right = right;
    }
};

class BinaryTree {
    public:
        int value;
        BinaryTree * left;
        BinaryTree * right;

    BinaryTree() {

    }

    BinaryTree(int value) {
        this -> value = value;
        left = NULL;
        right = NULL;
    }
};

void helper(BinaryTree *& tree, vector<Node> &nodes, int index) {
    tree = new BinaryTree(nodes.at(index).value);

    if (index * 2 < nodes.size()) {
        helper(tree -> left, nodes, index * 2);
    }

    if ((index * 2) + 1 < nodes.size()) {
        helper(tree -> right, nodes, (index * 2) + 1);
    }
}

void populateFromArray(BinaryTree *& tree, vector<Node> &nodes) {
    helper(tree, nodes, 1);
}

void printPrefix(BinaryTree *tree) {
    cout << tree -> value << endl;
    if (tree -> left) {
        printPrefix(tree -> left);
    }

    if (tree -> right) {
        printPrefix(tree -> right);
    }
}

int helper(BinaryTree *root, int depth) {
    if (root -> left == NULL && root -> right == NULL) {
        return depth;
    }
    int sum = depth;

    if (root -> left) {
        sum += helper(root -> left, depth + 1);
    }

    if (root -> right) {
        sum += helper(root -> right, depth + 1);
    }

    return sum;
}

int nodeDepthsSol1(BinaryTree *root) {
  return helper(root, 0);
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
	
    int n;

    cin >> n;

    vector<Node> nodes;
    Node temp = Node();
    nodes.push_back(temp);

    for (int i = 0; i < n; i++) {
        string id;
        string left;
        string right;
        int value;
        cin >> id >> left >> right >> value;
        Node new_node = Node(value, id, left, right);
        nodes.push_back(new_node);
    }

    BinaryTree * root;

    populateFromArray(root, nodes);

    cout << nodeDepthsSol1(root) << endl;

    return 0;
}