#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int a[n];

        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            a[j] = temp;
        }

        int num_of_skips = 0;
        bool turn = false;
        
        int pointer = 0;

        while (pointer < n) {
            if (turn) {
                pointer++;
                if (pointer < n){
                    if (a[pointer] == 1){
                        pointer++;
                    }
                }
                turn = false;
            }
            else {
                if (a[pointer] == 1) {
                    num_of_skips++;
                }
                pointer++;
                if (pointer < n) {
                    if (a[pointer] == 0){
                        pointer++;
                    }
                }
                turn = true;
            }

        }
        
        cout << num_of_skips << endl;
    }

    return 0;
}