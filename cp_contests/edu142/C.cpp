#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<int> p(n + 1, 0);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        p[x] = i;
    }
    int l = 0, r = 0, lv,rv;
    if(n % 2 == 1){
        l = p[(n + 1) / 2];
        r = l;
        lv = (n + 1)/2; rv = lv;
    }
    else{
        l = p[n / 2];
        r = p[n / 2 + 1];
        lv = n/2;
        rv = (n/2+ 1);
    }
    int ans = (n + 1)/2;
    //cout << l << " " << r << '\n';
    while(l <= r && ans != 0){
        ans--;
        lv--; rv++;

        if(p[lv] > l || p[rv] < r) break;
        l = p[lv];
        r = p[rv];   
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}