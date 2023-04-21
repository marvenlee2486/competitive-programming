#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

int main(){
    int n,q;
    cin >> n >> q;
    vector<ii> a(n);
    for(auto&[l,r]:a) cin >> l >> r;
    while(q--){
        ll xi,yi,vi;
        cin >> xi >> yi >> vi;
        __int128_t x = xi , y = yi, v = vi;
        x--,y--;
        __int128_t u = (v - a[x].first) * (a[y].second - a[y].first) + (a[x].second - a[x].first) * a[y].first;
        __int128_t d = a[x].second - a[x].first;

        if (u < 0 && d < 0) u = -1 * u, d = -1 * d;
        if (u < 0 || d < 0){
            if(u < 0) u = -1 * u;
            if(d < 0) d = -1 * d;
            cout << "-";
        }

        ll g = __gcd( u,  d);
        u /= g;
        d /= g;
        ll ui = (ll) u;
        ll di = (ll) d;
        cout << ui << "/" << di << "\n";


    }
}