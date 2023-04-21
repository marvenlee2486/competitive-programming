#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define FOR(i, a, b) for (ll i = a; i <= b; ++i)
#define chkmin(x, a) x = min(x, a)
#define chkmax(x, a) x = max(x, a)
#define PI = acos(1);
namespace Geometry {
    // Caution: cannot use x, y, use cout for debug, beware of the expected bugs: norm(); complex<ll>; always use ll / ld for T not integers.
    // Before Use: modify EPS
    // Notice: angle is in [-pi, pi], remainder(x, 2 * M_PI) for remainder in <cmath> to [-pi, pi]
    // Input: pt(a, b); cin >> pt only works for a+bi afaik
    // Conversion to other types: <ll> works fine against local and CF gcc; tested in nwerc21f
    // cannot use map / unordered_map; consider convert to pair for that.
    // Calculate precision and adjust EPS accordingly; sometimes this is nontrivial; 
        // there is no unsi gned long double, so if EPs is very small, consider use integer arithmetic, or change the variable you are storing.

    using T = ld;
    using pt = complex<T>;
    #define x real()
    #define y imag()

    // basic operations
    // conj(a) * b = (ax*bx + ay*by) + i (ax*by — ay*bx)
    #define dot(a, b) (conj(a) * (b)).x
    #define cross(a, b) (conj(a) * (b)).y
    #define dist_2(a, b) norm((a) - (b)) // beware precision loss bug in C++
    #define dist(a, b) abs((a) - (b))
    #define sign_area(a, b, c) (cross((b) - (a), (c) - (b))) // negative if c is rhs of AB (clockwise), zero if collinear; do not use thumb rule
    #define a_norm(a) (remainder(a, 2.0 * M_PI))

    // extra functions
    #define slope(a, b) arg((b) - (a))
    #define project_vec(p, a) ((v) * dot(p, v) / norm(v))
    #define project(p, a, b) ((a) + ((b) - (a)) * dot((p) - (a), (b) - (a)) / norm((b) - (a)))
    #define reflect(p, a, b) ((a) + conj(((p) - (a)) / ((b) - (a))) * ((b) - (a)))
    #define rotate(x, base, theta) (((x) - (base)) * polar(1.0, theta) + (base))
    #define angDiff(a, b, base) (a_norm(arg(a - base) - arg(b - base))) // positive angle yield by letting a "counter clockwise" from b. i.e. a is at left if y > 0. think a bout it.
    // floating point
    #define EPS 1e-12
    #define EQ(a, b) (fabs((a) - (b)) < EPS)

    bool clockwise(pt a, pt b, pt c, bool include_collinear) {
        T o = sign_area(a, b, c);
        return ((EQ(o, 0) && include_collinear) || (!EQ(o, 0) && o < 0));
    }

    // noncolinear tested on Kattis, Codeforces and Luogu; Luogu C++17 O2 wa/re for some reason.
    // colinear not rig. tested
    vector<pt> convexHull(vector<pt>& v, bool include_collinear = false) {
        assert(!v.empty());
        pt p0 = *min_element(v.begin(), v.end(), [](pt a, pt b) {
            return make_pair(a.y, a.x) < make_pair(b.y, b.x);
        });
        sort(v.begin(), v.end(), [&p0](const pt& a, const pt& b) {
            T o = sign_area(p0, a, b);
            if (a == b) return false;
            if (!EQ(o, 0)) return o < 0; // clockwise
            else return dist(p0, a) < dist(p0, b); 
        });
        if (include_collinear) {
            ll i = (ll)v.size() - 1;
            while (i >= 0 && EQ(sign_area(p0, v[i], v.back()), 0)) i--;
            reverse(v.begin() + i + 1, v.end());
        }

        vector<pt> ret;
        ll n = v.size();
        FOR(i, 0, n - 1) {
            while (ret.size() >= 2 && !clockwise(ret[ret.size() - 2], ret[ret.size() - 1], v[i], include_collinear)) ret.pop_back();
            ret.push_back(v[i]);
        }
        return ret;
    }

