#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, val;
    unordered_map<int, int> m;
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> val;
        if(m.count(x-val)){
            cout << m[x-val] << " " << i << "\n";
            return 0;
        }
        m[val] = i;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}