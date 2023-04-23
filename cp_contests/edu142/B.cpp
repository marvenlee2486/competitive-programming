#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

void solve(){
    int n, x,y,z;
    cin >> n >> x >> y >> z;
    if(n == 0){
        cout << "1\n";
        return;
    }
    int cur = n;
    int minus = min(x,y);
    x -= minus;
    y -= minus;
    int ans = n + 2 * minus;
    int left = cur - max(x, y);
    if(cur < max(x, y)){
        ans += cur + 1;
        cout << ans << "\n";
        return;
    }
    ans += max(x, y);
    int minv = min(left, z);
    ans += minv;
    left -= minv;
    z -= minv;
    if(z != 0) ans++;
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