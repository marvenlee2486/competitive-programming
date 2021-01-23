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
 int arr[13]={29,31,28,31,30,31,30,31,31,30,31,30,31};
 cin.tie(0);
 cout.tie(0);
 //freopen("OUT.txt","w",stdout);
 int n;
  int i=0;
 cin >> n ;
  while(n--){
    int y,m,d;
    cin >> d;
    y = d%10000;
    d/=10000;
    m = d%100;
    d/=100;
    swap(d,m);
  
    d+=40*7;
    if(y%4==0 && m==2)m=0;
    while(d>arr[m]){
      
      d-=arr[m];
      if(m==0)m=2;
      m++;
      if(m>12){
        m=1;
        y++;
      }
      if(y%4==0 && m==2)m=0;
    }
   
    cout << ++i << " " << setw(2) << setfill('0') << m << "/" << setw(2) << setfill('0') << d << "/" << y <<" ";
    if(m==1){
      if(d<=20) cout <<"capricorn\n";
      else cout << "aquarius\n";
    }
    elif(m==2) {
      if(d<=19) cout << "aquarius\n";
      else cout << "pisces\n";
    }
    elif(m==3){
      if(d<=20) cout <<"pisces\n";
      else cout <<"aries\n";
    }
    elif(m==4){
      if(d<=20) cout <<"aries\n";
      else cout << "taurus\n";

    }
    elif(m==5){
      if(d<=21) cout << "taurus\n";
      else cout << "gemini\n";
    }
    elif(m==6){
      if(d<=21) cout << "gemini\n";
      else cout << "cancer\n";
    }
    elif(m==7){
      if(d<=22) cout << "cancer\n";
      else cout << "leo\n";
    }
    elif(m==8){
      if(d<=21) cout <<"leo\n";
      else cout << "virgo\n";
    }
    elif (m==9){
      if(d<=23) cout << "virgo\n";
      else cout << "libra\n";

    }
    elif (m==10){
      if(d<=23) cout << "libra\n";
      else cout << "scorpio\n";

    }
    elif(m==11){
      if(d<=22) cout << "scorpio\n";
      else cout << "sagittarius\n";
    }
    elif(m==12){
      if(d<=22) cout <<"sagittarius\n";
      else cout << "capricorn\n";
    }
  }


}
