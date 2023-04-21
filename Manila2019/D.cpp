#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    s = "\0" + s;
    map<string, int> dict;
    int d;
    cin >> d;
    for(int i = 0; i < d; i++){
        string ss; int c;
        cin >> ss >> c;
        dict[ss] = c;
    }

    int dp[n + 1][n + 1];
    // dp is 1 - index;
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    
    for(int i = 1; i <= n; i++){
        dp[i] = 0;
        for(auto& [ss,val]: dict){
            if(i - ss.size() < 0) continue;
            bool can = true;
            int cnt = ss.size() - 1;
            int j = i;
            while(cnt >= 0 && j > 0){
                if(ss[cnt] == s[j]){
                    cnt--;
                }
                j--;
            }
            if(j == 0) continue;
            dp[i] = max(dp[i], dp[j - 1] + val);
        }
    }
    cout << dp[n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}