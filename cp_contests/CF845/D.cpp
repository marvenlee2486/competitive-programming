#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 2;
const ll MOD = 1e9 + 7;
ll pow2[N];
void init(){
    pow2[0] = 1;
    for(int i = 1; i < N; i++) pow2[i] = pow2[i - 1] * 2 % MOD;
}

void solve(){
    ll n;
    cin >> n;
    ll ans = 0;
    // vector<ll> depth(n, 0);
    vector<vector<ll> > graph(n, vector<ll>());
    for(int i = 0; i < n - 1; i++){
        int u,v;
        cin >> u >> v;
        u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    // vector<vector<ll> > depend(n, vector<ll>());
    function<ll(ll,ll)> dfs = [&](ll u, ll anc) -> ll{
        ll dept = 0, nc = 0, cur = 1;
        map<ll,ll> off;

        for(int v: graph[u]){
            if(v == anc) continue;
            
            ll temp = dfs(v,u) + 1;
            dept = max(dept, temp);
            if(off.find(temp) == off.end()) off[temp] = 0;
            off[temp] += 1;
            nc++;
        }

        ans += pow2[n - 1];
        ans %= MOD;

        for(auto&[nxt,cnt]: off){
            ans += (((nxt - cur + 1) * pow2[nc - 1] ) % MOD * (pow2[n - nc]) ) % MOD;
            //cout << cur << " " << nxt << " " << nc << " " << ans <<"\n";
            ans %= MOD;
            nc -= cnt;
            cur = nxt + 1;
        }

        return dept;
    };
    dfs(0, -1);
    cout << ans << "\n";
}

int main(){
    init();
    int t = 1;
    cin >> t;
    while(t--) solve();
}