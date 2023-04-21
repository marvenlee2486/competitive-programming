#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    ll n, m;
    cin >> n >> m;

    // n - 1 + n - 2 + n - 3 + .. n - m - 1;

    ll ans = m * (m - 1) - (m - n) * (m - n - 1);
    ans /= 2;
    cout << ans << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}