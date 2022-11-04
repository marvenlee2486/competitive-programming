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

const ll MOD = 998244353;
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

ll fact[62];
unordered_map<ll,ll> inv;

vvl graph;
vl depth;
vl lazy;

vl p;
int n;
int k;
int target=0;
int op;
int recur(int u, int anc=-1){
    int ans =0;
    for(int v:graph[u]){
        if(v==anc) continue;
        ans = max(recur(v,u)+1,ans);
    }
    //cout << ans << " ";
    if(ans==target-1 && (anc !=-1 && anc!=0) ){
        op++;
        ans =-1;
    }
    
    return ans;

}

bool can(int de){
    op = 0;
//cout <<de << "\n";
    target = de;
    recur(0);
    if(op>k) return false;
    else return true;

}
void solve(){
    cin >> n >> k;
    graph.assign(n+1,vl());
    depth.assign(n,0);
    p.assign(n,0);
    depth[0]=0;

   
    rep(i,0,n-1){
        
        cin >> p[i+1];
        p[i+1]--;
        depth[i+1] = depth[p[i+1]]+1;
        graph[p[i+1]].pb(i+1);
        graph[i+1].pb(p[i+1]);
    }

     int lo = 1, hi = n-1;
    while(lo<hi){
        int mid = (lo+hi)/2;

        if(can(mid)) hi = mid;
        else lo=mid+1;
    }
    cout << lo << '\n';

    return;

}  

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t =1 ;
  
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
