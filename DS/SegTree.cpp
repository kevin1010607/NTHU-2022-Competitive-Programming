#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Node{
    ll data, tag;
};
class SegTree{
private:
    int n;
    vector<Node> seg;
    ll get_val(int l, int r, int id){
        return (r-l+1)*seg[id].tag+seg[id].data;
    }
    void pull(int l, int r, int id){
        int mid = l+(r-l)/2;
        seg[id].data = get_val(l, mid, id*2)+get_val(mid+1, r, id*2+1);
    }
    void push(int l, int r, int id){
        seg[id].data = get_val(l, r, id);
        seg[id*2].tag += seg[id].tag;
        seg[id*2+1].tag += seg[id].tag;
        seg[id].tag = 0;
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
    void update(int ql, int qr, int val, int l, int r, int id=1){
        if(qr<l || ql>r) return;
        if(ql<=l && qr>=r) {seg[id].tag += val; return;}
        push(l, r, id);
        int mid = l+(r-l)/2;
        update(ql, qr, val, l, mid, id*2);
        update(ql, qr, val, mid+1, r, id*2+1);
        pull(l, r, id);
    }
};