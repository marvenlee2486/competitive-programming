#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;

void solve(){
    ll n, m, k, q;
    cin >> n >> k >> m >> q;

    vector<ll> c(n + 1, 0);
    vector<ll> x(m + 1, 0);
    vector<ll> pc(n + 1, 0);
    vector<ll> px(m + 1, 0);

    for(ll i = 1; i <= n; i++) {
        cin >> c[i];
        pc[i] = c[i] + pc[i - 1];
    }

    for(ll i = 0; i <= m; i++) {
        cin >> x[i];
        if(i == 0) px[i] = x[i];
        else px[i] = x[i] + px[i - 1];
    }

    set<ll> tc, tx;
    auto connect1k = [&]()->ll {
        // return -1;
        ll ans = INF;
        if(tx.size() == 0){
            ans = min(ans, px[m]);
        }
        if(tc.size() == 0){
            ans = min(ans, pc[k - 1]);
            ans = min(ans, pc[n] - pc[k - 1]);
        }
        else{
            if(*tc.begin() >= k) ans = min(ans, pc[k - 1]);
            auto it = tc.end();
            it--;
            if(*it < k ) ans = min(ans, pc[n] - pc[k - 1]);
        }
    
        return ans;
    };
    auto travel1 = [&](ll u)->ll {
        // cout << u << " one \n";
        if(u == 1) return 0;
        else if(u == k){
            return connect1k();
        }
        else if(u < k){ // correct
            if(tc.size() == 0 || *tc.begin() >= u) return pc[u - 1];
        } 
        else if(u <= n){ // checked
            if(tc.size() == 0) return pc[n] - pc[u - 1]; 
            auto it = tc.end();
            it--;
            if(*it < u ) return pc[n] - pc[u - 1]; 
        }
        else{ // checked
            u -= n;
            if(tx.size() == 0 || *tx.begin() >= u) return px[u - 1];
        }
        return INF;

    };

    auto travelk = [&](ll u)->ll {
       //  cout << u << " k \n";
        if(u == k) return 0;
        else if(u == 1) return connect1k();
        else if(u < k){ // correct
            auto left = tc.lower_bound(u);
            if(left == tc.end() || *left >= k) return pc[k - 1] - pc[u - 1];
        }
        else if(u <= n){ // correct
            auto left = tc.lower_bound(k);
            if(left == tc.end() || *left >= u) return pc[u - 1] - pc[k - 1];
        }
        else{ // checked
            u -= n;
            if(tx.size() == 0) return px[m] - px[u - 1];
            auto it = tx.end();
            it--;
            if(*it < u) return px[m] - px[u - 1];
        }
        return INF;
    };
    while(q--){
        char ch;
        cin >> ch;

        if(ch == 'q'){
            ll u, v;
            cin >> u >> v;
            
            ll ut1, utk, vt1, vtk;
            ut1 = travel1(u);
            utk = travelk(u);
            vt1 = travel1(v);
            vtk = travelk(v);
            ll ans = INF;
            // cout << ut1 << " " << utk << "\n";
            // cout << vt1 << " " << vtk << "\n";
            // cout << connect1k() << "\n";
            ans = min(ans, ut1 + vt1);
            ans = min(ans, utk + vtk);
            ans = min(ans, ut1 + vtk + connect1k());
            ans = min(ans, utk + vt1 + connect1k());

            // when both are in the same branch
            if( u > 1 && u <= n && v > 1 && v <= n){
                if(u > v) swap(u , v);
                auto it = tc.lower_bound(u);
                if(it == tc.end() || *it >= v) ans = min(ans, pc[v - 1] - pc[u - 1]);
            }
            else if(u > n && v > n){
                u -= n;
                v -= n;
                if( u > v) swap(u, v);
                auto it = tx.lower_bound(u);
                // cout << px[v - 1] << " " << px[u - 1] << " " << (it == tc.end);
                if(it == tx.end() || *it >= v) ans = min(ans, px[v - 1] - px[u - 1]);
            }

            if(ans == INF) cout << "impossible\n";
            else cout << ans << "\n";  
        }
        
        else if(ch == 'c'){
            ll x;
            cin >> x;
            if(tc.find(x) == tc.end()) tc.insert(x);
            else tc.erase(x);
        }
        else if(ch == 'x'){
            ll x;
            cin >> x;
            if(tx.find(x) == tx.end()) tx.insert(x);
            else tx.erase(x);
        }
    }   

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();
}