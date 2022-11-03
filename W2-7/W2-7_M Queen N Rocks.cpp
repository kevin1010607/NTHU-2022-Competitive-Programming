#include<bits/stdc++.h>
using namespace std;
int m, n, MASK;
int dfs(int M, int L_q, int R_q, int L_r, int R_r, int NQ, int NR){
    if(M == MASK) return 1;
    int res = 0;
    if(NQ){
        int legal = MASK&~(M|L_q|R_q|L_r|R_r);
        for(int num = 0; legal; legal ^= num){
            num = legal&-legal;
            res += dfs(M|num, (L_q|num)<<1, (R_q|num)>>1, L_r<<1, R_r>>1, NQ-1, NR);
        }
    }
    if(NR){
        int legal = MASK&~(M|L_q|R_q);
        for(int num = 0; legal; legal ^= num){
            num = legal&-legal;
            res += dfs(M|num, L_q<<1, R_q>>1, (L_r|num)<<1, (R_r|num)>>1, NQ, NR-1);
        }
    }
    return res;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;
        MASK = (1<<(m+n))-1;
        cout << dfs(0, 0, 0, 0, 0, m, n) << "\n";
    }
    return 0;
}