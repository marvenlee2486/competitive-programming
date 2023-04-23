#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)
#define ld long double

#define EPS 1e-8


void solve(){
    cout << "500 500 1000000 1\n";
    for(int i = 0; i < 500*500; i++) cout << "0 ";
    ll ans = 500*500;
    ans *= 1000000;
    cout <<"\n" << ans <<"\n";    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
