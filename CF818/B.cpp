#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef string str;
typedef vector<ll>  vl;
typedef vector< vector<ll> > vvl;
typedef vector<ii> vii;
typedef vector< vector<ii> > vvii;
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
const ll N = 1e5+2;

#ifndef ONLINE_JUDGE
#define LOG(message) cerr << message << endl;
#else 
#define LOG(message)
#endif

void solve(){
    int n,k,r,c;
    cin >> n >> k >> r >> c;
    r--,c--;
    char ans[n][n];
    rep(i,0,n) rep(j,0,n) ans[i][j] ='.';
    
    int left = r+c;
    int modleft,moddown;
    if(left<n){
         modleft = left%k;
         moddown = (modleft+1)%k;
         // 1 2
    }
    else{
        int down = c-(n-1-r );
        moddown =  down%k;
        modleft = ((moddown-1)+k)%k;
        // 1 , 0
        // 0 , 2 
        // 2 , 1
    }

    left = modleft;
    while(left<n){
        int i = left;
        int j = 0;
        while(j<n && i>=0){
            ans[i][j] = 'X';
            j++,i--;
        }
        left += k;
    }
    int down = moddown;
    while(down<n){
        int i = n-1;
        int j = down;
        while(j<n && i>=0){
            ans[i][j]='X';
            j++,i--;
        }
        down += k;
    }
    rep(i,0,n){
        rep(j,0,n) cout << ans[i][j];
        cout << "\n";
    }
    
    
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  cin >> t;
  while(t--) solve();
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
