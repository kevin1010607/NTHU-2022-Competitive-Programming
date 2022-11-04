#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, p1, p2, p3;
    cin >> n >> k;
    vector<int> A(n), cnt(1201);
    for(int i = 0; i < n; i++){
        cin >> p1 >> p2 >> p3;
        A[i] = p1+p2+p3;
        cnt[A[i]]++;
    }
    for(int i = 1199; i >= 0; i--)
        cnt[i] += cnt[i+1];
    for(auto i : A){
        int p = i+300;
        if(p>=1200 || cnt[p+1]<k) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}