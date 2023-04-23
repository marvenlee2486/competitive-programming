#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)
#define ld long double

#define EPS 1e-8
#define EQ(a, b) (fabsl((a) - (b)) <= EPS) //!!! please be EXTRA PARANOID WITH BRACKETS ... I fucking spend 10+ hour debug partly because of this
#define GEQ(a, b) (EQ(a, b) || a > b)
#define LEQ(a, b) (EQ(a, b) || a < b)
#define GT(a, b) (!EQ(a, b) && a > b)
#define LT(a, b) (!EQ(a, b) && a < b)
const ld pi = acos(-1);
void solve(){
    ll n; cin >> n;
    vector<pair<ll, ll>> pts(n + 1); FOR(i, 1, n) cin >> pts[i].first >> pts[i].second;
    ld ans = 1e16; //  large enuf!
    FOR(i, 1, n) {
        auto [x, y] = pts[i];
        // 1. check if possible
        bool gg = false;
        FOR(j, 1, n) if (i != j && pts[j].first >= pts[i].first && pts[j].second >= pts[i].second) {
            gg = true;
            break;
        }
        if (gg) continue;
        
        // 2. find answer
        vector<pair<ld, ld>> angles;
        FOR (j, 1, n) if (j != i) {
            auto [tx, ty] = pts[j];
            angles.emplace_back(atan2l(ty - y, tx - x), j);
        }
        sort(angles.begin(), angles.end());

        ld tAns = 0;
        // 1. take line 1
        // take closest to 0.5pi
        ld deg = 1e16;
        FOR(i, 0, (signed)angles.size() - 1) if (GEQ(angles[i].first, 0.5 * pi)) chkmin(deg, (ld)angles[i].first); // first largest closer to 0.5pi ie.. y

        // find line 1's length
        if (deg >= 1e15) tAns += x;
        else tAns += x / cosl(pi - deg);

        // 2. take line 2
        deg = -1e16;
        FOR(i, 0, (signed)angles.size() - 1) if (GEQ(angles[i].first, -0.5 * pi) && LEQ(angles[i].first, 0)) chkmax(deg, angles[i].first); // find closest to x
        if (deg <= -1e15) tAns += y;
        else tAns += y / sinl(-deg);
        
        chkmin(ans, tAns);
    }
    ll maxx =0, maxy = 0;
    for(auto[x,y]: pts){
        chkmax(maxx,x);
        chkmax(maxy,y);
    }

    chkmin(ans, (ld)maxx+maxy);

    cout << fixed << setprecision(16) << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
