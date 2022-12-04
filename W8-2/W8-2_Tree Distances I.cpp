#include<bits/stdc++.h>
using namespace std;
void dfs1(int idx, int parent, vector<int>& D1, vector<int>& D2, vector<int>& C, vector<vector<int>>& G){
    D1[idx] = D2[idx] = 0;
    for(auto i : G[idx]){
        if(i == parent) continue;
        dfs1(i, idx, D1, D2, C, G);
        int dis = D1[i]+1;
        if(dis > D1[idx]){
            D2[idx] = D1[idx];
            D1[idx] = dis;
            C[idx] = i;
        }
        else D2[idx] = max(D2[idx], dis);
    }
}
void dfs2(int idx, int parent, vector<int>& D1, vector<int>& D2, vector<int>& C, vector<vector<int>>& G){
    for(auto i : G[idx]){
        if(i == parent) continue;
        if(i == C[idx]){
            if(D2[idx]+1 > D1[i]){
                D2[i] = D1[i];
                D1[i] = D2[idx]+1;
                C[i] = idx;
            }
            else D2[i] = max(D2[i], D2[idx]+1);
        }
        else{
            D2[i] = D1[i];
            D1[i] = D1[idx]+1;
            C[i] = idx;
        }
        dfs2(i, idx, D1, D2, C, G);
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n;
    vector<vector<int>> G(n+1);
    vector<int> D1(n+1), D2(n+1), C(n+1);
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs1(1, -1, D1, D2, C, G);
    dfs2(1, -1, D1, D2, C, G);
    for(int i = 1; i <= n; i++)
        cout << D1[i] << " \n"[i==n];
    return 0;
}