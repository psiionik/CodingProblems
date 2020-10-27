#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool check(vector<int> &builder, vector<int> &sequence) {
    for (int i = 0; i < builder.size(); i++) {
        if (builder[i] != sequence[i]) {
            return false;
        }
    }
   
    return true;
}

bool helper(vector<int> &array, vector<int> &sequence, vector<int> &builder, int start_index) {
    // for (int i = 0; i < builder.size(); i++){ 
    //     cout << builder[i] << " ";
    // }
    // cout << endl;
    bool result;
    if (builder.size() == sequence.size()) {
        return check(builder, sequence);
    }

    for (int i = start_index; i < array.size(); i++) {
        if (builder.size() < sequence.size()) {
            builder.push_back(array[i]);
        }
        result = helper(array, sequence, builder, i + 1);
        if (result) {
            return result;
        }
        builder.erase(builder.begin() + builder.size() - 1);
    }

    return result;
}

bool isValidSubsequenceSol1(vector<int> &array, vector<int> &sequence) {
    vector<int> builder;

    return helper(array, sequence, builder, 0);
}

bool isValidSubsequenceSol2(vector<int> array, vector<int> sequence) {
    int first_pointer = 0;
    int second_pointer = 0;

    while(first_pointer < array.size()) {
        if (second_pointer == sequence.size()) {
            return true;
        }

        if (array[first_pointer] != sequence[second_pointer]) {
            first_pointer++;
        }
        else {
            first_pointer++;
            second_pointer++;
        }
    }

    if (second_pointer == sequence.size()) {
        return true;
    }

    return false;
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
	
    int n, m;

    cin >> n >> m;

    vector<int> array;
    vector<int> sequence;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        array.push_back(temp);
    }

    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        sequence.push_back(temp);
    }

    cout << (isValidSubsequenceSol2(array, sequence) ? "true" : "false") << endl;

    return 0;
}