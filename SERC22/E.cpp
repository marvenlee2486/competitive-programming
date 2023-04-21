#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<ii> a;
    for(int i = 0; i < 2 * n; i++){
        ll x; cin >> x;
        a.emplace_back(x, i);
    }
    sort(a.begin(),a.end());
    ll ans = 0;
    ll dp[n];
    ll cost[n];
    bool target[n];
    for(int i = 0; i < n; i++){
        ans += abs(a[2 * i + 1].first - a[2 * i].first);
        
        target[i] = a[2 * i + 1].second/2 == a[2 * i].second/2;

        if(i != 0) cost[i] = 2 * abs(a[2 * i].first - a[2 * i - 1].first);
        // if(i == 0) ans += 2 * abs(a[2 * i + 2].first - a[2 * i + 1].first);
        // else if(i == n - 1) ans += 2 * abs(a[2 * i].first - a[2 * i - 1].first);
        // else ans += 2 * min(abs(a[2 * i].first - a[2 * i - 1].first), abs(a[2 * i + 2].first - a[2 * i + 1].first));
    }
    dp[0] = 0;
    if(target[0]) dp[0] = cost[1];
    if(target[0] || target[1]){
        dp[1] = cost[1];
    }
    else{
        dp[1] = 0;
    }
    
    for(int i = 2; i < n; i++){
        if(target[i]){
            dp[i] = min(dp[i - 2] + cost[i], dp[i - 1] + cost[i]);
        }
        else{
            dp[i] = dp[i-1];
            if(target[i - 1]){
                dp[i] = min(dp[i], dp[i - 2] + cost[i]);
            }
        }
    }
    cout << ans + dp[n - 1] << "\n";
}