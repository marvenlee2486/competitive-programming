#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

void solve(){
    ll n, L, R, k; cin >> n >> L >> R >> k;
    vector<ll> a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    vector<ll> diffs(n + 2); diffs[1] = L;
    ll currVal = L; ll mxVal = L;
    deque<ll> incr; incr.emplace_back(1);
    FOR(i, 2, n) {
        // add greedily
        if (a[i - 1] < a[i]) diffs[i] = 1, incr.emplace_back(i), currVal++;
        else if (a[i - 1] == a[i]) diffs[i] = 0;
        else diffs[i] = -k, incr.emplace_back(i), currVal -= k;

        // try to keep lb
        while (currVal < L) {
            if (incr.empty()) {
                cout << -1 << '\n';
                return;
            } else {
                auto x = incr.back(); incr.pop_back();
                if (x == 1) {
                    ll allowed = R - diffs[1];
                    ll m = min(allowed, L - currVal);
                    currVal += m, allowed -=m, diffs[1] += m;
                    if (allowed > 0) incr.push_back(1);
                } else {
                    ll allowed = diffs[x] > 0 ? k - diffs[x] : -1 - diffs[x];
                    ll m = min(allowed, L - currVal);
                    // maintain vals
                    currVal += m; allowed -= m; diffs[x] += m;
                    if (allowed > 0) incr.push_back(x);
                }
            }
        }
        
        chkmax(mxVal, currVal);
    }
    // output answer
    if (mxVal <= R) {
        ll x = 0;
        FOR(i, 1, n) x += diffs[i], cout << x << " ";
        cout << '\n';
    } else cout << "-1\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
