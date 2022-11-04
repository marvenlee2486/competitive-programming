#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef string str;
typedef vector<ll>  vl;
typedef vector< vector<ll> > vvl;
typedef vector<ii> vii;
typedef vector< vector<ii> > vvii;
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
const ll N = 1e5+2;

#ifndef ONLINE_JUDGE
#define LOG(message) cerr << message << endl;
#else 
#define LOG(message)
#endif
ll n,q;
vvii graph;


void solve(){
    ll n,q;
    cin >> n >> q;
    int ans[n][32];
    graph.assign(n,vii());

    FILL(ans,-1);
    while(q--){
        int i,j,x;
        cin >> i >> j >> x ;
        i--;
        j--;
        if(i>j) swap(i,j);
        rep(bit,0,32){
            if( (x&(1<<bit)) ==0 ){
                ans[i][bit] = 0;
                ans[j][bit] = 0;
            }
            else if(i==j){
                ans[i][bit] = 1;
            }
        }
        graph[i].pb(j,x);
        graph[j].pb(i,x);
    }
    

    rep(bit,0,32){
        rep(i,0,n){
            if(ans[i][bit]!=-1) continue;
            int u;
            for(ii temp :graph[i]){
                u = temp.first;
                if(ans[u][bit]==0){
                    ans[i][bit] = 1;
                    break;
                }
            }
            if(ans[i][bit]==-1) ans[i][bit]=0;

        }
    }
    rep(i,0,n){
        ll cur = 0;
        rep(j,0,32){
            cur += (ans[i][j] << j);
        }
        cout << cur << " ";
    }
    

    


}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  while(t--) solve();
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
