#include<bits/stdc++.h>
using namespace std;
bool dfs(int idx, int n_edge, int sum, int target, vector<int>& A){
    if(n_edge == 3) return true;
    if(sum == target) return dfs(0, n_edge+1, 0, target, A);
    for(int i = idx; i < A.size(); i++){
        if(!A[i] || sum+A[i]>target) continue;
        int t = A[i]; A[i] = 0;
        if(dfs(i+1, n_edge, sum+t, target, A)) return true;
        A[i] = t;
    }
    return false;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int sum = 0, m = 0;
        vector<int> A(n);
        for(auto& i : A){
            cin >> i;
            sum += i;
            m = max(m, i);
        }
        if(sum%4 || m>sum/4){cout << "no\n"; continue;}
        sort(A.rbegin(), A.rend());
        cout << (dfs(0, 0, 0, sum/4, A)?"yes\n":"no\n");
    }
    return 0;
}