#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <set>

using namespace std;

vector<char> dic = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' ,'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

vector<set<char>> buildMap(vector<string> &answers) {
    vector<set<char>> result;
    for (int i = 0; i < answers.size(); i++) {
        set<char> groupAnswers;
        for (char c : answers.at(i)) {
            groupAnswers.emplace(c);
        }
        result.push_back(groupAnswers);
    }

    return result;
}

vector<unordered_map<char, int>> buildIndex(vector<vector<string>> &answers) {
    vector<unordered_map<char, int>> index;

    for (int i = 0; i < answers.size(); i++) {
        unordered_map<char, int> inner;
        for (int j = 0; j < answers.at(i).size(); j++) {
            for (char c : answers.at(i).at(j)) {
                if (inner.find(c) == inner.end()) {
                    inner.emplace(c, 1);
                }
                else {
                    inner.at(c) += 1;
                }
            }
        }
        index.push_back(inner);
    }

    return index;
}

long long customsOne(vector<string> &answers){
    long long result = 0;
    vector<set<char>> builtMap = buildMap(answers);

    for (int i = 0; i < builtMap.size(); i++) {
        result += builtMap.at(i).size();
    }

    return result;
}

long long customsTwo(vector<vector<string>> &answers){
    long long result = 0;

    vector<unordered_map<char, int>> index = buildIndex(answers);

    for (int i = 0; i < index.size(); i++) {
        for (char c : dic) {
            if (index.at(i).find(c) != index.at(i).end()) {
                if (index.at(i).find(c) -> second == answers.at(i).size()){
                    result++;
                }
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

    ifstream myFile;
    myFile.open("./input.txt");

    vector<string> lines;
    vector<vector<string>> lines2;
    lines2.push_back(vector<string>());
    int index = 0;
    string temp;
    string builder = "";
    while(!myFile.eof()){
        getline(myFile, temp);
        if (temp == "") {
            lines.push_back(builder);
            builder = "";
            lines2.push_back(vector<string>());
            index++;
        }
        else {
            builder += temp;
            lines2.at(index).push_back(temp);
        }
    }
    lines.push_back(builder);
    myFile.close();

    cout << customsOne(lines) << endl;
    cout << customsTwo(lines2) << endl;

    return 0;
}