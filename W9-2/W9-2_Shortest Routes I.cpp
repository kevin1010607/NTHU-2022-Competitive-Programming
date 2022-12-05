#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pli pair<ll, int>
#define INF (LLONG_MAX/2)
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<pii>> G(n+1);
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }
    vector<ll> D(n+1, INF);
    priority_queue<pli, vector<pli>, greater<pli>> q;
    D[1] = 0;
    q.push({0, 1});
    while(!q.empty()){
        auto [dis, now] = q.top(); q.pop();
        if(dis > D[now]) continue;
        for(auto [i, v] : G[now]){
            if(D[now]+v < D[i]){
                D[i] = D[now]+v;
                q.push({D[i], i});
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << D[i] << " \n"[i==n];
    return 0;
}