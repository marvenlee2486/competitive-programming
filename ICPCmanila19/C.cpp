#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD = 1e9 + 7;
vector< vector<ii> > graph;
ll minv= 0,maxv=0;
ll k;
ii dfs(int u, int anc = -1){
    
    int edge = 0;
    int num = 1;
    for(auto&[v,w]: graph[u] ){
        if(v==anc) continue;
        ll fi,se;
        ii res = dfs(v,u);
        fi = res.first;
        se = res.second;
        if(fi){
            edge ++;
            minv += w;
        }
        maxv += min(2*k - se, se) * w;
        num += se;
    }
    return ii(edge%2 == 0,num);
}

void solve(){
    minv= 0,maxv=0;
    cin >> k;
    graph.assign(2*k,vector<ii> ());

    for(int i = 0; i <2*k-1; i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        graph[u].emplace_back(v,w);
        graph[v].emplace_back(u,w);
    }

    dfs(0);
    cout << minv << " " << maxv << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("angle1.in", "r", stdin);
    //freopen("angle1.out", "w", stdout);
    int t=1;
    cin >> t;
    while(t--)
    solve();
}