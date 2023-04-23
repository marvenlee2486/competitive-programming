#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<ll,ll>;

void solve(){
    int n;
    cin >> n;
    vector<ii> a(n);
    vector<ll> p(n, -1), q(n, -1), up(n + 1,0), uq(n + 1,0);
    bool gg = false;
    for(int i = 0; i < n; i++){
        int aa;
        cin >> aa;
        if(up[aa] && uq[aa]) {
            
            gg = true;
        }
        else if(up[aa]){
            uq[aa] = 1;
            q[i] = aa;
        }
        else{
            up[aa] = 1;
            p[i] = aa;
        }
        a[i] = {aa,i};
    }
    if(gg ){
        cout << "NO\n";
        return;
    }
    sort(a.begin(), a.end());
    int pidx = 1, qidx = 1;
    for(int i = 0; i < n; i++){
        while(pidx <= n && up[pidx]) pidx++;
        while(qidx <= n && uq[qidx]) qidx++;
        auto&[aa, idx] = a[i];
        if(p[idx] == -1) p[idx] = pidx++;
        else if(q[idx] == -1) q[idx] = qidx++;

        if(max(p[idx],q[idx]) != aa) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for(auto &i : p) cout << i << " ";
    cout << "\n";
    for(auto &i : q) cout << i << " ";
    cout << "\n";


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}