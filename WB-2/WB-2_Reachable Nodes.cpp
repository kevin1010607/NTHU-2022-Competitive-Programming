#include<bits/stdc++.h>
#define N 50001
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<bitset<N>> dp(n);
    vector<int> in(n), q;
    vector<vector<int>> G(n);
    while(m--){
        cin >> a >> b;
        G[b-1].push_back(a-1);
        in[a-1]++;
    }
    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
        if(in[i] == 0) q.push_back(i);
    }
    for(int i = 0; i < n; i++){
        int now = q[i];
        for(auto j : G[now]){
            dp[j] |= dp[now];
            if(--in[j] == 0) q.push_back(j);
        }
    }
    for(int i = 0; i < n; i++)
        cout << dp[i].count() << " \n"[i==n-1];
    return 0;
}