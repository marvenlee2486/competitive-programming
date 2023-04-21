#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 9;
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
const int N = 1e5 + 2;
ll p2[N];

void solve(){
    ll n;
    cin >> n;
    ll x = p2[n] - 1;
    if(x < 0) x += MOD;
    ll ans = binpow(2, x);
    ll up = ((ans - x + MOD) % MOD);
    ll down = modInverse(ans);
    cout << up << " " << down << " " << ans << "\n";
    ans = up * down % MOD;
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    p2[0] = 1;
    for(int i = 1; i < N; i++) p2[i] = p2[i - 1] * 2 % MOD;

    
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}