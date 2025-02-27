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

    string s;

    cin >> s;

    int n = s.length();

    vector<int> memory(n, 0);

    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]) {
            memory[i] = memory[i-1] + 1;
        }
        else {
            memory[i] = memory[i - 1];
        }
    }

    int m;

    cin >> m;

    for (int i = 0; i < m; i++){
        int l, r;

        cin >> l >> r;

        int res = memory[r - 1] - memory[l - 1];

        cout << res << endl;
    }

    return 0;
}