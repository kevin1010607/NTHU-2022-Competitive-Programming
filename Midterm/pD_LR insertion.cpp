#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int HEAD = n+1, TAIL = n+2;
    vector<int> prev(n+3), next(n+3);
    next[HEAD] = prev[TAIL] = 0;
    next[0] = TAIL;
    prev[0] = HEAD;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            next[i+1] = i;
            prev[i+1] = prev[i];
            next[prev[i]] = i+1;
            prev[i] = i+1;
        }
        else{
            prev[i+1] = i;
            next[i+1] = next[i];
            prev[next[i]] = i+1;
            next[i] = i+1;
        }
    }
    int idx = next[HEAD];
    for(int i = 0; i <= n; i++){
        cout << idx << " \n"[i==n];
        idx = next[idx];
    }
    return 0;
}