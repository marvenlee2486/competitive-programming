#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD = 1e9 + 7;

void solve(){
    int x;
    cin >> x;
    string s;
    cin >> s;
    ll ans = s.size();
    for(int i = 0 ; i < x ; i ++ ){
        if(s.size() < x*2 +1 && s[i]!='1'){
            string add = s.substr(i+1,s.size()-i-1);
            for(int j = 0; j < s[i]-'1'; j++) s+=add;
        }
        ans = (ans-1) * (s[i]-'0');
        ans %= MOD;
    }
    cout << (ans + x)%MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("angle1.in", "r", stdin);
    //freopen("angle1.out", "w", stdout);
    int t=1;
    cin >> t;
    while(t--)
    solve();
}