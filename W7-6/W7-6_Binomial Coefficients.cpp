#include<bits/stdc++.h>
#define ll long long
#define N 1000001
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
    ll n, a, b, MOD = 1e9+7;
    vector<ll> F(N), P(N, -1);
    F[0] = F[1] = P[0] = P[1] = 1;
    for(int i = 2; i < N; i++)
        F[i] = (F[i-1]*i)%MOD;
    cin >> n;
    while(n--){
        cin >> a >> b;
        if(P[b] == -1) P[b] = pow(F[b], MOD-2, MOD);
        if(P[a-b] == -1) P[a-b] = pow(F[a-b], MOD-2, MOD);
        cout << (((F[a]*P[b])%MOD)*P[a-b])%MOD << "\n";
    }
    return 0;
}