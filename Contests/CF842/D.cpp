#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<ll,ll>;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n, -1);
    for(auto& i: a){
        cin >> i;
        i--;
    }

    vector<int> dsu(n, -1);
    int idx = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(dsu[i] != -1) continue;
        dsu[i] = idx;
        int u = i , cnt = 1;
        u = a[u];
        while(dsu[u] != idx){
            dsu[u] = idx;
            u = a[u];
            cnt++;
        }
        ans += cnt - 1;
        idx++;
    }
    int add = 1;
    for(int i = 0; i < n - 1; i++){
        if(dsu[a[i]] == dsu[a[i + 1]]) add = -1;
    }
    ans += add;
    cout << ans << '\n';

    

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}