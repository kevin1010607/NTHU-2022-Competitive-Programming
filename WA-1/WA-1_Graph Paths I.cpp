#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9+7;
vector<vector<ll>> mul(vector<vector<ll>> A, vector<vector<ll>> B, int n){
    vector<vector<ll>> res(n+1, vector<ll>(n+1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                res[i][j] = (res[i][j]+A[i][k]*B[k][j])%MOD;
    return res;
}
vector<vector<ll>> pow(vector<vector<ll>> A, int k, int n){
    vector<vector<ll>> res(n+1, vector<ll>(n+1));
    for(int i = 1; i <= n; i++) res[i][i] = 1;
    while(k){
        if(k&1) res = mul(res, A, n);
        k >>= 1;
        A = mul(A, A, n);
    }
    return res;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, a, b;
    cin >> n >> m >> k;
    vector<vector<ll>> G(n+1, vector<ll>(n+1));
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a][b]++;
    }
    G = pow(G, k, n);
    cout << G[1][n] << "\n";
    return 0;
}