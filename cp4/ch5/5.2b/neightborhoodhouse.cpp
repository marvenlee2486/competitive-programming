#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n,k;
    cin >> n >> k;
    ll cur = 0;
    ll ans = 0;
    while(k--){
        ll x;
        cin >> x;
        ans += (x - cur) * (n - x + 1);
        cur = x;
    }
    cout << ans << "\n";
}