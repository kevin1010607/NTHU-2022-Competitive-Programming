#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    unordered_map<int, pii> m;
    for(int i = n-1; i >= 0; i--){
        for(int j = i-1; j >= 0; j--){
            int t = x-A[i]-A[j];
            if(m.count(t)){
                cout << i+1 << " " << j+1 << " " << m[t].F+1 << " " << m[t].S+1 << "\n";
                return 0;
            }
        }
        for(int j = i+1; j < n; j++) m[A[i]+A[j]] = {i, j};
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}