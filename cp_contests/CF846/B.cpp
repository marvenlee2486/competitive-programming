#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll sum = 0;
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    for(auto&i : a){
        cin >> i;
        sum += i;
    }
    ll cur = 0;
    ll ans = 1;
    for(int i = 0; i < n - 1; i++){
        sum -= a[i];
        cur += a[i];
        ans = max(ans,__gcd(cur,sum));
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}