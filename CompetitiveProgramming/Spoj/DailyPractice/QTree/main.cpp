#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int t;

    cin >> t;

    for (int i = 0; i < t; i++){
        int N;
        cin >> N;

        vector<vector<int>> adj_matrix(N, vector<int>(N, -1));
        vector<pair<int,int>> edges;

        for (int n = 0; n < N - 1; n++) {
            int a, b, c;

            cin >> a >> b >> c;

            adj_matrix[a][b] = c;

            edges.push_back(make_pair(a, b));
        }

        string s;
        int a, b;

        do {
            cin >> s >> a >> b;
            if (s == "QUERY") {
                cout << adj_matrix[a][b] << endl;
            }
            else if (s == "CHANGE"){
                pair<int, int> change_pair = edges.at(a - 1);
                adj_matrix[change_pair.first][change_pair.second] = b;
            }

        }while(s != "DONE");
    }

    return 0;
}