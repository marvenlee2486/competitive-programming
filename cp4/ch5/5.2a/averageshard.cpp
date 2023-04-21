#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    int nc,ne;
    cin >> nc >> ne;
    vector<int> cs (nc, 0);
    vector<int> e (ne, 0);
    ll sc = 0,se = 0;
    for(auto&i: cs) {
        cin >> i;
        sc += i;
    }
    for(auto&i: e) {
        cin >> i;
        se += i;
    }

    ll ans = 0;
    ld pac = sc * 1.0 / nc , pae = se * 1.0 / ne;
    for(auto&i : cs){
        ld ac = (sc - i) * 1.0 / (nc - 1);
        ld ae = (se + i) * 1.0 / (ne + 1);

        ans +=  (ac > pac && ae > pae);
    }
    cout << ans << "\n";


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}