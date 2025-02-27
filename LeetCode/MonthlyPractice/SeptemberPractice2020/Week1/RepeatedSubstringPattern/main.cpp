#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;

bool repeatedSubstringPattern(string s) {
    if (s.length() == 0){
        return false;
    }

    map <char, int> dic;

    for (char c : s) {
        if (dic.find(c) == dic.end()){
            dic.emplace(c, 1);
        }
        else {
            dic.at(c) += 1;
        }
    }

    for (int window_length = dic.size(); window_length <= s.length() / 2; window_length++) {
        int left_window = 0;
        int right_window = window_length;

        string sub_string = s.substr(0, window_length); 

        if (right_window - left_window > (s.length() / 2)) {
            return false;
        }

        int number_of_substrings = 0;

        while (right_window <= s.length()) {

            if (s.substr(left_window, window_length) == sub_string) {
                number_of_substrings++;
            }

            left_window = right_window;
            right_window += window_length;
        }

        if(number_of_substrings * window_length == s.length()){
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

    string s;

    cin >> s;

    cout << (repeatedSubstringPattern(s) ? "true" : "false") << endl;

    return 0;
}