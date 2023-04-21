#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector< vector<int> > graph(n, vector<int>());
    for(auto& i: a) cin >> i;
    for(int i = 1; i < n; i++){
        int p; cin >> p; p--;
        graph[p].emplace_back(i);
    }
    // vector<int> dp[n][32];
    vector<int> val(n, 0);
    vector<int> size(n, 1);
    function<vector<vector<int> >(int)> dfs = [&](int u)->vector<vector<int> > {
        if(graph[u].size() == 0){
            val[u] = a[u];
            vector<vector<int> > ret(32, vector<int>());
            return ret;
        }

        int cur = a[u];
        vector< vector<int> > udp(32);
        for(int v: graph[u]){
            vector< vector<int> > vdp = dfs(v);

            cur ^= val[v];
            size[u] += size[v];

            vector< vector<int> > ndp(32);
            for(int i = 0; i < 32; i++){
                if(vdp[i].size() == 0) continue;
                // cout << u + 1 << " " << v + 1 << " " << i  << '\n';
                if(udp[i].size() == 0 && ndp[i].size() == 0) ndp[i] = vdp[i];    
                for(int j = 0; j < 32; j++){
                    if(udp[j].size() == 0 || udp[j ^ i].size() != 0 || ndp[j ^ i].size() != 0) continue;
                    ndp[j ^ i] = udp[j];
                    for(int x: vdp[i])
                        ndp[j ^ i].emplace_back(x);
                }
                
            }
            for(int j = 0; j < 32; j++){
                if(ndp[j].size() != 0) udp[j] = ndp[j];
            }

        }
        // cout << u + 1 << " " << size[u] << '\n';
        val[u] = cur;
        if(size[u] % 2 == 0){
            udp[cur].clear();
            udp[cur].emplace_back(u);
        }
        return udp;
    };
    vector<vector<int> > dp = dfs(0);
    int final = val[0];
    if(final == 0){
        cout << "1\n1\n";
        return;
    }
    // cout << final << '\n';
    if(dp[final].size() == 0) cout << "-1\n";
    else{
        cout << dp[final].size() + (final != 0) << '\n';
        for(int v: dp[final]) cout << v + 1 << " ";

        if(final != 0) cout << "1";
        cout << '\n';
        
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}