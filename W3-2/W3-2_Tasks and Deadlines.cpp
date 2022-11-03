#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, tmp, res = 0;
    cin >> n;
    vector<ll> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i] >> tmp;
        res += tmp;
    }
    sort(A.begin(), A.end());
    res -= A[0];
    for(int i = 1; i < n; i++){
        A[i] += A[i-1];
        res -= A[i];
    }
    cout << res << "\n";
    return 0;
}