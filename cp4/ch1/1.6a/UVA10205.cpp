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

void chin(str arr[], int how[]){
  str newa[52];
  rep(i,0,52){
    newa[i]=arr[how[i]-1];
  }
  rep(i,0,52) arr[i]=newa[i];
}

int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("OUT.txt","w",stdout);
  
int t;

cin >> t;
int n=0;
while(t--){
  if(n!=0) cout << "\n";
  
  
  str arr[52];
  str check[13]= {"2", "3","4","5","6","7","8","9","10", "Jack","Queen", "King","Ace"};
  rep(i,0,52){
    str s=check[i%13]; 
    s += " of ";
    if(i/13==0) s+= "Clubs";
    elif (i/13==1) s+= "Diamonds";
    elif (i/13==2) s+= "Hearts";
    else s+="Spades";

    arr[i]=s;
  }

  cin >> n;
  
    int change[n][52];
    rep(j,0,n)
    rep(i,0,52) cin >> change[j][i];
    
    str d;
    getline(cin,d);
    while(getline(cin,d) && d!=""){
      
      int k=0;
      rep(i,0,d.size()){
        k*=10;
        k+=d[i]-'0';
      }
      
      chin(arr,change[k-1]);
      
    }
    
  
  rep(i,0,52) cout << arr[i] << "\n";
  }
}
