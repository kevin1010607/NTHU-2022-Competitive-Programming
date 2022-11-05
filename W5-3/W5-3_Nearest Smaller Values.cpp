#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n+1), prev(n+1);
    for(int i = 1; i <= n; i++){
        cin >> A[i];
        int idx = i-1;
        while(A[idx] >= A[i]) idx = prev[idx];
        prev[i] = idx;
        cout << prev[i] << " \n"[i==n];
    }
    return 0;
}