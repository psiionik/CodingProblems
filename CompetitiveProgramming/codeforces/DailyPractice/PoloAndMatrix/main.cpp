#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstdlib>

using namespace std;

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int n, m, d;

    cin >> n >> m >> d;

    int matrix[n][m];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int temp;
            cin >> temp;
            matrix[i][j] = temp;
        }
    }

    int divisor = matrix[0][0] % d;

    vector<int> flat_list;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            flat_list.push_back(matrix[i][j]);
            if (divisor != (matrix[i][j] % d)) {
                cout << "-1" << endl;
                return 0;
            }
        }
    }

    sort(flat_list.begin(), flat_list.end());

    int mid_index = floor(flat_list.size() / 2);

    int value = flat_list.at(mid_index);

    int result = 0;

    for (int i = 0; i < flat_list.size(); i++) {
        result += abs(flat_list.at(i) - value) / d;
    }

    cout << result << endl;

    return 0;
}