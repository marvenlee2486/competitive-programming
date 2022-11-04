#include <bits/stdc++.h>
using namespace std;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n), G(max(n, m) * 2);
  vector<int> vis(max(n, m) * 2, 0), id(max(n, m) * 2, 0);
  for (int i = 0; i < m * 2; ++i) {
    id[i] = i;
    vis[i] = 0;
  }
  set<pair<int, int>> st;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  int node_id = n;
  function<void(int, int)> build = [&](int u, int fa) {
    vis[u] = 1;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      if (vis[v] && !st.contains({u, v})) {
        st.emplace(u, v);
        st.emplace(v, u);
        G[u].emplace_back(node_id);
        G[node_id].emplace_back(u);
        id[node_id] = v;
        node_id++;
      } else if (!vis[v]) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        build(v, u);
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      build(i, i);
    }
  }
  vector<tuple<int, int, int>> ans;
  fill(vis.begin(), vis.end(), 0);
  vector<int> used(node_id, 0);
  // Here used[i] shows whether i is used or not

  function<void(int, int)> dfs = [&](int u, int fa) {
    vis[u] = 1;
    vector<int> tmp;
    for (auto v : G[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      if (!used[v])
        tmp.emplace_back(v);
    }
    if (tmp.size() % 2 == 0) {
      for (int i = 0; i < tmp.size(); i += 2) {
        ans.emplace_back(tmp[i], u, tmp[i + 1]);
      }
    } else {
      used[u] = 1;
      if (fa != -1)
        ans.emplace_back(tmp[0], u, fa);
      for (int i = 1; i < tmp.size(); i += 2) {
        ans.emplace_back(tmp[i], u, tmp[i + 1]);
      }
    }
  };
  for (int i = 0; i < node_id; ++i) {
    // cout << i + 1 << " " << id[i] + 1 << ": ";
    // for(auto v: G[i]){
    //   cout<<v+1<<" ";
    // }
    // cout << "\n";
    if (!vis[i])
      dfs(i, -1);
  }
  cout << ans.size() << "\n";
  for (auto &[l, mid, r] : ans) {
    cout << id[l] + 1 << " " << id[mid] + 1 << " " << id[r] + 1 << "\n";
  }
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
