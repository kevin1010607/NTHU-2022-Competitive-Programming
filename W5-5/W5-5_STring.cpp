#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char c;
    stack<char> s;
    while(cin >> c){
        if(!s.empty() && s.top()=='S' && c=='T') s.pop();
        else s.push(c);
    }
    cout << s.size() << "\n";
    return 0;
}