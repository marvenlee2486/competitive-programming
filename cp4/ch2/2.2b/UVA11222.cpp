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
// if else int i = (number <0) ? 1:0 -  if (number <0) i=1 else 0
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("OUT.txt","w",stdout);
 
   int T;
   cin >> T;
   rep(t,1,T+1){
     set<int> p1,p2,p3, ans;
    int k;
    cin >> k;
    rep(i,0,k){
      int x;
      cin >> x;
      p1.insert(x);
  ans.insert(x);
    }
    cin >> k;
    rep(i,0,k){
      int x;
      cin >> x;

      if(ans.find(x)==ans.end())
      { p2.insert(x);ans.insert(x);}
      else if(p1.find(x)!=p1.end())p1.erase(p1.find(x));
      
    }
    cin >> k;
    rep(i,0,k){
      int x;
      cin >> x; int st=1;
      if(ans.find(x)!=ans.end()){
 if(p1.find(x)!=p1.end()){

p1.erase(p1.find(x));

      }
     if(p2.find(x)!=p2.end()){
p2.erase(p2.find(x));

      }
      }
     
      else{ p3.insert(x);
ans.insert(x);}
    }
    cout << "Case #" << t  <<":\n";
    int maxv=max(p1.size(),max(p2.size(),p3.size()));
    if(p1.size()==maxv){
      cout << "1 " << p1.size();
      FOR(i,p1){
        cout << " " << i;
      }
      cout << endl;
    }
    if(p2.size()==maxv){
      cout << "2 "<<p2.size();
      FOR(i,p2){
        cout << " " << i;
      }
      cout << endl;
    }
    if(p3.size()==maxv){
      cout << "3 " << p3.size();
      FOR(i,p3){
        cout << " " << i;
      }
      cout << endl;
    }

   }

}
