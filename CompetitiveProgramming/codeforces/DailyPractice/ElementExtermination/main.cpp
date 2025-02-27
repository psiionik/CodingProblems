#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(const vector<int>& v1, const vector<int>& v2) {
    for (int i = 0; i < v1.size(); i++) {
        if (v1.at(i) != v2.at(i)) {
            return false;
        }
    }

    return true;
}

int elementElimination(vector<int> arr, int n) {
    if (arr.at(arr.size() - 1) > arr.at(0)){
        cout << "YES" << endl;
        return 0;
    }
    else {
        cout << "NO" << endl;
        return 0;
    }
    // if (arr.size() == 1){
    //     cout << "YES" << endl;
    //     return 0;
    // }

    // vector<int> memory;
    // int last = arr[0];
    // int prev_segment_index = 0;
    // for (int i = 1; i <= n; i++) {
    //     if (i == n) {
    //         memory.push_back(*max_element(arr.begin() + prev_segment_index, arr.begin() + i));
    //     }
    //     else if (last > arr[i]) {
    //         memory.push_back(*min_element(arr.begin() + prev_segment_index, arr.begin() + i));
    //         prev_segment_index = i;
    //         last = arr[i];
    //     }
    //     else {
    //         last = arr[i];
    //     }
    // }

    // if (compare(memory, arr)) {
    //     cout << "NO" << endl;
    //     return 0;
    // }
    // else {
    //     elementElimination(memory, memory.size());
    // }

    // return 0;
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
	
    int t;

    cin >> t;

    for (int test_cases = 0; test_cases < t; test_cases++) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            arr[i] = a;
        }
        
        elementElimination(arr, n);

    }
    return 0;
}