#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
   
    vector<ll> a(n, 0);
    for(auto &i: a) cin >> i;

    if(n % 2 == 1){
        for(int i = 0; i < n; i++) a.emplace_back(a[i]);
        n *= 2;
    }
    vector<int> vis(n, 0);
    ll an = 0, b = 0, c = 0;
    for(int i = 0; i < n; i++){
        if(vis[i] || a[i] == 0) continue;
        bool even = false, odd = false;
        ll j = i; 
        while(!vis[j % n]){
            vis[j % n] = 1;
            if(j % 2 == 0) even = true;
            else odd = true;

            j += a[j % n];
        }
      
        if(even && odd) c += (j - i) / n;
        else if(even) an += (j - i) / n;
        else b += (j - i) / n;
    }
    cout << an << " " << b << " " << c << "\n";



}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}