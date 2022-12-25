#include<bits/stdc++.h>
using namespace std;
class SegTree{
private:
    int n;
    vector<int> seg;
    void pull(int id){
        seg[id] = min(seg[id*2], seg[id*2+1]);
    }
public:
    SegTree(int n): n(n), seg(4*n){}
    void build(int l, int r, vector<int>& A, int id=1){
        if(l == r){seg[id] = A[l]; return;}
        int mid = l+(r-l)/2;
        build(l, mid, A, id*2);
        build(mid+1, r, A, id*2+1);
        pull(id);
    }
    int query(int ql, int qr, int l, int r, int id=1){
        if(qr<l || ql>r) return INT_MAX;
        if(ql<=l && qr>=r) return seg[id];
        int mid = l+(r-l)/2;
        return min(query(ql, qr, l, mid, id*2), query(ql, qr, mid+1, r, id*2+1));
    }
    void update(int p, int val, int l, int r, int id=1){
        if(p<l || p>r) return;
        if(l == r){seg[id] = val; return;}
        int mid = l+(r-l)/2;
        update(p, val, l, mid, id*2);
        update(p, val, mid+1, r, id*2+1);
        pull(id);
    }
};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, type, a, b;
    cin >> n >> q;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    SegTree s(n);
    s.build(0, n-1, A);
    while(q--){
        cin >> type >> a >> b;
        if(type == 1) s.update(a-1, b, 0, n-1);
        else cout << s.query(a-1, b-1, 0, n-1) << "\n";
    }
    return 0;
}