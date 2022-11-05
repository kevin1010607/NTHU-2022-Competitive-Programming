#include<bits/stdc++.h>
#define P pair<int, int>
#define F first
#define S second
using namespace std;
const string D = "URDL";
const int DIR[5] = {-1, 0, 1, 0, -1};
string get_path(int eX, int eY, int sX, int sY, vector<vector<int>>& path){
    string res = "";
    while(eX!=sX || eY!=sY){
        int dir = path[eX][eY];
        res += D[dir];
        eX -= DIR[dir], eY -= DIR[dir+1];
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n, sX, sY, res = 0;
    cin >> m >> n;
    vector<string> A(m);
    vector<vector<int>> path(m, vector<int>(n));
    queue<P> q, mq;
    for(int i = 0; i < m; i++){
        cin >> A[i];
        for(int j = 0; j < n; j++){
            if(A[i][j] == 'A') sX = i, sY = j, A[i][j] = '#';
            if(A[i][j] == 'M'){
                mq.push({i, j});
                A[i][j] = '#';
            }
        }
    }
    q.push({sX, sY});
    while(!q.empty()){
        for(int i = mq.size()-1; i >= 0; i--){
            auto [x, y] = mq.front(); mq.pop();
            for(int j = 0; j < 4; j++){
                int nx = x+DIR[j], ny = y+DIR[j+1];
                if(nx<0||nx>=m||ny<0||ny>=n||A[nx][ny]!='.') continue;
                A[nx][ny] = '#';
                mq.push({nx, ny});
            }
        }
        for(int i = q.size()-1; i >= 0; i--){
            auto [x, y] = q.front(); q.pop();
            if(x==0||x==m-1||y==0||y==n-1){
                cout << "YES\n" << res << "\n" << get_path(x, y, sX, sY, path) << "\n";
                return 0;
            }
            for(int j = 0; j < 4; j++){
                int nx = x+DIR[j], ny = y+DIR[j+1];
                if(nx<0||nx>=m||ny<0||ny>=n||A[nx][ny]!='.') continue;
                A[nx][ny] = '#';
                path[nx][ny] = j;
                q.push({nx, ny});
            }
        }
        res++;
    }
    cout << "NO\n";
    return 0;
}