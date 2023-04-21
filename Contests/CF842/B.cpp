#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<ll,ll>;

void solve(){
    int n, k;
    cin >> n >> k;
    int cur = 1;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a == cur) cur++;
    }
    cur -= 1;
    int ans = (n - cur)/k + ((n - cur) % k != 0);
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}