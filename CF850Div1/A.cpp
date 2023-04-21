#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){  
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i:a) cin >> i;
    sort(a.begin(), a.end());
    int idx = 1;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > idx){
            ans += a[i] - idx;
            a[i] = idx;
        }
        if(a[i] == idx) idx++;
    }
    cout << ans << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}