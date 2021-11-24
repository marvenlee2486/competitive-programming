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


//typelower_bounddef priority_queue<long long> pq;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

#define LSOne(S) ( (S) & -(S))
#define elif else if
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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
// if else int i = (number <0) ? 1:0 -  if (number <0) i=1 else 0
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



int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    int n;cin >> n;
    
    int cnt[32];
    FILL(cnt,0);
    rep(i,0,n){
        int a;cin >> a;
        rep(i,0,32){
            if(a%2 ==1) {
                cnt[i]++;
                break;
            }
            a/=2;
        }
    }
    ll ans;
    ll memo[n+2];
    memo[0]=1;
    rep(i,1,n+1) memo[i]= (memo[i-1]*2) %MOD;
    ans = (memo[n] - memo[n - cnt[0]] + MOD )%MOD;
    ll left= n-cnt[0];
    LOG(ans);
    rep(i,1,32){
        if(cnt[i]>1)
        ans += (memo[left-1] - memo[left - cnt[i]]  +MOD)%MOD ;
        ans %= MOD;
        LOG(ans);
        left -= cnt[i];
        
    }
    cout << ans ;
    /*
    ll ans = binpow(2,n) ;
   //cout << ans << endl;

    vl even;
    vl odd;
    
    FOR(c,dict){
        if( (c/2)%2) odd.pb(c/2);
        else even.pb(c/2);
    }
    
    

    while(dict.size()!=0){
        ans = addm(ans, -1*( mulm(odd.size(), addm(  binpow(2,even.size()),-1)  )   ), -1 * addm( binpow(2,odd.size()), -1 ) );
        
        dict.clear();
        odd.clear();
        FOR(c,even){
            dict.pb(c);
        }
        even.clear();

        FOR(c,dict){
            if( (c/2)%2) odd.pb(c/2);
            else even.pb(c/2);
            
        }
    }

  
    cout << ans %MOD;
    */
  
  return 0;
}


/*
Advise
1) 逆向思维!!
2) long long
3)
*/
