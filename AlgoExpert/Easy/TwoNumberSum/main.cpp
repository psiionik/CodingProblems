#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> twoNumberSumSol3(vector<int> &array, int targetSum) {
    vector<int> result;

    sort(array.begin(), array.end());

    int left_pointer = 0;
    int right_pointer = array.size() - 1;

    while (left_pointer < right_pointer) {
        if (array[left_pointer] + array[right_pointer] == targetSum) {
            result.push_back(array[left_pointer]);
            result.push_back(array[right_pointer]);
            break;
        }
        else if (array[left_pointer] + array[right_pointer] < targetSum) {
            left_pointer++;
        }
        else {
            right_pointer--;
        }
    }

    return result;
}

vector<int> twoNumberSumSol2(vector<int> &array, int targetSum) {
    vector<int> result;
    unordered_map<int, int> dictionary;

    for (int i = 0; i < array.size(); i++) {
        if (dictionary.find(array[i]) == dictionary.end()) {
            dictionary.emplace(targetSum - array[i], array[i]);
        }
        else {
            int val = dictionary.at(array[i]);
            result.push_back(val);
            result.push_back(array[i]);
            break;
        }
    }

    return result;
}

vector<int> twoNumberSumSol1(vector<int> &array, int targetSum) {
    vector<int> result;

    for (int i = 0; i < array.size(); i++) {
        for (int j = i + 1; j < array.size(); j++) {
            if (array[i] + array[j] == targetSum) {
                result.push_back(array[i]);
                result.push_back(array[j]);

                return result;
            }
        }
    }

    return result;
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

    int n, targetSum;
    
    cin >> targetSum;
    cin >> n;

    vector<int> a;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    
    vector<int> res = twoNumberSumSol3(a, targetSum);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}