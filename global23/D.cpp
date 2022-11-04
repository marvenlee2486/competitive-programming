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

vvl graph;
vl a;
vii dp;
void dfs(ll u,ll k){
    //cout << u << " " << k <<'\n';
    if(graph[u].size()==0){
        dp[u] = ii( (k+1)*a[u],(k)*a[u]);
        return;
    }
    vl temp;
    ll first = (k+1) * a[u];
    ll second =  k * a[u];

    for(int v:graph[u]){
        dfs(v,k/graph[u].size());
        temp.push_back(dp[v].first - dp[v].second);
        first += dp[v].first;
        second += dp[v].first;
        //assert(dp[v].first > dp[v].second);
    }
    sort(ALL(temp));
    ll remain = k%graph[u].size();
    //cout << u << " " << remain << "remain\n";
    for(int i =0 ; i< graph[u].size()-remain;i++){
        if(i!=  graph[u].size()-remain-1) first -= temp[i];
        second -= temp[i];
    }
    // for(auto&[i1,i2]:temp){
    //     cout << i1 << " " << i2 <<'\n';
    // }

    dp[u] = ii(first,second);

}

void solve(){
    ll n,k;
    cin >> n >> k;

    graph.assign(n+1,vl());
    a.assign(n,0);
    dp.assign(n,ii(0,0));
    for(int i=1;i<n;i++){ 
        int p;
        cin >> p;
        graph[p-1].push_back(i);
    }
    rep(i,0,n) cin >> a[i];

    dfs(0,k);
    cout << dp[0].second << "\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
