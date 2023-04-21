#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve(){
    ll n;
    cin >> n;
    vector<vector<int> > graph(n);
    vector<ii> range(n,ii(0,0));
    for(int i = 1; i < n; i++){
        int p; cin >> p;
        p--;
        graph[p].push_back(i);
    }
    for(auto&[l,r]:range) cin >> l >> r;
    ll ans = 0;
    function<ll(ll)> dfs = [&](ll u) {
       ll sum = 0;
       for(int v: graph[u]){
        sum += dfs(v);
       }
       if(sum < range[u].first){
        ans ++;
        return range[u].second;
       }
       return min(sum,range[u].second);
    };

    dfs(0);
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}

