#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t, n, k;
bool check(ll m, vector<int>& A, vector<int>& B, vector<int>& C){
    vector<ll> D(n);
    for(int i = 0; i < n; i++) D[i] = A[i]+m*B[i];
    partial_sort(D.begin(), D.begin()+k, D.end(), greater<ll>());
    for(int i = 0; i < k; i++)
        if(D[k-1-i] <= C[i]) return false;
    return true;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int> A(n), B(n), C(n);
        for(int i = 0; i < n; i++) cin >> A[i] >> B[i];
        for(int i = 0; i < n; i++) cin >> C[i];
        partial_sort(C.begin(), C.begin()+k, C.end());
        ll l = 0, r = 1e8+1;
        while(l <= r){
            ll mid = l+(r-l)/2;
            if(check(mid, A, B, C)) r = mid-1;
            else l = mid+1;
        }
        if(check(l, A, B, C)) cout << l << "\n";
        else cout << "-1\n";
    }
    return 0;
}