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


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll h,w,k;
  cin >> h >> w >> k;
ll dp[2][4];
  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;
  dp[0][3] = 0;
ll x1,x2,y1,y2;
cin >> x1 >> y1 >> x2 >> y2;
    if( x1==x2 && y1 == y2) dp[0][3]=1;
    else if(x1==x2 ) dp[0][1]=1;
    else if (y1 == y2) dp[0][2]=1;
    else dp[0][0] =1;
 // 1 - x same
    rep(j,1,k+1){
        int i =1;
        dp[i][0] = dp[i-1][1] * (h-1) + dp[i-1][2] * (w-1) + dp[i-1][0] * ((h-2)+(w-2)) ;
        dp[i][0] %= MOD;

        dp[i][1] = dp[i-1][0] + dp[i-1][1] * (w-2) + dp[i-1][3]*(w-1);
        dp[i][1] %= MOD;

        dp[i][2] = dp[i-1][0] + dp[i-1][2] *(h-2) + dp[i-1][3]*(h-1);
        dp[i][2] %= MOD;

        dp[i][3] = dp[i-1][1] + dp[i-1][2];
        dp[i][3] %= MOD;

        rep(i,0,4) dp[0][i] = dp[1][i];
    }

    cout << dp[0][3]% MOD << endl;

  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/

