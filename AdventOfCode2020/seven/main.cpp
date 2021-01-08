#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <set>

using namespace std;

int handyHaversacksOne(unordered_map<string, vector<string>> &string_map) {
    for (auto it = string_map.begin(); it != string_map.end(); it++) {
        cout << "KEY: " << it -> first << " VALUE: ";
        for (string s : it -> second) {
            cout << s << ", ";
        }
        cout <<  endl;
    }
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    ifstream myFile;
    myFile.open("./input.txt");

    vector<string> lines;
    
    string temp;
    while(!myFile.eof()){
        getline(myFile, temp);
        lines.push_back(temp);
    }
    myFile.close();

    unordered_map<string, vector<string>> split_strings_map;

    for (string rule : lines) {
        vector<string> connected;
        string delimiter1 = "bags contain ";
        size_t start = 0;
        size_t end = rule.find(delimiter1);
        string key;
        while (end != string::npos) {
            key = rule.substr(start, end - start);
            start = end + delimiter1.length();
            end = rule.find(delimiter1, start);
        }
        
        string second = rule.substr(start, end - start);
        string delimiter2 = ", ";   
        start = 0;
        end = second.find(delimiter2);
        vector<string> temp;
        while (end != string::npos){
            string extracted = second.substr(start, end - start);
            temp.push_back(extracted);
            start = end + delimiter2.length();
            end = second.find(delimiter2, start);
        }

        temp.push_back(second.substr(start, end - start));
        
        for (string s : temp) {
            string delimiter3 = " ";
            start = 0;
            end = s.find(delimiter3);
            vector<string> temp2;
            while (end != string::npos) {
                string extracted = s.substr(start, end - start);
                temp2.push_back(extracted);
                start = end + delimiter3.length();
                end = s.find(delimiter3, start);
            }
            temp2.push_back(s.substr(start, end - start));

            connected.push_back(temp2.at(1) + " " + temp2.at(2));
        }

        split_strings_map.emplace(key, connected);
    }

    cout << handyHaversacksOne(split_strings_map) << endl;

    return 0;
}