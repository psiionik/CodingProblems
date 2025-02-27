#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int maxSubsetSumNoAdjacentSol3(vector<int> &array) {
    if (array.size() == 0) {
        return 0;
    }
    else if (array.size() == 1) {
        return array[0];
    }

    int second = array.at(0);
    int first = max(array.at(0), array.at(1));

    for (int i = 2; i < array.size(); i++) {
        int temp = second;
        second = first;
        first = max(first, temp + array.at(i));
    }

    return first;
}

int maxSubsetSumNoAdjacentSol2(vector<int> &array) {
    vector<int> dp(array.size(), 0);

    if (array.size() == 0) {
        return 0;
    }
    else if (array.size() == 1) {
        return array[0];
    }

    dp.at(0) = array.at(0);
    dp.at(1) = max(array.at(0), array.at(1));

    for (int i = 2; i < array.size(); i++) {
        dp.at(i) = max(dp.at(i-1), dp.at(i-2) + array.at(i));
    }

    return dp.at(dp.size() - 1);
}

int maxSubsetSumNoAdjacentSol1(vector<int> &array) {
    vector<int> dp(array.size(), 0);

    if (array.size() == 0) {
        return 0;
    }
    else if (array.size() == 1) {
        return array[0];
    }
    else if (array.size() == 2) {
        return max(array[0], array[1]);
    }

    dp.at(0) = array.at(0);
    dp.at(1) = array.at(1);

    for (int i = 2; i < array.size(); i++) {
        int max_ele = -1;
        for (int j = i - 2; j > -1; j--) {
            if (max_ele < dp[j]) {
                max_ele = dp[j];
            }
        }
        dp.at(i) = max(dp.at(i - 1), array.at(i) + max_ele);
    }

    return dp.at(array.size() - 1);
}


int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
	
    // for (int i = 0; i < array.size(); i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    int n;
     
    cin >> n;

    vector<int> a;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    
    cout << maxSubsetSumNoAdjacentSol3(a) << endl;

    return 0;
}