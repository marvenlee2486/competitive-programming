#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef string str;
typedef vector<ll>  vl;
typedef vector< vector<ll> > vvl;
typedef vector<ii> vii;
typedef vector< vector<ii> > vvii;
typedef vector<str>  vs;
typedef vector< vector<str> > vvs;


//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


#define LSOne(S) ( (S) & -(S))
#define elif else if
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define FOR(i,v) for(auto i:v)
#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>=(b);i--)
#define repn(i,a,b) for(int i=(a);i<=(b);i++)
#define repin(i,a,b,x) for(int i=(a);i<(b);i+=x)
#define repnin(i,a,b,x) for(int i=(a);i<=(b);i+=x)
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define fbo find_by_order
#define ook order_of_key
#define ALL(v) v.begin(),v.end()
#define FILL(arr,x) memset(arr,x,sizeof arr);

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const ll N = 1e6+2;

#ifndef ONLINE_JUDGE
#define LOG(message) cerr << message << endl;
#else 
#define LOG(message)
#endif

ll mod(ll x, ll y = MOD) { return ((x % y) + y) % y; }

ll addm(ll x) { return x; }
template <typename... Ts> ll addm(ll x, Ts... ys) { return mod(x + addm(ys...)); }

ll mulm(ll x) { return x; }
template <typename... Ts> ll mulm(ll x, Ts... ys) { return mod(x * mulm(ys...)); }

void solve(){
    int n;
    cin >> n;
    ii x[n];
    int t[n];
    int pos[n];
    int left[n];
    int right[n];
    rep(i,0,n) {
        int te; cin >> te;
        x[i] = ii(te,i);
        
    }
    sort(x,x+n);
    rep(i,0,n){
        pos[x[i].se] = i; 
    }
    rep(i,0,n) {
        int tt;
        cin >> tt;
        t[pos[i]] = tt;
    }
    rep(i,0,n){
        left[i] = x[i].fi-t[i];
        right[i] = x[i].fi+t[i];
    }
    int premin[n];
    int premax[n];
    premin[0] = left[0];
    rep(i,1,n){
        premin[i] = min(premin[i-1],left[i]);
    }
    premax[n-1] = right[n-1];
    rrep(i,n-2,0){
        premax[i]= max(premax[i+1],right[i]);
    }
    // rep(i,0,n){
    //     cout << premax[i] << " ";
    // }
    // cout << "\n";
    // rep(i,0,n){
    //     cout << premin[i] << " ";
    // }
    // cout << "\n";
    rep(i,0,n){
        
            int diff0 =  x[i].fi - premin[i];
            int diff1 = premax[i] - x[i].fi;
            int diff = diff0 - diff1;
        //cout << diff0 - diff1 << " ";

        if( diff >0){
            if(i==0) {
                cout << x[i].fi << "\n";
                return;
            }
            int prediff = (x[i-1].fi - premin[i-1]) - (premax[i-1] - x[i-1].fi  ) ;
            
            ld ans = (ld)(abs(prediff)) /(ld)(diff - prediff);
            ans = x[i-1].fi + ans *(x[i].fi - x[i-1].fi);
            cout << fixed << setprecision(10) << ans << "\n";
            return;
        }


          
    }
    cout << x[n-1].fi;
    cout << "\n";

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int t=1;
  cin >> t;
  while(t--) solve();
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
