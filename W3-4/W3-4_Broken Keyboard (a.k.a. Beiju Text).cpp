#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(cin >> s){
        s += "#";
        string t;
        bool in = false;
        deque<string> d;
        for(auto c : s){
            if(c=='[' || c==']' || c=='#'){
                if(in) d.emplace_front(t);
                else d.emplace_back(t);
                t = "", in = c=='[';
            }
            else t += c;
        }
        for(auto& i : d) cout << i;
        cout << "\n";
    }
    return 0;
}