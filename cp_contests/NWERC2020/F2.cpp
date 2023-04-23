#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for (ll i = a; i <= b; ++i)
const ll sz = 100000;
using ld = long double;
ll initLoc[sz + 2];
ll v[sz + 2];
set<ll> alivePts;

ld getCollisionTime(ll i, ll j) { // T > 0 under normal case
    assert(i < j);
    ll dV = v[j] - v[i], dX = initLoc[j] - initLoc[i];
    if (dV < 0) return (ld)dX / abs(dV);
    else return -1;
}

int main(){ 
    ll n; cin >> n;
    FOR(i, 1, n) cin >> initLoc[i] >> v[i];

    set<tuple<long double, ll, ll>> s;
    // 1. init
    FOR(i, 1, n - 1) {
        ld T = getCollisionTime(i, i + 1);
        if (T > 0) s.emplace(T, i, i + 1);
    }
    FOR(i, 1, n) alivePts.emplace(i);

    // 2. process
    while (!s.empty()) {
        auto [dInitT, i, j] = *s.begin(); s.erase(s.begin());
        alivePts.erase(i), alivePts.erase(j);

        ll leftId = -1, rightId = -1;
        // collision.
        if (alivePts.lower_bound(i) != alivePts.begin()) {
            // exist left segment
            leftId = *prev(alivePts.lower_bound(i));
            s.erase({getCollisionTime(leftId, i), leftId, i});
        } 

        if (alivePts.lower_bound(j) != alivePts.end()) {
            // exist right segment
            rightId = *alivePts.lower_bound(j);
            s.erase({getCollisionTime(j, rightId), j, rightId});
        }

        // insert new segment
        if (leftId != -1 && rightId != -1) {
            ld T = getCollisionTime(leftId, rightId);
            if (T > 0) s.emplace(T, leftId, rightId);
        }
    }

    // 3. output answer
    cout << alivePts.size() << '\n';
    for (auto e: alivePts) cout << e << " ";
    cout << endl;
}