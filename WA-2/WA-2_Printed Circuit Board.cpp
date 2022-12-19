#include<bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pii> A(n);
    for(int i = 0; i < n; i++)
        cin >> A[i].F >> A[i].S;
    sort(A.begin(), A.end());
    vector<int> dp;
    for(auto [i, j] : A){
        auto it = lower_bound(dp.begin(), dp.end(), -j);
        if(it == dp.end()) dp.push_back(-j);
        else *it = -j;
    }
    cout << dp.size() << "\n";
    return 0;
}