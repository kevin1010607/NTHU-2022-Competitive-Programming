#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    int N = 1<<n;
    vector<int> dp(N, n), last(N, INT_MAX);
    dp[0] = 1, last[0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < n; j++){
            if(!(i&(1<<j))) continue;
            int t = i&~(1<<j);
            if(last[t]+A[j] <= x){
                if(dp[t]<dp[i] || dp[t]==dp[i]&&last[t]+A[j]<last[i])
                    dp[i] = dp[t], last[i] = last[t]+A[j];
            }
            else{
                if(dp[t]+1<dp[i] || dp[t]+1==dp[i]&&A[j]<last[i])
                    dp[i] = dp[t]+1, last[i] = A[j];
            }
        }
    }
    cout << dp[N-1] << "\n";
    return 0;
}