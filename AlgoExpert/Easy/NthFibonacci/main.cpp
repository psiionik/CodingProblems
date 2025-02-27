#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <iostream>
#include <fstream>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

int getNthFibTopDown(int n) {
      if (n == 1) {
        return 0;
    }

    if (n == 2) {
          return 1;
      }

    return getNthFibTopDown(n - 1) + getNthFibTopDown(n - 2);
}

int getNthFibBottomUp(int n) {
  if (n == 1) {
        return 0;
    }
    if (n == 2) {
      return 1;
  }
    int back2 = 0;
    int back1 = 1;

    for (int i = 3; i < n; i++) {
       int temp = back2;
       back2 = back1;
       back1 = temp + back1;
    }

    return back2 + back1;
}

int helper(int n, vector<int> &cache) {
  if (n == 1) {
        return 0;
    }
    if (n == 2) {
      return 1;
  }

  if (cache.at(n) != -1) {
        return cache.at(n);
    }

  int val = helper(n - 1, cache) + helper(n - 2, cache);
  cache.at(n) = val;
  return val;
}

int getNthFibTopDownMemoization(int n) {
    vector<int> cache(n + 1, -1);
    cache.at(0) = 0;
    cache.at(1) = 0;
    cache.at(2) = 1;
    int res = helper(n, cache);

    return res;
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int n;

    cin >> n;

    cout << "TOP DOWN: " << getNthFibTopDown(n) << endl;
    cout << "BOTTOM UP: " << getNthFibBottomUp(n) << endl;
    cout << "TOP DOWN MEMOIZATION: " << getNthFibTopDownMemoization(n) << endl;
    
    return 0;
}
