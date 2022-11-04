#include<bits/stdc++.h>
using namespace std;
int ceil(int a, int b){
    return (a+b-1)/b;
}
int refuel(int M, int c, int d){
    if(M >= c) return 0;
    return ceil(c-M, d);
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d, M, S, T, s = 0, t = INT_MAX;
    cin >> a >> b >> c >> d >> M >> S >> T;
    for(int i = 0; b*(i-1)<S && i+refuel(M, c*i, d)<=T; i++){
        int b_t = i+refuel(M, c*i, d), a_t = T-b_t;
        int ss = b*i+a*a_t;
        s = max(s, ss);
        if(ss >= S){
            int tt = b_t+ceil(S-b*i, a);
            t = min(t, tt);
        }
    }
    if(s >= S) cout << "Yes\n" << t << "\n";
    else cout << "No\n" << s << "\n";
    return 0;
}