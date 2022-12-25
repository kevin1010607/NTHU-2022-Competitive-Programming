#include<bits/stdc++.h>
using namespace std;
class BIT{
private:
    int n;
    vector<int> bit;
public:
    BIT(int n): n(n), bit(n+1){}
    int query(int x){
        int res = 0;
        for(int i = x; i > 0; i -= i&-i)
            res += bit[i];
        return res;
    }
    void update(int x, int val){
        for(int i = x; i <= n; i += i&-i)
            bit[i] += val;
    }
};
class BIT2D{
private:
    int m;
    vector<BIT> bit;
public:
    BIT2D(int m, int n): m(m), bit(m+1, BIT(n)){}
    int query(int x, int y){
        int res = 0;
        for(int i = x; i > 0; i -= i&-i)
            res += bit[i].query(y);
        return res;
    }
    void update(int x, int y, int val){
        for(int i = x; i <= m; i += i&-i)
            bit[i].update(y, val);
    }
};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, type, x1, y1, x2, y2;
    cin >> n >> q;
    string s;
    BIT2D b(n, n);
    vector<vector<bool>> A(n+1, vector<bool>(n+1));
    for(int i = 1; i <= n; i++){
        cin >> s;
        for(int j = 1; j <= n; j++)
            if(s[j-1] == '*') A[i][j] = true, b.update(i, j, 1);
    }
    while(q--){
        cin >> type;
        if(type == 1){
            cin >> x1 >> y1;
            if(A[x1][y1] == true) b.update(x1, y1, -1);
            else b.update(x1, y1, 1);
            A[x1][y1] = !A[x1][y1];
        }
        else{
            cin >> x1 >> y1 >> x2 >> y2;
            cout << b.query(x2, y2)-b.query(x2,y1-1)-b.query(x1-1, y2)+b.query(x1-1, y1-1) << "\n";
        }
    }
    return 0;
}