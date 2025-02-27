#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;

bool binaryRangeSearch(vector<int> &state, int lower, int upper, int start, int end) {
    if (end == start) {
        return false;
    }

    if (end - start == 1) {
        if (state[end - 1] <= upper && state[start] >= lower){
            return true;
        }
        else {
            return false;
        }
    }

    if (end - start == 2){
        if (state[end - 1] <= upper && state[start] >= lower){
            return true;
        }
        else {
            return false;
        }
    }

    int middle = floor((end + start) / 2);

    if (state[start] >= lower && state[end - 1] <= upper) {
        return true;
    }

    if (lower <= state[middle] && upper >= state[middle]) {
        return true;
    }

    else if (lower <= state[middle] && upper <= state[middle]) {
        return binaryRangeSearch(state, lower, upper, 0, middle + 1);
    }

    else {
        return binaryRangeSearch(state, lower, upper, middle + 1, end);
    }

}

bool findDuplicates(vector<int> &nums, int t, int k){
    vector<int> state;

    int fill = 0;
    while (fill < nums.size() && fill < k) {
        state.push_back(nums.at(fill));
        fill++;
    }

    int left_pointer = 0;
    int right_pointer = k;

    for (int i = 0; i < nums.size(); i++) {
        if (left_pointer < nums.size()) {
            state.erase(remove(state.begin(), state.end(), nums.at(left_pointer)), state.end());
        }

        if (right_pointer < nums.size()) {
            state.push_back(nums.at(right_pointer));
        }

        sort(state.begin(), state.end());

        int lower_bound = nums.at(i) - k;
        int upper_bound = nums.at(i) + k;

        if (binaryRangeSearch(state, lower_bound, upper_bound, 0, state.size())) {
            return true;
        }

        left_pointer++;
        right_pointer++;
    }

    return false;
}

bool findDuplicatesSol(vector<int> &nums, int k, int t) {
    if (k == 0) {
        return false;
    }

    multiset<long> treeset;
    int end = 1;
    for (int i = 0; i < nums.size(); i++){
        long currentNum = nums[i];

        auto curItr = treeset.find(currentNum);
        if (curItr != treeset.end()) {
            treeset.erase(curItr);
        }

        while (treeset.size() < k && end < nums.size()) {
            treeset.insert(nums[end]);
            end++;
        }

        auto closest = treeset.lower_bound(currentNum - t);

        if (closest == treeset.end()) {
            continue;
        }

        if (abs(currentNum - *closest) <= t){
            return true;
        }
    }

    return false;
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int t, k;

    cin >> t >> k;

    vector<int> nums;

    int temp;
    while (cin >> temp) {
        nums.push_back(temp);
    }

    if (findDuplicatesSol(nums, k, t)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}