

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef string str;
typedef vector<ll>  vl;
typedef vector< vector<ll> > vvl;
typedef vector<ii> vii;
typedef vector< vector<ii> > vvii;
typedef vector<iii> viii;
typedef vector< vector<iii> > vviii;
typedef vector<str>  vs;
typedef vector< vector<str> > vvs;
typedef long double ld;

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
int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("UT.txt","w",stdout);
 int c,p,x,l;
 cin >> c >> p >> x >> l;
 vvl graph(c+1,vl());
 int leave[c+1];
 int cnt[c+1];
 FILL(leave,0);
    FILL(cnt,0);
    while(p--){
        int a,b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
        
    }

    leave[l]=1;
    FOR(v,graph[l]){
            cnt[v]++;
        }
    priority_queue<ll,vl,greater<ll>> pq;
    pq.push(l);

    while(!pq.empty()){
        ll u = pq.top();
        pq.pop();
        
        FOR(v,graph[u]){
            if(leave[v])continue;
            
            if( 2* cnt[v] >= graph[v].size() ) {
                leave[v]=1;
                FOR(v2,graph[v]) cnt[v2]++;
                pq.push(v);
            }
        }
    }

    cout << ( (leave[x])? "leave\n": "stay\n");



}
  
