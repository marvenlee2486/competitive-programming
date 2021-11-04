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
const ll MAXN = 1e6+2;

ll inv[2*MAXN+3];
ll cmemo[MAXN];
ll fact[2*MAXN+3];
ll ifact[2*MAXN+3];

ll mult(ll a, ll b){
    return (a*b)%MOD;
}

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

 
// A Binomial coefficient based function to find nth catalan
ll nCk(ll n , ll k){
    return mult(fact[n],mult(ifact[k],ifact[n-k]));
}

// number in O(n) time

ll catalan( ll n)
{
    if(cmemo[n]) return cmemo[n];
    // Calculate value of 2nCn
   
    // return 2nCn/(n+1)
    return cmemo[n] = mult(nCk(2*n,n) , modInverse (n + 1) );
}
void computefact(ll n){
    fact[0]=1;
    ifact[0]=1;
    rep(i,1,n+1){
        fact[i] = mult(fact[i-1],i) ;
        ifact[i] = mult(fact[i-1],modInverse(i));
    }
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("another.txt","w",stdout);
  
  computefact(2*MAXN);
  
  int cnt[MAXN];
  FILL(cnt,0);
  FILL(inv,0);
  FILL(cmemo,0);


  int n;
  cin >> n;
  if(n==0) {
    cout << "1\n";
    return 0;
  }

  stack<int> st;
  ll ans =1;
  vl arr;
  rep(i,0,n){
    int x; cin >> x; 
    while(!st.empty() && x<st.top()) {
       ans *= catalan(cnt[st.top()]);
       ans %= MOD;
       cnt[st.top()]=0;
       st.pop();
    }
    st.push(x);
    cnt[x]++;

  }
  while(!st.empty()){
      ans *= catalan(cnt[st.top()]);
      ans %= MOD;
      cnt[st.top()]=0;
      st.pop();
  }

  cout << ans %MOD <<"\n";
   
  return 0;
}


/*
Advise
1) 逆向思维!!
2) long long
3)
*/
