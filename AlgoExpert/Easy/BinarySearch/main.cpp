#include <bits/stc++.h>

using namespace std;

int helper(vector<int> inputArray, int target, int start, int end) {
    return -1;  
}

int binarySearchSolution1(vector<int> inputArray, int target) {
    return helper(inputArray, target, 0, inputArray.size() - 1);
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
    
    ifstream infile("input.txt");
    string line;
    string delimiter = " ";
    vector<int> inputArray;
    int count = 0;
    int target = 0;

    while (getline(infile, line)) {
        if (count == 0) {
            size_t pos = 0;
            while ((pos = line.find(delimiter)) != string::npos) {
                inputArray.push_back(stoi(line.substr(0, pos)));
                line.erase(0, pos + delimiter.length());
            }
        } else {
           target = stoi(line); 
        }
        count++;
    }
    
    cout << "TEST 1: " << binarySearchSolution1(inputArray, target) << endl;
    
    return 0;
}
