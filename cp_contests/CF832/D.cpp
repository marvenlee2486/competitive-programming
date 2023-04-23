#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

typedef pair<ll, ll> ii;
typedef tuple<ll,ll,ll> iii;
typedef string str;
typedef vector<ll>  vl;
typedef vector< vector<ll> > vvl;
typedef vector<ii> vii;
typedef vector< vector<ii> > vvii;
typedef vector<iii> viii;
typedef vector< vector<iii> > vviii;
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

const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;

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


typedef vector<ll> vi;

void solve(){
    int n,q;
    cin >> n >> q;
    int a[n+1];
    int px[n+1];
    int ps[n+1];
    px[0] = 0, ps[0] = 0;
    map<int,vector<int> > mpp[2];
    rep(i,1,n+1){
        cin >> a[i];
        px[i] = px[i-1] ^ a[i];
        mpp[i%2][px[i]].push_back(i);
        ps[i] = ps[i-1] + a[i];
    }

    while(q--){
        int l,r;
        cin >> l >> r;

        if(ps[r] - ps[l-1] == 0) {
            cout << "0\n";
            continue;
        }
        //cout << px[r] << " " << px[l-1] <<"\n";
        if( (px[r] ^ px[l-1])!=0){
            cout << "-1\n";
            continue;
        }
        if( (r-l+1) %2 ==1 ){
            cout << "1\n";
            continue;
        }
        if(a[l] == 0 || a[r] == 0){
            cout << "1\n";
            continue;
        }

        ll see = px[l-1];
        vector<int> temp = mpp[l%2][see];
        
        auto it = lower_bound(temp.begin(), temp.end(),l);
        if(it == temp.end() || *it >r ) cout << "-1\n";
        else cout << "2\n";
        
    }

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  //cin >> t;
  while(t--) solve();
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
