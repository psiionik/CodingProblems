#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <utility>
#include <climits>

using namespace std;

int t, nr, ng, nb;
long long ans;

long long sq(int x) { return 1ll * x * x; }

void answer(vector<int> a, vector<int> b, vector<int> c){
    for (auto x: a){
        auto y = lower_bound(b.begin(), b.end(), x);
        auto z = upper_bound(c.begin(), c.end(), x);

        if (y == b.end() || z == c.begin()) {
            continue;
        }

        z--; 
        ans = min(ans, (sq(x - *y) + sq(*y- *z) + sq(*z - x)));

    }
}

int main() {
    for (cin >> t; t; t--){
        cin >> nr >> ng >> nb;
        vector<int> r(nr), g(ng), b(nb);

        for (int i =0; i < nr; i++){
            cin >> r[i];
        }
        for (int i =0; i < ng; i++){
            cin >> g[i];
        }
        for (int i =0; i < nb; i++){
            cin >> b[i];
        }

        sort(r.begin(), r.end());
        sort(g.begin(), g.end());
        sort(b.begin(), b.end());

        ans = 9e18;

        answer(r, g, b);
        answer(r, b, g);
        answer(g, b, r);
        answer(g, r, b);
        answer(b, r, g);
        answer(b, g, r);

        cout << ans << endl;
    }

    return 0;
}

// long long distanceCalculation(int red, int green, int blue){
//     return (long long) pow((red - green), 2) + (long long) pow((green - blue), 2) + (long long) pow((blue - red), 2);
// }

// int main() {

//     int num_tests;
    
//     cin >> num_tests;

//     for (int i = 0; i < num_tests; i++){

//         vector<pair<int, string>> reds, greens, blues;
//         vector<pair<int, string>> all;

//         int red_gems, green_gems, blue_gems;
        

//         cin >> red_gems >> green_gems >> blue_gems;

//         for (int j = 0; j < red_gems; j++){
//             int gem;
//             cin >> gem;
//             reds.push_back(make_pair(gem, "red"));
//         }

//         for (int j = 0; j < green_gems; j++){
//             int gem;
//             cin >> gem;
//             greens.push_back(make_pair(gem, "green"));
//         }

//         for (int j = 0; j < blue_gems; j++){
//             int gem;
//             cin >> gem;
//             blues.push_back(make_pair(gem, "blue"));
//         }

//         all.insert(all.end(), reds.begin(), reds.end());
//         all.insert(all.end(), greens.begin(), greens.end());
//         all.insert(all.end(), blues.begin(), blues.end());

//         sort(all.begin(), all.end());

//         int mid_point = all.size() / 2;

//         int left_pointer, right_pointer;

//         if (all.size() % 2 == 0){
//             left_pointer = mid_point - 1;
//             right_pointer = mid_point;
//         }
//         else {
//             left_pointer = mid_point;
//             right_pointer = mid_point;
//         }

//         bool has_red = false;
//         bool has_green = false;
//         bool has_blue = false;

//         vector<int> short_reds, short_greens, short_blues;


//         while((!has_red || !has_green || !has_blue) && left_pointer >= 0 && right_pointer < all.size()){
//             pair<int,string> left = all.at(left_pointer);
//             pair<int,string> right = all.at(right_pointer);

//             if (left.second == "red"){
//                 if (find(short_reds.begin(), short_reds.end(), left.first) == short_reds.end()){
//                     short_reds.push_back(left.first);
//                     has_red = true;
//                 }
//             }
//             else if (left.second == "green"){
//                 if (find(short_greens.begin(), short_greens.end(), left.first) == short_greens.end()){
//                     short_greens.push_back(left.first);
//                     has_green = true;
//                 }
//             }
//             else {
//                 if (find(short_blues.begin(), short_blues.end(), left.first) == short_blues.end()){
//                     short_blues.push_back(left.first);
//                     has_blue = true;
//                 }
//             }

//             if (right.second == "red"){
//                 if (find(short_reds.begin(), short_reds.end(), right.first) == short_reds.end()){
//                     short_reds.push_back(right.first);
//                     has_red = true;
//                 }
//             }
//             else if (right.second == "green"){
//                 if (find(short_greens.begin(), short_greens.end(), right.first) == short_greens.end()){
//                     short_greens.push_back(right.first);
//                     has_green = true;
//                 }
//             }
//             else {
//                 if (find(short_blues.begin(), short_blues.end(), right.first) == short_blues.end()){
//                     short_blues.push_back(right.first);
//                     has_blue = true;
//                 }
//             }

//             left_pointer--;
//             right_pointer++;
//         }

//         long long result = LLONG_MAX;

//         for (int m = 0; m < short_reds.size(); m++){
//             for (int n = 0; n < short_greens.size(); n++){
//                 for (int l = 0; l < short_blues.size(); l++){
//                     long long value = distanceCalculation(short_reds.at(m), short_greens.at(n), short_blues.at(l));

//                     if(value < result){
//                         result = value;
//                     }
//                 }
//             }
//         }

//         cout << result << endl;

//     }

//     return 0;
// }

// for (int k = 0; k < all.size(); k++){
//     cout << all.at(k) << " ";
// }

// cout << endl;