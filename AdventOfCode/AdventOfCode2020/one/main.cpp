#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int getMultipleFromSumTwo(vector<int> &numbers) {
    sort(numbers.begin(), numbers.end());

    int left_pointer = 0;
    int right_pointer = numbers.size() - 1;
    int target = 2020;

    int num1 = 0;
    int num2 = 0;

    while (left_pointer != right_pointer) {
        if (numbers.at(left_pointer) + numbers.at(right_pointer) < target) {
            left_pointer++;
        }
        else if (numbers.at(left_pointer) + numbers.at(right_pointer) > target){
            right_pointer--;
        }
        else {
            num1 = numbers.at(left_pointer);
            num2 = numbers.at(right_pointer);
            break;
        }
    }

    return num1 * num2;
}

int getMultipleFromSumThree(vector<int> &numbers) {
    sort(numbers.begin(), numbers.end());

    int left_pointer = 0;
    int right_pointer = numbers.size() - 1;
    int target = 2020;

    for (int i = 0; i < numbers.size() - 2; i++) {
        left_pointer = i + 1;
        right_pointer = numbers.size() - 1;
        
        while (left_pointer < right_pointer) {
            if (numbers.at(i) + numbers.at(left_pointer) + numbers.at(right_pointer) == target) {
                return numbers.at(i) * numbers.at(left_pointer) * numbers.at(right_pointer);
            }
            else if (numbers.at(i) + numbers.at(left_pointer) + numbers.at(right_pointer) < target) {
                left_pointer++;
            }
            else {
                right_pointer--;
            }
        }
    }

    return -1;
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

    vector<int> numbers;

    while(cin.peek() != char_traits<char>::eof()){
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }


    cout << getMultipleFromSumThree(numbers) << endl;

    return 0;
}