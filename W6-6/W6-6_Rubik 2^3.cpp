#include<bits/stdc++.h>
using namespace std;
const int X[3][4] = {{18,21,9,1},{16,23,11,3},{12,13,15,14}};
const int Y[3][4] = {{16,12,8,4},{17,13,9,5},{0,1,3,2}};
const int Z[3][4] = {{2,12,21,7},{3,14,20,5},{8,9,11,10}};
void P(string& s){
    vector<vector<int>> A(6);
    for(int i = 0; i < s.size(); i++)
        A[s[i]-'0'].push_back(i);
    for(int i = 0; i < 6; i++)
        sort(A[i].begin(), A[i].end());
    sort(A.begin(), A.end());
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 4; j++)
            s[A[i][j]] = '0'+i;
}
string Input(){
    vector<string> in(6);
    for(auto& i : in) cin >> i;
    string res;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            if(in[i*2][j*2] == '.') continue;
            for(int a = 0; a < 2; a++){
                for(int b = 0; b < 2; b++){
                    char c = in[i*2+a][j*2+b], t;
                    if(c == 'R') t = '0';
                    else if(c == 'G') t = '1';
                    else if(c == 'B') t = '2';
                    else if(c == 'Y') t = '3';
                    else if(c == 'O') t = '4';
                    else if(c == 'W') t = '5';
                    res += t;
                }
            }
        }
    }
    if(!res.empty()) P(res);
    return res;
}
void Swap(string& s, const int C[3][4]){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 4-1; j++)
            swap(s[C[i][j]], s[C[i][j+1]]);
}
bool Check(string& s){
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 3; j++)
            if(s[i*4+j] != s[i*4+j+1]) return false;
    return true;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        string s = Input(), t;
        if(s.empty()) break;
        int res = 0, flag = false;
        queue<string> q;
        unordered_set<string> us;
        q.push(s);
        us.insert(s);
        while(!q.empty()){
            for(int i = q.size()-1; i >= 0; i--){
                s = q.front(); q.pop();
                if(Check(s)) {flag = true; break;}
                // X
                t = s;
                Swap(t, X);
                P(t);
                if(!us.count(t)){
                    us.insert(t);
                    q.push(t);
                }
                // Y
                t = s;
                Swap(t, Y);
                P(t);
                if(!us.count(t)){
                    us.insert(t);
                    q.push(t);
                }
                // Z
                t = s;
                Swap(t, Z);
                P(t);
                if(!us.count(t)){
                    us.insert(t);
                    q.push(t);
                }
            }
            if(flag) break;
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}