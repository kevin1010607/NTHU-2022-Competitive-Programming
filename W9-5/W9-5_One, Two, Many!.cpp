#include<bits/stdc++.h>
using namespace std;
bool dfs(int idx, int color, vector<int>& C, vector<vector<int>>& G){
    if(C[idx]) return color == C[idx];
    C[idx] = color;
    for(auto i : G[idx])
        if(!dfs(i, -color, C, G))
            return false;
    return true;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> G(n+1);
    vector<int> C(n+1);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(C[i]) continue;
        if(!dfs(i, 1, C, G)){
            cout << "MANY\n";
            return 0;
        }
    }
    for(int i = 1; i <= n; i++)
        cout << (C[i]==1?1:2) << " \n"[i==n];
    return 0;
}