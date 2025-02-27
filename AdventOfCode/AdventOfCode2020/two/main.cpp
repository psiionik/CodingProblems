#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>

using namespace std;

class Ranges {
    public:
        int minRange;
        int maxRange;

    Ranges() {

    }

    Ranges(int minRange, int maxRange) {
        this -> minRange = minRange;
        this -> maxRange = maxRange;
    }

    void setMinRange(int minRange) {
        this -> minRange = minRange;
    }

    void setMaxRange(int maxRange) {
        this -> maxRange = maxRange;
    }
};

int validPasswordsOne(vector<string> &passwords, vector<pair<char, Ranges>> &charInstanceMap) {
    int result = 0;

    for(int i = 0; i < passwords.size(); i++) {
        int countOfChar = count(passwords.at(i).begin(), passwords.at(i).end(), charInstanceMap.at(i).first);
        if (countOfChar >= charInstanceMap.at(i).second.minRange && countOfChar <= charInstanceMap.at(i).second.maxRange) {
            result++;
        }
    }

    return result;
}

int validPasswordsTwo(vector<string> &passwords, vector<pair<char, Ranges>> &charInstanceMap) {
    int result = 0;

    for (int i = 0; i< passwords.size(); i++) {
        int occurences = 0;

        if (passwords.at(i).at(charInstanceMap.at(i).second.minRange - 1) == charInstanceMap.at(i).first) {
            occurences++;
        }

        if (passwords.at(i).at(charInstanceMap.at(i).second.maxRange - 1) == charInstanceMap.at(i).first) {
            occurences++;
        }

        if (occurences == 1) {
            result++;
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
    string temp;
    while(!myFile.eof()){
        getline(myFile, temp);
        lines.push_back(temp);
    }
    myFile.close();

    vector<pair<char, Ranges>> charInstanceMap;
    vector<string> passwords;
    
    for (int i = 0; i < lines.size(); i++) {
        Ranges first;
        char second;
        string delim1 = " ";
        size_t start = 0;
        size_t end = lines.at(i).find(delim1);
        while (end != string::npos) {
            string extracted = lines.at(i).substr(start, end - start);
            if (start == 0) {
                string delim2 = "-";
                size_t startInner = 0;
                size_t endInner = extracted.find(delim2);
                while (endInner != string::npos) {
                    string innerExtracted = extracted.substr(startInner, endInner - startInner);
                    first.setMinRange(stoi(innerExtracted));
                    startInner = endInner + delim2.length();
                    endInner = extracted.find(delim2, startInner);
                }
                first.setMaxRange(stoi(extracted.substr(startInner, endInner)));
            }
            else {
                second = extracted.at(0);
            }
            start = end + delim1.length();
            end = lines.at(i).find(delim1, start);
        }
        charInstanceMap.push_back(make_pair(second, first));
        passwords.push_back(lines.at(i).substr(start, end));
    }


    cout << validPasswordsOne(passwords, charInstanceMap) << endl;
    cout << validPasswordsTwo(passwords, charInstanceMap) << endl;

    return 0;
}