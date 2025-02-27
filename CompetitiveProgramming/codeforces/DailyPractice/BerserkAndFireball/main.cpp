#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector<int> a;
vector<int> b;

long long cost_of_fireball, k, cost_of_berserk;

bool upd(int l, int r, long long &res){
    if (l > r) {
        return true;
    }

    bool canDel = false;

    int mx = *max_element(a.begin() + l, a.begin() + r + 1);

    int len = r - l + 1;

    if (l - 1 >= 0 && a[l - 1] > mx) {
        canDel = true;
    }

    if (r + 1 < n && a[r + 1] > mx) {
        canDel = true;
    }

    if (len < k && !canDel) {
        return false;
    }

    int need = len % k;
    res += need * cost_of_berserk;
    len -= need;

    if (cost_of_berserk * k >= cost_of_fireball){
        res += len / k * cost_of_fireball;
    }
    else if (canDel) {
        res += len * cost_of_berserk;
    }
    else {
        res += (len - k) * cost_of_berserk + cost_of_fireball;
    }

    return true;

}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
	

    cin >> n >> m;

    cin >> cost_of_fireball >> k >> cost_of_berserk;

    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    for (int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        b.push_back(temp);
    }

    long long res = 0;
    int lst = -1;
    int posa = 0;
    int posb = 0;

    while (posb < m){
        while(posa < n && a[posa] != b[posb]){
            ++posa;
        }

        if (posa == n){
            cout << "-1" << endl;
            return 0;
        }

        if (!upd(lst + 1, posa - 1, res)) {
            cout << "-1" << endl;
            return 0;
        }

        lst = posa;
        ++posb;
    }

    if (!upd(lst + 1, n - 1, res)){
        cout << "-1" << endl;
        return 0;
    }

    cout << res << endl;

    return 0;
}

