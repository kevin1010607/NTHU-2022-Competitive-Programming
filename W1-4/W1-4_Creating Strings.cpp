#include<bits/stdc++.h>
using namespace std;
int getN(int n, vector<int>& A){
    int res = 1;
    for(int i = 2; i <= n; i++) res *= i;
    for(auto i : A){
        if(i < 2) continue;
        for(int j = i; j > 1; j--)
            res /= j;
    }
    return res;
}
void dfs(string& t, int n, vector<int>& A){
    if(t.size() == n){
        cout << t << "\n";
        return;
    }
    for(int i = 0; i < 26; i++){
        if(A[i] == 0) continue;
        A[i]--;
        t.push_back('a'+i);
        dfs(t, n, A);
        A[i]++;
        t.pop_back();
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s;
    int n = s.size();
    vector<int> A(26);
    for(auto c : s) A[c-'a']++;
    cout << getN(n, A) << "\n";
    dfs(t, n, A);
    return 0;
}