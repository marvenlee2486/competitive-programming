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
const ll N = 1e6+2;
vvl graph;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("another.txt","w",stdout);
  int n,m; cin >> n >> m;
  graph.assign(n+2,vl());
  
  rep(i,0,m){
    int u,v;
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }

  queue<int> q;

  int allocated[n+1];
  FILL(allocated,0);
  bool ans =true;
  rep(vertex,1,n+1){
      if(allocated[vertex]) continue;
      if(graph[vertex].size()==0) continue;
      q.push(vertex);
      allocated[vertex]=1;
      while(!q.empty()){
        int u = q.front();
        q.pop();
        FOR(v,graph[u]){
          //cout << v << " " << allocated[v] << " " << u << allocated[u] << "\n";
          if(allocated[v]==allocated[u]) ans=false;
          if(allocated[v]) continue;
          allocated[v] = 3 - allocated[u];
          q.push(v);
        }
      }
  }
  if(!ans) {
    cout << "-1\n"; return 0;
  }
  vl ans1,ans2;
  rep(i,1,n+1) {
    if(allocated[i]==0) continue;
    if(allocated[i]==1) ans1.pb(i);
    else ans2.pb(i);
  }
  cout << ans1.size() <<"\n";
  FOR(c,ans1) cout << c << " ";
  cout << "\n";
  cout << ans2.size() << "\n";
  FOR(c,ans2) cout << c << " ";

  return 0;
}


/*
Advise
1) 逆向思维!!
2) long long
3)
*/
