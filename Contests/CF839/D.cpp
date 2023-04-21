#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve(){
    int n; cin >> n;
    vector<ll> a(n,0);
    for(auto&i:a)cin >> i;
    ll first = a[0];
    ll second = -1;
    for(int i = 0; i < n; i++){
        if(first != a[i]) {
            second = a[i];
            break;
        }
    }
    if(second == -1){
        cout << "0\n";
        return;
    }

    ll mid = (first + second )/ 2;
    for(ll x = mid - 2; x <= mid + 2; x++){
        if(x < 0) continue;
        bool gg = false;
        for(int i = 1; i < n; i++){
            if( abs(a[i] - x) < abs(a[i - 1] - x) ){
                gg = true;
                break;
            }
        }
        if(!gg){
            cout << x << "\n";
            return;
        }

    }
    cout << "-1\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}

