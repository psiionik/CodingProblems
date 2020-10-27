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

    int n;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a[i] = temp;
    }

    vector<vector<int>> dp(n, vector<int> (3, 1000));

    dp[0][0] = 1;

    if (a[0] == 1 || a[0] == 3) {
        dp[0][1] = 0;
    }

    if (a[0] == 2 || a[0] == 3){
        dp[0][2] = 0;
    }

    for(int i = 1; i < n; i++){
        switch (a[i]) {
            case 0:
                dp[i][0] = 1 + *min_element(dp[i-1].begin(), dp[i-1].end());
                break;
            case 1:
                dp[i][0] = 1 + *min_element(dp[i-1].begin(), dp[i-1].end());
                dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
                break;
            case 2:
                dp[i][0] = 1 + *min_element(dp[i-1].begin(), dp[i-1].end());
                dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
                break;
            case 3:
                dp[i][0] = 1 + *min_element(dp[i-1].begin(), dp[i-1].end());
                dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
                dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
                break;
        }
    }

    cout << *min_element(dp[n-1].begin(), dp[n-1].end()) << endl;

    return 0;
}