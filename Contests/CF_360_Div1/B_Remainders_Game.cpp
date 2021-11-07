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

int gpf[N];
void sieve() {
  
  rep(i,2,N){
    gpf[i]=2;
    i+=1;
  }

  rep(i,3,N){
    if(gpf[i]!=0) continue;
    gpf[i] = i;
    int j =i*2;
    while(j<N){
      gpf[j]=i;
      j+=i;
    }
    i+=1;

  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("another.txt","w",stdout);
  FILL(gpf,0);
  sieve();
  ll n,k,c; cin >> n >> k;
 
  ll state[N];
  //cout << gpf[12] << "\n";
  FILL(state,0);
  rep(i,0,n){
    cin >> c;   
    while(c!=1){
      
      ll cnt =0;
      ll j = c;
      
      while(c%gpf[j]==0){
          cnt++;
          c/=gpf[j];
      }
      MAX(state[gpf[j]],cnt);
    }  
  }
  bool ans=true;

  while(k!=1){
    
    ll cnt =0;
    ll j = k;
    while(k%gpf[j]==0){
        cnt++;
        k/=gpf[j];
    }
    if(state[gpf[j]]<cnt) ans=false;
    //cout << gpf[j] << " " << state[gpf[j]];
  } 

   
  if(ans) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}


/*
Advise
1) 逆向思维!!
2) long long
3)
*/
