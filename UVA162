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
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
  str s;
  //freopen("OUT.txt","w",stdout);
  while(1){
    int i=1;
     queue<char> q1;
  queue<char> q2;
stack<char> s1;
  stack<char> s2;
  rep(j,0,52){
    cin>>s ;
    if(s=="#")return 0;
   
    if(i%2==1) s2.push(s[1]);
    else s1.push(s[1]);

    i+=1;
    i%=2;
  } 
  while(!s1.empty()){
    q1.push(s1.top());
    s1.pop();
  }
  while(!s2.empty()){
    q2.push(s2.top());
    s2.pop();
  }
   i=1;
   int num=0;
   queue<char> play;
  while( (i==0)? !q1.empty() : !q2.empty()){
    // cout <<i << ": ";
      if(i%2==1){
        
        if(q2.front()=='J'){
          i=0;
          num=1;
        }
        elif (q2.front()=='Q'){
          i=0;
          num=2;
        }
        elif (q2.front()=='K'){
          i=0;
          num=3;
        }
        elif(q2.front()=='A'){
          i=0;
          num=4;
        }
        
        play.push(q2.front());
        q2.pop();

     //  cout << play.back() << endl;
        if(num && i==1){

          num--;
          if(num==0){
            while(!play.empty()){
                q1.push(play.front());
                play.pop();
            }
            //cout <<"q1 take the stack" <<endl;
            i=0;
            num=0;
          }
        }
        else {
          i=0;
        }
      }
      else{
      
        if(q1.front()=='J'){
          i=1;
          num=1;
        }
        elif (q1.front()=='Q'){
          i=1;
          num=2;
        }
        elif (q1.front()=='K'){
          i=1;
          num=3;
        }
        elif(q1.front()=='A'){
          i=1;
          num=4;
        }
        play.push(q1.front());
        q1.pop();
      // cout << play.back() << endl;
        if(num && i==0){
          num--;
          if(num==0){
            while(!play.empty()){
                q2.push(play.front());
                play.pop();
                
            }
           // cout <<"q2 take the stack" <<endl;
              i=1;        
              num=0;    
          }
        }
        else i=1;
      }
      
  }
  if(i==0) cout << "2 " << setw(2) << q2.size() << endl;
  else cout <<"1 " << setw(2) << q1.size() << endl;
  }
}
