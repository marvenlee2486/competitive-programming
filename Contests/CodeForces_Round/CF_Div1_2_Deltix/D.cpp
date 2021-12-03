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
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

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
#define LOG(message) // cerr << message << endl;
#else 
#define LOG(message)
#endif



ll mod(ll x, ll y = MOD) { return ((x % y) + y) % y; }

ll addm(ll x) { return x; }
template <typename... Ts> ll addm(ll x, Ts... ys) { return mod(x + addm(ys...)); }

ll mulm(ll x) { return x; }
template <typename... Ts> ll mulm(ll x, Ts... ys) { return mod(x * mulm(ys...)); }




multiset<int> as;

ll parent[N];
ll num_set[N];

ll maxv =0;
ll minv =0;
ll sum =0;
int cnt =0;
ll findset(int u){
    return parent[u] = (parent[u]==u)? u: findset(parent[u]);
}

bool isSameset(int u,int v){
    return findset(u)==findset(v);
}
int extra =0;
void unionset(int u,int v){
    u = findset(u);
    v= findset(v);
    if(isSameset(u,v)){
        
        cnt++;
        return;
    }

    parent[u]= parent[v];
    as.erase(as.find(num_set[v]));
    as.erase(as.find(num_set[u]));
    num_set[v] += num_set[u];
    LOG(as.size());
    as.insert(num_set[v]);

   
    num_set[u] = 0;
}
/*
7 6
1 2
3 4
2 4
7 6
6 5
1 7
*/
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n,d;

  cin >> n >> d;
rep(i,0,n){
    num_set[i]=1;
    as.insert(1);
}
iota(parent,parent+n,0);
    while(d--){
        int u,v; cin >> u >> v;
        u--,v--;
        //cout << "YE" << endl;
        LOG("ENTER!!!")
        unionset(u,v);
        ll sum=0;
        int c=0;
        for(auto it=as.rbegin();it!=as.rend();it++){
            sum+= *it;
            //cout << *it << " ";

            if(c==cnt) break;
            c++;
        }
        cout << sum-1 << endl;
    }

  return 0;
}


/*
Advise
0) RMB TO LOOK AT INPUT RANGE AND TAKE NOTE!!!!!!
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
