// BIT
#include<bits/stdc++.h>
#define ll long long
using namespace std;
class BIT{
private:
    int n;
    vector<ll> bit;
public:
    BIT(int n): n(n), bit(n+1){}
    ll query(int x){
        ll res = 0;
        for(int i = x; i > 0; i -= i&-i)
            res += bit[i];
        return res;
    }
    void update(int x, ll val){
        for(int i = x; i <= n; i += i&-i)
            bit[i] += val;
    }
};
class RangeBIT{
private:
    int n;
    BIT D, xD;
public:
    RangeBIT(int n): n(n), D(n), xD(n){}
    ll query(int x){
        return (x+1)*D.query(x)-xD.query(x);
    }
    void update(int ql, int qr, ll val){
        D.update(ql, val);
        xD.update(ql, ql*val);
        D.update(qr+1, -val);
        xD.update(qr+1, -(qr+1)*val);
    }
};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, type, a, b, u, k;
    cin >> n >> q;
    RangeBIT r(n);
    for(int i = 1; i <= n; i++){
        cin >> k;
        r.update(i, i, k);
    }
    while(q--){
        cin >> type;
        if(type == 1){
            cin >> a >> b >> u;
            r.update(a, b, u);
        }
        else{
            cin >> k;
            cout << r.query(k)-r.query(k-1) << "\n";
        }
    }
    return 0;
}

// SegTree
// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;
// struct Node{
//     ll data, tag;
// };
// class SegTree{
// private:
//     int n;
//     vector<Node> seg;
//     ll get_val(int l, int r, int id){
//         return (r-l+1)*seg[id].tag+seg[id].data;
//     }
//     void pull(int l, int r, int id){
//         int mid = l+(r-l)/2;
//         seg[id].data = get_val(l, mid, id*2)+get_val(mid+1, r, id*2+1);
//     }
//     void push(int l, int r, int id){
//         seg[id].data = get_val(l, r, id);
//         seg[id*2].tag += seg[id].tag;
//         seg[id*2+1].tag += seg[id].tag;
//         seg[id].tag = 0;
//     }
// public:
//     SegTree(int n): n(n), seg(4*n){}
//     void build(int l, int r, vector<int>& A, int id=1){
//         if(l == r) {seg[id].data = A[l]; return;}
//         int mid = l+(r-l)/2;
//         build(l, mid, A, id*2);
//         build(mid+1, r, A, id*2+1);
//         pull(l, r, id);
//     }
//     ll query(int ql, int qr, int l, int r, int id=1){
//         if(qr<l || ql>r) return 0;
//         if(ql<=l && qr>=r) return get_val(l, r, id);
//         push(l, r, id);
//         int mid = l+(r-l)/2;
//         return query(ql, qr, l, mid, id*2)+query(ql, qr, mid+1, r, id*2+1);
//     }
//     void update(int ql, int qr, int val, int l, int r, int id=1){
//         if(qr<l || ql>r) return;
//         if(ql<=l && qr>=r) {seg[id].tag += val; return;}
//         push(l, r, id);
//         int mid = l+(r-l)/2;
//         update(ql, qr, val, l, mid, id*2);
//         update(ql, qr, val, mid+1, r, id*2+1);
//         pull(l, r, id);
//     }
// };
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int n, q, type, a, b, u, k;
//     cin >> n >> q;
//     vector<int> A(n);
//     for(auto& i : A) cin >> i;
//     SegTree s(n);
//     s.build(0, n-1, A);
//     while(q--){
//         cin >> type;
//         if(type == 1){
//             cin >> a >> b >> u;
//             s.update(a-1, b-1, u, 0, n-1);
//         }
//         else{
//             cin >> k;
//             cout << s.query(k-1, k-1, 0, n-1) << "\n";
//         }
//     }
//     return 0;
// }