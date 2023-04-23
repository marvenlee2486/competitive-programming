
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

const ll MOD = 998244353 ;
const ll INF = 1e9;
const ld EPS = 1e-9;
const ll N = 5100;

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
ll fact[N];
ll modInverse(ll a)
{
   
    return  binpow(a, MOD - 2);
    
}

ll nCk(int n, int k){
    return ((fact[n]*modInverse(fact[k]))%MOD * modInverse(fact[n-k]))%MOD;
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

fact[0]=1;
rep(i,1,N){
fact[i]= (fact[i-1]*i)%MOD;
}

  int n,k;
  cin >> n >> k;
  str s;
  cin >> s;
  int cur = 0;
  int l=0,r=0;
    ll ans=0;
    for(auto c:s){
        if(c=='1') ans++;
    }
    if(ans<k || k==0){
        cout << "1\n";
        return 0;
    }
    ans =1;
  rep(r,0,n){
    if(s[r]=='1') cur ++;
    //cout << "r = " << r << " " << cur << "\n";

    while(cur ==k){
      if(r==n-1 || s[r+1]=='0') break;
      else{
          //cout << l << "" << r << " ";
          if(s[l]=='0') ans += nCk(r-l,k-1);
          else {
              ans+= nCk(r-l,k);cur--;}
            ans %=MOD;
          l++;
      }
      //cout << ans  <<endl; 
    }
  }
  r= n-1;
  while(l<s.size()){
      if(cur ==0) break;
      //cout << cur << " " << l << " " << r << " ";
      if(s[l]=='0') ans += nCk(r-l,cur-1);
          else {
              ans+= nCk(r-l,cur);cur--;}
            ans %=MOD;
          l++;
        //cout << ans  <<endl; 
  }
  cout << ans;
  
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/