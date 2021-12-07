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
#define LOG(message) cerr << message << "\n";
#else 
#define LOG(message)
#endif

ll mod(ll x, ll y = MOD) { return ((x % y) + y) % y; }

ll addm(ll x) { return x; }
template <typename... Ts> ll addm(ll x, Ts... ys) { return mod(x + addm(ys...)); }

ll mulm(ll x) { return x; }
template <typename... Ts> ll mulm(ll x, Ts... ys) { return mod(x * mulm(ys...)); }

bool clash(int xk, int yk, int x1, int y1, int x2 , int y2){
    if( (x1==xk  && y1==yk)||
     (x2==xk && y2 == yk) || 
     (x1==x2 && y1 == y2)||
     x1<1 || y1<1 || x1 >8 || y1 >8 || 
     x2<1 || y2<1 || x2>8 || y2>8
    ) return false;

    int dx[8] = {0,0,1,1,1,-1,-1,-1};
    int dy[8] = {1,-1,0,-1,1,0,-1,1};

    for(int d=0;d<8;d++){
        int nx = dx[d]+xk;
        int ny = dy[d]+yk;

        if(nx<1 || ny<1 || nx>8|| ny>8) continue;
        
        if( (!(x1==nx && y1==ny) && (nx == x1||ny == y1 ))||
          (!(x2==nx && y2==ny) && (nx == x2||ny == y2 ))
          ) continue;

          return false;
    }
    LOG( xk << " " << yk << " "<< x1 << " " << y1  << " " << x2 << " " << y2 );
    return true;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
 while(t--){
 int xk,yk,x1,y1,x2,y2;
 cin >> xk >> yk >> x1 >> y1 >> x2 >> y2;

    if(  ( (y1!=y2 || !(x2 > min(x1,xk) && x2 < max(x1,xk) ) ) && clash(xk,yk,xk,y1,x2,y2) )|| ((x1!=x2 || !(y2 > min(y1,yk) && y2 < max(y1,yk) )) && clash(xk,yk,x1,yk,x2,y2) ) ||
     ((y1!=y2 || !(x1 > min(x2,xk) && x1 < max(x2,xk) ))&& clash(xk,yk,xk,y2,x1,y1)) ||  ((x1!=x2 || !(y1 > min(y2,xk) && y1 < max(y2,xk))) && clash(xk,yk,x2,yk,x1,y1) )
     ){
         cout <<"YES\n";
     }
     else cout << "NO\n";
    
 }

  
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
