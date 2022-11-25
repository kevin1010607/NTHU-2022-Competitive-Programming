#include<bits/stdc++.h>
using namespace std;
bool dfs(int idx, int now, int cnt, int target_len, int target_cnt, vector<int>& A, vector<bool>& used){
    if(now == target_len){
        if(cnt+1 == target_cnt) return true;
        else return dfs(0, 0, cnt+1, target_len, target_cnt, A, used);
    }
    for(int i = idx; i < A.size(); i++){
        if(used[i] || now+A[i]>target_len || (i&&A[i]==A[i-1]&&!used[i-1])) continue;
        used[i] = true;
        if(dfs(i+1, now+A[i], cnt, target_len, target_cnt, A, used)) return true;
        used[i] = false;
        if(now==0 || now+A[i]==target_len) return false;
    }
    return false;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n){
        if(n == 0) break;
        int sum = 0, m = 0;
        vector<int> A(n);
        vector<bool> used(n);
        for(auto& i : A){
            cin >> i;
            sum += i;
            m = max(m, i);
        }
        sort(A.rbegin(), A.rend());
        for(int i = m; i <= sum; i++){
            if(sum%i) continue;
            if(dfs(0, 0, 0, i, sum/i, A, used)){
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}