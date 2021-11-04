

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef string str;
typedef vector<ll>  vl;
typedef vector< vector<ll> > vvl;
typedef vector<ii> vii;
typedef vector< vector<ii> > vvii;
typedef vector<iii> viii;
typedef vector< vector<iii> > vviii;
typedef vector<str>  vs;
typedef vector< vector<str> > vvs;
typedef long double ld;

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
int n,m;
int visited[200002];
void dfs(int u,int anc=-1){
    if(visited[u]) return;
    visited[u]=1;
    FOR(v,graph[u]){
        if(v==anc || visited[v]) continue;
       
        dfs(v,u);
    }
}


int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("UT.txt","w",stdout);

 
 
     int n,m;
     cin >> m >> n;
     int arr[n+2][m+2];
     FILL(arr,-1);
     rep(i,1,n+1){
         rep(j,1,m+1){
            cin >> arr[i][j]; 
         }
     }
     int node =0;
     int p [n+2][m+2];
     vl sizes;
     FILL(p,-1);
     
     rep(i,1,n+1){
         rep(j,1,m+1){
             
            if(p[i][j]!= -1) continue;
            int cnt=0;
            queue<ii> q;
            q.push(ii(i,j));
            while(!q.empty()){
                int x,y;
                tie(x,y)=q.front();
                q.pop();
                if(p[x][y]==node) continue;
                p[x][y]=node;
                cnt++;
                if(arr[x+1][y] == arr[x][y] && p[x+1][y]!=node) q.push(ii(x+1,y));
                if(arr[x-1][y] == arr[x][y] && p[x-1][y]!=node) q.push(ii(x-1,y));
                if(arr[x][y+1] == arr[x][y] && p[x][y+1]!=node) q.push(ii(x,y+1));
                if(arr[x][y-1] == arr[x][y] && p[x][y-1]!=node) q.push(ii(x,y-1));
            }
            sizes.pb(cnt);
            node++;
        }
     }
     
     vvl graph(node,vl());
     int ans[node];
     
     FILL(adj,0);
     rep(i,1,n+1){
         rep(j,1,m+1){
             if(p[i][j] != p[i-1][j] && p[i-1][j]!=-1 ){
                if(arr[i][j]<arr[i-1][j] && adj[p[i-1][j]][p[i][j]] == 0){
                    graph[p[i-1][j]].pb(p[i][j]);
                    adj[p[i-1][j]][p[i][j]] =1;
                }
                else if(arr[i][j]>arr[i-1][j] && adj[p[i][j]][p[i-1][j]] == 0){
                    graph[p[i][j]].pb(p[i-1][j] );
                    adj[p[i][j]] [p[i-1][j]]=1; 
                }
             }
            if(p[i][j] != p[i+1][j] && p[i+1][j]!=-1 ){
                if(arr[i][j]<arr[i+1][j] && adj[p[i+1][j]][p[i][j]] == 0){
                    graph[p[i+1][j]].pb(p[i][j]);
                    adj[p[i+1][j]][p[i][j]] =1;
                }
                else if(arr[i][j]>arr[i+1][j] && adj[p[i][j]][p[i+1][j]] == 0){
                    graph[p[i][j]].pb(p[i+1][j] );
                    adj[p[i][j]] [p[i+1][j]]=1; 
                }
             }

             if(p[i][j] != p[i][j-1] && p[i][j-1]!=-1 ){
                if(arr[i][j]<arr[i][j-1] && adj[p[i][j-1]][p[i][j]] == 0){
                    graph[p[i][j-1]].pb(p[i][j]);
                    adj[p[i][j-1]][p[i][j]] =1;
                }
                else if(arr[i][j]>arr[i][j-1] && adj[p[i][j]][p[i][j-1]] == 0){
                    graph[p[i][j]].pb(p[i][j-1] );
                    adj[p[i][j]] [p[i][j-1]]=1; 
                }
             }

             if(p[i][j] != p[i][j+1] && p[i][j+1]!=-1 ){
                if(arr[i][j]<arr[i][j+1] && adj[p[i][j+1]][p[i][j]] == 0){
                    graph[p[i][j+1]].pb(p[i][j]);
                    adj[p[i][j+1]][p[i][j]] =1;
                }
                else if(arr[i][j]>arr[i][j+1] && adj[p[i][j]][p[i-1][j]] == 0){
                    graph[p[i][j]].pb(p[i][j+1] );
                    adj[p[i][j]] [p[i][j+1]]=1; 
                }
             }



         }
     }
     
        int ans=0;
        
     rep(i,0,node){
         if(graph[i].size()==0) ans+= sizes[i];
     }
cout << ans << "\n";


 
}
  
