
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
        str block[h];
        rep(i,0,h) cin >> block[i];

        priority_queue<iii, viii, greater<iii>> pq;
        int dist[h][w];
        rep(i,0,h){
          rep(j,0,w) dist[i][j] = INF;
        }
        ii parent[h][w];
        rep(i,0,h){
          rep(j,0,w) parent[i][j] = ii(0,0);
        }
        rep(i,0,w){
            dist[0][i] = block[0][i]-'0';
            pq.emplace(dist[0][i],0,i);
        } 
        
        int dx[] = {0,0,1,1,1,-1,-1,-1};
        int dy[] = {1,-1,0,1,-1,0,1,-1};
        while(!pq.empty()){
            auto [d,ui,uj] = pq.top();
            pq.pop();
            if(dist[ui][uj]!=d) continue;
            
            rep(d,0,8){
                int vi = ui + dx[d], vj =uj +dy[d];
                if(vi<0 || vi >=h || vj<0 || vj >=w) continue;
                int w = block[vi][vj]-'0';
                if(dist[ui][uj] + w >= dist[vi][vj] ) continue;
                
                parent[vi][vj]=ii(ui,uj);
                dist[vi][vj] = dist[ui][uj] + w; 
                pq.emplace(dist[vi][vj],vi,vj);
            }
        }
       int minj;
       int minv = INF;

       rep(j,0,w){
           if(dist[h-1][j]<minv ) {
               minv = dist[h-1][j];
               minj = j;
           }
       }

       int j = minj;
       int i = h-1;
       while(i!=0){
           block[i][j]= ' ';
           auto&[u,v] = parent[i][j];
           i=u,j=v;
       }
        block[i][j]= ' ';
       rep(i,0,h) cout << block[i] << "\n";
        cout << "\n";
    }
    
} 

  
