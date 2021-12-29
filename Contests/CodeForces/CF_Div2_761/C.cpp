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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--){
      int n;
      cin >> n;
    
      int cnt[n+2];
      FILL(cnt,0);
      vl ans;
      bool flag = false;
      int x;
      rep(i,0,n){
          cin >> x;
          if(x>n || cnt[x]) ans.pb( (x-1)/2 );
          else{
              if(cnt[x]==1) flag= true;
              cnt[x]=1;
          }
      }
      if(flag){
          cout <<"-1\n";
          continue;
      }

      sort(ALL(ans));
      int ptr = 0;
      rep(i,1,n+1){
          if(cnt[i]) continue;
          
        if(ans[ptr]<i) flag= true;
        ptr++;
      }
      if(flag) cout << "-1\n";
      else cout << ans.size() <<"\n";
  }


  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)

1 = 1
2 = 1,2
3 = 1,X,3
4 = 1,X,X,4
5 = 1,2,X,X,5
6 = 1,2,X,X,X,6
7 = 1,2,3,X,X,X
8 = 1,2,3,X,X
9 = 1,2,3,4,X,X

X-1/2
*/

