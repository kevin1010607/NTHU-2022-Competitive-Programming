#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll extgcd(ll a, ll b, ll& x, ll& y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    ll res = extgcd(b, a%b, y, x);
    y -= (a/b)*x;
    return res;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t, m, n, x, y, vx, vy, c, a, b, g, N, resx, resy;
    cin >> t;
    while(t--){
        cin >> m >> n >> x >> y >> vx >> vy;
        if(vx == 0){
            if(x==0 || x==m) cout << x << " " << (vy==1?n:0) << "\n";
            else cout << "-1\n";
            continue;
        }
        if(vy == 0){
            if(y==0 || y==n) cout << (vx==1?m:0) << " " << y << "\n";
            else cout << "-1\n";
            continue;
        }
        if(vx == -1) x = m-x;
        if(vy == -1) y = n-y;
        c = x-y, g = extgcd(m, n, a, b);
        if(c%g){
            cout << "-1\n";
            continue;
        }
        a *= c/g, b *= c/g;
        N = n/g;
        a = (a%N+N-1)%N+1;
        b = -(c-a*m)/n;
        resx = m, resy = n;
        if(a%2 == 0) resx = m-resx;
        if(b%2 == 0) resy = n-resy;
        if(vx == -1) resx = m-resx;
        if(vy == -1) resy = n-resy;
        cout << resx << " " << resy << "\n";
    }
    return 0;
}