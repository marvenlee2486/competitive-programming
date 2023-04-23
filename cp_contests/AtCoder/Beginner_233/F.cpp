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

vvii graph;
int p[1002];
vl path;
vl anspath;
vii edgelist;
bool found= false;

void dfspath(int u,int anc, int target){
    if(p[u]==target) {
        found=true;
        return;
    }

    for(auto &[v,i]:graph[u]){ 
        if(v==anc) continue;
        if(found == false)
        path.pb(i);
        dfspath(v,u,target);
        if(found == false)
        path.pop_back();
        if(found)return;
    }
    if(found) return;
   

}

void dfs(int u, int anc){
    
    for(auto &[v,i]:graph[u]){
        if(v==anc) continue;
        dfs(v,u);
    }
    found=false;
    dfspath(u,-1,u);
    reverse(ALL(path));
    for(int c:path){
        swap(p[edgelist[c].fi],p[edgelist[c].se]);
        anspath.pb(c);
    }
    path.clear();
}

int parent[N];
int findSet(int i){
    return (parent[i]==i)?i:parent[i]=findSet(parent[i]);
}

bool unionset(int u,int v){
    u = findSet(u);
    v = findSet(v);
    if(u==v) return false;

    parent[v]=u;

    return true;

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
rep(i,1,n+1){
    cin >> p[i];
    parent[i]=i;
}

int m;
cin >> m;
int a,b;
 graph.assign(n+1,vii());
rep(i,0,m){
    int a,b;
    cin >> a >> b;
     edgelist.pb(ii(a,b));
    if(!unionset(a,b))continue;
    graph[a].pb(ii(b,i));
    graph[b].pb(ii(a,i));
   
}
bool can=true;
rep(i,1,n+1){
    if(findSet(i) != findSet(p[i]) ) {
        can=false;break;
    }
}
if(!can){
    cout <<"-1\n";return 0;
}
for(int i=1;i<=n;i++){
    if(parent[i]==i) dfs(i,-1);
}


cout << anspath.size() << "\n";
//rep(i,1,n+1) cout << p[i] << " ";
FOR(c,anspath) cout << c+1 << " ";


  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/

