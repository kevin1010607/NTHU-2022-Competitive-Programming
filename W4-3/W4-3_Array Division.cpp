#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(ll target, ll k, vector<int>& A){
    ll cnt = 1, sum = 0;
    for(auto i : A){
        sum += i;
        if(sum > target){
            sum = i;
            if(++cnt > k) return false;
        }
    }
    return true;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, l = 0, r = 0;
    cin >> n >> k;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
        l = max(l, (ll)A[i]);
        r += A[i];
    }
    while(l <= r){
        ll mid = l+(r-l)/2;
        if(check(mid, k, A)) r = mid-1;
        else l = mid+1;
    }
    cout << l << "\n";
    return 0;
}