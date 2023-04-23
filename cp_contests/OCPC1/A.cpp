#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll sum = 0;
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    for(auto& i: a) cin >> i;

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    ll f = a[0], s = a[1];
    sum += f * s;
    for(int i = 2; i < n; i++){
        sum += a[i] * max(f, s);
        if(f > s) f = a[i];
        else s = a[i];
    }
    sum += f * s;
    cout << sum << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}