#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)
 
const int maxn = 500005; // TODO
 
struct segt{
	int l, r;
	ll ans; // TODO
    ll lazy;
}T[maxn<<2];
 
segt combine(segt l, segt r) {
	segt res; res.l = l.l, res.r = r.r, res.lazy = 0;
	res.ans = l.ans + r.ans;
	return res;
}
 
void build(int o, int l, int r) {
	T[o].l = l, T[o].r = r, T[o].lazy = 0;
	if (l == r) T[o].ans = 0;
	else {
		int m = (l + r) >> 1;
		build(o<<1, l, m), build(o<<1|1, m+1, r);
		T[o] = combine(T[o << 1], T[o << 1 | 1]);
	}
}
 
void ddl(int o) {
    if (T[o].l != T[o].r) {
        auto &ls = T[o << 1], &rs = T[o << 1 | 1];
        ls.lazy += T[o].lazy, ls.ans += T[o].lazy * (ls.r - ls.l + 1);
        rs.lazy += T[o].lazy, rs.ans += T[o].lazy * (rs.r - rs.l + 1);
    }
    T[o].lazy = 0;
}
 
segt query(int o, int l, int r) {
    ddl(o);
	if (T[o].l == l && T[o].r == r) return T[o];
	else {
		int m = (T[o].l + T[o].r) >> 1;
		if (r <= m) return query(o << 1, l, r);
		else if (l >= m + 1) return query(o << 1 | 1, l, r);
		return combine(query(o << 1, l, m), query(o << 1 | 1, m + 1, r));
	}
}
 
void update(int o, int l, int r, ll dx) {
    ddl(o);
	if (T[o].l == l && T[o].r == r) T[o].lazy += dx, T[o].ans += dx * (r - l + 1);
	else {
		int m = (T[o].l + T[o].r) >> 1;
		if (r <= m) update(o<<1, l, r, dx);
		else if (l >= m + 1) update(o << 1 | 1, l, r, dx);
		else update(o << 1, l, m, dx), update(o << 1 | 1, m + 1, r, dx);
        T[o] = combine(T[o << 1], T[o << 1 | 1]);
	}
}
 
 
ll n, q; 
int getKth(ll k) { // binary search over prefix kth
    int lo = 1, hi = n;
    while (lo < hi) {
        int mi = lo + hi >> 1;
        if (query(1, 1, mi).ans >= k) hi = mi;
        else lo = mi + 1;
    }
    return lo;
}
 
void solve(){
    cin >> n >> q;
    int swt[n+1]; FOR(i, 1, n) cin >> swt[i];
 
    build(1, 1, n);
 
    FOR(tq, 1, q) {
        int cnt; cin >> cnt;
        vector<tuple<int, int, int>> segs;
        FOR(ttup, 1, cnt) {
            ll u, v, x; cin >> u >> v >> x;
            segs.emplace_back(u, v, x);
            update(1, u, v, x);
        }
 
        ll totalCnt = query(1, 1, n).ans;
        ll dblAns = swt[getKth((totalCnt + 1) / 2)];
        if (totalCnt % 2 == 0) dblAns += swt[getKth(totalCnt / 2 + 1)];
        cout << (totalCnt % 2 ? (double)dblAns : (double)dblAns / 2.0) << '\n';
 
        for (auto [u, v, x]: segs) update(1, u, v, -x);
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    solve();
    return 0;
}