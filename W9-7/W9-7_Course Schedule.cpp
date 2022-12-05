#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> G(n+1);
    vector<int> in(n+1), res;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        in[b]++;
    }
    for(int i = 1; i <= n; i++)
        if(in[i] == 0) res.push_back(i);
    for(int i = 0; i < res.size(); i++)
        for(auto j : G[res[i]])
            if(--in[j] == 0) res.push_back(j);
    if(res.size() != n) cout << "IMPOSSIBLE\n";
    else{ 
        for(int i = 0; i < n; i++)
            cout << res[i] << " \n"[i==n-1];
    }
    return 0;
}