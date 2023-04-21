#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll binpow(ll a, ll b) {
    ll res = 1;

    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        res %= MOD;
        a %= MOD;
        b >>= 1;
    }
    return res % MOD;
}

ll modInverse(ll a)
{
    return binpow(a, MOD - 2);
}
const int N = 2e5;
ll fact[N];
void solve(){
    int n;
    cin >> n;
    ll ans = 1;
    int minv = 0;
    for(int i = 0; i < n/3; i++){
        int w1,w2,w3;
        cin >> w1 >> w2 >> w3;

        minv = min(w1, w2);
        minv = min(minv, w3);

        int cnt = 0;
        if(w1 == minv) cnt++;
        if(w2 == minv) cnt++;
        if(w3 == minv) cnt++;
        ans *= cnt;
        ans %= MOD;
    }
    ans *= fact[n / 3];
    ans %= MOD;

    ans *= modInverse(fact[n / 6]);
    ans %= MOD;
     
    ans *= modInverse(fact[n / 6]);
    ans %= MOD;

    cout << ans << "\n";


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}