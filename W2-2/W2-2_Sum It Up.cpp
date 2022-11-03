#include<bits/stdc++.h>
using namespace std;
void print(vector<int>& now){
    for(int i = 0; i < now.size(); i++)
        cout << now[i] << "+\n"[i==now.size()-1];
}
bool dfs(int idx, int t, bool get, vector<int>& A, vector<int>& now){
    if(t == 0){
        print(now);
        return true;
    }
    if(t<0 || idx==A.size()) return false;
    bool res = false;
    if((idx==0 || A[idx-1]!=A[idx] || get)){
        now.push_back(A[idx]);
        if(dfs(idx+1, t-A[idx], true, A, now)) res = true;
        now.pop_back();
    }
    if(dfs(idx+1, t, false, A, now)) res = true;
    return res;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    while(cin >> t >> n){
        if(n == 0) break;
        vector<int> A(n), now;
        for(auto& i : A) cin >> i;
        sort(A.rbegin(), A.rend());
        cout << "Sums of " << t << ":\n";
        if(!dfs(0, t, true, A, now)) cout << "NONE\n";
    }
    return 0;
}