#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <math.h>

using namespace std;

int binaryBoardingOne(vector<string> &passes) {
    int highestSeatId = -1;
    int lengthRow = 7;
    int lengthCol = 3;

    for (int i = 0; i < passes.size(); i++) {
        int seatId = -1;
        int rowAdd = 0;
        int colAdd = 0;

        for (int j = 0; j < lengthRow; j++) {
            if (passes.at(i).at(j) == 'B') {
                rowAdd += pow(2, lengthRow - (j + 1));
            }
        }

        for (int j = 0; j < lengthCol; j++) {
            if (passes.at(i).at(j + lengthRow) == 'R') {
                colAdd += pow(2, lengthCol - (j + 1));
            }
        }

        seatId = (rowAdd * 8) + colAdd;

        if (seatId > highestSeatId) {
            highestSeatId = seatId;
        }
    }

    return highestSeatId;
}

int binaryBoardingTwo(vector<string> &passes) {
    vector<int> ids;
    int lengthRow = 7;
    int lengthCol = 3;

    for (int i = 0; i < passes.size(); i++) {
        int seatId = -1;
        int rowAdd = 0;
        int colAdd = 0;

        for (int j = 0; j < lengthRow; j++) {
            if (passes.at(i).at(j) == 'B') {
                rowAdd += pow(2, lengthRow - (j + 1));
            }
        }

        for (int j = 0; j < lengthCol; j++) {
            if (passes.at(i).at(j + lengthRow) == 'R') {
                colAdd += pow(2, lengthCol - (j + 1));
            }
        }

        seatId = (rowAdd * 8) + colAdd;

        ids.push_back(seatId);
    }

    sort(ids.begin(), ids.end());

    int comparison = ids.at(0);

    for (int i = 0; i < ids.size(); i++) {
        if (comparison != ids.at(i)) {
            break;
        }

        comparison++;
    }

    return comparison;
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

    cout << binaryBoardingOne(lines) << endl;
    cout << binaryBoardingTwo(lines) << endl;

    return 0;
}