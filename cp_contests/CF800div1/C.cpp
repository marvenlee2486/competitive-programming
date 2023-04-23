#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve(){
    ll n, m;
    cin >> n >> m;

    vector< unordered_map<ll,ll> > graph(n);
    vector< unordered_map<ll,ll> > out_graph(n);
    vector<ll> tot(n);
    for(int i = 0; i < m; i++){
        ll u,v;
        cin >> u >> v;
        u--,v--;
        tot[u]++;
        graph[u][v] += 1;
        out_graph[v][u] += 1;
    }
    // The main point is we have to remove > dist[u] only. no need care the smaller one haha
    priority_queue<ii> pq;
    pq.emplace(0, n - 1);
    vector<ll> dist(n, INF);
    vector< unordered_map<ll,ll> > rec(n);
    dist[n - 1] = 0;
    while(!pq.empty()){
        auto[d, u] = pq.top();
        pq.pop();
        d = -d;
        //cout << "d = " <<  d << ", u = " << u << '\n';
        if(dist[u] != d) continue;

        for(auto[v,cnt] : out_graph[u]){
            tot[v] -= cnt;
            if(dist[v] > dist[u] + tot[v] + 1){
                dist[v] = dist[u] + tot[v] + 1;
                pq.emplace( - dist[v],v);
            }
            
        }
    }
    cout << dist[0] << "\n";
    // assert(dist[n-1] != INF);
    // cout << dist[n-1] << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}

