#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
#define INF (LLONG_MAX/2)
using namespace std;
void FW(vector<vector<ll>>& G){
    int n = G.size()-1;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
}
bool check(ll r, int n, vector<vector<ll>>& G, vector<vector<ll>>& P){
    vector<vector<ll>> newG(n+1, vector<ll>(n+1, INF));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            newG[i][j] = G[i][j]==INF?INF:G[i][j]*r-P[i][j];
    FW(newG);
    for(int i = 1; i <= n; i++)
        if(newG[i][i] <= 0) return true;
    return false;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, K;
    cin >> n >> m >> K;
    vector<vector<pll>> C(n+1, vector<pll>(K));
    vector<vector<ll>> G(n+1, vector<ll>(n+1, INF)), P(n+1, vector<ll>(n+1));
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < K; j++)
            cin >> C[i][j].F >> C[i][j].S;
    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        G[a][b] = c;
    }
    FW(G);
    // Get profit
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 0; k < K; k++)
                if(C[i][k].F!=-1 && C[j][k].S!=-1)
                    P[i][j] = max(P[i][j], C[j][k].S-C[i][k].F);
    // Binary search
    ll l = 0, r = 1e9;
    while(l <= r){
        ll mid = l+(r-l)/2;
        if(check(mid, n, G, P)) l = mid+1;
        else r = mid-1;
    }
    cout << r << "\n";
    return 0;
}