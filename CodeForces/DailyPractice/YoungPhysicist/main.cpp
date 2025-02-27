#include <iostream>

using namespace std;

bool findEquilibrium(int n, int x[], int y[], int z[]) {
    int resx = 0;
    int resy = 0;
    int resz = 0;
  for (int i = 0; i < n; i++) {
      resx += x[i];
      resy += y[i];
      resz += z[i];
    }
    
    if (resx == 0 && resy == 0 && resz == 0) return true; 

    return false;
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int n; 
    int x, y, z;
    cin >> n;
    
    int xar[n];
    int yar[n];
    int zar[n];

    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        xar[i] = x;
        yar[i] = y;
        zar[i] = z;
    }

    cout << (findEquilibrium(n, xar, yar, zar) == true ? "YES" : "NO") << endl;

    return 0;
}
