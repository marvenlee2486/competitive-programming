// n * (n - 1) * n !

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 2;
ll fact[N];
const ll MOD = 1e9 + 7;

/*
1 2 3 3 2 1 - 2 + 4 = 6 
1 3 2 2 3 1 - 2 + 4 = 6
2 1 3 3 1 2 - 1 + 3 + 2 = 6
3 1 2 2 1 3 - 1 + 1 + 1 + 3 = 6
2 3 1 1 3 2 - 2 + 2 + 2 
3 2 1 1 2 3 - 1 + 2 + 2 + 1 = 6

0, 2, 6 ,
*/
void solve(){
    ll n;
    cin >> n;
    // 0, 2, 4 + ... 
    // 2(1 + .. n -1 )
    // 1 + 2 + 3 = 3 * 4 / 2;
    ll ans = (n) * (n - 1) % MOD;
    ans  = ans * fact[n] % MOD;
    cout << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    fact[0] = 1;
    for(ll i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % MOD;
    while(t--) solve();
}