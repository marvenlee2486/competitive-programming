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

int ranki(int n[],int s[]){
 // rep(i,0,4) cout << s[i] << " ";
  if(n[0]==n[1]-1 && n[1]==n[2]-1 && n[2]==n[3]-1 && n[3]== n[4]-1){
    if(s[0]==5 || s[1]==5 || s[2]==5 || s[3]==5) return 100*8+ n[4];
    else 
    return 100*4 + n[4];
  }
  if( (n[0]==n[1] && n[1]==n[2] && n[2]==n[3] )||(  n[1]==n[2] && n[2]==n[3]&& n[3]== n[4]) ){
    return 700 + n[2];
  }
  elif ((n[0]==n[1] && n[1]==n[2] && n[3]==n[4])||
  (n[0]==n[1] && n[2]==n[3] && n[3]==n[4])  ) {return 600 + n[2];
  }
  elif(s[0]==5 || s[1]==5 || s[2]==5 || s[3]==5){
    return 500;
  } 
  elif( (n[0]==n[1] && n[1]==n[2] )|| (n[1]==n[2] && n[2]==n[3])||
  (n[2]==n[3] && n[3]==n[4]) ){
    return 300 + n[2];
  }
  elif((n[0]==n[1] && n[3]==n[2])|| (n[0]==n[1] && n[3]==n[4])|| (n[1]==n[2] && n[3]==n[4])){
    if(n[4]!=n[3]) {
      int temp=n[4];
      n[4]=n[3];
      n[3]=n[2];
      n[2]=n[1];
      n[1]=n[0];
      n[0]=temp;
    }
    elif(n[1]!=n[2]){
        int temp=n[2];
        n[2]=n[1];
        n[1]=n[0];
        n[0]=temp;
    }
    return 200 ;
  }
  elif(n[0]==n[1]||n[1]==n[2]||n[2]==n[3]||n[3]==n[4]){
    if(n[3]==n[2]) {
      int temp=n[4];
      n[4]=n[3];
      n[3]=n[2];
      n[2]=temp;
    }
    elif(n[1]==n[2]){
        int temp=n[2];
        n[1]=n[3];
        n[2]=n[4];
        n[3]=temp;
        n[4]=temp;
    }
    elif(n[0]==n[1]){
      int temp=n[1];
      n[0]=n[2];
        n[1]=n[3];
        n[2]=n[4];
        n[3]=temp;
        n[4]=temp;
    }
return 100;
  } 
  else return 0;

}

int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
// freopen("OUT.txt","w",stdout);
  str number ="23456789TJQKA";
  str suit = "CDHS";
 
  str s;
  while(cin>>s){
     int wn[5]={0},ws[4]={0},bn[5]={0},bs[4]={0};
    bn[0]=number.find(s[0]);
    bs[suit.find(s[1])]++;
    rep(i,1,5) {
        cin >> s;
         bn[i]=number.find(s[0]);
    bs[suit.find(s[1])]++;
    }
    rep(i,0,5) {
        cin >> s;
         wn[i]=number.find(s[0]);
    ws[suit.find(s[1])]++;
    }
    sort(bn,bn+5);
    sort(wn,wn+5);
    
    int w = ranki(wn,ws);
    int b = ranki(bn,bs);
  //cout << b << " "<< w;
    if(b<w) cout <<"White wins.\n";
    elif (b>w) cout <<"Black wins.\n";
    else {
      int st=0;
     for(int i=4;i>=0;i--){
       if(bn[i]==wn[i]) continue;
    //cout << bn[i] << wn[i];
       cout << ((bn[i]<wn[i])?"White wins.\n": "Black wins.\n" );
       st=1;
       break;
     }
     if(st==0) cout <<"Tie.\n";
    }


  }
}
