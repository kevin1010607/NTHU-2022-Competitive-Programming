#include<bits/stdc++.h>
#define BASE 1001
#define N 2003
using namespace std;
class UF{
private:
    int n;
    unordered_map<int, int> parent, rank;
public:
    UF(): n(0){}
    void set(int x){
        parent[x] = x, rank[x] = 0, n++;
    }
    bool exist(int x){
        return parent.count(x);
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
        n--;
    }
    int group(){
        return n;
    }
};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y;
    UF u;
    const int dx[6] = {-1,-1,0,0,1,1}, dy[6] = {-1,0,-1,1,0,1};
    cin >> n;
    while(n--){
        cin >> x >> y;
        x += BASE, y += BASE;
        int id = x*N+y;
        u.set(id);
        for(int i = 0; i < 6; i++){
            int nx = x+dx[i], ny = y+dy[i];
            int nid = nx*N+ny;
            if(!u.exist(nid)) continue;
            u.join(id, nid);
        }
    }
    cout << u.group() << "\n";
    return 0;
}