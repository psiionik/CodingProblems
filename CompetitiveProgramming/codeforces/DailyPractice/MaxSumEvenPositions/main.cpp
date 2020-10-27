#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
	

    int t;

    cin >> t;

    for (int j = 0; j < t; j++) {
        int n;
        cin >> n;

        int a[n];

        for(int k = 0; k < n; k++){
            int temp;
            cin >> temp;
            a[k] = temp;
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(3));


        for (int i = 0; i < n; i++) {
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + (i % 2 == 0 ? a[i] : 0));
            if (i + 2 <= n) {
                dp[i + 2][1] = max(dp[i + 2][1], max(dp[i][0], dp[i][1]) + (i % 2 == 0 ? a[i+1] : a[i]));
            }
            dp[i + 1][2] = max(dp[i + 1][2], max({dp[i][0], dp[i][1], dp[i][2]}) + (i % 2 == 0 ? a[i] : 0));
        }

        cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;

        // for (int k = 0; k < dp.size(); k++){
        //     for (int l = 0; l < dp.at(k).size(); l++){
        //         cout << dp[k][l] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << endl;

    }

    return 0;
}

