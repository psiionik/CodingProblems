#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;

bool searchMatrix2BruteForce(vector<vector<int>> &matrix, int target) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.at(i).size(); j++) {
            if (matrix.at(i).at(j) == target) {
                return true;
            }
        }
    }

    return false;
}

bool binarySearch(vector<int> &arr, int target, int start, int end) {
    if (start == end) {
        return false;
    }

    int mid = (end + start) / 2;
    int mid_value = arr.at(mid);

    if (mid_value == target) {
        return true;
    }
    else if (mid_value < target) {
        return binarySearch(arr, target, mid + 1, end);
    }
    else {
        return binarySearch(arr, target, start, mid);
    }
}

bool searchMatrix2BinarySearch(vector<vector<int>> &matrix, int target) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = i; j < matrix.at(i).size(); j++) {
            vector<int> parsed_row;
            vector<int> parsed_col;

            for (int k = i; k < matrix.size(); k++) {
                parsed_row.push_back(matrix.at(k).at(j));
            }

            for (int l = j; l < matrix.at(i).size(); l++) {
                parsed_col.push_back(matrix.at(i).at(l));
            }

            if (binarySearch(parsed_col, target, 0, parsed_col.size()) || binarySearch(parsed_row, target, 0, parsed_row.size())){
                return true;
            }
        }
    }
    return false;
}

bool searchDivideAndConquer(vector<vector<int>> &matrix, int target, int left, int up, int right, int down) {
    if (left > right || up > down) {
        return false;
    }

    if (matrix.at(up).at(left) > target || matrix.at(down).at(right) < target) {
        return false;
    }

    int mid = left + (right - left) / 2;
    int row = up;

    while (row <= down && matrix.at(row).at(mid) <= target) {
        if (matrix.at(row).at(mid) == target) {
            return true;
        }

        row++;
    }

    return searchDivideAndConquer(matrix, target, left, row, mid - 1, down) || searchDivideAndConquer(matrix, target, mid + 1, up, right, row - 1);
}

bool searchMatrix2DivideAndConquer(vector<vector<int>> &matrix, int target) {
    if (matrix.size() == 0) {
        return false;
    }

    return searchDivideAndConquer(matrix, target, 0, 0, matrix.at(0).size() - 1, matrix.size() - 1);
}

bool searchMatrix2SearchSpaceReduction(vector<vector<int>> &matrix, int target) {
    int row = matrix.size() - 1;
    int col = 0;

    while (row >= 0 && col < matrix.at(row).size()) {
        if (matrix.at(row).at(col) == target) {
            return true;
        }
        else if(matrix.at(row).at(col) < target) {
            col++;
        }
        else {
            row--;
        }
    }

    return false;
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
        freopen("input.txt", "r", stdin);
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

    cout << "LEVEL 2 BRUTE FORCE: \n" << (searchMatrix2BruteForce(matrix, target) ? "true" : "false") << endl;

    cout << "LEVEL 2 BINARY SEARCH: \n" << (searchMatrix2BinarySearch(matrix, target) ? "true" : "false") << endl;

    cout << "LEVEL 2 DIVIDE AND CONQUER: \n" << (searchMatrix2DivideAndConquer(matrix, target) ? "true" : "false") << endl;

    cout << "LEVEL 2 SEARCH SPACE REDUCTION: \n" << (searchMatrix2SearchSpaceReduction(matrix, target) ? "true" : "false") << endl;

    return 0;
}
