#include<bits/stdc++.h>
#define ll long long
using namespace std;
void dfs1(int idx, int parent, int depth, vector<ll>& res, vector<ll>& sz, vector<vector<int>>& G){
    res[1] += depth;
    sz[idx] = 1;
    for(auto i : G[idx]){
        if(i == parent) continue;
        dfs1(i, idx, depth+1, res, sz, G);
        sz[idx] += sz[i];
    }
}
void dfs2(int idx, int parent, int n, vector<ll>& res, vector<ll>& sz, vector<vector<int>>& G){
    for(auto i : G[idx]){
        if(i == parent) continue;
        res[i] = res[idx]+(n-sz[i])-sz[i];
        dfs2(i, idx, n, res, sz, G);
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n;
    vector<vector<int>> G(n+1);
    vector<ll> res(n+1), sz(n+1);
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs1(1, -1, 0, res, sz, G);
    dfs2(1, -1, n, res, sz, G);
    for(int i = 1; i <= n; i++)
        cout << res[i] << " \n"[i==n];
    return 0;
}