#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;

vector<int> partitionLabels(string S) {
    vector<int> result;
    map <char, pair<int, int>> dic;
    vector<pair<int, int>> pairs;

    for (int i = 0; i < S.length(); i++) {
        if (dic.find(S.at(i)) == dic.end()){
            dic.emplace(S.at(i), make_pair(i, i));
        }
        else {
            dic.at(S.at(i)).second = i;
        }
    }

    // for (auto it = dic.begin(); it != dic.end(); it++){
    //     cout << it -> first << ": [" << pairs[i].first << "-" << pairs[i].second << "]" << endl;
    // }

    for (auto& it : dic) { 
        pairs.push_back(it.second); 
    }

    sort(pairs.begin(), pairs.end());

    int min_index = pairs[0].first;
    int max_index = pairs[0].second;

    for (int i = 1; i < pairs.size(); i++) {
        if (max_index < pairs[i].first) {
            result.push_back(max_index - min_index + 1);
            min_index = pairs[i].first;
            max_index = pairs[i].second;
        }

        if (min_index > pairs[i].first){
            min_index = pairs[i].first;
        }

        if (max_index < pairs[i].second) {
            max_index = pairs[i].second;
        }
    }

    result.push_back(max_index - min_index + 1);

    return result;
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    string s;

    cin >> s;

    vector<int> res = partitionLabels(s);

    for (int i = 0; i < res.size(); i++){
        cout << res.at(i) << " ";
    }

    cout << endl;

    return 0;
}