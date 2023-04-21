#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr ld eps = 1e-16;
ll cross(pair<ll, ll> x, pair<ll, ll> y) {
  return x.first * y.second - y.first * x.second;
}
bool side(pair<ll, ll> x, pair<ll, ll> y, pair<ll, ll> z) {
  return cross({y.first - x.first, y.second - x.second},
               {z.first - y.first, z.second - y.second}) >= 0;
}
pair<ll, ll> s, e;
ll len(pair<ll, ll> x, pair<ll, ll> y) {
  return (y.first - x.first) * (y.first - x.first) +
               (y.second - x.second) * (y.second - x.second);
}

ll recos(ll a, ll b, ll c) {
  return (a + b - c) / sqrtl(a);
}
pair<ld, ld> cal(pair<ll, ll> x) {
  ll d = len(s, e);
  ll L = len(s, x);
  ll R = len(e, x);
  return {recos(L, d, R), recos(R, d, L)};
}
int discrete(vector<pair<ll, ll>> &vec) {
  vector<pair<ld, ld>> v;
  v.reserve(vec.size());
  for (auto i : vec) {
    v.emplace_back(cal(i));
  }
  vector<ld> a;
  for (auto &[l, r] : v) {
    a.emplace_back(l);
    a.emplace_back(r);
  }
  set<ld> st;
  map<ld, ll> mp;
  int n = 0;
  sort(a.begin(), a.end());
  for (auto i : a) {
    auto it = st.lower_bound(i - eps);
    if (it != st.end() && *it - i < eps) {
      mp[i] = mp[*it];
    } else {
      st.emplace(i);
      mp[i] = ++n;
    }
  }
  for (int i = 0; i < (int)vec.size(); ++i) {
    vec[i].first = mp[v[i].first];
    vec[i].second = mp[v[i].second];
  }
  return n;
}
struct SegmentTree {
  struct segt {
    ll l, r;
    ll ans;
  };
  vector<segt> T;

  SegmentTree(ll n) { // don't forget to call build.
    T.resize(n << 2);
  }

  segt combine(segt l, segt r) {
    segt res;
    res.l = l.l, res.r = r.r;
    res.ans = l.ans + r.ans; // TODO
    return res;
  }

  void build(ll l, ll r, ll o = 1) {
    T[o].l = l, T[o].r = r;
    if (l == r)
      T[o].ans = 0; // TODO
    else {
      ll m = (l + r) >> 1;
      build(l, m, o << 1), build(m + 1, r, o << 1 | 1);
      T[o] = combine(T[o << 1], T[o << 1 | 1]);
    }
  }

  segt query(ll l, ll r, ll o = 1) {
    assert(l <= r);
    if (T[o].l == l && T[o].r == r)
      return T[o];
    else {
      ll m = (T[o].l + T[o].r) >> 1;
      if (r <= m)
        return query(l, r, o << 1);
      else if (l >= m + 1)
        return query(l, r, o << 1 | 1);
      return combine(query(l, m, o << 1), query(m + 1, r, o << 1 | 1));
    }
  }

  void update(ll tx, ll nx, ll o = 1) { // singly update
    if (T[o].l == T[o].r)               // TODO
      T[o].ans++;
    else {
      ll m = (T[o].l + T[o].r) >> 1;
      if (tx <= m)
        update(tx, nx, o << 1);
      else
        update(tx, nx, o << 1 | 1);
      T[o] = combine(T[o << 1], T[o << 1 | 1]);
    }
  }
};
ll solve(vector<pair<ll, ll>> &vec, int mx) {
  SegmentTree a(mx);
  a.build(1, mx);
  sort(vec.begin(), vec.end());
  ll ans = 0;
  for (auto &[l, r] : vec) {
    ans += a.query(1, r).ans;
    a.update(r, 1);
  }
  return ans;
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> s.first >> s.second >> e.first >> e.second;
  if (s.first > e.first) {
    swap(s, e);
  }
  int n;
  cin >> n;
  vector<pair<ll, ll>> p(n);
  for (auto &[x, y] : p) {
    cin >> x >> y;
  }
  vector<pair<ll, ll>> above, below;
  for (auto i : p) {
    if (side(s, e, i)) {
      above.emplace_back(i);
    } else {
      below.emplace_back(i);
    }
  }
  ll ans = 0;
  int mx = discrete(above);
  if (mx)
    ans += solve(above, mx);
  mx = discrete(below);
  if (mx)
    ans += solve(below, mx);
  cout << ans << "\n";
}