#include<bits/stdc++.h>
#define Pii pair<int, int>
using namespace std;
int dt(int a, int b){
    return abs(a/5-b/5)+abs(a%5-b%5);
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, M = INT_MAX;
        cin >> n;
        vector<Pii> A(n);
        vector<int> res(5, INT_MAX);
        for(int i = 0; i < n; i++){
            int x, y, v;
            cin >> x >> y >> v;
            A[i] = {x*5+y, v};
        }
        for(int a = 0; a < 25; a++){
            for(int b = a+1; b < 25; b++){
                for(int c = b+1; c < 25; c++){
                    for(int d = c+1; d < 25; d++){
                        for(int e = d+1; e < 25; e++){
                            int N = 0;
                            for(auto [i, v] : A){
                                int D = min({dt(i, a), dt(i, b), dt(i, c), dt(i, d), dt(i, e)});
                                N += D*v;
                            }
                            if(N<M || N==M&&vector<int>{a, b, c, d, e}<res){
                                M = N;
                                res = vector<int>{a, b, c, d, e};
                            }
                        }
                    }
                }
            }
        }
        cout << res[0] << " " << res[1] << " " << res[2] << " " << res[3] << " " << res[4] << "\n";
    }
    return 0;
}
