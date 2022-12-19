#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<ll>> dp(n, vector<ll>(n));
    // len = 1
    for(int i = 0; i < n; i++) cin >> dp[i][i];
    // len = 2
    for(int i = 0; i < n-1; i++)
        dp[i][i+1] = max(dp[i][i], dp[i+1][i+1]);
    // len = 3 ~ n
    for(int len = 3; len <= n; len++){
        for(int i = 0; i < n-len+1; i++){
            int l = i, r = i+len-1;
            dp[l][r] = max(dp[l][l]+min(dp[l+2][r], dp[l+1][r-1]), dp[r][r]+min(dp[l+1][r-1], dp[l][r-2]));
        }
    }
    cout << dp[0][n-1] << "\n";
    return 0;
}