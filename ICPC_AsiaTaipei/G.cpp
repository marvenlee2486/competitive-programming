#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
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
const ll N = 1e6+2;

#ifndef ONLINE_JUDGE
#define LOG(message) cerr << message << endl;
#else 
#define LOG(message)
#endif

int dx[] = {1,0,0,-1,0};
int dy[] = {0,1,-1,0,0};
bool dp[42][42][842];
    bool dp2[42][42][842];
    
void solve(){
    int m,n;
    cin >> m >> n;
    int a[n+2][m+2];
    rep(i,0,n+2) rep(j,0,m+2) a[i][j] = INF;
    rep(i,1,n+1){
        rep(j,1,m+1){
            cin >> a[i][j];
        }
    }
    int x,y;
    cin >> y >> x;
    y++,x++;
    queue<iii> q;
    q.push(iii(ii(x,y),0));
    int g;cin >> g;
    
    
    memset(dp,0,sizeof dp);
    memset(dp2,0,sizeof dp);
    
    vvii guard (g,vii());
    unsigned int lcm = 1;
    dp[x][y][0] = 1;
    rep(i,0,g){
        unsigned int nu;
        cin >> nu;
        lcm = lcm*nu/(__gcd(lcm,nu));
        rep(j,0,nu){
            cin >> y >> x;
            y++,x++;
            //cout << x << " " << y << "\n";
            guard[i].push_back(ii(x,y));
        }
    }

    for(int nx =1;nx<=n;nx++){
        for(int ny=1;ny<=m;ny++){ 
            for(int cost = 0;cost <lcm;cost++){
                bool can = true;
                for(int i = 0;i<g;i++){
                    if(
                        (nx==guard[i][ cost%guard[i].size() ].fi && ny==guard[i][ cost%guard[i].size() ].se ) || 
                        (nx==guard[i][ (cost+1)%guard[i].size() ].fi && ny==guard[i][ (cost+1)%guard[i].size() ].se )
                    ){
                        can=false;
                        break;
                    }
                }
                dp[nx][ny][cost]=can;
            }
        }
    }
    
    int ans = -1;
    
    int cost;
    while(!q.empty()){
        auto temp = q.front();
        //cout << x<< " " << y << "\n";
        x = temp.fi.fi;
        y = temp.fi.se;
        cost = temp.se;
        
        if(a[x][y] == 0){
            ans = cost;
            break;
        }
        q.pop();
        
            int ncost = cost%lcm;
        
        for(int d=0;d<5;d++){
            int nx = x+dx[d];
            int ny = y+dy[d];
            int mcost = (cost+1)%lcm;
            if(a[nx][ny]>a[x][y] || !dp[nx][ny][ncost] || dp2[nx][ny][mcost]) continue;
            dp2[nx][ny][mcost] = true;
            q.push(iii(ii(nx,ny),cost+1));
            
            
        }

    }

    cout << ans << "\n";
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

