#include<bits/stdc++.h>
using namespace std;
void dfs(int idx, int m, vector<int>& A, vector<int>& now){
    if(now.size() == m){
        for(int i = 0; i < m; i++)
            cout << now[i] << " \n"[i==m-1];
        return;
    }
    for(int i = idx; i < A.size(); i++){
        now.push_back(A[i]);
        dfs(i+1, m, A, now);
        now.pop_back();
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> A(n), now;
    for(auto& i : A) cin >> i;
    dfs(0, m, A, now);
    return 0;
}