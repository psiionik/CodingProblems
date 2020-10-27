#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <unordered_map>
#include <map>
#include <set>
#include <math.h>

using namespace std;

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int t; 
    cin >> t;

    for (int l = 0; l < t; l++) {
        int n;
        cin >> n;

        string result = "";

        for(int i = 0; i < n; i++) {
            result += "9";
        }

        int eights_num = ceil((double) n / 4);

        for(int i = result.length() -1; i >= (result.length() - (int) eights_num); i--){
            if (i < 0){
                break;
            }
            
            result[i] = '8';
        }

        cout << result << endl;
    }

    return 0;
}