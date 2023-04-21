#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<double, int>;
ll maxv = 1e18 + 2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    cin >> n >> q;
 
    ll a[n + 1];
    ll dp[n * n + n + 2];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = a[i];
    }
    for (int i = n + 1; i <= n * n + n; i++)
    {
        dp[i] = maxv;
        for (int j = 1; j <= n; j++)
        {
            dp[i] = min(dp[i], dp[i - j] + a[j]);
        }
    }
 
    while (q--)
    {
        ll x;
        cin >> x;
        if (x <= n * n)
        {
            cout << dp[x] << "\n";
            continue;
        }
        ll cnt = maxv;
        for (ll i = 1; i <= n; ++i)
        {
            ll mx = i;
            ll dif = x - n * n;
            ll num = dif / mx;
            ll ans = num * a[i];
            ans += dp[x - mx * num];
            cnt = min(cnt, ans);
        }
        cout << cnt << "\n";
    }
}