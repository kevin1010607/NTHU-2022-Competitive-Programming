#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll pow(ll a, ll b, ll MOD){
    ll res = 1;
    while(b){
        if(b&1) res = (res*a)%MOD;
        b >>= 1;
        a = (a*a)%MOD;
    }
    return res;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, a, b, c, MOD = 1e9+7;
    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        cout << pow(a, pow(b, c, MOD-1), MOD) << "\n";
    }
    return 0;
}