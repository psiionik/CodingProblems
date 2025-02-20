#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>

using namespace std;

int tobogganTrajectoryOne(vector<vector<char>> &lines) {
    int row = 0;
    int col = 0;
    int amountOfTrees = 0;

    while(row < lines.size()) {
        if (lines.at(row).at(col) == '#') {
            amountOfTrees++;
        }

        row++;
        col += 3;

        if (row < lines.size() && col >= lines.at(row).size()) {
            col = col - lines.at(row).size();
        }
    }

    return amountOfTrees;
}

long long calculateNumberOfTrees(vector<vector<char>> &lines, int rowInc, int colInc) {
    int row = 0;
    int col = 0;
    long long amountOfTrees = 0;
    while(row < lines.size()) {
        if (lines.at(row).at(col) == '#') {
            amountOfTrees++;
        }

        row += rowInc,
        col = (col + colInc) % lines.at(0).size() ;

    }

    return amountOfTrees;
}

long long tobogganTrajectoryTwo(vector<vector<char>> &lines) {
    long long slope1 = calculateNumberOfTrees(lines, 1, 1);
    long long slope2 = calculateNumberOfTrees(lines, 1, 3);   
    long long slope3 = calculateNumberOfTrees(lines, 1, 5);
    long long slope4 = calculateNumberOfTrees(lines, 1, 7);
    long long slope5 = calculateNumberOfTrees(lines, 2, 1);

    return slope1 * slope2 * slope3 * slope4 * slope5;
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    ifstream myFile;
    myFile.open("./input.txt");

    vector<vector<char>> lines;
    lines.push_back(vector<char>());
    string temp;
    while(!myFile.eof()){
        getline(myFile, temp);
        for (char c : temp) {
            lines.at(lines.size() - 1).push_back(c);
        }
        lines.push_back(vector<char>());
    }
    myFile.close();

    lines.erase(lines.begin() + (lines.size() - 1), lines.end());

    cout << tobogganTrajectoryOne(lines) << endl;
    cout << tobogganTrajectoryTwo(lines) << endl;

    return 0;
}