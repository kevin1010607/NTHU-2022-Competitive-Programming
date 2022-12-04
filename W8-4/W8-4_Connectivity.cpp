#include<bits/stdc++.h>
using namespace std;
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
    int n, k, l, a, b;
    cin >> n >> k >> l;
    UF road(n+1), rail(n+1);
    while(k--){
        cin >> a >> b;
        road.join(a, b);
    }
    while(l--){
        cin >> a >> b;
        rail.join(a, b);
    }
    map<pair<int, int>, int> m;
    for(int i = 1; i <= n; i++)
        m[{road.find(i), rail.find(i)}]++;
    for(int i = 1; i <= n; i++)
        cout << m[{road.find(i), rail.find(i)}] << " \n"[i==n];
    return 0;
}