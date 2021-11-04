

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
const ll LEN = 1e6 +2;
map<str, set<str> > graph;
map<str,str> visited;

void dfs(str u, str anc=""){

    if(visited.find(u)!=visited.end()) return;
    
    visited[u]=anc;
    FOR(v, graph[u]){
        if(visited.find(v)!=visited.end()) continue;
        dfs(v,u);
    }

}



int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("UT.txt","w",stdout);
    int n;
    cin >> n;
    
    str s;  
    getline(cin, s);

    rep(i,0,n){
        getline(cin,s);
        stringstream ss (s);
        str token;
        vs tokens;
        while(getline(ss,token,' ')){
            tokens.pb(token);
        }
        rep(i,1,tokens.size()){
            graph[tokens[0]].insert(tokens[i]);
            graph[tokens[i]].insert(tokens[0]);
        }
        
    }
    str start, end;
    cin >> start >> end;
    dfs(start);
    if(visited.find(end)==visited.end()) cout << "no route found\n";
    else{
        vs ans;
        ans.pb(end);
        str now = end;
        while(now!=start){
            now=visited[now];
            ans.pb(now);
        }
        reverse(ALL(ans));
        FOR(v,ans) cout << v << " ";
    }
}
  
