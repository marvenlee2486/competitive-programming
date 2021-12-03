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
const ll N = 2e5+2;

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

ll parent[N];
ll num_set=0;

ll findset(int u){
    return parent[u] = (parent[u]==u)? u: findset(parent[u]);
}

bool isSameset(int u,int v){
    return findset(u)==findset(v);
}

void unionset(int u,int v){
    if(isSameset(u,v)){
        return;
    }

    parent[findset(u)]= parent[findset(v)];
    num_set --;
}



int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

    int n,m;
    cin >> n >> m;

    vvl graph(n+1,vl());
    rep(i,0,m){
        int u,v; cin >> u >> v;
        graph[u].pb(v);
    }
    ll ans[n+1];
    rrep(i,n,1){
        parent[i]=i;
        
        ans[i] = num_set;
        FOR(v,graph[i]){
            unionset(i,v);
        }
        num_set++;
    }

    rep(i,1,n+1) cout << ans[i] << "\n";


  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
