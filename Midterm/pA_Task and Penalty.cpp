#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, prefix = 0, res = 0;
    cin >> n;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    sort(A.begin(), A.end());
    for(int i = 0; i < n; i++){
        prefix += A[i];
        res += prefix;
    }
    cout << res << "\n";
    return 0;
}