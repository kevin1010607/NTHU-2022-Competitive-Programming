#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Node{
    ll sum, MCS, preMax, postMax;
    Node(ll sum=0): sum(sum), MCS(max(sum, 0LL)), preMax(MCS), postMax(MCS){}
    Node operator+(const Node& node){
        Node res(sum+node.sum);
        res.MCS = max({MCS, node.MCS, postMax+node.preMax});
        res.preMax = max(preMax, sum+node.preMax);
        res.postMax = max(node.postMax, node.sum+postMax);
        return res;
    }
};
struct SegTree{
private:
    int n;
    vector<Node> seg;
    void pull(int id){
        seg[id] = seg[id*2]+seg[id*2+1];
    }
public:
    SegTree(int n): n(n), seg(4*n){}
    void build(int l, int r, vector<int>& A, int id=1){
        if(l == r) {seg[id] = Node(A[l]); return;}
        int mid = l+(r-l)/2;
        build(l, mid, A, id*2);
        build(mid+1, r, A, id*2+1);
        pull(id);
    }
    Node query(int ql, int qr, int l, int r, int id=1){
        if(qr<l || ql>r) return Node(0);
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
    int n, m, k, x;
    cin >> n >> m;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    SegTree s(n);
    s.build(0, n-1, A);
    while(m--){
        cin >> k >> x;
        s.update(k-1, x, 0, n-1);
        cout << s.query(0, n-1, 0, n-1).MCS << "\n";
    }
    return 0;
}