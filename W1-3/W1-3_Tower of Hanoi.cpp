#include<bits/stdc++.h>
using namespace std;
void solve(int a, int b, int c, int n){
    if(n == 0) return;
    solve(a, c, b, n-1);
    cout << a << " " << c << "\n";
    solve(b, a, c, n-1);
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << (1<<n)-1 << "\n";
    solve(1, 2, 3, n);
    return 0;
}