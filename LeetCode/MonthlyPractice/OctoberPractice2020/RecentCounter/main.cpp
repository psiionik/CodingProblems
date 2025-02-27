#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>
#include <list>


using namespace std;

// Suceeded, iterating over sliding window with a linked list
class RecentCounterSol3 {
    public:
        list<int> linked;

        RecentCounterSol3() {

        }

        int ping(int t) {
            this -> linked.emplace_back(t);

            while (this -> linked.front() < ( t - 3000)){
                this -> linked.pop_front();
            }

            return this -> linked.size();
        }

};

// Suceeded, used binary search to find index of t - 3000
class RecentCounterSol2 {
    public:
        vector<int> tracker;
        int recent;

        RecentCounterSol2() {
            this -> recent = 0;
        }

        int ping(int t) {
            tracker.push_back(t);

            int position = binarySearch(t - 3000, 0, this -> tracker.size());

            this -> recent = this -> tracker.size() - position;

            return this -> recent;
        }

        int binarySearch(int num, int start, int end) {
            int mid = (end + start) / 2;

            if (end == start) {
                return start;
            }

            if (this -> tracker[mid] == num) {
                return mid;
            }
            else if (this -> tracker[mid] > num) {
                return binarySearch(num, start, mid);
            }
            else {
                return binarySearch(num, mid + 1, end);
            }
        }
};

// Success, used min-heap with checking size
class RecentCounterSol1 {
    public:
        priority_queue<int, vector<int>, greater<int>> min_heap;

        RecentCounterSol1() {
            
        }

        int ping(int t) {
            if (!this -> min_heap.empty()) {
                while (t - 3000 > this -> min_heap.top()) {
                    if (this -> min_heap.empty()) {
                        break;
                    }
                    min_heap.pop();
                }
            }

            min_heap.push(t);

            return this -> min_heap.size();
        }
};

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    RecentCounterSol3* obj = new RecentCounterSol3();

    int n;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[i] = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << obj -> ping(a[i]) << endl;
    }

    delete obj;

    return 0;
}