#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
#define all(x) x.begin(),x.end()
#define FOR(i, a, b) for (ll i = a; i <= b; ++i) 
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)
const ll INF = 1e9;
struct pt{
    int x, y;
    pt(int x, int y): x(x),y(y){}
};

ll sign(ll x){
    if(x<0) return -1;
    if(x>0) return 1;
    return 0;
}

void solve(){
    ll dr = INF,dl = INF, ul = -1 * INF, ur = -1 * INF;
    ll uu = -1*INF, dd = INF, rr = -1 * INF, le = INF;
    ll n;
    cin >> n;
    vector<pt> original;
    for(ll i = 0; i < n; i++){
        ll x,y;
        cin >> x >> y;
        original.emplace_back(pt(x,y));
        chkmax(ul,y-x);
        chkmin(dl,y+x);
        chkmax(ur,y+x);
        chkmin(dr,y-x);
        chkmax(uu,y);
        chkmin(dd,y);
        chkmax(rr,x);
        chkmin(le,x);
    }
    sort(original.begin(),original.end(), [&](auto left, auto right){
        return left.x < right.x || (left.x == right.x && left.y < right.y);
    });
    if(n==1){
        cout << "4\n";
        return;
    }

    ll x[] = {(uu - ul) , (ur - uu), rr, rr, (dd - dr), (dl - dd), le, le };
    ll y[] = {uu,uu , (ur - rr) , (dr + rr), dd, dd, (dl - le), (ul + le) };
    
    // for(ll i = 0; i < 8; i++) cout << x[i] << " " << y[i] << "\n";
    ll ans = max(abs(x[0] - x[7]), abs(y[0] - y[7]));
    for(ll i = 1; i < 8; i++){

        // cout << ans << " ";
        ans += max(abs(x[i] - x[i-1]), abs(y[i] - y[i-1]));
    }

    bool can = !(abs(original[1].y - original[0].y) != abs(original[1].x - original[0].x));
    for(ll i = 2; i < n; i++){
        if( abs(original[i].y - original[i-1].y) != abs(original[i].x - original[i-1].x) || 
            !( sign(original[i].y - original[i-1].y) == sign(original[i-1].y - original[i-2].y) &&
                sign(original[i].x - original[i-1].x)%2  == sign(original[i-1].x - original[i-2].x))
        ){
            can = false;
            break;
        }
    }
 

    cout << ans + 4 + can << "\n";

    


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}
