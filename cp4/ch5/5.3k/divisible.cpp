#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// (SUM - prefix) % d == 0
// SUM % d - prefix % d == 0
// SUM % d = prefix % d
void solve(){
    ll d,n;
    cin >> d >> n;
    unordered_map<ll, ll> mp;
    ll ans = 0;
    ll cur = 0;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        cur += a;
        cur %= d;
        if(mp.find(cur) == mp.end()) mp[cur] = 0;
        ans += mp[cur];
        if(cur == 0) ans ++;
        mp[cur] += 1;
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}