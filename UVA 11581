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

int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("OUT.txt","w",stdout);
 int t;
 cin >> t;
 while(t--){
   str s[5];
   s[0]="00000";
   s[4]="00000";
   int st2=0;
   str c;
   cin >> c;
   c = "0"+c+"0";
   s[1]=c;
    if(c!="00000") st2=1;
   cin >> c;
   c = "0"+c+"0";
   s[2]=c;
 if(c!="00000") st2=1;
   cin >> c;
   c = "0"+c+"0";
   s[3]=c;
 if(c!="00000") st2=1;
  int ans=0;
  while(st2){
    str newa[5];
    newa[1]="00000";
    newa[2]="00000";
    newa[3]="00000";
    ans++;
    int st=1;
//    cout << s[0] << s[4];
    rep(i,1,4){
      //cout << s[i] << endl;
      rep(j,1,4){
          //cout << s[i][j];
        int x= s[i-1][j]+s[i+1][j] + s[i][j+1] + s[i][j-1]-4* ('0');
        
        x%=2;
        
        
        if(x==0) newa[i][j]='0';
        else{
          newa[i][j]='1';
          st=0;
        }
      }
      //cout << endl;
    }
   // cout << endl;
    if(st) break;
    rep(i,0,5)s[i]=newa[i];
  }
  if(st2)
  cout << ans-1 << endl;
    else cout << "-1\n";
 }
  
}
