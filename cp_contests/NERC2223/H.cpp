#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;


const ll maxn = 2005; // TODO
ll a[maxn];
struct segt{
    ll l, r;
    ll ans; // TODO
}T[maxn<<2];

segt combine(segt l, segt r) {
    segt res; res.l = l.l, res.r = r.r;
    res.ans = l.ans + r.ans;// TODO
    return res;
}

void build(ll o, ll l, ll r) {
    T[o].l = l, T[o].r = r;
    if (l == r) T[o].ans = a[l]; // TODO
    else {
        ll m = (l + r) >> 1;
        build(o<<1, l, m), build(o<<1|1, m+1, r);
        T[o] = combine(T[o << 1], T[o << 1 | 1]);
    }
}

segt query(ll o, ll l, ll r) {
    if (T[o].l == l && T[o].r == r) return T[o];
    else {
        ll m = (T[o].l + T[o].r) >> 1;
        if (r <= m) return query(o<<1, l, r);
        else if (l >= m+1) return query(o<<1|1, l, r);
        return combine(query(o << 1, l, m), query(o << 1 | 1, m + 1, r));
    }
}

void update(ll o, ll tx, ll nx) { // singly update
    if (T[o].l == T[o].r) T[o].ans += nx;
    else {
        ll m = T[o].l + T[o].r >> 1;
        if (tx <= m) update(o << 1, tx, nx);
        else update(o << 1 | 1, tx, nx);
        T[o] = combine(T[o << 1], T[o << 1 | 1]);
    }
}

ll actualQuery(ll x) {
    return query(1, 1, x).ans;
}

void actualUpdate(ll l, ll r, ll d) {
    update(1, l, d);
    update(1, r + 1, -d); // make sure extra space
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> p(n), h(n, 1), in(n), out(n), vis(n);
  for (auto &i : p) {
    cin >> i;
  }
  vector<vector<int>> E(n), revE(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v); // u earlier than v
    revE[v].emplace_back(u);
    in[v]++, out[u]++;
  }


  vector< unordered_set<int> > isbefore(n, unordered_set<int>());
  
  function<void(int)> dfsh = [&](int u) {
    for (auto v : E[u]) {
      h[v] += h[u];
      in[v]--;
      for(auto u2: isbefore[u])
        isbefore[v].insert(u2);
      isbefore[v].insert(u);
      if (in[v] == 0) {
        dfsh(v);
      }
    }
  };

  
  function<void(int)> dfsp = [&](int u) {
    vis[u] = 1;
    for (auto v : revE[u]) {
      p[v] = min(p[v], p[u] - 1);
      out[v]--;
      if (out[v] == 0) {
        dfsp(0);
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    if (in[i] == 0 && h[i] == 1) {
      dfsh(i);
    }
    if (out[i] == 0 && !vis[i]) {
      dfsp(i);
    }
  }
  vector<ii> arr(n);
  for (int i = 0; i < n; ++i) {
    arr[i] = ii(p[i] - h[i],i);
    cout << h[i] << " " << p[i] << "\n";
    //cout << i << " HERE "<< h[i] << "\n";
    // for(int v:isbefore[i]) cout << v << " ";
    // cout <<'\n';
  }
sort(arr.begin(),arr.end());
vector<ll> idv(n);
for(int i = 0; i < n; i++) {a[i+1] = arr[i].first; idv[arr[i].second] = i;}

// for(int i = 1 ; i <=n ; i++) cout << a[i] << " ";




for(int aa = 0; aa < n; aa++){
    build(1,1,n+3);
    int idx = idv[aa];
    int ans = h[idx];

    actualUpdate(1,n, -1 * h[idx] );
    // cout << arr[1].second << "\n";
    //assert(isbefore[idx].size() == h[idx]);
    for(int i = 0; i < n; i++){
        if( isbefore[idx].find(arr[i].second) != isbefore[idx].end()) continue;

        // cout << i << " " << "\n";
        // cout << i+1 << " ";
        // cout << actualQuery(i+1) + (int)isbefore[arr[i].second].size() << " :: " << (int)isbefore[arr[i].second].size() << " NEXT ";
        // cout << "\n";
        if( actualQuery(i+1) +(int)isbefore[arr[i].second].size() >= 0) continue;
        ans++;
        
        actualUpdate(1,n,-1);
    }
    
    cout << ans << " ";

}






}