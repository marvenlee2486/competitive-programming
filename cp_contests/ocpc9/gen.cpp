#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

void solve(){

    FOR(n, 2, 10) {
        cout << "n = " << n << '\n';
        set<vector<vector<bool>>> confs;
        FOR(msk, 0, (1ll << (3 * n)) - 1) {
            vector<vector<bool>> a(n + 1, vector<bool>(n + 1));
            FOR(i, 0, 3 * n - 1) if ((1ll << i) & (msk)) {
                ll op;
                if (i < n) {
                    op = i + 1;
                    FOR(t, 1, op) a[op][t] = a[op][t] ^ 1; 
                }
                else if (i < 2 * n) {
                    op = i - n + 1;
                    ll y = 1;
                    FOR(t, op, n) a[t][y] = (a[t][y] ^ 1), y++;
                } else {
                    op = i - 2 * n + 1;
                    FOR(t, op, n) a[t][op] = (a[t][op] ^ 1);
                }
            }
            cout << "and: " << endl;
            FOR(i, 1, n) {
                FOR(j, 1, i) cout << a[i][j] << " ";
                cout << endl;
            }
            confs.emplace(a);
        }
        cout << "Failed sol: " << (1ll << ((n + 1) * n / 2)) - confs.size() << endl;
        cout << "Success: " << confs.size() << endl;
    }
}

int main(){
    ios::sync_withstdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}