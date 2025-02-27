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

    int n;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a[i] = temp;
    }

    int left_pointer = 0;
    int right_pointer = 1;
    int length = 0;

    while (right_pointer <= n){
        if (right_pointer == n) {
            if ((right_pointer - left_pointer) > length) {
                length = right_pointer - left_pointer;
            }
            break;
        }
        if (a[right_pointer] < a[right_pointer - 1]){
            if ((right_pointer - left_pointer) > length) {
                length = right_pointer - left_pointer;
            }

            left_pointer = right_pointer;
            right_pointer++;
        }   
        else {
            right_pointer++;
        }
    }

    cout << length << endl;

    return 0;
}