#include<bits/stdc++.h>
using namespace std;
const int N = 7, DIR[5] = {-1, 0, 1, 0, -1};
bool seen[N][N];
bool illegal(int x, int y){
    return (x==0||seen[x-1][y])&&(x==N-1||seen[x+1][y])&&(y!=0&&!seen[x][y-1])&&(y!=N-1&&!seen[x][y+1]) || \
            (y==0||seen[x][y-1])&&(y==N-1||seen[x][y+1])&&(x!=0&&!seen[x-1][y])&&(x!=N-1&&!seen[x+1][y]);
}
int dfs(int idx, int x, int y, string& s){
    if(x==N-1 && y==0) return idx == N*N-1;
    int res = 0;
    seen[x][y] = true;
    if(s[idx] != '?'){
        int i = s[idx]-'0';
        int nx = x+DIR[i], ny = y+DIR[i+1];
        if(!(nx<0||nx>=N||ny<0||ny>=N||seen[nx][ny]||illegal(nx, ny)))
            res = dfs(idx+1, nx, ny, s);
    }
    else{
        for(int i = 0; i < 4; i++){
            int nx = x+DIR[i], ny = y+DIR[i+1];
            if(nx<0||nx>=N||ny<0||ny>=N||seen[nx][ny]||illegal(nx, ny)) continue;
            res += dfs(idx+1, nx, ny, s);
        }
    }
    seen[x][y] = false;
    return res;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(auto& c : s){
        if(c == 'U') c = '0';
        else if(c == 'R') c = '1';
        else if(c == 'D') c = '2';
        else if(c == 'L') c = '3';
    }
    cout << dfs(0, 0, 0, s) << "\n";
    return 0;
}