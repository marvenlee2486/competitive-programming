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

#define elif else if
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,v) for(auto i:v)
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>=(b);i--)
#define repn(i,a,b) for(int i=(a);i<=(b);i++)
#define repin(i,a,b,x) for(int i=(a);i<(b);i+=x)
#define repnin(i,a,b,x) for(int i=(a);i<=(b);i+=x)
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define fbo find_by_order
#define ook order_of_key
#define ALL(v) v.begin(),v.end()
#define FILL(arr) memset(arr,0,sizeof arr);
// if else int i = (number <0) ? 1:0 -  if (number <0) i=1 else 0
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int solve(int n,int d){
  int p[n],r[n];
   vii left;
   int ans=0;
   rep(i,0,n){
    int x,y;
    cin >> x >> y;
    if(y>d) {
        ans=1;
        continue;
    }
    int p = sqrt(d*d - y*y);
    r[i]=p;
    left.pb(ii(x+p,i));
   } 
   if(ans) return -1;

   sort(ALL(left));

   int cur =-INF;
   int just=-INF,justidx=-1;
   rep(i,0,n){
     
     int t,idx;
     tie(t,idx)=left[i];
     if(t-2*r[idx]>cur){
       ans++;
       cur = left[i].fi;
     }
     
   }
  return ans;
}

int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("OUT.txt","w",stdout);
 int n,d,t=1;

 while(cin >> n >> d && n && d){
   cout << "Case " << t << ": " << solve(n,d) << "\n";
  t++;
   
 }
  return 0;
}
