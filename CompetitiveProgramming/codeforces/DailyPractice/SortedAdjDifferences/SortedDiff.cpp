#include "SortedDiff.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>

void SortedDiff::getSorted(int arr_len, vector<int> arr){
    if (arr_len == 1){
        cout << arr[0] << endl;;
    }

    vector<pair<int, pair<int,int>>> differences;

    for (int i = 1; i < arr_len; i++){
        differences.push_back(make_pair(abs(arr[i] - arr[i-1]), make_pair(i-1 , i)));
    }

    sort(differences.begin(), differences.end());

    // for (int i = 0; i < differences.size(); i++){
    //     cout << "Difference: " << differences.at(i).first << " , "
    //     << "Index (i-1): " << differences.at(i).second.first << " Index (i): " << differences.at(i).second.second << endl;
    // }

    for (int i = 0; i < differences.size(); i++){
        if (i == 0){
            cout << arr[differences.at(i).second.second] << " ";
        }

        cout << arr[differences.at(i).second.first] << " ";
    }

    cout << endl;
}

void SortedDiff::getSortedAnswer(int arr_len, vector<int> arr){
    // Sort the list first
    sort(arr.begin(), arr.end());

    // for (int i =0; i < arr.size(); i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // Get the middle element
    int mid = arr.size() / 2;

    int left_pointer = mid;
    int right_pointer = mid+1;
    int even_odd = 0;
    while (left_pointer >= 0 || right_pointer < arr.size()){
        if (even_odd % 2 == 0){
            if (left_pointer >= 0){
                cout << arr[left_pointer] << " ";
                left_pointer--;
            }
            even_odd += 1;
        }
        else {
            if (right_pointer < arr.size()){
                cout << arr[right_pointer] << " ";
                right_pointer++;
            }
            even_odd += 1;
        }
    }

    cout << endl;
}
