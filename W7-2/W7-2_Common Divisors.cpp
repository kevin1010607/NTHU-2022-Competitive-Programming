#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, A[1000001] = {}, m = 0, res = 1, val;
    cin >> n;
    while(n--){
        cin >> val;
        m = max(m, val);
        A[val]++;
    }
    for(int i = 2; i <= m; i++){
        int cnt = 0;
        for(int j = i; j <= m; j += i)
            cnt += A[j];
        if(cnt >= 2) res = i;
    }
    cout << res << "\n";
    return 0;
}