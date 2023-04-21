#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr ld eps = 1e-16;

/*
-1000000000 -1000000000 -999999999 -999999999
9
1000000000 1000000000
999999999 999999999
999999998 999999998
1000000000 999999999
999999999 999999998
999999998 999999997
999999999 1000000000
999999998 999999999
999999997 999999998

*/
ll gcd(ll a, ll b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
using ii = pair<ll,ll>;
ii fminus(ii x, ii y){
    // cout << "LEFT : " << x.first << " " << x.second << "\n";
    // cout << "RIGHT : " << y.first << " " << y.second << "\n";
    ll down = x.second * y.second;
    ll up = abs(x.first * y.second  - y.first * x.second);
    ll g = gcd(up,down);
    // cout << "MINUS " << up << " " << down << " " << g << "\n";
    return {up/g, down/g};
}

ll cross(pair<ll, ll> x, pair<ll, ll> y) {
  return x.first * y.second - y.first * x.second;
}
bool side(pair<ll, ll> x, pair<ll, ll> y, pair<ll, ll> z) {
  return cross({y.first - x.first, y.second - x.second},
               {z.first - y.first, z.second - y.second}) >= 0;
}
pair<ll, ll> s, e;
ll len(pair<ll, ll> x, pair<ll, ll> y) {
  return ((y.first - x.first) * (y.first - x.first) +
               (y.second - x.second) * (y.second - x.second));
}
// ll recos(ll a, ll b, ll c) {
//     // cosine rule , c^2 = b^2 + a^2 - 2*a*b cos tita. Find tita
//     // cout << fixed << a << " " << b << ' ' << c << "\n";
//   return ((a  - c + b   ) );/// sqrtl(a) );
// }

ii gradient(pair<ll,ll> l, pair<ll, ll> r){
//     cout << (l.second - r.second) << " " << (l.first - r.first) << "\n";
//     cout << (1.0 * (l.second - r.second) / (l.first - r.first)) << " GAA\n"; 
    int mul = 1;
    if(l.first - r.first < 0)  mul = -1;

    ll down = mul * (l.first - r.first);
    ll up = mul * (l.second - r.second);
    ll g = gcd(abs(up),abs(down));

    return  ii( up/g, down/g );
}
pair<ii, ii> cal(pair<ll, ll> x) {
//   ll d = len(s, e);
//   ll L = len(s, x);
//   ll R = len(e, x);
  // cout << "L " << L << ", R " << R << "\n";
  //cout << recos(L,d, R) << " "<< recos(R,d,L) << "\n";
  //return {recos(L, d, R), recos(R, d, L)};
  ii gra = gradient(s,e);
  return { fminus (gradient(s,x), gra) , fminus(gradient(e,x) , gra) };
}
int discrete(vector<pair<ll, ll>> &vec) {
  vector<pair<ii, ii>> v;
  ii gra = gradient(s,e);
  // cout << gra.first << " " << gra.second << "\n";
  v.reserve(vec.size());
  for (auto i : vec) {
    v.emplace_back(cal(i));
    cout << "I : " <<  i.first << " " << i.second << "\n";
  }
  vector<ii> a;
  for (auto &[l, r] : v) {
    cout << fixed << l.first << " / " << l.second << "\n";
    // cout << fixed << r.first << " / " << r.second << "\n";
    a.emplace_back(l);
    a.emplace_back(r);
  }
  auto cmp = [](auto l, auto r) { return l.first*r.second < r.first*l.second; };
  set<ii, decltype(cmp)> st;
  map<ii, ll> mp;
  int n = 0;
  sort(a.begin(), a.end(), cmp);
  for (auto i : a) {
    auto it = st.lower_bound(i);
    if (it != st.end() && *it == i) {
      mp[i] = mp[*it];
    } else {
      st.insert(i);
      mp[i] = ++n;
    }
  }
  for (int i = 0; i < (int)vec.size(); ++i) {
    vec[i].first = mp[v[i].first];
    vec[i].second = mp[v[i].second];
    cout << vec[i].first << " " << vec[i].second << "\n";

  }
  cout << n << "\n";
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