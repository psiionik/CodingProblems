#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <queue>

using namespace std;

// Naive solution is to just double for loop through each of the elements
// If the element is unique then compare it to the max seen so far
// Else just skip
int largestUniqueNumberNaive(vector<int> &numbers) {
    int max_so_far = -1; 
    for (int i = 0; i < numbers.size(); i++) {
        bool seen = false;
        for (int j = 0; j < numbers.size(); j++) {
            if (i == j) {
                continue;
            }
            if (numbers.at(i) == numbers.at(j)){
                seen = true;
            }
        }

        if (seen == false) {
            max_so_far = max(max_so_far, numbers.at(i));
        }
    }

    return max_so_far;
}

// Limited to one level of for loops since the hashtable is trying to optimize lookups
// As you loop through the array, add the count of each element into the hashtable.
// Loop through the hashtable and find the max value for one that has frequencies of 1
int largestUniqueNumberHashTable(vector<int> &numbers) {
    unordered_map<int, int> counts;
    int result = -1;
    
    for (int i = 0; i < numbers.size(); i++){
        int current_num = numbers.at(i);
        if (counts.find(current_num) == counts.end()) {
            counts.emplace(current_num, 1);
        }
        else {
            counts.at(current_num)++;
        }
    }
    
    for (unordered_map<int, int>::iterator it = counts.begin(); it != counts.end(); it++) {

        if (it -> second == 1) {
            result = max(result, it -> first);
        }
    }

    return result;
}

// First sort the array
// Start looping from largest to smallest number
// If the current index and the next are the same, skip that number until you reach a new number
// Either return the first number that is unique or if the loop ends, return -1
int largestUniqueNumberSorting(vector<int> &numbers) {

    sort(numbers.begin(), numbers.end());
    int i = numbers.size() - 1;
    int next = i - 1;
    while (i > -1 && next > -1){
        if (numbers.at(next) != numbers.at(i)) {
            return numbers.at(i);
        }
        else {
            while(numbers.at(i) == numbers.at(next)) {
                next--;
                if (next < 0) {
                    return -1;
                }
            } 
            i = next;
            next = i - 1;
        }
    }

    return numbers.at(0);
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
    
    vector<int> numbers;
    string rawInput;

    while( getline(cin, rawInput, ' ') ){
        numbers.push_back(stoi(rawInput));
    }

    cout << "Naive: " << largestUniqueNumberNaive(numbers) << endl;
    cout << "Hash Table Optimization: " << largestUniqueNumberHashTable(numbers) << endl;
    cout << "Sorting: " << largestUniqueNumberSorting(numbers) << endl;

    return 0;
}
