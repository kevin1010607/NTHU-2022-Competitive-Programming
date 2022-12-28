#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct S{
    int x, y, z;
};
int cost(S& a, S& b){
    return abs(b.x-a.x)+abs(b.y-a.y)+max(0, b.z-a.z);
}
int dfs(int idx, int used, vector<S>& A, vector<vector<int>>& path, vector<vector<int>>& dp){
    int n = dp.size(), N = dp[0].size();
    int U = used|(1<<idx);
    if(U == N-1) return cost(A[idx], A[0]);
    if(dp[idx][used] != -1) return dp[idx][used];
    dp[idx][used] = INT_MAX;
    for(int i = 0; i < n; i++){
        if(U&(1<<i)) continue;
        dp[idx][used] = min(dp[idx][used], dfs(i, U|(1<<i), A, path, dp)+path[idx][i]);
    }
    return dp[idx][used];
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<S> A(n);
    for(int i = 0; i < n; i++)
        cin >> A[i].x >> A[i].y >> A[i].z;
    vector<vector<int>> path(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                path[i][j] = min(path[i][j], cost(A[i], A[k])+cost(A[k], A[j]));
    int N = 1<<n;
    vector<vector<int>> dp(n, vector<int>(N, -1));
    cout << dfs(0, 0, A, path, dp) << "\n";
    return 0;
}