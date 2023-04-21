#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > graph;
string s;

void solve(){
    int n;
    cin >> n;
    graph.assign(2 * n, vector<int>());

    cin >> s;
    int cur = n;
    for(int i = 0; i < n - 1; i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        graph[cur].emplace_back(v);
        graph[v].emplace_back(cur);
        cur++;
        s+='$';
    }

    for(int i = 0; i < n; )

}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
