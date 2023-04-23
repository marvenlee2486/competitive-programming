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

int p[1002];

int find_parent(int u){
    return (p[u]==u)?u:p[u]=find_parent(p[u]);
}

void uni(int u,int v){
    int x = p[u], y = p[v];
    if(x==y) return;
    p[x]=p[y];
}

void solve(){
   int n;
   cin >> n;
   ii d[n];
   rep(i,0,n) p[i]=-1;
   rep(i,0,n){
    int v;
    cin >> v;
     d[i]= ii(v,i);
   }
   sort(d,d+n);
   reverse(d,d+n);
   rep(id,0,n){
    int i = d[id].second;
     if(p[i]!=-1) continue; 
     p[i]=i;
     rep(j,0,d[id].first){
        cout << "? " << i+1 << endl;
        int y;
        cin >> y;
        y--;
        if( p[y]!=-1 ){
            uni(i,y);
            break;
        }
        p[y] = i;
     }
   }
   int c=1;
   int col[n];
   rep(i,0,n) col[i]=-1;
    cout << "! ";
   rep(i,0,n){
    if( col[find_parent(i)]==-1) col[p[i]]=c++;
    cout << col[find_parent(i)] << " ";

   }
   cout << endl;

   
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
