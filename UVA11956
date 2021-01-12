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
#define repn(i,a,b) for(int i=(a);i<=(b);i++)
#define repin(i,a,b,x) for(int i=(a);i<(b);i+=x)
#define repnin(i,a,b,x) for(int i=(a);i<=(b);i+=x)
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define fbo find_by_order
#define ook order_of_key

// if else int i = (number <0) ? 1:0 -  if (number <0) i=1 else 0
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
int main()
{ 
  int T;
  cin >> T;
  freopen("output.txt","w",stdout);
  rep(t,0,T){
    str s;
    cin >> s;
    
    int arr[100];
    rep(i,0,100) arr[i]=0;
    int p=0;
    FOR(i,s){
      if(i=='+') arr[p]++;
      elif(i=='-') arr[p]--;
      elif(i=='>') p++;
      elif(i=='<') p--;
      if(arr[p]==-1) arr[p]+=256;
      else arr[p]%=256;
      if(p>=100) p-=100;
      if(p<0) p+=100;
    }
    cout <<"Case " << dec<< t+1 << ":";
    rep(i,0,100){
      cout << " " << setfill('0')<< setw(2) << right << uppercase<< hex<< arr[i];
    }
    cout << endl;
  }
}

/*
Method dealing with BITS!!! %
and  cout << hex !!
*/
