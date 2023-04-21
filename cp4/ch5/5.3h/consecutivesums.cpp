#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin >> n;

    for(int i = 2; i < n ; i++){
        ll ss = i * (i - 1)/ 2;
        if(n - ss < i) break;
        if( (n - ss) % i == 0){
            ll a = ( n - ss) / i;
            cout << n << " = " << a;
            for(int j = 1; j < i; j++) cout << " + " << a + j;
            cout << '\n';
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}