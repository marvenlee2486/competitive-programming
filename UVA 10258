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
struct score{
  int s=0,p=0,id,st=0;
};
bool cmpr(score l, score r){
  if(l.s > r.s) return true;
  elif( l.s < r.s) return false;

  if(l.p<r.p) return true;
  elif (r.p<l.p) return false;

  if(l.id<r.id) return true;
  else return false;
}
int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("OUT.txt","w",stdout);
  
  int t;
  cin >> t;
  str s;
   getline(cin,s);
   getline(cin,s);
   while(t--){
     score score[101];
     rep(i,0,101) score[i].id=i;
     int player[101][10];
     memset(player, 0 ,sizeof player);
   
     while(getline(cin,s) && s!=""){
      vector<str> tok;
      stringstream ss;
      ss.str(s);
      str token;
      while(getline(ss,token,' ')){
        tok.pb(token);
      }
     
      int con=0;
        rep(i,0,tok[0].size()) {
          con*=10;
          con+=tok[0][i]-'0';
        }
        int tim=0;
        rep(i,0,tok[2].size()) {
          tim*=10;
          tim+=tok[2][i]-'0';
        }
   
      score[con].st = 1;
     if(tok[3]=="C" && player[con][tok[1][0]-'1']!=-1){
        
        score[con].s+=1;
        score[con].p+=tim+  player[con][tok[1][0]-'1'];
         player[con][tok[1][0]-'1']=-1;
     }
     elif(tok[3]=="I" && player[con][tok[1][0]-'1']!=-1){
        player[con][tok[1][0]-'1']+=20;
     }
      
   }
   sort(score,score+101,cmpr);
   rep(i,0,101){
     if(score[i].st){
       cout << score[i].id << " " << score[i].s << " " << score[i].p << endl; 
     }
   }
   if(t!=0)cout << endl;
  }

}
