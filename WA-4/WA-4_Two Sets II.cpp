#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, MOD = 1e9+7, MOD_INV_2 = 5e8+4;
    cin >> n;
    if(n*(n+1)/2%2) {cout << "0\n"; return 0;}
    int target = n*(n+1)/2/2;
    vector<int> dp(target+1);
    dp[0] = 1;
    for(int i = 2; i <= n; i++)
        for(int j = target; j >= i; j--)
            dp[j] = (dp[j]+dp[j-i])%MOD;
    cout << ((ll)dp[target]*MOD_INV_2%MOD) << "\n";
    return 0;
}