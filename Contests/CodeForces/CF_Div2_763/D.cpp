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
ll binpow(ll a, ll b) {
    ll res = 1;

    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        res%=MOD;
        a%=MOD;
        b >>= 1;
    }
    return res%MOD;
}

ll modInverse(ll a)
{

    return binpow(a, MOD - 2);
    
}

ll aob(ll a, ll b){
    return (a* modInverse(b))%MOD;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  //cout.tie(0);
  int t;
  cin >> t;
  while(t--){
       ll n,m,ra,ca,rb,cb, p;
        cin >> n >> m >> ra>> ca >> rb >> cb >> p;
        set<ll> s;
        ll rs;
        ll cs;
        vector<ll> radd;
        vector<ll> cadd;
        if(ra>rb) {
            rs= (n-rb) + (n-ra);
            if(rb !=1) radd.pb( (rb-1)*2 );
            radd.pb( (n-rb)*2 );
        }
        else {
            rs = rb-ra;
            if(rb !=n) radd.pb( (n-rb)*2 );
            radd.pb( (rb-1)*2 );
            
        }


        if(ca>cb) {
            cs= (m-cb) + (m-ca);
            if(cb !=1) cadd.pb( (cb-1)*2 );
            cadd.pb( (m-cb)*2 );
        }
        else {
            cs = cb-ca;
            if(cb !=n)  cadd.pb( (m-cb)*2 );
            cadd.pb( (cb-1)*2 );
           
        }
        
        ll hit = aob(p,100);
        ll miss = aob(100-p,100);
        ll misscu = 1;
        ll ans=0;int cnt=0;
        int cptr = 0,rptr=0;
        while(true){
            if(rs<0 || cs <0) break;
            ll time;
            if(rs>cs){
            time = cs;
              cs+=cadd[cptr];
              cptr++;
              cptr%=cadd.size();        
            }
            
            else{
                time = rs;
              rs+=radd[rptr];
              rptr++;
              rptr%=radd.size(); 
            }

            ans+= time*misscu;
            ans %= MOD;
            misscu*=miss;
            misscu%=MOD;
            cnt++;

            cout << ans << " ";
        }
        
        FOR(time,s){
           cout << ans << " " ;
            
        }
        cout << (ans*hit)%MOD << "\n";
  }
 
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/

