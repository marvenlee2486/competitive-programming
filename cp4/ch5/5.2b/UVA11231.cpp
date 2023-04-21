#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll n,m,l;
    while(cin >> n >> m >> l && n){
        ll ans = ((n - (1 - l) < 8)? 0 : (n - (1 - l) - 8)/2 + 1 ) *
                    ((m - (1 - l) < 8)? 0 : (m - (1 - l) - 8)/2 + 1 );

        cout << ans << "\n";
    }
    
}