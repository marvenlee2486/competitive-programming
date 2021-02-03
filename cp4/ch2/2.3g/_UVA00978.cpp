#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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
// cin.tie(0);
 //cout.tie(0);
 //freopen("OUT.txt","w",stdout);
 int t;
 cin >> t;
 int k=0;
 while(t--){
   if(k) cout <<"\n";
   k=1;
  priority_queue<int> pqb,pqg;
  int ba, sg,sb;
  cin >> ba >> sg >> sb;
  rep(i,0,sg){
    int x;
    cin >> x;
    pqb.push(x);
  }
  rep(i,0,sb){
    int x;
    cin >> x;
    pqg.push(x);
  }
  while(!pqb.empty() && ! pqg.empty()){
    vector<int> b,g;
    rep(i,0,ba){
      if(pqb.empty() || pqg.empty()) break;
      if(pqb.top()>pqg.top()) b.pb(pqb.top()-pqg.top());
      elif (pqb.top()<pqg.top()) g.pb(pqg.top()-pqb.top());

      pqb.pop();pqg.pop();
    }
    FOR(x,b) pqb.push(x);
    FOR(x,g) pqg.push(x);
  }
  if(pqb.empty() && pqg.empty()){
    cout << "green and blue died\n";
  }
  elif(pqb.empty()){
    cout << "blue wins\n";
    while(!pqg.empty()){
      cout << pqg.top() << endl;
      pqg.pop();
    }
  }
  else {
    cout << "green wins\n";
    while(!pqb.empty()){
      cout << pqb.top() << endl;
      pqb.pop();
    }
  }
 }
 
 
  

}
