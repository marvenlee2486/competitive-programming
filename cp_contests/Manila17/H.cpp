#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)
#define ld long double

#define EPS 1e-8


void solve(){
    ll r,c, h, q;
    cin >> r >> c >> h >> q;
    ll arr[h+1];
    memset(arr,0,sizeof arr);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            ll a;
            cin >> a;
            arr[a]++;
        }
    }

    ll curv = 0;
    vector<ii> ans;
    ll cell = r*c;
    for(int i = 0; i <= h; i++){


        if(arr[i] != 0)
            ans.emplace_back(curv + 1,cell - arr[i]);
        
        cell -= arr[i];

        curv += (r*c -cell);
    }
    
    // for(auto[v,an]:ans){
    //     cout << v << " " << an << "\n";
    // }

    while(q--){
        ll v;
        cin >> v;
        auto it = upper_bound(ans.begin(),ans.end(), ii(v,r*c+1));
        it--;
        cout << it->second << "\n";

    }


     
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
