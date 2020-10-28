#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iterator>
#include <iostream>

using namespace std;

class Node {
    public:
        string id;
        string left;
        string right;
        int value;

        Node() {

        }

        Node(string id, string left, string right, int value) {
            this -> id = id;
            this -> left = left;
            this -> right = right;
            this -> value = value;
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
            this -> left = NULL;
            this -> right = NULL;
        }

        
};

void helper(BinaryTree *&tree, vector<Node> &nodes, int index) {
    tree = new BinaryTree(nodes.at(index).value);
    if (index * 2 < nodes.size()){
        helper(tree -> left, nodes, index*2);
    }

    if ((index * 2 + 1) < nodes.size()) {
        helper(tree -> right, nodes, index*2 + 1);
    }
}

void populateFromArray(BinaryTree *&tree, vector<Node> &nodes) {
    helper(tree, nodes, 1);
}

void printPrefix(BinaryTree *&root) {
    cout << root -> value << endl;

    if (root -> left) {
        printPrefix(root -> left);
    }

    if (root -> right) {
        printPrefix(root -> right);
    }
}

void branchSumsSol1Helper(BinaryTree *root, vector<int> &result, int acc) {
    if (root -> left == NULL && root -> right == NULL) {
        acc += root -> value;
        result.push_back(acc);
        return;
    }

    if (root -> left) {
        branchSumsSol1Helper(root -> left, result, acc + root -> value);
    }

    if (root -> right) {
        branchSumsSol1Helper(root -> right, result, acc + root -> value);
    }
}

vector<int> branchSumsSol1(BinaryTree *root) {
    vector<int> result;

    branchSumsSol1Helper(root, result, 0);

    return result;
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

        Node newNode = Node(id, left, right, value);

        nodes.push_back(newNode);
    }

    string root;
    Node rootNode;

    cin >> root;

    BinaryTree * tree;

    populateFromArray(tree, nodes);

    vector<int> result = branchSumsSol1(tree);

    ostringstream oss;

    if (!result.empty()){
        copy(result.begin(), result.end() - 1, ostream_iterator<int>(oss, ","));
        oss << result.back();
    }

    cout << oss.str() << endl;

    return 0;
}