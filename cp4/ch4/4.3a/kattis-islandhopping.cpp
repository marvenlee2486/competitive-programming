
#include <bits/stdc++.h>
using namespace std;
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


class UnionFind{
  private:
  vl p, rank, setSize;
  int numSets;
  public:
  UnionFind(int N){
    p.assign(N,0); for (int i=0;i<N;++i) p[i]=i;
    rank.assign(N,0);
    setSize.assign(N,1);
    numSets =N;
  }
  int findSet(int i){ return (p[i]==i)? i : (p[i]= findSet(p[i]));}
  bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
  int numDisjointSets(){return numSets;}
  int sizeOfSSet(int i){return setSize[ findSet(i)]; }
  void unionSet(int i,int j){
    if(isSameSet(i,j)) return;
    int x=findSet(i),y=findSet(j);
    if(rank[x]>rank[y])swap(x,y);
    p[x]=y;
    if(rank[x]==rank[y]) ++ rank[y];
    setSize[y] +=setSize[x];
    --numSets;
  }
};


int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("UT.txt","w",stdout);
 
 int t; cin >> t; 
 while(t--){
    int n;
    cin >> n;
    ld x[n],y[n];
    rep(i,0,n) cin >> x[i] >> y[i];
    viii EL(n*(n-1)/2);
    rep(i,0,n){
        rep(j,0,i){
            ld w = sqrt(pow(x[i]-x[j],2 )+ pow(y[i]-y[j],2) );
            EL[i*i-1 + j ] = {w,i,j }  ;
        }
    }
    sort(ALL(EL));
    UnionFind UF(n);
    ld cost =0;
    for( auto&[w,u,v]: EL){
        if(UF.isSameSet(u,v)) continue;
        cost +=w;
        UF.unionSet(u,v);
    }
    cout << fixed << setprecision(10) << cost << "\n";
    
 }
    
}
  
