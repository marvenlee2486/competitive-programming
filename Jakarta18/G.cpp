#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int,int> ii;
vector< vector<int> > graph;
vector<int> deg;
vector<int> done;
int n,m;
int getMax(){
    int maxv =0;
    int p=-1;
    for(int i = 0 ; i < n ; i++){
        if(done[i]) continue;

        if(deg[i]>maxv){
            maxv  = deg[i];
            p = i;
        }
    }
    return p;
}
bool can(int k){
  
  done.assign(n, 0);
  
  //O(N) 
  int idx = getMax();
  

    // Loop N times
  while(idx != -1){
    done[idx] = 1;
    // // O(N log N)
    vector<ii> sortd;
    for(int i = 0 ; i < deg.size() ; i++){
        sortd.emplace_back(deg[i],i);
    }
    sort(sortd.begin(),sortd.end());
    reverse(sortd.begin(),sortd.end());
    int i = idx;
    int ori = deg[i];

    // O(N)
    for(auto&[_,j]:sortd){
        if(graph[i][j] || i==j) continue;
    //cout << i << " " << j << " " << deg[i] << " " << deg[j] << "\n";
        if(deg[j]+ deg[i] >=k){
            graph[i][j] = 1;
            graph[j][i] = 1;
            deg[i]++;
            deg[j]++;
        }
    }

    // O(N)
    idx = getMax();
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j< n; j++){
        if(i==j) continue;
        if(graph[i][j] == 0) return false;
    }
  }
  return true;
  

        
}
auto solve() {
  cin >> n >> m;
  
  vector< vector<int> > ori_graph;
  vector<int> ori_deg;
  ori_deg.assign(n,0);
  ori_graph.assign(n, vector<int>(n,0));
  while(m--){
    int u,v;
    cin >> u >> v;
    u--,v--;
    ori_graph[u][v]=1;
    ori_graph[v][u]=1;
    ori_deg[u]++, ori_deg[v]++;
  }
  int l = 0, r = 2*n;
  while(l<r){
    int k = (l+r+1)/2;
    graph = ori_graph;
    deg = ori_deg;
    if(can(k)){
        l = k;
    }
    else {
        r = k-1;
    }
  }
  cout << l << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}
