#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> &adj_list, vector<int> &depths, vector<int> &sizes){
    set<int> seen;
    stack<pair<int, int>> sta;
    sta.push(make_pair(1, 0));
    seen.insert(1);

    while(!sta.empty()){
        pair<int, int> ele = sta.top();
        sta.pop();
        int index = ele.first;
        int count = ele.second;

        depths.at(index) = count - sizes.at(index);

        vector<int> children = adj_list.at(index);

        for (int i =0; i < children.size(); i++){
            if(seen.find(children.at(i)) == seen.end()){
                sta.push(make_pair(children.at(i), count + 1));
                seen.insert(children.at(i));
            }
        }
    }
}

int getSize(vector<vector<int>> &adj_list, vector<int> &sizes, int index, set<int> &seen){
    vector<int> children = adj_list.at(index);
    seen.insert(index);

    if(children.size() == 1){
        return 1;
    }

    int subtreeSize = 1;

    for (int i =0; i < children.size(); i++){
        if(seen.find(children.at(i)) == seen.end()){
            subtreeSize += getSize(adj_list, sizes, children.at(i), seen);
        }
    }

    sizes.at(index) = subtreeSize - 1;
    return subtreeSize;
}

int main() {

    int n, k;

    cin >> n >> k;

    vector<vector<int>> adj_list(n + 1);

    for (int i = 0; i < n - 1; i++){
        int u, v;

        cin >> u >> v;

        adj_list.at(u).push_back(v);
        adj_list.at(v).push_back(u);

    }

    vector<int> depths(n + 1, -1);
    vector<int> sizes(n + 1, 0);
    depths.at(1) = 0;
    set<int> seen;
    seen.insert(1);

    getSize(adj_list, sizes, 1, seen);

    dfs(adj_list, depths, sizes);

    long long result = 0;

    sort(depths.begin(), depths.end());

    for(int i = 0; i < k; i++){
        result += depths.at(depths.size() - 1 - i);
    }

    cout << result << endl;

    return 0;
}

// #define maxn 200005

// std::vector<int>conj[maxn];

// int n,k,u,v,depth[maxn]={0},size[maxn]={0},det[maxn];

// long long ans=0;

// int cmp(int a,int b){
//     return a>b;
// }

// int dfs(int u,int f){

//     depth[u]=depth[f]+1;
//     size[u]=1;

// 	for (int i=0;i<conj[u].size();++i){
// 		if ((v=conj[u][i])==f)
//             continue;
// 		size[u]+=dfs(v,u);
// 	}
//     det[u]=size[u]-depth[u];
//     return size[u];
// }
// int main(){
// 	scanf("%d%d",&n,&k);
// 	for (int i=1;i<n;++i){
// 		scanf("%d%d",&u,&v);
//         conj[u].push_back(v);
//         conj[v].push_back(u);
// 	}
//     dfs(1,0);
//     //  for (int i =0; i < n + 1; i++){
//     //     std::cout << det[i] << " ";
//     // }
//     // std::cout<<std::endl;
    

// 	std::nth_element(det+1,det+n-k,det+n+1,cmp);

   

// 	for (int i=1;i<=n-k;++i)
//         ans+=det[i];

//     std::cout<<ans;

// 	return 0;
// }