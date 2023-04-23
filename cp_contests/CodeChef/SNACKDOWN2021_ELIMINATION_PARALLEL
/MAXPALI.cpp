#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll,ll,ll> iii;
typedef string str;
typedef vector<ll>  vl;
typedef vector< vector<ll> > vvl;
typedef vector<ii> vii;
typedef vector< vector<ii> > vvii;
typedef vector<iii> viii;
typedef vector< vector<iii> > vviii;
typedef vector<str>  vs;
typedef vector< vector<str> > vvs;


//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


#define LSOne(S) ( (S) & -(S))
#define elif else if
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
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

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const ll N = 1e6+2;

#ifndef ONLINE_JUDGE
#define LOG(message) cerr << message << endl;
#else 
#define LOG(message)
#endif

ll mod(ll x, ll y = MOD) { return ((x % y) + y) % y; }

ll addm(ll x) { return x; }
template <typename... Ts> ll addm(ll x, Ts... ys) { return mod(x + addm(ys...)); }

ll mulm(ll x) { return x; }
template <typename... Ts> ll mulm(ll x, Ts... ys) { return mod(x * mulm(ys...)); }

str left_shift(str s){
  return s[s.size()-1] + s.substr(0,s.size()-1);
}

void dfs(char u, set<char> &visited, map<char, vector<char>> graph){
  
  for(char v: graph[u]){
    //cout << "SAS";
    if(visited.find(v)==visited.end()){
      visited.insert(v);
      dfs(v,visited,graph);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
/*
  int n;
  cin >> n;

  str s;
  rep(i,0,n/2){
    s+= i+'a';
  }
  str y= s;
  reverse(ALL(y));
  s+= '0'+ y;
  s = "abbaabbaabbaabbaabbaaaabbaabbaabbaabbaabba";
  cout << s << "\n";
  rep(i,0,n){
    cout << i << "th shift ::  ";
    map<char, vector<char> > graph;
    rep(i,0,n/2){
      //cout << s[i] << "=" << s[s.size()-1-i] << "\n";
      if(graph.find(s[i])==graph.end()) graph[s[i]]=vector<char>();
      if(graph.find(s[s.size()-1-i] ) == graph.end()) graph[s[s.size()-1-i]] = vector<char>();
      graph[s[i]].pb(s[s.size()-1-i]);
      graph[s[s.size()-1-i]].pb(s[i]);
    }
    set<char> visited;
    dfs('a',visited,graph);

    if(visited.size()== (n/2)+1) cout << "Connected\n";
    
    else {
      cout << "NOT CONNECTED\n";
      FOR(v,visited) cout << v ;
      cout << "\n";
    }
    s = left_shift(s);
  }


  */
   int t;
   cin >> t;
   while(t--){
       int n;
       cin >> n;
       if(n==2){ cout << "ab\n"; continue;}
       if(n==3){ cout << "aba\n"; continue;}

        if(n%2){
          string s;
          rep(i,0,n/2+1){
            s+=(i%3==1)?'a':'b';
          }
          string s1=s;
          reverse(ALL(s1));
          s+=s1.substr(1,s1.size()-1);

          cout << s ;
     
        }
      else{
        str s;
        rep(i,0,n/2){
          s+=(i%4==0 || i%4==3)?"a":"b";
        }  
          string s1=s;
          reverse(ALL(s1));
          s+=s1;


      
        
          cout << s;
   
      }

        cout << "\n";
        
   }

  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/