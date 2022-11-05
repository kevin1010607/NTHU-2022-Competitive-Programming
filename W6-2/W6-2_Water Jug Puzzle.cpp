#include<bits/stdc++.h>
using namespace std;
bool check(int Q, vector<int>& A){
    for(auto i : A) if(i == Q) return true;
    return false;
}
struct Hash{
    size_t operator()(const vector<int>& A) const{
        int res = 0, p = 1;
        for(auto& i : A) 
            res += i*p, p *= 61;
        return res;
    }
};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, Q, res = 0;
    cin >> n;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    cin >> Q;
    queue<vector<int>> q;
    unordered_set<vector<int>, Hash> s;
    q.push(vector<int>(n));
    s.insert(vector<int>(n));
    while(!q.empty()){
        for(int i = q.size()-1; i >= 0; i--){
            auto V = q.front(); q.pop();
            if(check(Q, V)){
                cout << res << "\n";
                return 0;
            }
            for(int j = 0; j < n; j++){
                int tmp = V[j];
                // type 1
                V[j] = A[j];
                if(!s.count(V)){
                    s.insert(V);
                    q.push(V);
                }
                V[j] = tmp;
                // type 2
                V[j] = 0;
                if(!s.count(V)){
                    s.insert(V);
                    q.push(V);
                }
                V[j] = tmp;
                // type 3
                for(int k = j+1; k < n; k++){
                    int tmp_k = V[k];
                    // j to k
                    int k_new = min(V[j]+V[k], A[k]);
                    V[j] = V[j]+V[k]-k_new, V[k] = k_new;
                    if(!s.count(V)){
                        s.insert(V);
                        q.push(V);
                    }
                    V[j] = tmp, V[k] = tmp_k;
                    // k to j
                    int j_new = min(V[j]+V[k], A[j]);
                    V[k] = V[j]+V[k]-j_new, V[j] = j_new;
                    if(!s.count(V)){
                        s.insert(V);
                        q.push(V);
                    }
                    V[j] = tmp, V[k] = tmp_k;
                }
            }
        }
        res++;
    }
    cout << "-1\n";
    return 0;
}