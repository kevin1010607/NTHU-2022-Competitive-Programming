#include<bits/stdc++.h>
using namespace std;
struct Node{
    int ans, len, pre0, pre1, post0, post1;
    Node(){
        ans = len = pre0 = pre1 = post0 = post1 = 0;
    }
    Node(int data){
        ans = len = 1;
        if(data == 0) pre0 = post0 = 1, pre1 = post1 = 0;
        else pre0 = post0 = 0, pre1 = post1 = 1;
    }
    Node operator+(const Node& n){
        Node res;
        res.ans = max({ans, n.ans, post0+n.pre0, post1+n.pre1});
        res.len = len+n.len;
        res.pre0 = pre0==len?len+n.pre0:pre0;
        res.pre1 = pre1==len?len+n.pre1:pre1;
        res.post0 = n.post0==n.len?n.len+post0:n.post0;
        res.post1 = n.post1==n.len?n.len+post1:n.post1;
        return res;
    }
};
class SegTree{
private:
    int n;
    vector<Node> seg;
    void pull(int id){
        seg[id] = seg[id*2]+seg[id*2+1];
    }
public:
    SegTree(int n): n(n), seg(4*n){}
    void build(int l, int r, string& s, int id=1){
        if(l == r) {seg[id] = Node(s[l]-'0'); return;}
        int mid = l+(r-l)/2;
        build(l, mid, s, id*2);
        build(mid+1, r, s, id*2+1);
        pull(id);
    }
    Node query(int ql, int qr, int l, int r, int id=1){
        if(qr<l || ql>r) return Node();
        if(ql<=l && qr>=r) return seg[id];
        int mid = l+(r-l)/2;
        return query(ql, qr, l, mid, id*2)+query(ql, qr, mid+1, r, id*2+1);
    }
    void update(int p, int val, int l, int r, int id=1){
        if(p<l || p>r) return;
        if(l == r){seg[id] = Node(val); return;}
        int mid = l+(r-l)/2;
        update(p, val, l, mid, id*2);
        update(p, val, mid+1, r, id*2+1);
        pull(id);
    }
};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n, m, x;
    cin >> s >> m;
    n = s.size();
    SegTree t(n);
    t.build(0, n-1, s);
    for(int i = 0; i < m; i++){
        cin >> x;
        x--;
        t.update(x, (s[x]-'0')^1, 0, n-1);
        s[x] = '0'+((s[x]-'0')^1);
        cout << t.query(0, n-1, 0, n-1).ans << " \n"[i==m-1];
    }
    return 0;
}