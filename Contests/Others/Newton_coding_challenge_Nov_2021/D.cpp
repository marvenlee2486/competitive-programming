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
   
    return  binpow(a, MOD - 2);
    
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n,m,k;
  cin >> n >> m >> k;
  int cell[n+2][m+2];

  FILL(cell,0);
  while(k--){
      int x,y;
      char c;
      cin >> x >> y >> c;
      int fill = 1;
      if(c=='R') fill =0;
      rep(i,0,n+2){
        if((x+i)%2 == fill){
            cell[x][i] = -1;
            
        }
        
      }
      fill = 1-fill;
      rep(i,0,m+2){
        if((i+y)%2 == fill){
            cell[i][y] = -1;  
        }
      }
  }

  queue<ii> q;
  q.push({1,1});
    int dist[n+2][m+2];
    FILL(dist,-1);
    dist[1][1]=0;
 int dx[4]= {0,0,-1,1};
 int dy[4] = {1,-1,0,0};
   
 while(!q.empty()){
     int x,y;
     tie(x,y) = q.front();
     q.pop();
   
     if(cell[x][y]==-1) continue;
    cell [x][y]=-1;
     for(int d=0;d<4;d++){
         int nx = x +dx[d];
         int ny = y + dy[d];
    
         if(nx<1 || nx>n || ny<1 || ny >m || cell[nx][ny]==-1) continue;
         dist[nx][ny] = dist[x][y]+1;
        q.push({nx,ny});
         
     }



 }

  cout << dist[n][m] << "\n";
 



  

  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/