#include<bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, res = 0;
    cin >> n >> k;
    vector<pii> A(n);
    for(int i = 0; i < n; i++)
        cin >> A[i].S >> A[i].F;
    sort(A.begin(), A.end());
    multiset<int> s;
    for(int i = 0; i < n; i++){
        auto it = s.lower_bound(-A[i].S);
        if(it==s.end() && s.size()==k) continue;
        if(it != s.end()) s.erase(it);
        s.insert(-A[i].F);
        res++;
    }
    cout << res << "\n";
    return 0;
}