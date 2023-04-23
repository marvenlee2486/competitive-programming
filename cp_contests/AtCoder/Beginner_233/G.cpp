
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
  
  int n;
  cin >> n;
  str blocks[n];
  int prefix[n+1][n+1];
  int dp[n+2][n+2][n+2][n+2];
  rep(i,0,n) cin >> blocks[i];

  FILL(prefix,0);
  FILL(dp,0);

  rep(i,1,n+1){
      rep(j,1,n+1){
          prefix[i][j] = prefix[i][j-1]+ prefix[i-1][j] - prefix[i-1][j-1] + (blocks[i-1][j-1]=='#');
          //dp[i][j][i][j] = (blocks[i-1][j-1]=='#')?1:0;
          
      }
      
  }

  rep(x1,1,n+1){
      rep(y1,1,n+1){
          rrep(x2,x1,1){
              rrep(y2,y1,1){
                dp[x1][y1][x2][y2] = max(y1-y2,x1-x2)+1;
                if(x1==x2 && y1==y2){
                    if(blocks[x1-1][y1-1] =='.') dp[x1][y1][x2][y2] =0;
                    else dp[x1][y1][x2][y2]=1;
                    //cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << dp[x1][y1][x2][y2] << "\n";       
                    continue;
                }
                rep(i,x2,x1+1){
                    if(prefix[i][y1]-prefix[i][y2-1]-prefix[i-1][y1] + prefix[i-1][y2-1] == 0) MIN(dp[x1][y1][x2][y2], dp[i-1][y1][x2][y2] + dp[x1][y1][i+1][y2]);
                    //if(x1==n && x1==1 && y1==n && y1==1) cout << 
                    //if(i==2) cout << i << " " << y1 << " " << y2 << " " << prefix[i][y1]-prefix[i][y2-1]-prefix[i-1][y1] + prefix[i-1][y2-1] << "\n";
                }

                rep(j,y2,y1+1){
                    if(prefix[x1][j]-prefix[x2-1][j]-prefix[x1][j-1] + prefix[x2-1][j-1] == 0) MIN(dp[x1][y1][x2][y2], dp[x1][j-1][x2][y2] + dp[x1][y1][x2][j+1]);
                }
                //if(x2>=3 && x1<=4)
                //cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << dp[x1][y1][x2][y2] << "\n";                   
              }
          }
      }
  }
  cout << dp[n][n][1][1];
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/

