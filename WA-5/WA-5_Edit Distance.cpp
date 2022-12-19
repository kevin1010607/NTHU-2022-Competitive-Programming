#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(2, vector<int>(n+1));
    for(int i = 0; i <= n; i++) dp[0][i] = i;
    for(int i = 1; i <= m; i++){
        dp[1][0] = i;
        for(int j = 1; j <= n; j++)
            dp[1][j] = s[i-1]==t[j-1]?dp[0][j-1]:1+min({dp[0][j-1], dp[0][j], dp[1][j-1]});
        swap(dp[0], dp[1]);
    }
    cout << dp[0][n] << "\n";
    return 0;
}