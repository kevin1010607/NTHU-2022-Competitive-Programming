#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<ll> A(n+1);
        vector<int> L(n+1), R(n+1);
        for(int i = 1; i <= n; i++){
            cin >> A[i];
            A[i] += A[i-1];
        }
        for(int i = n; i >= 0; i--){
            int idx = i+1;
            while(idx<=n && A[idx]>=A[i]) idx = L[idx];
            L[i] = idx;
            idx = i+1;
            while(idx<=n && A[idx]<A[i]) idx = R[idx];
            R[i] = idx;
        }
        int l = 0, r = 0, res = 0;
        while(l < n){
            while(r<=n && R[r]<L[l]) r = R[r];
            res = max(res, r-l);
            l = r = r+1;
        }
        cout << res << "\n";
    }
    return 0;
}