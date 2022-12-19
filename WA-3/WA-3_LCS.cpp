#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t, res;
    cin >> s >> t;
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = s[i-1]==t[j-1]?dp[i-1][j-1]+1:max(dp[i-1][j], dp[i][j-1]);
    while(m>0 && n>0){
        if(dp[m][n] == dp[m-1][n]) m--;
        else if(dp[m][n] == dp[m][n-1]) n--;
        else res += s[m-1], m--, n--;
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
    return 0;
}