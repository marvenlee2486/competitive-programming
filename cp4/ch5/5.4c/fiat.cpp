#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll N = 200002;
ll fact[N];

ll binpow(ll a, ll b) {
    ll res = 1;

    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        res%=MOD;
        a%=MOD;
        b >>= 1;
    }
    return res%MOD;
}

ll inv(ll n){
  return binpow(n, MOD - 2);
    

}

ll nCk(ll n, ll k){
    return fact[n] * inv(fact[k]) % MOD * inv(fact[n - k]) % MOD;
}

int main(){
    fact[0] = 1;
    for(int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD;

    int n;
    cin >> n;

    ll ans = (nCk(2 * n, n) - nCk(2 * n, n + 1) + MOD) % MOD;
    cout << ans << "\n";
}