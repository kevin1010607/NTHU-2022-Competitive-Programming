#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int dfs(int now, int parent, int color, vector<vector<int>>& G, vector<vector<int>>& dp){
    if(G[now].size()==1 && G[now][0]==parent) return 1;
    if(dp[color][now]) return dp[color][now];
    dp[color][now] = 1;
    for(auto i : G[now]){
        if(i == parent) continue;
        int child = dfs(i, now, 0, G, dp)+(color==0?dfs(i, now, 1, G, dp):0);
        dp[color][now] = ((ll)dp[color][now]*child)%MOD;
    }
    return dp[color][now];
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n;
    vector<vector<int>> G(n+1), dp(2, vector<int>(n+1));
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << (dfs(1, -1, 0, G, dp)+dfs(1, -1, 1, G, dp))%MOD << "\n";
    return 0;
}