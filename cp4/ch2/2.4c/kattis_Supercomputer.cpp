

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
    FenwickTree(int n){
      ft.assign(n+1,0);
    }

    void update(int i,int v){
      for(;i<=ft.size();i+=LSOne(i)) ft[i]+=v;
    }

    int sum (int i ){
      int sum=0;
      for(;i;i-=LSOne(i)) sum+= ft[i];
      return sum;
    }
};

int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("UT.txt","w",stdout);
  int n,k;
  cin >> n >> k;
  FenwickTree ft(n);

  while(k--){
    char c;
    cin >> c;
    if(c=='F'){
      int p;
      cin >> p;
      int x = ft.sum(p) - ft.sum(p-1);
      if(x) ft.update(p,-1);
      else ft.update(p,1);
    }
    else{
      int l,r;
      cin >> l >> r;
      cout << ft.sum(r) - ft.sum(l-1) << "\n";
    }
  }


}
  
