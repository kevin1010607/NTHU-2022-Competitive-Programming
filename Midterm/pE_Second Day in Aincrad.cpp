#include<bits/stdc++.h>
using namespace std;
int nA, nB, nC;
string A, B, C, op, as;
bool dfs(int idx, int a, int b, int c){
    if(idx == nA+nB+nC){
        if(op == "+") return a+b == c;
        else return a-b == c;
    }
    if(idx < nA){
        if(A[idx] != 'X') return dfs(idx+1, 10*a+(A[idx]-'0'), b, c);
        for(int i = 0; i < 10; i++){
            if(idx==0 && i==0 && nA!=1) continue;
            A[idx] = '0'+i;
            if(dfs(idx+1, 10*a+i, b, c)) return true;
        }
        A[idx] = 'X';
    }
    else if(idx < nA+nB){
        if(B[idx-nA] != 'X') return dfs(idx+1, a, 10*b+(B[idx-nA]-'0'), c);
        for(int i = 0; i < 10; i++){
            if(idx==nA && i==0 && nB!=1) continue;
            B[idx-nA] = '0'+i;
            if(dfs(idx+1, a, 10*b+i, c)) return true;
        }
        B[idx-nA] = 'X';
    }
    else{
        if(C[idx-nA-nB] != 'X') return dfs(idx+1, a, b, 10*c+(C[idx-nA-nB]-'0'));
        for(int i = 0; i < 10; i++){
            if(idx==nA+nB && i==0 && nC!=1) continue;
            C[idx-nA-nB] = '0'+i;
            if(dfs(idx+1, a, b, 10*c+i)) return true;
        }
        C[idx-nA-nB] = 'X';
    }
    return false;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> op >> B >> as >> C;
    nA = A.size(), nB = B.size(), nC = C.size();
    dfs(0, 0, 0, 0);
    cout << A << " " << B << " " << C << "\n";
    return 0;
}