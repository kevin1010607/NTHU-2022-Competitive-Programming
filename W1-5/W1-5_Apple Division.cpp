#include<bits/stdc++.h>
#define ll long long
using namespace std;
void dfs(int idx, ll now, ll total, vector<int>& A, ll& res){
    if(idx == A.size()){
        res = min(res, abs(now-(total-now)));
        return;
    }
    dfs(idx+1, now, total, A, res);
    dfs(idx+1, now+A[idx], total, A, res);
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    ll total = accumulate(A.begin(), A.end(), 0LL), res = LLONG_MAX;
    dfs(0, 0, total, A, res);
    cout << res << "\n";
    return 0;
}