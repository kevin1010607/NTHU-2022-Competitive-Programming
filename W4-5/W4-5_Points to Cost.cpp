#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, c, sum_x = 0;
    cin >> n >> c;
    vector<int> X(n), Y(n);
    for(int i = 0; i < n; i++){
        cin >> X[i] >> Y[i];
        sum_x += X[i];
    }
    double res = 0, mean = (double)sum_x/n;
    for(int i = 0; i < n; i++)
        res += (mean-X[i])*(mean-X[i])+(double)(c-Y[i])*(c-Y[i]);
    cout << setprecision(10) << fixed << res << "\n";
    return 0;
}