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
 str s;
 map<char,int> mp;
 mp['I']=1;
 mp['X']=10;
 mp['C']=100;
 mp['M']=1000;
 mp['V']=5;
 mp['L']=50;
 mp['D']=500;
 while(cin >> s && s!="#"){
   int ope[3]={0,0,0};
   int st=0;
   int cur=mp[s[0]];
   rep(i,1,s.size()){
     if(s[i]=='+'||s[i]=='=') {
       ope[st]+=cur;
       i+=1;
       cur=mp[s[i]];
       st++;
       continue;
     }
     if(s[i]!=s[i-1]){
         if(mp[s[i]]>mp[s[i-1]]) cur = mp[s[i]]-cur;
         ope[st]+=cur;
       }
       else {
         cur+=mp[s[i]];
       }
   }
   cout << ope[0] << " " << ope[1] << " " << ope[2];
   ope[st]+=cur;
   if(ope[0]+ope[1]==ope[2]) cout <<"Correct ";
   else cout <<"Incorrect ";
 }

}
