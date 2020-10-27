#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;

int calculateOverlapUpRight(int x_coord, int y_coord, vector<vector<int>> &A, vector<vector<int>> &B){
    int overlap = 0;

    int sec_y = 0;
    for (int i = y_coord; i < A.size(); i++){
        int sec_x = x_coord;
        for (int j = 0; j < A.size() - sec_x; j++){
            if (A[i][j] == 1 && A[i][j] == B[sec_y][sec_x]) {
                overlap++;
            }
            sec_x++;
        }
        sec_y++;
    }

    return overlap;
}

int calculateOverlap(int x_coord, int y_coord, vector<vector<int>> &A, vector<vector<int>> &B) {
    int overlap = 0;

    int sec_y = 0;
    for (int i = y_coord; i < A.size(); i++){
        int sec_x = 0;
        for (int j = x_coord; j < A.size(); j++){
            if (A[i][j] == 1 && A[i][j] == B[sec_y][sec_x]) {
                overlap++;
            }
            sec_x++;
        }
        sec_y++;
    }

    return overlap;
}

int imageOverlap(vector<vector<int>> &A, vector<vector<int>> &B){
    int max_overlap = -1;

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            max_overlap = max(max_overlap, calculateOverlap(j, i, A, B));
            max_overlap = max(max_overlap, calculateOverlap(j, i, B, A));

            max_overlap = max(max_overlap, calculateOverlapUpRight(j, i, A, B));
            max_overlap = max(max_overlap, calculateOverlapUpRight(j, i, B, A));
        }
    }

    return max_overlap;
}

int imageOverlapLinearTransformation(vector<vector<int>> &A, vector<vector<int>> &B) {
    vector<pair<int, int>> pairs_A;
    vector<pair<int, int>> pairs_B;

    //* The two double for loops are used to find and store the coordinates of cells with '1'

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            if (A[i][j] == 1) {
                pairs_A.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            if (B[i][j] == 1) {
                pairs_B.push_back(make_pair(i, j));
            }
        }
    }

    int res = 0;

    //* Counter for keeping track of vector transformations found to the number of times you find it

    map<pair<int, int>, int> counter;
    for (int i = 0; i < pairs_A.size(); i++){
        for (int j = 0; j < pairs_B.size(); j++) {

            //* Takes the cartesian product (basically everything in set A paired with everything in set B)
            //* Finds the linear transformation vector with V_ab = (X_b - X_a, Y_b - Y_a)

            pair<int, int> vector_ab = make_pair(pairs_B[j].first - pairs_A[i].first, pairs_B[j].second - pairs_A[i].second);

            //* Keeping track of how many times we have encountered the same linear transformation vector
            
            if (counter.find(vector_ab) == counter.end()) {
                counter.emplace(vector_ab, 1);
            }
            else {
                counter.at(vector_ab) += 1;
            }

            res = max(res, counter.at(vector_ab));
        }
    }

    return res;

}

int convolution(vector<vector<int>> &A, vector<vector<int>> &kernel, int xShift, int yShift) {
    int result = 0;

    // cout << "Convolution of: \n A: \n";
    
    // for(int row = 0; row < A.size(); row++) {
    //     for (int col = 0; col < A.size(); col++) {
    //         cout << A[row][col] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "Convolution of: \n kernel: \n";

    // for(int row = 0; row < A.size(); row++) {
    //     for (int col = 0; col < A.size(); col++) {
    //         cout << kernel[row + xShift][col + yShift] << " ";
    //     }
    //     cout << endl;
    // }

    //* Convolution of the two matricies. We access the bigger padded matrix by shifting it a certain amount.
    //* This becomes our "kernel" matrix

    for (int row = 0; row < A.size(); row++) {
        for (int col = 0; col < A.size(); col++) {
            result += A[row][col] * kernel[row + xShift][col + yShift];
        }
    }

    return result;
}

int imageOverlapConvolutions(vector<vector<int>> &A, vector<vector<int>> &B) {
    int N = A.size();

    vector<vector<int>> B_padded(3 * N - 2, vector<int>(3 * N - 2, 0));

    //* Padding B such that it can be shifted by amount N (its length)

    for(int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            B_padded[row + (N - 1)][col + (N - 1)] = B[row][col];
        }
    }


    int maxOverlap = -1;

    //* For each kernel we create from the padded matrix, we run a convolution operation with matrix A
    //* This is essentially going through all the possible kernel matricies and getting the dot product of the kernel with A
    //* This finds the eventually finds the maximum convolution value possible
    
    for (int row = 0; row < (2 * N - 1); row++) {
        for (int col = 0; col < (2 * N - 1); col++) {
            maxOverlap = max(maxOverlap, convolution(A, B_padded, row, col));
        }
    }

    return maxOverlap;

}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    
    vector<vector<int>> A;
    vector<vector<int>> B;

    for (int i = 0; i < n; i++) {
        vector<int> v1;
        for (int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            v1.push_back(temp);
        }
        A.push_back(v1);
    }

    for (int i = 0; i < n; i++) {
        vector<int> v1;
        for (int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            v1.push_back(temp);
        }
        B.push_back(v1);
    }

    cout << imageOverlapConvolutions(A, B) << endl;

    return 0;
}