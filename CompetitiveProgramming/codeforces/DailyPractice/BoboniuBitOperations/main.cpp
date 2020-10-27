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

int a[210];
int b[210];
int n, m;


#define ci const int&

bool check(ci x){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)if(((a[i]&b[j])|x)==x)goto Next;
		return 0;
		Next:;
	}
	return 1;
}
int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    int ans = (1 << 9) - 1;

    for (int i = 8; i >= 0; i--){
        check(ans ^ (1 << i)) ? ans ^= (1 << i) : 0;
    }

    cout << ans << endl;

    return 0;
}