#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n,m;
    cin >> n >> m;
    m--;
    vector<ll> a(n, 0);
    for(auto&i : a) cin >> i;
    ll ans = 0;
    ll cur = 0;
    priority_queue<ll> pq;
    for(int i = m; i > 0; i--){
        cur += a[i];
        if(a[i] > 0) pq.push(a[i]);
        while(cur > 0){
            ans++;
            cur -= pq.top() * 2;
            pq.pop();
        }
    }
    

    while(!pq.empty()) pq.pop();
    cur = 0;
    for(int i = m + 1; i < n; i++){
        cur += a[i];
        if(a[i] < 0) pq.push(abs(a[i]));
        while(cur < 0){
            ans++;
            cur += pq.top() * 2;
            pq.pop();
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}