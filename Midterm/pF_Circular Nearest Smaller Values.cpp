#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n+n), prev(n+n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
        A[i+n] = A[i];
    }
    for(int i = 1; i < n+n; i++){
        int idx = i-1;
        while(idx>0 && A[idx]<A[i]) idx = prev[idx];
        prev[i] = idx;
        if(i >= n) cout << idx%n+1 << " \n"[i==n+n-1];
    }
    return 0;
}