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

ll fact[62];
unordered_map<ll,ll> inv;

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
    if(inv[a]) return inv[a];
    return inv[a] = binpow(a, MOD - 2);
    
}
void solve(){
    int n;
    cin >> n;
    ll a=0,b=0,d=0;
    ll k = n/2;
    int turn = 0;
    rrep(i,n,1){
        if(i%2 ==0 ){
        if(turn%2==0)
        a += ((fact[i-1] * modInverse(fact[k-1])) %MOD * modInverse( fact[i-k]) )%MOD; // i-1 C k-1
        else b+= ((fact[i-1] * modInverse(fact[k-1])) %MOD * modInverse( fact[i-k]) )%MOD; // i-1 
        k--;
        }
        else {
            if(turn%2==0)
          b += ( ((fact[i-1]* modInverse(fact[k-1])) %MOD * modInverse(fact[i-k]))%MOD);
          else a+=( ((fact[i-1]* modInverse(fact[k-1])) %MOD * modInverse(fact[i-k]))%MOD);
          turn++;
        }
        a %= MOD;
        b%=MOD;
        //cout << a << " " << b << "\n";
    }
    cout << a << " " << b << " 1\n";
}  

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t =1 ;
  fact[0]=1;
  rep(i,1,62) fact[i] = (fact[i-1] * i)%MOD;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
