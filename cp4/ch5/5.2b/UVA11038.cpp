#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
ll dp[32];

ll f(string n){
    if(n.size() == 0) return 1;
    if(n.size() == 1) return 1;
    
    return f(n.substr(1, n.size() - 1)) * (n[0] - '0') + dp[n.size() - 1];
}

ll f(ll n){
    string s = "";
    while(n != 0){
        char c = n % 10 + '0';
        s = c + s;
        n /= 10;
    } 
    return f(s);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll n,m;
    
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < 32; i++) dp[i] = dp[i-1] * 10;
    for(int i = 0; i < 32; i++) cout << i << " " << dp[i] << "\n";
    for(int i = 0; i <= 100; i++) cout << i << " " << f(i) << "\n";

    while(cin >> n >> m && m >= 0){
        cout << f(m) << " " << f(n-1) << " ";
        cout << f(m) - f(n - 1) << "\n";
    }
}