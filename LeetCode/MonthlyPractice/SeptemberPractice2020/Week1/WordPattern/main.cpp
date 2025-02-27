#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <iterator>

using namespace std;

template<char delimiter>
class WordDelimitedBy : public string {};

istream& operator>>(istream& is, WordDelimitedBy<' '>& output) {
    getline(is, output, ' ');
    return is;
}


bool wordPattern(string pattern, string s) {
        
    istringstream iss(s);

    vector<string> string_array((istream_iterator<WordDelimitedBy<' '>>(iss)), istream_iterator<WordDelimitedBy<' '>>());

    if (pattern.size() != string_array.size()) {
        return false;
    }

    unordered_map<char, string> pattern_map;
    unordered_map<string, char> pattern_map_reverse;

    for (int i = 0; i < string_array.size(); i++) {
        if (pattern_map.find(pattern[i]) == pattern_map.end()) {
            pattern_map.emplace(pattern[i], string_array[i]);
        }
        else {
            if (pattern_map.at(pattern[i]) != string_array[i]) {
                return false;
            }
        }

        if (pattern_map_reverse.find(string_array[i]) == pattern_map_reverse.end()) {
            pattern_map_reverse.emplace(string_array[i], pattern[i]);
        }
        else {
            if (pattern_map_reverse.at(string_array[i]) != pattern[i]) {
                return false;
            }
        }
    }

    return true;
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    string pattern;
    string s;
    
    ifstream file("input.txt");
    getline(file, pattern);
    getline(file, s);

    cout << (wordPattern(pattern, s) ? "true" : "false") << endl;

    return 0;
}