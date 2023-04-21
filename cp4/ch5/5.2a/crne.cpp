#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    ll n;
    cin >> n;

    ll ans = (n/2 + 1)*((n+1)/2 + 1);
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    // int t;
    // while(cin >> t)
    //     solve(t);
}