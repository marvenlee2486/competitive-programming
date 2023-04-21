#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e9;
void solve(){
    ll n,k,m,c,d;
    cin >> n >> k >> m >> c >> d;
    vector<ll> a(n, 0);
    for(auto&i : a) cin >> i;
    ll l = 0, r = INF * INF;
    while(l < r){
        // cout << l << " " << r << "\n";
        ll mid = (l + r + 1) / 2;
        // cout << mid << '\n';
        vector<ll> req(n, 0);
        ll cur = 0;
        for(ll i = 0; i < n; i++){
            req[i] = max(0ll, mid - a[i]);
            if(req[i] == 0) cur++;
            else if(d != 0){
                if( req[i] <= c) req[i] = 1;
                else req[i] = (req[i] - c + d - 1)/d + 1;
            }else{
                if( req[i] <= c) req[i] = 1;
                else req[i] = m + 2;
            }
            
        }
        // for(ll i = 0; i < n; i++) cout << req[i] << " ";
        // cout << "\n";
        ll maxv = cur;
        vector<ll> maybe(n + m + 10, 0);
        // cout << "HERE\n";
        for(ll i = 0; i < m; i++){
            if(req[i] != 0 && req[i] <= (i + 1)){
                maybe[  (i + 1) - req[i] + m]++;
                cur++;
            }
        }
        maxv = cur;
        for(ll i = m; i < n; i++){
            
            if(req[i] != 0 && req[i] <= m){
                cur++;
                maybe[ i + m - req[i] + 1]++;
            }
            cur -= maybe[i];
            maxv = max(maxv, cur);
        }
        // cout << maxv << "\n";
        if(maxv >= k) l = mid;
        else r = mid - 1;


    }
    cout << l << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}