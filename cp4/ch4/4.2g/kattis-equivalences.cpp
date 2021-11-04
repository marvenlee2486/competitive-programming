
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
vl dfs_num;
vl dfs_low;
vl visited;
stack<int> St;
int cnt;
int ans;

void dfs(int u){
    cnt++;
    dfs_num[u] = dfs_low[u] = cnt;

    St.push(u);
    visited[u]=1;
    FOR(v, graph[u]){

        if(dfs_num[v]==0)
            dfs(v);
        if(visited[v]){
            
            MIN(dfs_low[u],dfs_low[v]);
        }
            
        
    }
    if(dfs_low[u] == dfs_num[u]){
       
        while(1){
            int v = St.top(); St.pop();
            visited[v] = 0;
            if(u==v) break;
        }
    }
}

int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("UT.txt","w",stdout);
 
 int t; cin >> t; 
 while(t--){
    int n,m;
    cin >> n >> m;
    while(!St.empty()) St.pop();
    graph.assign(n+1,vl());
    dfs_num.assign(n+1,0);
    dfs_low.assign(n+1,0);
    visited.assign(n+1,0);
   // cout << "ROW " << t << "\n";
   // cout << n <<  " "<< m <<"\n";

    rep(i,0,m){
        int x,y; cin >> x >> y;
        //cout << x << " " << y <<"\n";
        graph[x].pb(y);
    }
    
    cnt = 0;
    rep(i,1,n+1) if(dfs_num[i]==0)  dfs(i);
    vl in_degree(cnt+1,-1);
    vl out_degree(cnt+1,-1);
    rep(u,1,n+1){
        //cout << in_degree[u] << "\n";
        if( in_degree[dfs_low[u]] == -1) in_degree[dfs_low[u]]=0;
        if( out_degree[dfs_low[u]] == -1) out_degree[dfs_low[u]]=0;
        
        FOR(v,graph[u]){
           // cout << dfs_low[u] << " " <<  dfs_num[v] << "\n";
            if( in_degree[dfs_low[v]] == -1) in_degree[dfs_low[v]]=0;
            if( out_degree[dfs_low[v]] == -1) out_degree[dfs_low[v]]=0;
            
            if(dfs_low[u]!=dfs_low[v] ){
              out_degree[dfs_low[u]]++;
              in_degree[dfs_low[v]]++;
            } 
        }
    }
    //rep(i,1,cnt+1) cout << in_degree[i] << " ";
    ans = 0;
    int ans_out = 0;
    int cnt2=0;
    rep(i,1,cnt+1){
        if(in_degree[i]!=-1) cnt2++;
        if(in_degree[i]==0) ans++;
        if(out_degree[i]==0) ans_out++;
    } 
    //rep(i,1,n+1) cout << dfs_low[i] << "\n";
    if (cnt2==1) ans=0,ans_out=0;
    cout << max(ans,ans_out) << "\n";
    
 }
    
}
  
