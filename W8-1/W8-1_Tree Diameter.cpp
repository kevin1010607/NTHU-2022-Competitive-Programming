#include<bits/stdc++.h>
using namespace std;
void dfs(int idx, int parent, int& res, vector<int>& D1, vector<int>& D2, vector<vector<int>>& G){
    D1[idx] = D2[idx] = 0;
    for(auto i : G[idx]){
        if(i == parent) continue;
        dfs(i, idx, res, D1, D2, G);
        int dis = D1[i]+1;
        if(dis > D1[idx]){
            D2[idx] = D1[idx];
            D1[idx] = dis;
        }
        else D2[idx] = max(D2[idx], dis);
    }
    res = max(res, D1[idx]+D2[idx]);
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, res = 0;
    cin >> n;
    vector<vector<int>> G(n+1);
    vector<int> D1(n+1), D2(n+1);
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, -1, res, D1, D2, G);
    cout << res << "\n";
    return 0;
}