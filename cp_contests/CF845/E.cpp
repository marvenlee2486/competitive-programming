#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
const ll INF = 1e9;

void solve(){
    int n,m;
    cin >> n >> m;
    int maxv = 0;
    vector<tuple<ll,ll,ll>> el;
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        maxv = max(maxv, w);
        el.emplace_back(u,v,w);
    }
    function<bool(ll)> can = [&](ll c)->bool {
        vector<vector<int> > graph(n, vector<int>());
        for(auto&[u,v,w]:el){
            graph[u].emplace_back(v);
            if(w <= c) graph[v].emplace_back(u);
        }

        int cnt = 0, nscc = 0;
        vector<int> dfs_num(n, -1), dfs_low(n, 0), visited(n, 0);
        stack<int> st;
        unordered_map<int, int> low2in;
        function<void(ll)> tarjan = [&](ll u){
            //cout << "INF\n";
            dfs_low[u] = dfs_num[u] = cnt;
            cnt++;
            st.push(u);
            visited[u] = 1;
            for(ll v: graph[u]){
                // cout << u << " " << v << "\n";
                if(dfs_num[v] == -1) tarjan(v);
                if(visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            }
            if(dfs_low[u] == dfs_num[u]){
                low2in[dfs_low[u]] = nscc;
                nscc++;
                while(1){
                    int v = st.top(); st.pop();
                    visited[v] = 0;
                    dfs_low[v] = dfs_low[u];
                    if(u == v) break;
                }
            }
        };
        for(int i = 0; i < n; i++) if(dfs_num[i] == -1) tarjan(i);
        // for(int i = 0; i < n; i++){
        //     cout << i + 1 << " : ";
        //     for(int v: graph[i]) cout << v + 1<< " ";
        //     cout << '\n';
        // }
        // for(int i = 0; i < n; i++){
        //     cout << dfs_num[i] << " " << dfs_low[i] << "\n";
        // }
        unordered_set<int> candi;
        for(int i = 0; i < nscc; i++) candi.emplace(i);
        vector<vector<int> > cgraph(nscc, vector<int>());
        // for(auto[u,v]: low2in) cout << u << " " << v << '\n';
        for(int u = 0; u < n; u++){
            for(int v: graph[u]){
                if(dfs_low[v] == dfs_low[u]) continue; 
                // cout << u << " " << v << " " << dfs_low[u] << " " << dfs_low[v] << "\n";
                cgraph[low2in[dfs_low[u]]].emplace_back(low2in[dfs_low[v]]);
                candi.erase(low2in[dfs_low[v]]);
            }
        }
        // for(int i = 0; i < nscc; i++){
        //     cout << i << " : ";
        //     for(int v: cgraph[i]){
        //         cout << v << " ";
        //     }
        //     cout << '\n';
        // }
        vector<int> vis(nscc,0);
        function<void(ll,ll)> dfs = [&](ll u, ll anc) {
            //cout << "INF2\n";
            if(vis[u]) return;
            vis[u] = 1;
            for(int v: cgraph[u]){
                if(v == anc) continue;
                dfs(v,u);
            }
        };
        dfs(*candi.begin(), -1);

        for(int i = 0; i < nscc; i++) if(vis[i] == 0) return false;
        return true;
    };
    if(!can(INF)) {
        cout << "-1\n";
        return;
    }
    ll l = 0, r = maxv;
    while(l < r){
        ll m = (r + l)/2;
        if(can(m)){
            r = m;
        }else{
            l = m + 1;
        }
    }
    cout << l << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}