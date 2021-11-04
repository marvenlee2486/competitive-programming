

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

int cnt;
bool ans = false;
void dfs(int u,  int anc =- 1){
    dfs_num[u] = cnt++;
    dfs_low[u] = dfs_num[u];

    FOR(v, graph[u]){
        if(v == anc) continue;
        if(dfs_num[v]){
            MIN(dfs_low[u],dfs_num[v]);
            continue;
        }

        dfs(v,u);

        if(dfs_low[v] > dfs_num[u]) ans = true;

        MIN(dfs_low[u],dfs_low[v]);

    }
}

int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("UT.txt","w",stdout);
 
 int p, c; 
 while(cin >> p  && cin >> c && p){
    graph.assign(p,vl());
    dfs_num.assign(p,0);
    dfs_low.assign(p,0);
    rep(i,0,c){
        int a,b; cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    cnt =0;
    ans = false;
    dfs(0);
    rep(i,0,p) if(i !=0 && dfs_num[i]==0) ans= true;
    // If original graph is not connected, then no matter what it is dy Yes

    if(ans) cout << "Yes" << "\n";
    else cout <<"No\n";
 }
    
}
  
