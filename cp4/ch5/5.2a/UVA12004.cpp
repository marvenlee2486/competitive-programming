#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;



void solve(){
    ll n;
    cin >> n;
    ll ans = n * n - n;
    if(ans % 4 == 0) cout << ans/4;
    else{
        cout << ans/__gcd(ans,4ll) << "/" << 4/__gcd(ans,4ll);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;

    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
        cout << "\n";
    }
}