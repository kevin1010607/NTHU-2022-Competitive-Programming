#include<bits/stdc++.h>
using namespace std;
void dfs(int idx, int parent, int& res, vector<int>& sz, vector<vector<int>>& G){
    sz[idx] = 1;
    int m = 0, n = G.size()-1;
    for(auto i : G[idx]){
        if(i == parent) continue;
        dfs(i, idx, res, sz, G);
        sz[idx] += sz[i];
        m = max(m, sz[i]);
    }
    m = max(m, n-sz[idx]);
    if(m <= n/2) res = idx;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, res;
    cin >> n;
    vector<vector<int>> G(n+1);
    vector<int> sz(n+1);
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, -1, res, sz, G);
    cout << res << "\n";
    return 0;
}