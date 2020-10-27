#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
	
    int n;

    cin >> n;

    int number_of_bills = 0;

    while(n != 0){
        if (n / 100 != 0){
            n -= 100;
            number_of_bills++;
        }
        else if (n / 20 != 0) {
            n -= 20;
            number_of_bills++;
        }
        else if (n / 10 != 0){
            n -= 10;
            number_of_bills++;
        }
        else if (n / 5 != 0) {
            n -= 5;
            number_of_bills++;
        }
        else {
            n -= 1;
            number_of_bills++;
        }
    }

    cout << number_of_bills << endl;


    return 0;
}