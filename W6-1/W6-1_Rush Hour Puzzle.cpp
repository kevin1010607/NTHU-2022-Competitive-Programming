#include<bits/stdc++.h>
#define ll long long
#define N 6
using namespace std;
ll encode(vector<int>& A, int n){
    ll res = 0;
    for(int i = 1; i <= n; i++)
        res = (N*N)*res+A[i];
    return res;
}
void decode(ll p, int n, vector<int>& pos){
    for(int i = n; i >= 1; i--)
        pos[i] = p%(N*N), p /= (N*N);
}
void change(vector<int>& pos, vector<int>& lenX, vector<int>& lenY, vector<vector<int>>& A){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            A[i][j] = 0;
    for(int i = 1; i < pos.size(); i++){
        int x = pos[i]/N, y = pos[i]%N;
        for(int j = 0; j <= lenX[i]; j++) A[x+j][y] = i;
        for(int j = 0; j <= lenY[i]; j++) A[x][y+j] = i; 
    }
}
int check(int p, int len, vector<vector<int>>& A){
    for(int i = p+len+1; i < N; i++)
        if(A[2][i]) return 0;
    return N-p;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 0, res = 0;
    vector<vector<int>> A(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
            n = max(n, A[i][j]);
        }
    }
    vector<int> pos(n+1, -1), lenX(n+1), lenY(n+1);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(A[i][j]==0 || pos[A[i][j]]!= -1) continue;
            pos[A[i][j]] = i*N+j;
            if(j+1<N && A[i][j]==A[i][j+1]){
                if(j+2<N && A[i][j]==A[i][j+2]) lenY[A[i][j]] = 2;
                else lenY[A[i][j]] = 1;
            }
            else{
                if(i+2<N && A[i][j]==A[i+2][j]) lenX[A[i][j]] = 2;
                else lenX[A[i][j]] = 1;
            }
        }
    }
    if(lenX[1] || pos[1]/N!=2) {cout << "-1\n"; return 0;}
    queue<ll> q;
    unordered_set<ll> s;
    q.push(encode(pos, n));
    s.insert(encode(pos, n));
    while(!q.empty() && res<=10-(lenY[1]+1)){
        for(int i = q.size()-1; i >= 0; i--){
            decode(q.front(), n, pos); q.pop();
            change(pos, lenX, lenY, A);
            int step = check(pos[1]%N, lenY[1], A);
            if(step){
                if(res+step <= 10) cout << res+step << "\n";
                else cout << "-1\n";
                return 0;
            }
            for(int j = 1; j <= n; j++){
                int x = pos[j]/N, y = pos[j]%N;
                if(lenX[j]){
                    if(x!=0 && !A[x-1][y]){
                        pos[j] = (x-1)*N+y;
                        ll p = encode(pos, n);
                        if(!s.count(p)) q.push(p), s.insert(p);
                    }
                    if(x+lenX[j]!=N-1 && !A[x+lenX[j]+1][y]){
                        pos[j] = (x+1)*N+y;
                        ll p = encode(pos, n);
                        if(!s.count(p)) q.push(p), s.insert(p);
                    }
                }
                if(lenY[j]){
                    if(y!=0 && !A[x][y-1]){
                        pos[j] = x*N+(y-1);
                        ll p = encode(pos, n);
                        if(!s.count(p)) q.push(p), s.insert(p);
                    }
                    if(y+lenY[j]!=N-1 && !A[x][y+lenY[j]+1]){
                        pos[j] = x*N+(y+1);
                        ll p = encode(pos, n);
                        if(!s.count(p)) q.push(p), s.insert(p);
                    }
                }
                pos[j] = x*N+y;
            }
        }
        res++;
    }
    cout << "-1\n";
    return 0;
}