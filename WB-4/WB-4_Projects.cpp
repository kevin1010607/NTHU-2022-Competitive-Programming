#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct S{
    int a, b, p;
    bool operator<(const S& x) const{
        return b < x.b;
    }
};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<S> A(n);
    vector<int> V(2*n);
    for(int i = 0; i < n; i++){
        cin >> A[i].a >> A[i].b >> A[i].p;
        V[i] = A[i].a, V[i+n] = A[i].b;
    }
    sort(A.begin(), A.end());
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    auto ID = [&](int x){
        return lower_bound(V.begin(), V.end(), x)-V.begin()+1;
    };
    int m = V.size(), idx = 1;
    vector<ll> dp(m+1);
    for(int i = 0; i < n; i++){
        int ia = ID(A[i].a), ib = ID(A[i].b);
        while(idx < ib) dp[idx] = max(dp[idx], dp[idx-1]), idx++;
        dp[idx] = max({dp[idx], dp[idx-1], dp[ia-1]+A[i].p});
    }
    cout << dp[m] << "\n";
    return 0;
}