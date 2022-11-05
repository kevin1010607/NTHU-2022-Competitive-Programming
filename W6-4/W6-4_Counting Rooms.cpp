#include<bits/stdc++.h>
using namespace std;
int m, n, DIR[5] = {-1, 0, 1, 0, -1};
void dfs(int x, int y, vector<string>& A){
    A[x][y] = '#';
    for(int i = 0; i < 4; i++){
        int nx = x+DIR[i], ny = y+DIR[i+1];
        if(nx<0||nx>=m||ny<0||ny>=n||A[nx][ny]=='#') continue;
        dfs(nx, ny, A);
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    int res = 0;
    vector<string> A(m);
    for(auto& i : A) cin >> i;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(A[i][j] == '#') continue;
            dfs(i, j, A);
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}