#include<bits/stdc++.h>
using namespace std;
void solve(int idx, bool hook, vector<bool>& H){
    if(hook == H[idx]) return;
    if(idx != 1) solve(idx-1, true, H);
    for(int i = idx-2; i >= 1; i--)
        solve(i, false, H);
    H[idx] = hook;
    cout << "Move ring " << idx << " " << (hook?"in":"out") << "\n";
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<bool> H(n+1, true);
    for(int i = n; i >= 1; i--)
        solve(i, false, H);
    return 0;
}