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
#define FILL(arr,x) memset(arr,x,sizeof arr);
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
  str s;
  int t=0;
  vector<str> board;
  str state ="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  while(getline(cin,s)){
    if(t) cout << endl;
    t=1;
    board.pb(s);
    while(getline(cin,s)  && s!=""){
        board.pb(s);
    }
    ii check[100];
    rep(i,0,100) check[i]=ii(-1,-1);
    rep(i,0,board.size()){
      rep(j,0,board[i].size()){
        if(board[i][j]!='.')check[state.find(board[i][j])]=ii(i,j);
      }
    }
   
    rep(i,1,100){
      int x1,x2,y1,y2;
      x1=check[i].fi;
      x2=check[i-1].fi;
      y1=check[i].se;
      y2=check[i-1].se;
  if(x1==-1) break;
      if(x1==x2){
        rep(i,min(y1,y2)+1,max(y1,y2)){
          if(board[x1][i]=='|')board[x1][i]='+';
          else if(board[x1][i]=='.') board[x1][i]='-';
        }
      }
      else{
         rep(i,min(x1,x2)+1,max(x1,x2)){
          if(board[i][y1]=='-')board[i][y1]='+';
          else if (board[i][y1]=='.') board[i][y1]='|';
        }
      }
    
    }
     rep(i,0,board.size()){
       cout << board[i] << endl;
     }
    board.clear();
  } 
}
