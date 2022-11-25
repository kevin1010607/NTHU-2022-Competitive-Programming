#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(ll val, ll k, vector<int>& A, vector<int>& F){
    for(int i = 0; i < A.size(); i++){
        k -= max(0LL, A[i]-val/F[i]);
        if(k < 0) return false;
    }
    return true;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, l = 0, r = 1e12, mid;
    cin >> n >> k;
    vector<int> A(n), F(n);
    for(auto& i : A) cin >> i;
    for(auto& i : F) cin >> i;
    sort(A.rbegin(), A.rend());
    sort(F.begin(), F.end());
    while(l <= r){
        mid = l+(r-l)/2;
        if(check(mid, k, A, F)) r = mid-1;
        else l = mid+1;
    }
    cout << l << "\n";
    return 0;
}