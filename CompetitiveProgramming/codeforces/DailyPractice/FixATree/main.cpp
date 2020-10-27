#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class DisjointSet {
    
    public:
        map<int, int> parent;

        void makeSet(vector<int> const &wholeset){
            for(int i : wholeset){
                parent[i] = i;
            }
        }

        int Find(int l){
            if (parent[l] == l){
                return l;
            }

            return Find(parent[l]);
        }

        void Union(int m, int n){
            int x = Find(m);
            int y = Find(n);
            parent[x] = y;
        }

        void printMap() {
            for(auto i = parent.begin(); i != parent.end(); i++){
                cout << i -> second << " ";
            }
            cout << endl;
        }

        vector<int> getGraph() {
            vector<int> result;
            for(auto i = parent.begin(); i != parent.end(); i++){
                result.push_back(i -> second);
            }

            return result;
        }

        set<int> findParents() {
            set<int> result;
            for(auto i = parent.begin(); i != parent.end(); i++){
                if(result.find(Find(i -> first)) == result.end()){
                    result.insert(Find(i->first));
                }
            }

            return result;
        }
};

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a[i] = temp;
    }

    vector<int> sets;

    for(int i = 0; i < n; i++){
        sets.push_back(i+1);
    }


    DisjointSet dis;
    dis.makeSet(sets);

    for (int i = 0; i < n; i++){
        dis.Union(i + 1, a[i]);
    }

    int count = 0;
    for (int i = 1; i < n; i++){
        if (dis.Find(i + 1) != dis.Find(i)) {
            count++;
        }
    }
    
    set<int> parents = dis.findParents();

    int counter = 0;
    set<int>::reverse_iterator it = parents.rbegin();
    
    for(int i = 0; i < n; i++){
        if(counter < count){
            if(dis.Find(i+1) != *it){
                dis.Union(i + 1, *it);
                counter++;
            }
        }
        else {
            break;
        }
    }

    cout << count << endl;

    vector<int> res = dis.getGraph();

    for(int i = 0; i < n; i++){
        if(dis.parent[i] == *it){
            cout << a[i] << " ";
        }
        else {
            cout << res[i] << " ";
        }
    }
    cout << endl;

    return 0;
}