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

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const ll N = 1e5+2;

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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    
    int dp[N+1][11];
    FILL(dp,-1);
    rep(i,0,N) dp[i][0]=0;
    rep(j,0,11) dp[0][j]=0;
    dp[1][1] = 1;
    rep(i,1,N){
        rep(j,1,11){
            if(i==1 && j==1) continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1] ;
            dp[i][j] %= MOD;
        }
    }
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        str s; cin >> s;
        int cur =0;
        bool flag = true;
        rep(i,0,s.size()){
            if(s[i] =='-') continue;
            if(s[i]-'0'<cur) flag = false;
            cur = s[i]-'0';
            
        }
        if(!flag){ cout << "0\n"; continue;}

        ll lo = 1;
        ll l=0;
        ll ans=1;
        rep(i,0,n){
            if(s[i]=='-') l++;
            else{
                if(l==0) lo = s[i]-'0';
                else{
                    ll ri = s[i]-'0';
                    ll subans=0;
                    rep(j,1,ri-lo+1+1){
                        subans += dp[l][j];
                        subans %= MOD;
                    }
                    ans*=subans;
                    ans%=MOD;
                    l=0;
                }
            }
        }
        if(l!=0){
            ll ri = 9;
            ll subans=0;
            rep(j,1,ri-lo+1+1){
                subans += dp[l][j];
                subans %= MOD;
            }
            ans *= subans;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
