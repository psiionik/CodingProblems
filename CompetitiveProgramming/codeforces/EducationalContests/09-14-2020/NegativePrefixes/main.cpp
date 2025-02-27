#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int a[n];
        int locked[n];
        priority_queue<int, vector<int>> max_heap;

        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            a[j] = temp;
        }

        for (int j = 0; j < n; j++) { 
            int temp;
            cin >> temp;
            locked[j] = temp;
        }

        for (int j = 0; j < n; j++) {
            if (locked[j] == 0) {
                max_heap.push(a[j]);
            }
            else {
                continue;
            }
        }

        vector<int> result;

        for (int j = 0; j < n; j++) {
            if (locked[j] == 0){
                int val = max_heap.top();
                max_heap.pop();
                result.push_back(val);
            }
            else {
                result.push_back(a[j]);
            }
        }

        for (int j = 0; j < n; j++) {
            cout << result[j] << " ";
        }
        cout << endl;
    }

    return 0;
}