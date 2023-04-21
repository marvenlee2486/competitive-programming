#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e17;
void solve(){
    ll a,b,c,d,e,f;
    
    cin >> a >> b >> c >> d >> e >> f;

    ll minv = (d - a) * (d - a) + (e - b) * (e - b) + (f - c) * (f - c);
    ll idx = 0;

   
    for(int i = 1; i <= 1000000; i++){
        ll x = 3 * b + c
        ,y = a/2
        ,z = b/2;
        
        a = x, b = y, c = z;

        ll val = (d - a) * (d - a) + (e - b) * (e - b) + (f - c) * (f - c);
        if(val < 0 || val > INF) break;
        if(val < minv){
            minv = val;
            idx = i;
        }
        
    
    }
    cout << minv << " " << idx << '\n';

}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}