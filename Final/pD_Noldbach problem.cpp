#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, res = 0;
    cin >> n;
    // sieve
    vector<int> prime;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++){
        if(is_prime[i]) prime.push_back(i);
        for(auto j : prime){
            if(i*j > n) break;
            is_prime[i*j] = false;
            if(i%j == 0) break;
        }
    }
    // count
    unordered_set<int> s(prime.begin(), prime.end());
    for(int i = 1; i < prime.size(); i++)
        if(s.count(prime[i]+prime[i-1]+1)) res++;
    cout << res << "\n";
    return 0;
}