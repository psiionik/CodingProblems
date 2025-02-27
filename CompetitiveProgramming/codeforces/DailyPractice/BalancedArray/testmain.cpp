#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void isBalancedArray(int n) {

    int len = n / 2;
    int left_array[len];
    int right_array[len];
    int left_count = 0;
    int right_count = 0;
    int diff = 0;

    // YES Case
    if (len % 2 == 0){
        cout << "YES" << endl;

        for (int i = 1; i < n + 1; i++){
            if (i % 2 == 0 && left_count < len){
                left_array[left_count] = i;
                left_count++;
                diff += i;
            }

            if (i % 2 == 1 && right_count < (len - 1)){
                right_array[right_count] = i;
                right_count++;
                diff -= i;
            }
        }

        right_array[right_count] = diff;

        for (int j = 0; j < n; j++) {
            if (j < len){
                cout << left_array[j] << " ";
            }
            else {
                cout << right_array[j-len] << " ";
            }
        }

        cout << endl;

    }
    // NO case
    else {
        cout << "NO" << endl;
    }
}

int main() {

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        isBalancedArray(n);
    }

    return 0;
}