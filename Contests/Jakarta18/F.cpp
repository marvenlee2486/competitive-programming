#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n+1);
    vector<ll> b(n+1);
    vector<ll> pa(n+1);
    vector<ll> pb(n+1);
    vector<ii> maxv(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
     pa[0] = 0;
    pb[0] = 0;
    for(int i=1; i<=n; i++) pa[i] = pa[i-1] + a[i] ,
    pb[i] = pb[i-1] + b[i];
    for(int i =1;i<=n;i++){
        if(pa[i]>=m){
            if(pb[i]>m){
                cout << "0\n";
                return;
            }
            for(int j=i+(pa[i]==m);j<=n;j++){
                a.pop_back();
                b.pop_back();
                pa.pop_back();
                pb.pop_back();
                maxv.pop_back();
            }
            break;
        }
    }
    maxv.push_back(ii(0,0));
    n = a.size()-1;
   
    for(int i = n; i>0 ;i--){
        if(maxv[i+1].first < b[i]){
            maxv[i] = ii(b[i],i);
        }
        else{
            maxv[i] = maxv[i+1];
        }
    }
    ll pen = 0;
    vector<ll> ans;
    for(int i=1; i<=n; i++){
        int idx = lower_bound(pb.begin(),pb.end(),pa[i]) - pb.begin();
        if( pb[maxv[idx].second] + pen > m){
            break;
        }
        //cout << pa[i] << " " << idx << "\n";
        ans.emplace_back( pb[maxv[idx].second] + pen);
        pen += maxv[idx].first;
    }
    //cout << pb[n] << " " << pa[n] << " " << pen <<'\n';
    if( pa[n]-pb[n] > pen){
        cout << "-1\n";
        return;
    }
    cout << ans.size() << '\n';
    for(int v:ans) cout << v << " ";
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
