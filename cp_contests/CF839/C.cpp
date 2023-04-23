#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve(){
    int k,n;
    cin >> k >> n;
    int cur = 1;
    for(int i = 0; i < k; i++){
        cout << cur << " ";
        if( n - (cur + i + 1) + 1 >= (k - i - 1)) cur += i + 1;
        else cur += 1;
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}

