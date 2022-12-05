#include<bits/stdc++.h>
#define ll long long
#define INF (LLONG_MAX/2)
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, q, a, b, c;
    cin >> n >> m >> q;
    vector<vector<ll>> D(n+1, vector<ll>(n+1, INF));
    for(int i = 1; i <= n; i++) D[i][i] = 0;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        D[a][b] = min(D[a][b], c);
      	D[b][a] = min(D[b][a], c);
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
    while(q--){
        cin >> a >> b;
        cout << (D[a][b]==INF?-1:D[a][b]) << "\n";
    }
    return 0;
}