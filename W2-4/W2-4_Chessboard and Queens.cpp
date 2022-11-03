#include<bits/stdc++.h>
using namespace std;
const int N = 8, MASK = (1<<N)-1;
int dfs(int i, int M, int L, int R, vector<int>& A){
    if(i == 8) return 1;
    int res = 0, legal = MASK&~(M|L|R|A[i]);
    for(int num = 0; legal; legal ^= num){
        num = legal&-legal;
        res += dfs(i+1, M|num, (L|num)<<1, (R|num)>>1, A);
    }
    return res;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < N; j++)
            if(tmp[j] == '*') A[i] |= 1<<j;
    }
    cout << dfs(0, 0, 0, 0, A) << "\n";
    return 0;
}