#include<bits/stdc++.h>
#define ll long long
#define Pii pair<int, int>
#define F first
#define S second
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<Pii> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i].F;
        A[i].S = i+1;
    }
    sort(A.begin(), A.end());
    for(int i = 0; i < n; i++){
        int l = i+1, r = n-1;
        while(l < r){
            ll s = (ll)A[i].F+A[l].F+A[r].F;
            if(s == x){
                cout << A[i].S << " " << A[l].S << " " << A[r].S << "\n";
                return 0;
            }
            else if(s < x) l++;
            else r--;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}