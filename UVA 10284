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
 //freopen("OUT.txt","w",stdout);
  str s;
  while(cin>>s){
    stringstream ss;
    ss.str(s);
    str token;
    int i=2;
    int arr[12][12];
    char board[12][12];
    memset(board,'.',sizeof board);
    memset(arr,0,sizeof arr)
;    while(getline(ss,token,'/')){
      int j=2;
     // cout << token;
      rep(l,0,token.size()){
        //int j=token[2*i]-'0'+1;
        if(token[l]=='p') {
          board[i][j]='p';
        }
        elif(token[l]=='P'){
          board[i][j]='P';
        }
        elif(token[l]=='N'||token[l]=='n'){
          board[i][j]='n';
        }
        elif(token[l]=='B'||token[l]=='b'){
          board[i][j]='b';
        }
        elif(token[l]=='R'||token[l]=='r'){
          board[i][j]='r';
        }
        elif(token[l]=='Q'||token[l]=='q'){
          board[i][j]='q';
        }
        elif(token[l]=='K'||token[l]=='k'){
          board[i][j]='k';
        }
        else{
          j+=token[l]-'0'-1;
        }
        j+=1;

        
      }
      i+=1;
    }
    rep(i,2,10){
      rep(j,2,10){
        if(board[i][j]=='p') {
          arr[i][j]=1;
            arr[i+1][j-1]=1;
            arr[i+1][j+1]=1;
        }
        elif(board[i][j]=='P'){
          arr[i][j]=1;
          arr[i-1][j+1]=1;
          arr[i-1][j-1]=1;
        }
        elif(board[i][j]=='n'){
          arr[i][j]=1;
          arr[i-2][j-1]=1;
          arr[i-2][j+1]=1;
          arr[i+2][j-1]=1;
          arr[i+2][j+1]=1;
          arr[i+1][j+2]=1;
          arr[i+1][j-2]=1;
          arr[i-1][j+2]=1;
          arr[i-1][j-2]=1;
        }
        elif(board[i][j]=='b'){
          arr[i][j]=1;
          int x=i,y=j;
          while(x>1 && y>1){
            arr[x][y]=1;
            x--;y--;
            if(board[x][y]!='.')break;
          }
           x=i,y=j;
          while(x<=10 && y<=10){
            arr[x][y]=1;
            x++;y++;
            if(board[x][y]!='.')break;
          }
           x=i,y=j;
          while(x>1 && y<=10){
            arr[x][y]=1;
            x--;y++;
            if(board[x][y]!='.')break;
          }
           x=i,y=j;
          while(x<=10 && y>1){
            arr[x][y]=1;
            x++;y--;
            if(board[x][y]!='.')break;
          }

        }
        elif(board[i][j]=='r'){
          arr[i][j]=1;
          int x=i,y=j;
          while(x>0){
            arr[x][y]=1;
            x--;
            if(board[x][y]!='.')break;
          }
           x=i,y=j;
          while(x<=10){
            arr[x][y]=1;
            x++;
            if(board[x][y]!='.')break;
          }
           x=i,y=j;
          while( y<=10){
            arr[x][y]=1;
            y++;
            if(board[x][y]!='.')break;
          }
           x=i,y=j;
          while( y>0){
            arr[x][y]=1;
            y--;
            if(board[x][y]!='.')break;
          }
        }
        elif(board[i][j]=='q'){
          int x=i,y=j;
          arr[i][j]=1;
          while(x>0){
            arr[x][y]=1;
            x--;
            if(board[x][y]!='.')break;
          }
           x=i,y=j;
          while(x<=10){
            arr[x][y]=1;
            x++;
            if(board[x][y]!='.')break;
          }
           x=i,y=j;
          while( y<=10){
            arr[x][y]=1;
            y++;
            if(board[x][y]!='.')break;
          }
           x=i,y=j;
          while( y>0){
            arr[x][y]=1;
            y--;
            if(board[x][y]!='.')break;
          }
           x=i,y=j;
          while(x>0 && y>0){
            arr[x][y]=1;
            x--;y--;
            if(board[x][y]!='.')break;
          }
           x=i,y=j;
          while(x<=10 && y<=10){
            arr[x][y]=1;
            x++;y++;
            if(board[x][y]!='.')break;
          }
           x=i,y=j;
          while(x>0 && y<=10){
            arr[x][y]=1;
            x--;y++;
            if(board[x][y]!='.')break;
          }
           x=i,y=j;
          while(x<=10 && y>0){
            arr[x][y]=1;
            x++;y--;
            if(board[x][y]!='.')break;
          }
        }
        elif(board[i][j]=='k'){
          arr[i][j]=1;
          arr[i-1][j]=1;
          arr[i][j-1]=1;
          arr[i-1][j-1]=1;
          arr[i-1][j+1]=1;
          arr[i+1][j-1]=1;
          arr[i+1][j]=1;
          arr[i][j+1]=1;
          arr[i+1][j+1]=1;
        }
      }
    }
    
    int cnt=0;
    rep(i,2,10){
      rep(j,2,10){
        if(arr[i][j]==0)cnt++;
      }
    }
    cout << cnt <<endl;
  }
}
