#include <iostream>
#include <fstream>
#include <string>
#include "BalancedArray.h"

using namespace std;

int main() {

    BalancedArray solution;

    ifstream myReadFile("test.txt");
    int count = 0;
    string line;
    if(myReadFile.is_open()){
        while(!myReadFile.eof()){
            if (count == 0){
                count++;
                getline(myReadFile, line);
                continue;
            }

            getline(myReadFile, line);

            solution.isBalancedArray(stoi(line));
            
        }
    }


    return 0;
}