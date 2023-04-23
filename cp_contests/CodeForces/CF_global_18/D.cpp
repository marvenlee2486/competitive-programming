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
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        graph.assign(n+1,vii());
        viii edgelist;
        rep(i,0,n-1){
            int u,v,w;
            cin >> u >> v >> w;
            iii temp = iii(u,v,w);
            
            if(w!=-1){
                edgelist.pb(temp);
                int cnt =0;
                while(w!=0){
                    cnt+=w%2;
                    w/=2;
                }
                cnt%=2;
                w=cnt;
            }
            graph[u].pb(ii(v,w));
            graph[v].pb(ii(u,w));

        }
        rep(i,0,m){
            int u,v,c;
            cin >> u >> v >> c;
            graph[u].pb(ii(v,c));
            graph[v].pb(ii(u,c));
            
        }
        int r[n+1];
        FILL(r,-1);
        queue<int> q;
        bool can = true;
        rep(i,1,n+1){
            if(r[i]!=-1) continue;
            r[i]=0;
            q.push(i);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                
                for(auto&[v,w]:graph[u]){
                    if(w==-1) continue;
                    if(r[v]==-1) {
                        r[v] = r[u]^w;
                        q.push(v);
                    }
                    else{
                        if(r[v]!=r[u]^w){
                            can = false;
                            break;
                        }
                    }
                }
                if(can==false) break;
            }
            if(can==false) break;
        }

        if(can==false){
            cout << "NO\n";
            continue;
        }
        
        cout <<"YES\n";
        
        q.push(1);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(r[u]==-1)continue;

            for(auto&[v,w]:graph[u]){
                if(r[v]==-1) continue;
                q.push(v);
                if(w==-1){
                    w = r[v]^r[u];
                    iii temp = iii(u,v,w);
                    edgelist.pb(temp);
                }
            }

            r[u]=-1;
            
        }
        for(auto&[u,v,w]:edgelist){
            cout << u << " " << v << " " << w << "\n";
        }
        

    }

  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/

