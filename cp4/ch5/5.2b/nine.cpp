#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
ll qpow(ll x, ll y){
    ll ans = 1;
    while(y > 0){
        if(y & 1) ans =  ans * x;
        x = x * x;
        ans %= MOD;
        x %= MOD;
        y /= 2;
    }
    return ans;
}
void solve(){
    ll d;
    cin >> d;
    ll cur = 8;
    // 8 * 9 ^ (d - 1) % p;
    cur = 8 * qpow(9,d - 1) % MOD;
    cout << cur << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}