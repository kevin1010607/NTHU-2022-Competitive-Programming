#include<bits/stdc++.h>
using namespace std;
struct Cat{
    string name;
    int pos, age;
    bool operator<(const Cat b){
        if(pos != b.pos) return pos > b.pos;
        if(age != b.age){
            if(pos == 5) return age > b.age;
            else return age < b.age;
        }
        return name > b.name;
    }
};
int getP(string& s){
    if(s == "elder") return 1;
    if(s == "nursy") return 2;
    if(s == "kit") return 3;
    if(s == "warrior") return 4;
    if(s == "appentice") return 5;
    if(s == "medicent") return 6;
    if(s == "deputy") return 7;
    if(s == "leader") return 8;
    return -1;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, age;
    while(cin >> n >> m){
        vector<Cat> C(n);
        string pos;
        for(int i = 0; i < n; i++){
            cin >> C[i].name >> pos >> C[i].age;
            C[i].pos = getP(pos);
        }
        sort(C.rbegin(), C.rend());
        for(int i = 0; i < min(m, n); i++)
            cout << C[i].name << "\n";
    }
    return 0;
}