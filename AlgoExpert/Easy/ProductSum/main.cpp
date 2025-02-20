#include <string>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <any>

using namespace std;

int helper(vector<any> array, int depth) {
    int sum = 0;
    for (int i = 0; i < array.size(); i++) {
        // When the element is another VECTOR 
        if (array[i].type() == typeid(vector<any>)) {
            sum += helper(any_cast<vector<any>>(array[i]), depth + 1);
        } 
        // When the element is a NUMBER 
        else {
            sum += any_cast<int>(array[i]);
        }
    }

    cout << "SUM: " << sum << endl;

    return depth * sum;
}

int productSumSolution1(vector<any> &array) {
    return helper(array, 1);
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
    
    vector<any> test1; 
    vector<any> ele1 {7, -1};
    vector<any> ele2;
    vector<any> ele3;
    
    ele3.push_back(-13);
    ele3.push_back(8);

    ele2.push_back(6);
    ele2.push_back(ele3);
    ele2.push_back(4);
    
    test1.push_back(5);
    test1.push_back(2);
    test1.push_back(ele1);
    test1.push_back(3);
    test1.push_back(ele2);


    cout << "TEST 1\n" << productSumSolution1(test1) << endl;
    
    return 0;
}
