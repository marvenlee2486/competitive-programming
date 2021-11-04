

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
int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("UT.txt","w",stdout);
 
    int n,m;
    cin >> n >> m;
    vvl graph(n,vl());
    int in_degree[n];
    int visited[n];
    FILL(in_degree,0);
    FILL(visited,0);

    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        u--,v--;

        graph[u].pb(v);
        in_degree[v]++;

    }
    queue<ll> q;
    rep(i,0,n){
        if(in_degree[i]==0) q.push(i);
    }
    vl ans;
    int check=0;
    while(!q.empty()){
        int u = q.front();
        if(check) break;
        q.pop();
        visited[u]=1;
        ans.pb(u);
        FOR(v,graph[u]){
            if(visited[v]) check = 1;
            in_degree[v]--;
            if(in_degree[v]==0) q.push(v);
        }

    }
    rep(i,0,n){
        if(!visited[i]) check =1;
    }
    if(check ) cout <<"IMPOSSIBLE\n";
    else{
        FOR(v,ans) cout << v+1 << "\n";
    }
    
}
  
