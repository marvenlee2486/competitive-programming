
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ld,ll,ll> iii;
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
vvl graph;
int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("UT.txt","w",stdout);
    int p,t;
    cin >> p >> t;

    vvii graph (p,vii());

    rep(i,0,t){
        int p1,p2,l;
        cin >> p1 >> p2 >> l;
        graph[p1].pb(ii(p2,l));
        graph[p2].pb(ii(p1,l));
    }

    priority_queue<ii, vii, greater<ii>> pq;
    pq.emplace(0,0);
    vl dist(p,INF);
    dist[p] = 0;
    vvii parent(p,vii());
    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();

        for( auto[v,w]: graph[u]){
            if(dist[u]+w == dist[v]) parent[v].pb(ii(u,w)));
            if(dist[u]+w >= dist[v] ) continue;
            parent[v].clear();
            parent[v].pb(ii(u,w));
            dist[v] = dist[u] + w; 
            pq.emplace(dist[v],v);
        }
    }
    queue<ll> q;
    q.push(p-1);
    ll ans =0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto[u,w]:parent[v]){
            ans+=w;
            q.push(u);
        }
    }
    cout << ans;

   
    
} 

  
