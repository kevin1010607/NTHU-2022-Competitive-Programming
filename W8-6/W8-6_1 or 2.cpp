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
    int n, m, x, y, z;
    cin >> n >> m;
    UF u(n+1);
    while(m--){
        cin >> x >> y >> z;
        u.join(x, y);
    }
    unordered_set<int> s;
    for(int i = 1; i <= n; i++)
        s.insert(u.find(i));
    cout << s.size() << "\n";
    return 0;
}