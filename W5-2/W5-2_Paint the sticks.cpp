#include<bits/stdc++.h>
#define ll long long
#define P pair<int, ll>
#define F first
#define S second
using namespace std;
ll solve(vector<ll>& A){
    ll res = 0;
    stack<P> s;
    A.push_back(0);
    for(int i = 0; i < A.size(); i++){
        int idx = i;
        while(!s.empty() && s.top().S>=A[i]){
            idx = s.top().F;
            res = max(res, (i-idx)*s.top().S);
            s.pop();
        }
        s.push({idx, A[i]});
    }
    return res;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n){
        vector<ll> A(n);
        for(auto& i : A) cin >> i;
        cout << solve(A) << "\n";
    }
    return 0;
}