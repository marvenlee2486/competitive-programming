#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr ld inf = 1e12;
struct node
{
    ll l, r, vl, vr;
    ll lid, rid;
    ld dis;
    bool operator>(const node &ano) const
    {
        if (dis != ano.dis)
            return dis > ano.dis;
        else if (lid != ano.lid)
            return lid < ano.lid;
        else
            return rid < ano.rid;
    }
    bool operator<(const node &ano) const
    {
        if (dis != ano.dis)
            return dis < ano.dis;
        else if (lid != ano.lid)
            return lid > ano.lid;
        else
            return rid > ano.rid;
    }
    node(ll nl, ll nr, ll nvl, ll nvr, ll idl, ll idr) : l(nl), r(nr), vl(nvl), vr(nvr), lid(idl), rid(idr)
    {
        assert(l < r);
        assert(lid < rid);
        if (vl == 0 && vr == 0)
        {
            dis = inf;
        }
        else if (vl >= 0 && vr <= 0)
        {
            dis = (r - l) * 1.0 / (abs(vl) + abs(vr));
        }
        else if (vl >= 0 && vr >= 0)
        {
            if (vl > vr)
            {
                dis = (r - l) * 1.0 / (vl - vr);
            }
            else
            {
                dis = inf;
            }
        }
        else if (vl <= 0 && vr <= 0)
        {
            if (abs(vr) > abs(vl))
            {
                dis = (r - l) * 1.0 / (abs(vr) - abs(vl));
            }
            else
            {
                dis = inf;
            }
        }
        else
        {
            dis = inf;
        }
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ll n;
    cin >> n;
    set<node> st;
    vector<ll> x(n), v(n), l(n), r(n), vis(n, 0);
    for (ll i = 0; i < n; ++i)
    {
        cin >> x[i] >> v[i];
        l[i] = i - 1;
        r[i] = i + 1;
    }
    for (ll i = 0; i + 1 < n; ++i)
    {
        node tmp = node(x[i], x[i + 1], v[i], v[i + 1], i, i + 1);
        st.insert(tmp);
    }
    while (!st.empty())
    {
        node cur = *st.begin();
        // cout<<cur.lid<<" "<<cur.rid<<" "<< cur.dis<<"\n";
        if (cur.dis >= inf / 2)
            break;
        st.erase(cur);
        assert(!vis[cur.lid] && !vis[cur.rid]);
        vis[cur.lid] = vis[cur.rid] = 1;
        // change left
        assert(r[cur.lid] == cur.rid);
        assert(l[cur.rid] == cur.lid);
        if (l[cur.lid] != -1)
        {
            ll L = cur.lid;
            ll LL = l[L];
            r[LL] = r[cur.rid];
            assert(LL < L);
            node tmp = node(x[LL], x[L], v[LL], v[L], LL, L);

            st.erase(tmp);
        }
        if (r[cur.rid] != n)
        {
            ll R = cur.rid;
            ll RR = r[R];
            l[RR] = l[cur.lid];
            assert(R < RR);
            node tmp = node(x[R], x[RR], v[R], v[RR], R, RR);
            st.erase(tmp);
        }
        if (l[cur.lid] != -1 && r[cur.rid] != n)
        {
            ll L = l[cur.lid], R = r[cur.rid];
            assert(r[L] == R && r[R] == L);
            node tmp = node(x[L], x[R], v[L], v[R], L, R);
            st.emplace(tmp);
        }
    }
    ll ans = 0;
    for (auto &i : vis)
    {
        if (i == 0)
            ans++;
    }
    cout << ans << "\n";
    for (ll i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
}