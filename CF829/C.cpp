#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll qpow(ll x, ll y){
    ll res = 1;
    while (y) {
        if (y & 1) {
        res = res * x % MOD;
        }
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}


ll inv(ll x) {
    return qpow(x, MOD-2) % MOD;
}

ll frac(ll x, ll y) {
    x %= MOD;
    y %= MOD;
  return x * inv(y) % MOD;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> a (n, 0);
    ll n0 = 0, ni0 = 0;
    for(ll i = 0 ; i < n ; i ++ ){
        cin >> a[i];
        n0 += a[i]==0;
    }
    for(ll i = 0 ; i < n0; i++){
        ni0 += a[i]==0;
    }
    ll dp = 0;
    // cout << ni0 << " " << n0 << "\n";
    for(ll i = ni0; i< n0; i++){
        dp += frac( n * (n-1)/2 , (n0-i)*(n0-i)  );
        dp %= MOD;
    }
    cout << dp << "\n";

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}