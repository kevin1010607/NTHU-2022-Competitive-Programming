#include<bits/stdc++.h>
using namespace std;
void print(int b, int n){
    for(int i = n-1; i >= 0; i--)
        cout << ((b>>i)&1);
    cout << "\n";
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, b = 0;
    cin >> n;
    while(b != (3<<(n-1))){
        print(b, n);
        b ^= 1;
        print(b, n);
        b ^= (b&(-b))<<1;
    }
    return 0;
}