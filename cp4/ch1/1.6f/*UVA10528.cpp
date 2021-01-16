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
 cin.tie(0);
 cout.tie(0);
// freopen("OUT.txt","w",stdout);
 str s;
 map<str,int> mp;
 mp["C"]=0;
 mp["C#"]=1;
 mp["D"]=2;
 mp["D#"]=3;
 mp["E"]=4;
 mp["F"]=5;
 mp["F#"]=6;
 mp["G"]=7;
 mp["G#"]=8;
 mp["A"]=9;
 mp["A#"]=10;
 mp["B"]=11;
 str arr[12] ={"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
 vector<vector<int>> v(12, vector<int>());
 rep(i,0,12){
    v[i].pb(i);
    v[ (i+2)%12 ].pb(i);
    v[ (i+4)%12 ].pb(i);
    v[ (i+5)%12 ].pb(i);
    v[ (i+7)%12 ].pb(i);
    v[ (i+9)%12 ].pb(i);
    v[ (i+11)%12 ].pb(i);
   
 }
 while(getline(cin,s) && s !="END"){
   stringstream ss;
   ss.str(s);
   str token;
   set<int> st;
    set<int> news;
   int state=0;
   while(getline(ss,token,' ')){

      rep(i,0,v[mp[token]].size()){
       
        if(state)
        {
          if(st.find(v[mp[token]][i])!=st.end()) news.insert(v[mp[token]][i]);
          
          }
        else {
          
          news.insert(v[mp[token]][i]);
        }
       
        
      }
      st=news;
      news.clear();
      state=1;

   }
   int i=0;
  FOR(x,st){
    if(i==st.size()-1) cout << arr[x];
    else cout << arr[x] << " ";
    i++;
  }
  cout << endl;
 }
  
}
