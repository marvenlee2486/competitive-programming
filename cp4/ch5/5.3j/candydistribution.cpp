/*

kX + 1 = CY
1 = CY - kX

is there such X or Y
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int ext(ll a, ll b, ll &x, ll &y){
    ll xx = y = 0;
    ll yy = x = 1;
    while(b){
        ll q = a / b;
        ll t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }
    return a;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll k,c; cin >> k >> c;
        if( __gcd((unsigned long long) k, (unsigned long long)c) != 1){
            cout << "IMPOSSIBLE\n";
        }
        else{
            ll x,y;
            ext(k,c,x,y);
            cout << y << "\n";
        }
    }
}