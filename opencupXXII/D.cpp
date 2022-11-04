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
const ll N = 1e6+1;

#ifndef ONLINE_JUDGE
#define LOG(message) cerr << message << endl;
#else 
#define LOG(message)
#endif

void solve(){
    int n;
    cin >> n;
    ll x,y,v;
    map<ii,int> mpp;
    ll row[N];
        ll col[N];
    rep(i,0,n){
         cin >> x >> y >> v;
        x--,y--;
        
        row[x]+=v;
        col[y]+=v;
        mpp[ii(x,y)]=v;
    }
    vector<ii> roww;
    vector<ii> coll;
    rep(i,0,N){
        if(row[i]!=0){
            roww.emplace_back(row[i],i);
        }
        if(col[i]!=0){
            coll.emplace_back(col[i],i);
        }
    }
    sort(roww.begin(),roww.end());
    reverse(roww.begin(),roww.end());
    sort(coll.begin(),coll.end());
    reverse(coll.begin(),coll.end());
    ll ans =0;
    ll cur =0;
    rep(i,0,min(3,(int)roww.size())){
        cur+=roww[i].fi;
    }
    ans= max(ans,cur);
    cur = 0;
    rep(i,0,min(3,(int)coll.size())){
        cur+=coll[i].fi;
    }
    ans= max(ans,cur);


    


}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  //cin >> t;
  while(t--) solve();
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
