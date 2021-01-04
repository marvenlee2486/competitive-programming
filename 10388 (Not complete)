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
// freopen("OUT.txt","w",stdout);
  int t;
  cin >> t;
  int k=0;
  while(t--){
    if(k)cout <<"\n";
    k=1;
    str s1,s2;
    cin >> s1 >> s2;
    str p1="",p2="";
    int i1=0,i2=0;
    int st=1;
    int SIZE = s1.size() *2;
    rep(i,0,1000){
      p1.pb(s1[i1]);
      p2.pb(s2[i2]);
      if(s1[i1]==s2[i2]){
          int x = random()/142%2;
          if(x==0){
            cout << "Snap! for Jane: ";
            p1+=p2;
            p2="";
            for(int j=p1.size()-1;j>=0;j--) cout << p1[j];
            cout << endl;
          }
          else{
            cout << "Snap! for John: ";
            p2+=p1;
            p1="";
            for(int j=p2.size()-1;j>=0;j--) cout << p2[j];
            cout << endl;

            
          }
      }
     
      i1++;i2++;
      if(i1==s1.size()){
        s1=p1;
        p1.clear();
        i1=0;
      }
      if(i2==s2.size()){
        s2=p2;
        p2.clear();
        i2=0;
      }
      if ((s2.empty()&&p2.empty())|| p1.size()==SIZE || s1.size()==SIZE) {
        cout << "Jane wins.\n";
        st=0;
        break;
      }

      if((s1.empty()&&s2.empty()) || p2.size()==SIZE || s2.size()==SIZE){
        cout << "John wins.\n";
        st=0;
        break;
      }
    }
    if(st) cout <<"Keeps going and going ...\n";
  }

  
}
