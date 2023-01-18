#include<bits/stdc++.h>
#define ll long long
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
class MaxBIT{
private:
    int n;
    vector<ll> bit;
public:
    MaxBIT(int n): n(n), bit(n+1){}
    ll query(int x){
        ll res = 0;
        for(int i = x; i > 0; i -= i&-i)
            res = max(res, bit[i]);
        return res;
    }
    void update(int x, ll val){
        for(int i = x; i <= n; i += i&-i)
            bit[i] = max(bit[i], val);
    }
};