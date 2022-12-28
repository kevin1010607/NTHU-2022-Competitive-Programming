#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n+2, vector<int>(m+1));
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= min(m, n-i+1); j++)
            cin >> A[i][j];
    vector<ll> dp(n+2, LLONG_MAX);
    dp[1] = A[1][0];
    for(int i = 2; i <= n+1; i++)
        for(int j = 1; j <= min(m, i-1); j++)
            dp[i] = min(dp[i], dp[i-j]-A[i-j][j]+A[i][0]);
    cout << dp[n+1] << "\n";
    return 0;
}