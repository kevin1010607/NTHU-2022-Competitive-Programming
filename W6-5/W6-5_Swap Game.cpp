#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>& A){
    for(int i = 0; i < 9; i++)
        if(A[i] != i+1) return false;
    return true;
}
int H(vector<int>& A){
    int res = 0;
    for(int i = 0; i < 9; i++)
        res += abs((A[i]-1)/3-i/3)+abs((A[i]-1)%3-i%3);
    return res/2;
}
struct S{
    int g, h;
    vector<int> A;
    bool operator>(const S& s) const{
        return g+h > s.g+s.h;
    }
};
struct Hash{
    size_t operator()(const vector<int>& A) const{
        int res = 0, p = 1;
        for(auto& i : A)
            res += i*p, p *= 10;
        return res;
    }
};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int DIR[12][2] = {{0,1},{1,2},{3,4},{4,5},{6,7},{7,8},{0,3},{3,6},{1,4},{4,7},{2,5},{5,8}};
    vector<int> A(9);
    for(auto& i : A) cin >> i;
    priority_queue<S, vector<S>, greater<S>> q;
    unordered_set<vector<int>, Hash> s;
    q.push({0, H(A), A});
    s.insert(A);
    while(!q.empty()){
        auto [g, h, V] = q.top(); q.pop();
        if(check(V)){
            cout << g << "\n";
            return 0;
        }
        for(int i = 0; i < 12; i++){
            swap(V[DIR[i][0]], V[DIR[i][1]]);
            if(!s.count(V)){
                s.insert(V);
                q.push({g+1, H(V), V});
            }
            swap(V[DIR[i][0]], V[DIR[i][1]]);
        }
    }
    return 0;
}