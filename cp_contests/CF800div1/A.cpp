#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

bool solve(){
    ll n;
    cin >> n;
    vector<ll> a(n, 0);
    for(auto &i : a) cin >> i;
    for(int i = 0; i < n; i++){
        if(a[i] != 0) break;
        if(i== n -1) return true;
    }
    a[0] -= 1;
    bool st = false;
    for(int i = n - 1; i > 0; i--){
        if(!st && a[i]){
            a[i]++;
            st = true;
        }
        if(!st) continue;
        if(a[i] > 0) return false;
        a[i - 1] -= abs(a[i]);
    }
    
    if(st && a[0] == 0) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) cout << ((solve())? "YES\n":"NO\n");
}

