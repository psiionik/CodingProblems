#include <iostream>


using namespace std;

int main() {

    int tests;

    cin >> tests;

    for (int i=0; i < tests; i++){
        int h, void_absorption, lightning_strike;

        cin >> h >> void_absorption >> lightning_strike;

        while(void_absorption != 0 && h >= 20){
            h = (h / 2) + 10;
            void_absorption--;
        }

        while(lightning_strike != 0 && h > 0) {
            h -= 10;
            lightning_strike--;
        }

        if (h <= 0) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }

        cout << endl;
    }

    return 0;
}