#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstdlib>

using namespace std;

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int t;
    
    cin >> t;

    for (int i = 0; i < t; i++){
        int n;
        cin >> n;

        int a[n];

        for (int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            a[j] = temp;
        }

        int k = n;
        for (int j = 0; j < n; j++) {
            if (a[j] != 1){
                k = j;
                break;
            }
        }


        if (k == n && k % 2 == 1) {
            cout << "First" << endl;
        }
        else if (k == n && k % 2 == 0) {
            cout << "Second" << endl;
        }
        else {
            if ((k % 2) == 0){
                cout << "First" << endl;
            }
            else {
                cout << "Second" << endl;
            }
        }

    }

    return 0;
}