    // tested in Kattis
    T circum(vector<pt>& v) {
        T ans = 0;
        for (int i = 0; i <= (signed)v.size() - 2; ++i) ans += dist(v[i], v[i + 1]);
        ans += dist(v[0], v.back());
        return ans;
    }

}
struct IntegerDisc {
    vector<ll> vecs;
    vector<ll> dedup;
    void init() {
        vecs.clear();
        dedup.clear();
    }
    void insert(ll v) { vecs.emplace_back(v); }
    void discretize() {
        sort(vecs.begin(), vecs.end());
        
        for (auto e: vecs) {
            while (!dedup.empty() && dedup.back() == e) dedup.pop_back();
            dedup.emplace_back(e);
        }
    }
    // assume x is in vecs; zero index.
    ll query(const ll v) {
        auto pos = lower_bound(dedup.begin(), dedup.end(), v);
        return pos - dedup.begin();
    }
};

struct FloatDisc {
    vector<ld> vecs;
    vector<ld> dedup;
    void init() {
        vecs.clear();
        dedup.clear();
    }
    void insert(ld v) { vecs.emplace_back(v); }
    void discretize() {
        sort(vecs.begin(), vecs.end());
        
        for (auto e: vecs) {
            while (!dedup.empty() && EQ(dedup.back(), e)) dedup.pop_back();
            dedup.emplace_back(e);
        }
    }
    // assume x is in vecs; zero index.
    ll query(const ld v) {
        auto pos = lower_bound(dedup.begin(), dedup.end(), v);
        if (pos != dedup.begin() && abs(*prev(pos) - v) < abs(*pos - v)) pos = prev(pos);
        return pos - dedup.begin();
    }
};

int sign(ld x, ld y){
    // x < y;
    if(y < 0) y += 2 * PI;
    if(x < 0) x += 2 * PI;
    if(y >= x && y <= x + PI) return 1;
    else return -1;
}
using namespace Geometry;
void solve() {

    // n is cho, m = stra
    ll n, m;
    cin >> n >> m;
    vector<pt> cho;
    vector<pt> stra;
    FOR(i, 1, n) {
        ld u, v; cin >> u >> v;
        cho.emplace_back(u, v);
    }
    FOR(i, 1, m) {
        ld u, v; cin >> u >> v;
        stra.emplace_back(u, v);
    }
    vector<pt> ch = convexHull(stra, false);
    // check for case where 2 stra
    ll ans = 0;
    for(pt xx : ch) cout << xx << "\n";
    for(int i = 0; i < ch.size(); i++){
        ld minv = arg(ch[(i == 0)? ch.size() - 1 : i - 1] - ch[i]);
        ld maxv = arg(ch[(i == ch.size() - 1)? 0 : i + 1] - ch[i]);
        
        vector<ld> angle;
        cout << minv << " " << maxv << "\n";
        for(pt c: cho){
            angle.emplace_back(arg(c - ch[i]));
        }
        sort(angle.begin(), angle.end());
        for(ld an: angle) cout << an << " ";
        cout << "\n";
        ll cur = 0;
        int ptr = 0;
        auto it = upper_bound(angle.begin(), angle.end(), minv);
        if(it == angle.begin()) it = angle.end();
    
        ptr = it - angle.begin();
        int ori = ptr;
        ld tar = minv - PI;
        for(int i = ptr - 1; i != ptr; i--){
            if( angle[i] < tar) {
                break;
            }
            cur++;
            if(i == 0) tar += 2 * PI;
            if(i - 1 < 0) i += n;
        }

        ans = max(ans, cur);
        if(angle[ptr] < maxv) maxv -= 2 * PI;
        for(int i = ptr - 1; i != ptr; i--){
            if( angle[i] < maxv) {
                break;
            }
            cur++;
            for(int j = ori; j != ori; j--){
                tar = angle[i] + PI;
                if(tar > 2 * PI) tar -= PI;
                
                if( sign(angle[j], tar) != sign(angle[(j == n - 1)? 0 : j + 1], tar)) {
                    break;
                }
                cur--;
                if(j == 0) tar += 2 * PI;
                if(j - 1 < 0) i += n;
            }
            ans = max(cur, ans);
            if(i == 0) maxv += 2 * PI;
            if(i - 1 < 0) i += n;
        }
        

    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}

/*
    5 2
0.2 0.6
0.8 0.6
0.6 0.2
0.1 0.2
0.6 0.8
0.6 0.6
0.5 0.5
*/