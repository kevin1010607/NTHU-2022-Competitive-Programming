#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> A(n+1);
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    for(int i = 1; i <= n; i++){
        cin >> A[i];
        A[i] += A[i-1];
    }
    for(int len = 2; len <= n; len++){
        for(int i = 1; i <= n-len+1; i++){
            int l = i, r = i+len-1;
            dp[l][r] = LLONG_MAX;
            for(int j = l; j < r; j++)
                dp[l][r] = min(dp[l][r], dp[l][j]+dp[j+1][r]+(A[r]-A[l-1]));
        }
    }
    cout << dp[1][n] << "\n";
    return 0;
}