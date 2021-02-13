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

class FenwickTree{
  private:
    vl ft;
  public:
    FenwickTree(int m){
      ft.assign(m+1,0);
    }

    void update(int p, ll v){
        for(;p<int(ft.size());p+=LSOne(p)) ft[p]+=v;
    }

    ll rsq(int p){
      ll sum=0;
      for(;p;p-=LSOne(p)) sum+=ft[p];
      return sum;
    }
};


int main()
{
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("OUT.txt","w",stdout);
 int n,q;
 cin >> n >> q;
 vector<FenwickTree> ft(6,n);

 ll val[6];

 rep(i,0,6) cin >> val[i];

 string s;
 //cout <<"E";
 cin >> s;
    //cout <<"q";
 rep(i,0,s.size()){
    ft[s[i]-'1'].update(i+1,1);
 }
 while(q--){
   int x;
   cin >> x;
   if(x==3){
     int l,r;
     cin >> l >> r;
     ll ans =0;
     rep(i,0,6) ans+=(ft[i].rsq(r) - ft[i].rsq(l-1))*val[i];
     cout << ans << endl;
   }
   elif(x==1){
     int k,p;
     cin >> k >> p;
     ft[s[k-1]-'1'].update(k,-1);
     s[k-1]= '0'+p;
     ft[p-1].update(k,1);
   }
   elif(x==2){
      int p,v;
      cin >> p >> v;
      val[p-1]=v;
   }
 }
}
