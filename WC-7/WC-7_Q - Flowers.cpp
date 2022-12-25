#include<bits/stdc++.h>
#define ll long long
using namespace std;
class MaxBIT{
private:
    int n;
    vector<ll> bit;
public:
    MaxBIT(int n): n(n), bit(n+1){}
    ll query(int x){
        ll res = 0;
        for(int i = x; i > 0; i -= i&-i)
            res = max(res, bit[i]);
        return res;
    }
    void update(int x, ll val){
        for(int i = x; i <= n; i += i&-i)
            bit[i] = max(bit[i], val);
    }
};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> H(n), A(n);
    for(auto& i : H) cin >> i;
    for(auto& i : A) cin >> i;
    MaxBIT b(n+1);
    for(int i = 0; i < n; i++){
        ll sum = b.query(H[i]-1)+A[i];
        b.update(H[i], sum);
    }
    cout << b.query(n+1) << "\n";
    return 0;
}