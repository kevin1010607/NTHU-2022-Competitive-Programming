#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, val, mid = -1;
    cin >> n;
    priority_queue<int> L;
    priority_queue<int, vector<int>, greater<int>> R;
    for(int i = 0; i < n; i++){
        cin >> val;
        if(mid == -1) mid = val;
        else{
            if(val < mid){
                if(L.size()+1 == R.size()) L.push(val);
                else{
                    L.push(val);
                    R.push(mid);
                    mid = L.top(); L.pop();
                }
            }
            else{
                if(L.size()+1 == R.size()){
                    R.push(val);
                    L.push(mid);
                    mid = R.top(); R.pop();
                }
                else R.push(val);
            }
        }
        cout << mid << " \n"[i==n-1];
    }
    return 0;
}