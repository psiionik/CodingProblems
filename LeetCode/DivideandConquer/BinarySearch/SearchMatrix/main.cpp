#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;

bool recursiveHelper2(vector<vector<int> > &matrix, int target, int row_start, int col_start, int row_end, int col_end) {
    if (row_start == row_end || col_start == col_end) {
        return false;
    }
    
    int row_med = (row_start + row_end) / 2;
    int col_med = (col_start + col_end) / 2;
    int median_value = matrix.at(row_med).at(col_med);

    cout << "MEDIAN VALUE: " << median_value << endl;
    cout << "Row Start: " << row_start << endl;
    cout << "Row Med: " << row_med << endl;
    cout << "Row End: " << row_end << endl;
    cout << "Col Start: " << col_start << endl;
    cout << "Col Med: " << col_med << endl;
    cout << "Col End: " << col_end << endl;

    if (median_value == target) {
        return true;
    }

    if (median_value > target) {
        // Top left
        return recursiveHelper2(matrix, target, row_start, col_start, row_med, col_med);
    }
    else {
        
        // Bottom left
        bool branch1 = recursiveHelper2(matrix, target, row_med + 1, col_start, row_end, col_med);

        // Bottom Right
        bool branch2 = recursiveHelper2(matrix, target, row_med + 1, col_med + 1, row_end, col_end);

        // Top Right
        bool branch3 = recursiveHelper2(matrix, target, row_start, col_med + 1, row_med, col_end);

        return branch1 || branch2 || branch3;
    }
}

bool searchMatrix2(vector<vector<int> > &matrix, int target) {
    int m = matrix.size();
    int n = matrix.at(0).size();

    return recursiveHelper2(matrix, target, 0, 0, m, n);
}

vector<int> convertTo2d(int value, int row_size, int col_size) {
    vector<int> res(2, 0);
    int row_value = value / col_size;
    int col_value = value % col_size;
    res.at(0) = row_value;
    res.at(1) = col_value;

    return res;
}

int convertTo1d(int row, int col, int col_size) {
    return (row * col_size) + col;
}

bool recursiveHelper(vector<vector<int> > &matrix, int target, int row_size, int col_size, int row_start, int col_start, int row_end, int col_end) {
    if (row_start == row_end && col_start == col_end) {
        return false;
    }

    int temp_start = convertTo1d(row_start, col_start, col_size);
    int temp_end = convertTo1d(row_end, col_end, col_size);
    vector<int> temp2d = convertTo2d((temp_start + temp_end) / 2, row_size, col_size);
    int med_row = temp2d.at(0);
    int med_col = temp2d.at(1);

    if (matrix.at(med_row).at(med_col) == target) {
        return true;
    }

    if (matrix.at(med_row).at(med_col) > target) {
        return recursiveHelper(matrix, target, row_size, col_size, row_start, col_start, med_row, med_col);
    }
    else {
        vector<int> temp2d2 = convertTo2d((temp_start + temp_end + 1) / 2, row_size, col_size);
        med_row = temp2d2.at(0);
        med_col = temp2d2.at(1);
        return recursiveHelper(matrix, target, row_size, col_size, med_row, med_col, row_end, col_end);
    }
}

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int m = matrix.size();
    int n = matrix.at(0).size();
    int total_size = (m * n);
    
    vector<int> median2d = convertTo2d(total_size, m, n);
    int row = median2d.at(0);
    int col = median2d.at(1);

    return recursiveHelper(matrix, target, m, n, 0, 0, row, col);
}

int main() {

    #ifdef _DEBUG
        freopen("input3.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int m;
    int n;

    cin >> m >> n;

    vector<vector<int> > matrix(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            matrix.at(i).at(j) = temp;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix.at(i).at(j) << " ";
        }
        cout << endl;
    }

    int target;

    cin >> target;

    // cout << "LEVEL 1: \n" << (searchMatrix(matrix, target) ? "true" : "false") << endl;

    cout << "LEVEL 2: \n" << (searchMatrix2(matrix, target) ? "true" : "false") << endl;

    return 0;
}