#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
ll N = 1e6+1;
ll q(ll x,ll y){
    cout << x << " " << y << endl;
    ll ans;
     cin >> ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    ll n;
    cin >> n;
    
    for(ll idx=0;idx<n;idx++){
        //cout << "1YS\n";
        ll d = q(0,0); 
        ii loc;
        if(d == 0) continue;
        vector<ii> possible;
        for(ll i = 0; i<N;i++){
            if(i*i > d) break;
            ll sq = sqrt(d- i*i);
            if(sq*sq != d-i*i) continue;
            ll getd = q(i,sq);
            if(getd==0)break;
        }
    }
    
}