#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;
const int MN = 2e5+7;

vector<int> v[MN];


int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {

        int n, k;
        cin >> n >> k;

        vector<pair<int, bool>> a(n);
        vector<int> w(k);

        for(int j = 0; j <= n; j++){
            v[j].clear();
        }

        for (int j = 0; j < n; j++){
            int a_j;
            cin >> a_j;
            a.at(j) = make_pair(a_j, true);
        }

        for (int j = 0; j < k; j++){
            int a_j;
            cin >> a_j;
            w.at(j) = a_j;
        }

        sort(a.begin(), a.end());
        sort(w.begin(), w.end());

        for(int t = 0; t < k/2; t++)swap(w[t], w[k-t-1]);

        int po = 0;
        for (int j = 0; j < n - k; j++) {
            while(w[po] == v[po].size() + 1){
                po++;
            }
            v[po].push_back(a[j].first);
        }

        long long max_happiness = 0;
        int qf = 1;
        for (int j = 0; j < k;  j++){
            max_happiness += a.at(n - j - 1).first;
            if(v[j].size()){
                max_happiness += v[j].at(0);
            }
            else {
                max_happiness += a.at(n - qf).first;
                qf++;
            }
        }

        cout << max_happiness << endl;
    }


    return 0;
}