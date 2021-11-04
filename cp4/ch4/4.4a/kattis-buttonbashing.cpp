
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
    int test; cin >> test;
    while(test--){
        int n,t;
        cin >> n >> t;
        int arr[n];
        rep(i,0,n) cin >> arr[i];
        graph.assign(3601,vl());

        rep(i,0,3601){
            rep(j,0,n){
                if(arr[j]>0) graph[i].pb(  min(i+arr[j],3600ll)     );
                else graph[i].pb(  max(i+arr[j],0ll)     );
            }
        }

        vl dist(3601,-1);
        dist[0]=0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int u = q.front();
            q.pop();

            FOR(v,graph[u]){
                if(dist[v]!=-1) continue;

                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        rep(j,t,3601){
            if(dist[j]!=-1){
                cout << dist[j] << " " << j-t << "\n";
                break;
            }
        }

    }
    
} 

  
