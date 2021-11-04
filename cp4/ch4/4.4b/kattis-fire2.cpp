
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ld,ll,ll> iii;
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
vvl graph;
int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("UT.txt","w",stdout);
int t;
cin >> t;
while(t--){
    int w,h;
    cin >> w>> h;
    str grid[h];
    rep(i,0,h) cin >> grid[i];

    vii fire;
    ii start;
    rep(i,0,h){
        rep(j,0,w){
            if(grid[i][j] == '*') fire.pb(ii(i,j));
            if(grid[i][j] == '@') start = ii(i,j);
        }
    }

    int firedistance[h][w];
    FILL(firedistance,-1);

    queue<ii> q;
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    for(auto&[x,y]:fire){
        q.push(ii(x,y));
        firedistance[x][y]=0;
        while(!q.empty()){
            auto[i,j] = q.front();
            q.pop();

            rep(d,0,4){
                if(i+dx[d] >= h || i+dx[d]<0 || j+dy[d]>=w || j+dy[d]<0 || grid[i+dx[d]][j+dy[d]] == '#') continue;
                if(firedistance[i+dx[d]][j+dy[d]] > firedistance[i][j]+1 || firedistance[i+dx[d]][j+dy[d]]  == -1){
                    firedistance[i+dx[d]][j+dy[d]] = firedistance[i][j]+1;
                    q.push(ii(i+dx[d],j+dy[d]));

                }
            }

        }
    }
    int dist[h][w];
    FILL(dist,-1);
    dist[start.fi][start.se]=0;
    q.push(ii(start.fi,start.se));
    
    while(!q.empty()){
        auto[i,j] = q.front();
        q.pop();

        rep(d,0,4){
            if(i+dx[d] >= h || i+dx[d]<0 || j+dy[d]>=w || j+dy[d]<0 || 
            grid[i+dx[d]][j+dy[d]] == '#' || (firedistance[i+dx[d]][j+dy[d]]!=-1 && firedistance[i+dx[d]][j+dy[d]]<=dist[i][j]+1 )|| dist[i+dx[d]][j+dy[d]]!= -1) continue;
            
            if(dist[i+dx[d]][j+dy[d]]  == -1){
                dist[i+dx[d]][j+dy[d]] = dist[i][j]+1;
                q.push(ii(i+dx[d],j+dy[d]));

            }
        }

    }
    int ans = INF;
    rep(i,0,h){
        if( grid[i][0] != '#' && dist[i][0] != -1) MIN(ans,dist[i][0]+1); 
        if( grid[i][w-1] != '#' && dist[i][w-1] != -1) MIN(ans,dist[i][w-1]+1); 
    }
    rep(j,0,w){
      
        if( grid[0][j] != '#' && dist[0][j] != -1) MIN(ans,dist[0][j]+1); 
        if( grid[h-1][j] != '#' && dist[h-1][j] != -1) MIN(ans,dist[h-1][j]+1); 
    }
    if(ans == INF) cout << "IMPOSSIBLE\n";
    else cout << ans << "\n";


}
    
} 

  
