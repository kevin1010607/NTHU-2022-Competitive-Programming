#include<bits/stdc++.h>
#define ll long long
#define INF (LLONG_MAX/2)
using namespace std;
struct Edge{
    int u, v, c;
};
void dfs(int idx, vector<bool>& seen, vector<vector<int>>& G){
    seen[idx] = true;
    for(auto i : G[idx]){
        if(seen[i]) continue;
        dfs(i, seen, G);
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Edge> E(m);
    vector<ll> D(n+1, -INF);
    vector<vector<int>> G1(n+1), G2(n+1);
    vector<bool> seen1(n+1), seen2(n+1);
    for(int i = 0; i < m; i++){
        cin >> E[i].u >> E[i].v >> E[i].c;
        G1[E[i].u].push_back(E[i].v);
        G2[E[i].v].push_back(E[i].u);
    }
    dfs(1, seen1, G1);
    dfs(n, seen2, G2);
    D[1] = 0;
    for(int i = 0; i < n; i++){
        bool update = false;
        for(auto [u, v, c] : E){
            if(D[v] < D[u]+c){
                D[v] = D[u]+c;
                update = true;
                if(i==n-1 && seen1[v] && seen2[v]){
                    cout << "-1\n";
                    return 0;
                }
            }
        }
        if(!update) break;
    }
    cout << D[n] << "\n";
    return 0;
}