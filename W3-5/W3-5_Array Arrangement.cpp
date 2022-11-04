#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char c;
    int t, n, q, id;
    cin >> t;
    while(t--){
        cin >> n >> q;
        vector<int> next(n+2), prev(n+2);
        next[0] = 1, prev[n+1] = n;
        for(int i = 1; i <= n; i++)
            next[i] = i+1, prev[i] = i-1;
        while(q--){
            cin >> c >> id;
            if(c == 'H'){
                next[prev[id]] = next[id];
                prev[next[id]] = prev[id];
                next[id] = next[0], prev[id] = 0;
                prev[next[0]] = id;
                next[0] = id;
            }
            else{
                next[prev[id]] = next[id];
                prev[next[id]] = prev[id];
                next[id] = n+1, prev[id] = prev[n+1];
                next[prev[n+1]] = id;
                prev[n+1] = id;
            }
        }
        int idx = next[0];
        for(int i = 0; i < n; i++){
            cout << idx << " \n"[i==n-1];
            idx = next[idx];
        }
    }
    return 0;
}