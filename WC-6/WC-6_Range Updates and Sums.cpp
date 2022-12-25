#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Node{
    ll data, tag_add, tag_set;
};
class SegTree{
private:
    int n;
    vector<Node> seg;
    ll get_val(int l, int r, int id){
        if(seg[id].tag_set) return (r-l+1)*(seg[id].tag_set+seg[id].tag_add);
        else return (r-l+1)*seg[id].tag_add+seg[id].data;
    }
    void pull(int l, int r, int id){
        int mid = l+(r-l)/2;
        seg[id].data = get_val(l, mid, id*2)+get_val(mid+1, r, id*2+1);
    }
    void push(int l, int r, int id){
        seg[id].data = get_val(l, r, id);
        if(seg[id].tag_set){
            seg[id*2].tag_set = seg[id*2+1].tag_set = seg[id].tag_set;
            seg[id*2].tag_add = seg[id*2+1].tag_add = 0;
            seg[id].tag_set = 0;
        }
        if(seg[id].tag_add){
            seg[id*2].tag_add += seg[id].tag_add;
            seg[id*2+1].tag_add += seg[id].tag_add;
            seg[id].tag_add = 0;
        }
    }
public:
    SegTree(int n): n(n), seg(4*n){}
    void build(int l, int r, vector<int>& A, int id=1){
        if(l == r) {seg[id].data = A[l]; return;}
        int mid = l+(r-l)/2;
        build(l, mid, A, id*2);
        build(mid+1, r, A, id*2+1);
        pull(l, r, id);
    }
    ll query(int ql, int qr, int l, int r, int id=1){
        if(qr<l || ql>r) return 0;
        if(ql<=l && qr>=r) return get_val(l, r, id);
        push(l, r, id);
        int mid = l+(r-l)/2;
        return query(ql, qr, l, mid, id*2)+query(ql, qr, mid+1, r, id*2+1);
    }
    void update_add(int ql, int qr, int dval, int l, int r, int id=1){
        if(qr<l || ql>r) return;
        if(ql<=l && qr>=r) {seg[id].tag_add += dval; return;}
        push(l, r, id);
        int mid = l+(r-l)/2;
        update_add(ql, qr, dval, l, mid, id*2);
        update_add(ql, qr, dval, mid+1, r, id*2+1);
        pull(l, r, id);
    }
    void update_set(int ql, int qr, int val, int l, int r, int id=1){
        if(qr<l || ql>r) return;
        if(ql<=l && qr>=r) {seg[id].tag_set = val, seg[id].tag_add = 0; return;}
        push(l, r, id);
        int mid = l+(r-l)/2;
        update_set(ql, qr, val, l, mid, id*2);
        update_set(ql, qr, val, mid+1, r, id*2+1);
        pull(l, r, id);
    }
};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, type, a, b, x;
    cin >> n >> q;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    SegTree s(n);
    s.build(0, n-1, A);
    while(q--){
        cin >> type;
        if(type == 1){
            cin >> a >> b >> x;
            s.update_add(a-1, b-1, x, 0, n-1);
        }
        else if(type == 2){
            cin >> a >> b >> x;
            s.update_set(a-1, b-1, x, 0, n-1);
        }
        else{
            cin >> a >> b;
            cout << s.query(a-1, b-1, 0, n-1) << "\n";
        }
    }
    return 0;
}