#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

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

class BST {
    public:
        int value;
        string id;
        BST *left;
        BST *right;

        BST() {
            
        }

        BST(int val, string id) {
            this -> value = val;
            this -> left = NULL;
            this -> right = NULL;
            this -> id = id;
        }

        BST &insert(int val, string id) {
            BST *newNode = new BST(val, id);
            BST **leftpointer = &this -> left;
            BST **rightpointer = &this -> right;
            int currentVal = this -> value;

            while(*leftpointer || *rightpointer) {
                if (val < currentVal) {
                    if (*leftpointer) {
                        currentVal = (*leftpointer) -> value;
                        rightpointer = &(*leftpointer) -> right;
                        leftpointer = &(*leftpointer) -> left;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (*rightpointer) {
                        currentVal = (*rightpointer) -> value;
                        leftpointer = &(*rightpointer) -> left;
                        rightpointer = &(*rightpointer) -> right;
                    }
                    else {
                        break;
                    }
                }
            }

            if (val < currentVal) {
                *leftpointer = newNode;
            }
            else {
                *rightpointer = newNode;
            }

            // this -> printInfix(this);

            return *this;
        }

        void printInfix(BST* tree) {
            if (tree -> left) {
                printInfix(tree -> left);
            }
            cout << tree -> value << endl;
            if (tree -> right) {
                printInfix(tree -> right);
            }
        }
};

int findClosestValueInBstSol1(BST *tree, int target) {
    int res1 = 1000000;
    int res2 = 1000000;

    if (tree -> left) {
        res1 = findClosestValueInBstSol1(tree -> left, target);
    }

    if (tree -> right) {
        res2 = findClosestValueInBstSol1(tree -> right, target);
    }

    int diff1 = abs(tree -> value - target);
    int diff2 = abs(res1 - target);
    int diff3 = abs(res2 - target);

    if (diff1 <= diff3 && diff1 <= diff2) {
        return tree -> value;
    }
    else if (diff2 <= diff1 && diff2 <= diff3){
        return res1;
    }
    else {
        return res2;
    }
}

void getInfixArray(BST *tree, vector<int> &res) {
    if (tree -> left) {
        getInfixArray(tree -> left, res);
    }
    res.push_back(tree -> value);
    if (tree -> right) {
        getInfixArray   (tree -> right, res);
    }
}

int binarySearch(vector<int> &res, int start, int end, int target) {
    int mid = (start + end) / 2;

    if (end - start == 1 || end - start == 0) {
        int diff1 = abs(res[end] - target);
        int diff2 = abs(res[start] - target);

        if (diff1 < diff2) {
            return res[end];
        }
        else {
            return res[start];
        }
    }
    if (res[mid] == target) {
        return res[mid];
    }
    else if (res[mid] > target) {
        return binarySearch(res, start, mid, target);
    }
    else {
        return binarySearch(res, mid, end, target);
    }
}

int findClosestValueInBstSol2(BST *tree, int target) {
    vector<int> res;
    getInfixArray(tree, res);

    return binarySearch(res, 0, res.size(), target);
}

int findClosestValueInBstSol3(BST *tree, int target) {
    if (tree -> left == NULL && tree -> right == NULL) {
        return tree -> value;
    }    
    else {
        int currentVal = tree -> value;
        int currentDiff = abs(currentVal - target);
        int leftVal = 10000000;
        int rightVal = 10000000;

        if (tree -> value == target) {
            return tree -> value;
        }
        else if (tree -> value > target) {
            if (tree -> left){
                leftVal = findClosestValueInBstSol3(tree -> left, target);
            }
        }
        else {
            if (tree -> right){
                rightVal = findClosestValueInBstSol3(tree -> right, target);
            }
        }

        int leftDiff = abs(leftVal - target);
        int rightDiff = abs(rightVal - target);
        
        if (currentDiff <= leftDiff && currentDiff <= rightDiff) {
            return currentVal;
        }
        else if (leftDiff <= currentDiff && leftDiff <= rightDiff){
            return leftVal;
        }
        else {
            return rightVal;
        }
    }
}


int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
	
    int n;

    cin >> n;
    vector<Node> nodes;

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
    int target;

    cin >> root;
    cin >> target;
    BST tree;

    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].id == root){
            tree = BST(nodes[i].value, nodes[i].id);
        }
        else {
            tree.insert(nodes[i].value, nodes[i].id);
        }
    }

    tree.printInfix(&tree);

    cout << "\n";

    cout << findClosestValueInBstSol3(&tree, target) << endl;

    return 0;
}