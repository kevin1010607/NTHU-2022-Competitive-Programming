#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, A[1000001] = {}, m = 0, res = 0, val;
    cin >> n;
    while(n--){
        cin >> val;
        m = max(m, val);
        A[val]++;
    }
    // sieve
    vector<int> prime, spf(m+1), mobius(m+1);
    vector<bool> is_prime(m+1, true);
    is_prime[0] = is_prime[1] = false;
    mobius[1] = 1;
    for(int i = 2; i <= m; i++){
        if(is_prime[i]){
            prime.push_back(i);
            spf[i] = i;
            mobius[i] = -1;
        }
        for(auto j : prime){
            if(i*j > m) break;
            is_prime[i*j] = false;
            spf[i*j] = j;
            mobius[i*j] = spf[i]==j?0:-mobius[i];
            if(i%j == 0) break;
        }
    }
    // solve
    for(int i = 1; i <= m; i++){
        ll cnt = 0;
        for(int j = i; j <= m; j += i)
            cnt += A[j];
        res += cnt*(cnt-1)/2*mobius[i];
    }
    cout << res << "\n";
    return 0;
}