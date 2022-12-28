#include<bits/stdc++.h>
using namespace std;
void dfs(int idx, vector<vector<int>>& G, vector<int>& sz){
    for(auto i : G[idx]){
        dfs(i, G, sz);
        sz[idx] += sz[i]+1;
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n;
    vector<int> sz(n+1);
    vector<vector<int>> G(n+1);
    for(int i = 2; i <= n; i++){
        cin >> x;
        G[x].push_back(i);
    }
    dfs(1, G, sz);
    for(int i = 1; i <= n; i++)
        cout << sz[i] << " \n"[i==n];
    return 0;
}