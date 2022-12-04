#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, res = 0, MOD = 1e9+7, MOD_INV_2 = 5e8+4;
    cin >> n;
    for(ll i = 1; i*i <= n; i++){
        ll l = i+1, r = n/i;
        ll s1 = ((((l+r)%MOD)*((r-l+1)%MOD))%MOD)*MOD_INV_2%MOD;
        ll s2 = (i*(r-l+1+1))%MOD;
        res = (res+s1+s2)%MOD;
    }
    cout << res << "\n";
    return 0;
}