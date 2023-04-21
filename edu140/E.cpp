#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> c(n, 0);
    vector<int> p(m, 0);
    for(auto& i: c) {
        cin >> i;
        i--;
    }

    for(auto&i: p) cin >> i;

    vector<int> dp(n+1 , 0);
    dp[0] = p[c[0]];
    dp[1] = dp[0] + p[c[1]];
    for(int i = 2; i < n; i++){
        dp[i] = min(dp[i-1],dp[i-2]) + p[c[i]];
    }
    cout << dp[n-1] << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}