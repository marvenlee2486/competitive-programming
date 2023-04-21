#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll dp[n + 1][2];
        dp[0][0] = 1;
        dp[0][1] = 0;

        for(int i = 1; i <= n; i++){
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
            dp[i][1] = dp[i - 1][0];
        }
        cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
    }
}