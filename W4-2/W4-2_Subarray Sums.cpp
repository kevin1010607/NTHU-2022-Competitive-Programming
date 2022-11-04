#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, x, val, sum = 0, res = 0;
    map<ll, int> m{{0, 1}};
    cin >> n >> x;
    while(n--){
        cin >> val;
        sum += val;
        if(m.count(sum-x))
            res += m[sum-x];
        m[sum]++;
    }
    cout << res << "\n";
    return 0;
}