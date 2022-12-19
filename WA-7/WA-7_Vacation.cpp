#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, c;
    cin >> n;
    int na = 0, nb = 0, nc = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        int ta = a+max(nb, nc);
        int tb = b+max(na, nc);
        int tc = c+max(na, nb);
        na = ta, nb = tb, nc = tc;
    }
    cout << max({na, nb, nc}) << "\n";
    return 0; 
}