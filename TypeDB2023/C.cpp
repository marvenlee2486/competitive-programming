#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n, 0);
    vector<ll> maxv(n, 0);
    vector<ll> minv(n, 0);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(s >= a[i]) minv[i] = 0, maxv[i] = a[i];
        else minv[i] = min(s, a[i] - s), maxv[i] = max(s, a[i] - s);
    }
    vector< vector<ll> >dp(n, vector<ll>(2));
    dp[1][0] = a[0] * minv[1];
    dp[1][1] = a[0] * maxv[1];
    for(int i = 2; i < n - 1; i++){
        dp[i][0] = min(dp[i - 1][0] + maxv[i - 1] * minv[i], dp[i - 1][1] + minv[i - 1] * minv[i]);
        dp[i][1] = min(dp[i - 1][0] + maxv[i - 1] * maxv[i], dp[i - 1][1] + minv[i - 1] * maxv[i]);
    }
    ll ans = min(dp[n - 2][0] + maxv[n - 2] * a[n - 1], dp[n - 2][1] + minv[n - 2] * a[n - 1]);
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}