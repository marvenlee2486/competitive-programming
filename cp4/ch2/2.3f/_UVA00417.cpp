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

 unordered_map<str,int> mip;
void recursive(str s, int *cur,int loop,int size){
  if(loop==0){
    if(size==0){
      for(char i = 'a';i<='z';i++){
        mip[s+i]=*cur;
        (*cur)++;
       // cout << s+i << endl;
      }
    }
    else{
      for(char i = s[size-1]+1;i<='z';i++){
        mip[s+i]=*cur;
        (*cur)++;
        //cout << s+i << endl;
      }
    }
    return;
  }
  str s2=s;
  if(size==0){
      for(char i = 'a';i<='z';i++){
        s2=s+i;
        recursive(s2, cur, loop-1,size+1);
      }
    }
    else{
      for(char i = char(s[size-1]+1);i<='z';i++){
        s2= s+i;
        recursive(s2, cur, loop-1,size+1);
      }
    }
}

int main()
{ 
 //ios_base::sync_with_stdio(0);
// cin.tie(0);
 //cout.tie(0);
 //freopen("OUT.txt","w",stdout);
 str s; 
 int cur=1;

rep(i,0,5) recursive("",&cur,i,0);
  

//cout <<"AS" <<cur;
 while (cin >> s){
   if(mip.find(s)==mip.end()) cout <<"0\n";
   else cout << mip[s] << endl;
 }
 
}
