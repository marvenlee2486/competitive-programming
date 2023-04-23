#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;
void solve(){
    int n;
    cin >> n;
    ll a;
    ll minv = INF+4;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a;
            
            if(i == (n-j-1) ) {
                minv = min( minv, a);
            }
            sum += a;
        }
    } 
    sum -= minv;
    cout << sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);  
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}