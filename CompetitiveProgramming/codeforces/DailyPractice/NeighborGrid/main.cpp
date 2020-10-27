#include <vector>
#include <iostream>
#include <string>

using namespace std;

int * getNeighborsCount(int **grid, int row, int col, int rows, int cols) {
    static int results[2];
    int countZeros = 0;
    int countNumbers = 0;

    for (int i = row - 1; i < row + 2; i++){
        for (int j = col - 1; j < col + 2; j++) {
            if ((i < 0 || i >= rows) || (j < 0 || j >= cols) || (i == row && j == col) || (i != row && j != col)) {
                continue;
            }
            
            if (grid[i][j] == 0){
                countZeros++;
            }
            else {
                countNumbers++;
            }
        }
    }

    results[0] = countZeros;
    results[1] = countNumbers;

    return results;
}

int runLoop(int **arr, int rows, int cols){
    for (int j = 0; j < rows; j++){
        for(int k = 0; k < cols; k++) {
            int* neighbors = getNeighborsCount(arr, j, k, rows, cols);
            int zeros = *(neighbors + 0);
            int numbers = *(neighbors + 1);
            if (arr[j][k] > (zeros + numbers)) {
                cout << "NO" << endl;
                return 0;
            }
            else {
                if (zeros + numbers == 2){
                    arr[j][k] = 2;
                }
                else if(zeros + numbers == 3) {
                    arr[j][k] = 3;
                }
                else if(zeros + numbers == 4){
                    arr[j][k] = 4;
                }
            }
        }
    }

    cout << "YES" << endl;

    for (int j = 0; j < rows; j++){
        for(int k = 0; k < cols; k++) {
            cout << arr[j][k] << " ";
        }
        cout << endl;
    }

    return 0;
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int t;

    cin >> t;

    for(int i = 0; i < t; i++){

        int n, m;

        cin >> n >> m;

        int **arr = new int *[n];

        for (int j = 0; j < n; j++){
            arr[j] = new int[m];
            for (int k = 0; k < m; k++){
                int temp = 0;
                cin >> temp;
                arr[j][k] = temp;
            }
        }

        runLoop(arr, n, m);

        for (int j = 0; j < n; j++){
            delete [] arr[j];
        }
        delete [] arr;


    }

    return 0;
}