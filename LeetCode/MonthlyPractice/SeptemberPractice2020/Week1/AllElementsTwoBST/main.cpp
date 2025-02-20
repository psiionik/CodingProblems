#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> merge(vector<int> &arr1, vector<int> &arr2) {
    vector<int> res;

    int i = 0;
    int j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]){
            res.push_back(arr1[i]);
            i++;
        }
        else if (arr1[i] > arr2[j]){
            res.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size()) {
        res.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size()) {
        res.push_back(arr2[j]);
        j++;
    }

    return res;
}

void inFixNotation(TreeNode* root, vector<int> &arr){
    if (root == NULL){
        return;
    }

    inFixNotation(root -> left, arr);
    if (root != nullptr) {
        arr.push_back(root -> val);
    }
    inFixNotation(root -> right, arr);

    return;
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> arr1;
    inFixNotation(root1, arr1);
    vector<int> arr2;
    inFixNotation(root2, arr2);

    return merge(arr1, arr2);
}

void constructTree(TreeNode *& root, vector<int> &arr, int index) {
    if (index >= arr.size()) {
        return;
    }
    
    root = new TreeNode(arr[index]);

    if (2 * index < arr.size()) {
        constructTree(root -> left, arr, 2 * index);
    }
    
    if (((2 * index) + 1) < arr.size()) {
        constructTree(root -> right, arr, (2*index) + 1);
    }

    return;
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int size1, size2;

    cin >> size1 >> size2;

    vector<int> tree1;
    vector<int> tree2;
    
    tree1.push_back(-1);
    tree2.push_back(-1);

    for (int i = 0; i < size1; i++) {
        int temp;
        cin >> temp;
        tree1.push_back(temp);
    }

    for (int i = 0; i < size2; i++) {
        int temp;
        cin >> temp;
        tree2.push_back(temp);
    }

    TreeNode * root1;
    TreeNode * root2;

    constructTree(root1, tree1, 1);
    constructTree(root2, tree2, 1);

    vector<int> res;

    res = getAllElements(root1, root2);

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}