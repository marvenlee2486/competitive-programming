#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
int main(){
    ll n,m;
    cin >> n >> m;
    priority_queue<ii> pq;
    vector<ll> ans(n,-1);
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        pq.emplace(a,i);
    }

    while(!pq.empty()){
        auto[a,idx] = pq.top();
        pq.pop();
        if(ans[idx] != -1) continue;
        ans[idx] = a;
        if(idx != 0) pq.emplace(a - m,idx - 1);
        if(idx != n - 1) pq.emplace(a - m, idx + 1);
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";

}