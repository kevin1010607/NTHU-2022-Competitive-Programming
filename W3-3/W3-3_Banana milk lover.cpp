#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Group{
    ll n, sum, M, idx;
    vector<ll> A;
    bool operator<(const Group a){
        if(sum != a.sum) return sum < a.sum;
        if(M != a.M) return M < a.M;
        if(n != a.n) return n < a.n;
        return idx > a.idx;
    }
};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<Group> G(n);
        for(int i = 0; i < n; i++){
            cin >> G[i].n;
            G[i].idx = i;
            G[i].A.resize(G[i].n);
            for(int j = 0; j < G[i].n; j++){
                cin >> G[i].A[j];
                G[i].sum += G[i].A[j];
                G[i].M = max(G[i].M, G[i].A[j]);
            }
        }
        sort(G.rbegin(), G.rend());
        for(int i = 0; i < n; i++)
            for(int j = 0; j < G[i].n; j++)
                cout << G[i].A[j] << " \n"[j==G[i].n-1];
    }
    return 0;
}