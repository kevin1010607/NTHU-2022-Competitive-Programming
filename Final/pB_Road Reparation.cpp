#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Edge{
    int u, v, c;
    bool operator<(const Edge& e) const{
        return c < e.c;
    }
};
class UF{
private:
    vector<int> parent, rank;
public:
    UF(int n):parent(n), rank(n){
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void join(int x, int y){
        int px = find(x), py = find(y);
        if(px == py) return;
        if(rank[px] < rank[py]) parent[px] = py;
        else if(rank[px] > rank[py]) parent[py] = px;
        else parent[py] = px, rank[px]++;
    }
};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, cnt = 0, res = 0;
    cin >> n >> m;
    vector<Edge> E(m);
    UF U(n+1);
    for(int i = 0; i < m; i++)
        cin >> E[i].u >> E[i].v >> E[i].c;
    sort(E.begin(), E.end());
    for(auto [u, v, c] : E){
        if(U.find(u) == U.find(v)) continue;
        U.join(u, v);
        res += c, cnt++;
    }
    if(cnt == n-1) cout << res << "\n";
    else cout << "IMPOSSIBLE\n";
    return 0;
}