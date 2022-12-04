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
    int n, q, l, r;
    cin >> n >> q;
    UF u(n+1);
    while(q--){
        cin >> l >> r;
        u.join(l-1, r);
    }
    cout << (u.find(0)==u.find(n)?"Yes\n":"No\n");
    return 0;
}