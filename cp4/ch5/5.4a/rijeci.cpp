#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    int dp[k + 1][2];
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i = 1; i <= k; i++){
        dp[i][0] = dp[i-1][1];
        dp[i][1] = dp[i-1][0] + dp[i-1][1];
    }
    cout << dp[k][0] <<  " " << dp[k][1] << "\n";
}