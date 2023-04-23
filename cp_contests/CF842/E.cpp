#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<ll,ll>;
const ll MAXN = 3e6+2;
ll MOD = 1;
ll fact[MAXN];
unordered_map<ll,ll> inv;
void init(){
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;
}

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

ll modInverse(ll a)
{
    if(inv.find(a) != inv.end()) return inv[a];
    return inv[a] = binpow(a, MOD - 2);
}

ll nPk(ll n, ll k){
    return (fact[n] * modInverse(fact[n - k])) % MOD ;
}

ll nCk(ll n, ll k){
    return (fact[n] * modInverse(fact[n - k])) % MOD * modInverse(fact[k]) % MOD;
}

void solve(){
    ll n;
    cin >> n >> MOD;
    init();
    ll cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
    
    cnt1 = fact[2 * n] * 2 - fact[n] - 1;
    cnt1 = (cnt1 % MOD + MOD) % MOD;
    cnt2 = nPk(2 * n, n) * fact[2 * n] * 2;
    cnt2 %= MOD;
    for(int i = 0; i <= n; i++){
        // nPi * n C i * (2 * n - i) P n * (2 * n - i)!
        // cnt2 += nPk(n, i) * nCk(n, i) % MOD * nPk(2 * n - i, n) % MOD * fact[2 * n - i] % MOD;
        cnt2 -= nCk(n,i) * nCk(n, n - i) % MOD * nPk(2 * n - i, n) % MOD * binpow(fact[n],2) % MOD;
        cnt2 = (cnt2 % MOD + MOD) % MOD;
    }
    /*
    1 2 3 - 0
    1 3 2 - 1
    2 1 3 - 1
    3 1 2 - 2
    2 3 1 - 2 
    3 2 1 - 3
    */
    // 1 - 0
    // 3 - 1
    // 2 - 2
    // 1 - 3
    cnt2 = cnt2 - cnt1 - 1;
    cnt2 = (cnt2 % MOD + MOD) % MOD;
    
    cnt3 = fact[3 * n] - cnt1 - cnt2 - 1;
    cnt3 = (cnt3 % MOD + MOD) % MOD;
    
    ans = cnt1 + cnt2 * 2 + cnt3 * 3;
    ans %= MOD;
    cout << ans << '\n';

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();
}