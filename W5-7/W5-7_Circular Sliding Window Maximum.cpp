#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    deque<int> dq;
    for(auto& i : A) cin >> i;
    for(int i = 0; i < k-1; i++) A.push_back(A[i]);
    for(int i = 0; i < A.size(); i++){
        if(!dq.empty() && dq.front()==i-k) dq.pop_front();
        while(!dq.empty() && A[dq.back()]<=A[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k-1) cout << A[dq.front()] << " \n"[i==A.size()-1];
    }
    return 0;
}