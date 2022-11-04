#include <bits/stdc++.h>
using namespace std;
using ll = long long;



auto main()->int{
    int n, m;
    cin >> n >> m;
    string a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    //int dp[n][m];

    vector<tuple<char, ll, ll>> locations;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] != '.') locations.emplace_back(a[i][j], i, j);
        }
    }
    sort(locations.begin(), locations.end());
    
    // 1. brute force find largest A
    for (auto [currChar, ai, aj]: locations) {
        ll mxArea = -1; ll u1, u2, v1, v2;
        for (int u = 0; u <= aj; ++u) {
            ll upper = ai, lower = ai;
            for (int v = m - 1; v >= aj; --v) {
                // edge case: impossible
                bool ok = true;
                for (int t = u; t <= v; ++t) if (a[ai][t] != '.' && a[ai][t] != currChar) {
                    ok = false;
                    break;
                }
                if (!ok) continue;

                // extend upwards
                while (true) {
                    bool ok = true;
                    for (int t = u; t <= v; ++t) if (upper == 0 || a[upper - 1][t] != '.'){ ok = false;break;}
                    if (ok) upper--;
                    else break;
                }
                // extend downwards
                while (true) {
                    bool ok = true;
                    for (int t = u; t <= v; ++t) if (lower == n - 1 || a[lower + 1][t] != '.') {ok = false;break;}
                    if (ok) lower++;
                    else break;
                }
                ll area = (lower - upper + 1) * (v - u + 1);
                if (area >= mxArea) mxArea = area, u1 = upper, u2 = lower, v1 = u, v2 = v;
            }
        }
        for (int i = u1; i <= u2; ++i) for (int j = v1; j <= v2; ++j) if (!(a[i][j] >= 'A' && a[i][j] <= 'Z')) a[i][j] = currChar - ('A' - 'a');
    }
    // 2. output answer

    for (int i = 0; i <= n - 1; ++i) {
        for (int j = 0; j <= m - 1; ++j) cout << a[i][j];
        cout << '\n';
    }
}       