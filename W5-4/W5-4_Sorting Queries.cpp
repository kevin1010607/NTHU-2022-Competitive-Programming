#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int Q, t, x;
    cin >> Q;
    queue<int> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(Q--){
        cin >> t;
        if(t == 1){
            cin >> x;
            q.push(x);
        }
        else if(t == 2){
            if(!pq.empty()){
                cout << pq.top() << "\n";
                pq.pop();
            }
            else{
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(t == 3){
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }
    }
    return 0;
}