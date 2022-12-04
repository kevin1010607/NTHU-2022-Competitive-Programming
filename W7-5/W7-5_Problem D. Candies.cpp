#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;
pll extgcd(ll a, ll b){
    if(b == 0) return {1, 0};
    auto [xp, yp] = extgcd(b, a%b);
    return {yp, xp-a/b*yp};
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, A[3], B[3];
    cin >> n;
    while(n--){
        for(int i = 0; i < 3; i++)
            cin >> A[i] >> B[i];
        ll M = A[0]*A[1]*A[2], res = 0;
        for(int i = 0; i < 3; i++){
            ll m = M/A[i];
            auto [x, y] = extgcd(m, A[i]);
            ll t = (x+x/A[i]*A[i]+A[i])%A[i];
            res = (res+B[i]*t*m)%M;
        }
        cout << res << "\n";
    }
    return 0;
}