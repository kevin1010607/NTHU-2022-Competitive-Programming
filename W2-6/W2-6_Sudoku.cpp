#include<bits/stdc++.h>
using namespace std;
const int MASK = (1<<10)-2;
int R[9], C[9], D[9][9];
void update(int i, int j, int num){
    R[i] ^= num;
    C[j] ^= num;
    D[i/3][j/3] ^= num;
}
bool dfs(int idx, string& s){
    if(idx == 81) return true;
    if(s[idx] != '.') return dfs(idx+1, s);
    int i = idx/9, j = idx%9;
    int legal = MASK&~(R[i]|C[j]|D[i/3][j/3]);
    for(int num = 0; legal; legal ^= num){
        num = legal&-legal;
        s[idx] = '0'+__builtin_ctz(num);
        update(i, j, num);
        if(dfs(idx+1, s)) return true;
        update(i, j, num);
    }
    s[idx] = '.';
    return false;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(cin >> s){
        if(s == "end") break;
        memset(R, 0, sizeof(R));
        memset(C, 0, sizeof(C));
        memset(D, 0, sizeof(D));
        bool legal = true;
        for(int idx = 0; idx < 81; idx++){
            if(s[idx] == '.') continue;
            int i = idx/9, j = idx%9, num = 1<<(s[idx]-'0');
            if(R[i]&C[j]&D[i/3][j/3]&num) {legal = false; break;}
            update(i, j, num);            
        }
        if(legal && dfs(0, s)) cout << s << "\n";
        else cout << "No solution.\n";
    }
    return 0;
}