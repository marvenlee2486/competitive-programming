
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
    int h,w;
    while(cin >> h >> w && h){
        int grid[h][w];
        FILL(grid,-1);
        int g; cin >> g;
        vvii graph (w*h,vii());
        while(g--){
            int x,y;
            cin >> x >> y;
            grid[x][y]=-2;
        }
        
        map<int,int> weight;
        int e; cin >> e;
        while(e--){
            int x1,y1,x2,y2,t;
            cin >> x1 >> y1 >> x2 >> y2 >> t;
            grid[x1][y1] = x2*w + y2;
            weight[x2*w + y2] = t;
        }
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        rep(i,0,h){
            rep(j,0,w){
              //cout << grid[i][j] << " ";
              if(grid[i][j]==-2) continue;
                if(grid[i][j]>=0){
                    graph[i*w+j].pb(ii(grid[i][j], weight[grid[i][j]] ));
                }
                else{
                  rep(d,0,4){
                      if(i+dx[d]<0 || i+dx[d]>=h || j+dy[d]<0 || j+dy[d]>=w || grid[i+dx[d]][j+dy[d]]== -2 ) continue;
                      
                      graph[ i*w + j ].pb( ii((i+dx[d])*w + (j+dy[d]) ,1) );

                  }
                }
            }
            //cout << "\n";
        }

        vl dist(h*w, INF); dist[0]=0;
        rep(i,0,h*w-1){
            rep(u,0,h*w){
                if(dist[u]!=INF)
                    for(auto &[v,w]:graph[u])
                        MIN(dist[v],dist[u]+w);
            }
        }

        bool negative = false;
        rep(u,0,w*h){
            if(dist[u]!= INF)
                for(auto &[v,w] : graph[u])
                    if(dist[v] > dist[u]+w) negative = true;
        }

        if(negative) cout << "Never\n";
        elif(dist[w*h - 1] == INF) cout <<"Impossible\n";
        else cout << dist[w*h-1] << "\n";
    }
} 

  
