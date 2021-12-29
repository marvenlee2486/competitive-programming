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
  str s;
  cin >> s;
  int n=s.size();
  int dp[s.size()+1][s.size()+1];
  int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211};

  rep(i,0,n+1){
 
      rep(j,0,n+1){
          dp[i][j] = INF; 
      }
  }

  rep(i,0,n){
      rrep(j,i,0){
          if(i==j) {
              dp[i][j] = 1;
              continue;
          }
          rep(k,j,i){
            dp[i][j] = min(dp[i][j], dp[k][j]+ dp[i][k+1]);
          }
          int idx=0;
          //cout << j << " " << i  << endl;
          while((i-j+1) >= prime[idx]){
              
            if((i-j+1)%prime[idx]==0){
                bool can = true;
                //if(i==9 && j==2) cout << prime[idx] << " :: ";
                rep(k,j,j+(i-j+1)/prime[idx]){
                    char c = s[k];
                    //if(i==9 && j==2)cout << k << " ";
                    rep(cnt,1, prime[idx]){
                        //if(i==9 && j==2)cout << cnt *prime[idx] + k  << " ";
                        if(s[cnt *(i-j+1)/prime[idx] + k ]!=c) {
                            can = false;
                            break;
                        }
                    }
                    if(i==9 && j==2)cout << "\n";
                    if(!can) break;
                }
               
                if(can){
                    //cout << i << " " << j << " " << j+(i-j+1)/prime[idx]-1 << "SUCEWSS\n"  ;
                    dp[i][j]=min(dp[i][j],dp[j+(i-j+1)/prime[idx]-1][j]);  
                }
            
            }
            idx++;   
          }
           //cout <<"\n";
            
         
      }
  }
  
  
  
  cout << dp[n-1][0];
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/

