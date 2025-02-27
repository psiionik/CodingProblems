#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <array>

using namespace std;

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    string n;

    cin >> n;

    // string sub_sequence = "";

    // int count = 0;

    // for (int i = 0; i < n.length(); i++){
    //     for (int j = i; j < n.length(); j++){
    //         for (int k = j; k < n.length(); k++){
    //             sub_sequence = string() + n[i] + n[j] + n[k];
    //             if (sub_sequence == "QAQ"){
    //                 count++;
    //             }
    //         }
    //     }
    // }

    // cout << count << endl;

    int q1 = 0;
    int q2 = 0;

    for (int i = 0; i < n.length(); i++) {
        if (n[i] == 'Q') {
            q1++;
        }
    }

    int result = 0;

    for (int i = 0; i < n.length(); i++) {
        if(n[i] == 'Q'){
            q2++;
            q1--;
        }
        else if (n[i] == 'A'){
            result += q2 * q1;
        }
    }

    cout << result << endl;

    return 0;
}