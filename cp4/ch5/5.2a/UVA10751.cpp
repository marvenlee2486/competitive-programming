#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    ll n;
    cin >> n;
    ll dia = 0;
    if(n == 1) {
        cout << "0.000\n";
        return;
    }
    else if(n == 2) {
        cout << "4.000\n";
        return;
    }
    dia = ((n/3) * 2 + (n % 3 == 2) - (((n/3) + (n%3 != 0)) % 2)) * (n - 2);

    ll str = n * n - dia;
    ld ans = str + sqrt(2) * 1.0 * dia;
    //cout << dia << " ";
    cout << fixed << setprecision(3) << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
        if(t) cout << "\n";
    }
}