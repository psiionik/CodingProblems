#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int max_time = -1;
        
        string largestTimeFromDigits(vector<int>& A) {

            this -> permuteTimes(A, 0);

            if (this -> max_time == -1){
                return "";
            }
            else {
                string hours = to_string(this -> max_time / 60);
                if (stoi(hours) < 10) {
                    hours = "0" + hours;
                }
                string minutes = to_string(this -> max_time % 60);
                if (stoi(minutes) < 10) {
                    minutes = "0" + minutes;
                }
                string result = hours + ":" + minutes;

                return result;
            }
        }
        
        void permuteTimes(vector<int>& A, int start_index) {
            if (start_index == A.size()) {
                this -> buildTime(A);
                return;
            }

            for (int i = start_index; i < A.size(); i++) {
                swapIndex(A, i, start_index);
                permuteTimes(A, start_index + 1);
                swapIndex(A, i, start_index);
            }
        }

        void buildTime(vector<int>& perm){
            int hour = perm[0] * 10 + perm[1];
            int minute = perm[2] * 10 + perm[3];
            if (hour < 24 && minute < 60) {
                this -> max_time = max(this -> max_time, hour * 60 + minute);
            }
        }

        void swapIndex(vector<int>& A, int a, int b){
            if (a != b){
                int temp = A[a];
                A[a] = A[b];
                A[b] = temp;
            }
        }
};

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
	
    vector<int> A;

    for (int i = 0; i < 4; i++){
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    Solution sol = Solution();

    cout << sol.largestTimeFromDigits(A) << endl;

    return 0;
}