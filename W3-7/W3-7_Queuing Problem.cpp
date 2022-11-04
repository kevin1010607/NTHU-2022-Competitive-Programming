#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, t, a, b;
    cin >> n >> m;
    int HEAD = n, TAIL = n+n;
    vector<int> next(n*3+1), prev(n*3+1);
    for(int i = 1; i <= n; i++){
        next[HEAD+i] = prev[TAIL+i] = i;
        next[i] = TAIL+i, prev[i] = HEAD+i;
    }
    while(m--){
        cin >> t >> a >> b;
        if(t == 0){
            next[prev[a]] = next[a];
            prev[next[a]] = prev[a];
            next[a] = next[b], prev[a] = b;
            prev[next[b]] = a;
            next[b] = a;
        }
        else{
            if(next[HEAD+a] == TAIL+a) continue;
            prev[next[HEAD+a]] = prev[TAIL+b];
            next[prev[TAIL+a]] = TAIL+b;
            next[prev[TAIL+b]] = next[HEAD+a];
            prev[TAIL+b] = prev[TAIL+a];
            next[HEAD+a] = TAIL+a;
            prev[TAIL+a] = HEAD+a;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << "#" << i << ":";
        int idx = next[HEAD+i];
        while(idx != TAIL+i){
            cout << " " << idx;
            idx = next[idx];
        }
        cout << "\n";
    }
    return 0;
}