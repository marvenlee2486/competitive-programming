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
 cin.tie(0);
 cout.tie(0);
 //freopen("OUT.txt","w",stdout);
  map<char,int> mp;
  mp['`']='`';
  mp['1']='1';
  mp['2']='2';
  mp['3']='3'; 
  mp['4']='q';
  mp['5']='j';
  mp['6']='l';
  mp['7']='m';
  mp['8']='f';
  mp['9']='p';
  mp['0']='/';
  mp['-']='[';
  mp['=']=']';
  
  mp['q']='4';
  mp['w']='5';
  mp['e']='6'; 
  mp['r']='.';
  mp['t']='o';
  mp['y']='r';
  mp['u']='s';
  mp['i']='u';
  mp['o']='y';
  mp['p']='b';
  mp['[']=';';
  mp[']']='=';
  mp['\\']='\\';

  mp['a']='7';
  mp['s']='8';
  mp['d']='9'; 
  mp['f']='a';
  mp['g']='e';
  mp['h']='h';
  mp['j']='t';
  mp['k']='d';
  mp['l']='c';
  mp[';']='k';
  mp[char(39)]='-';

  mp['z']='0';
  mp['x']='z';
  mp['c']='x'; 
  mp['v']=',';
  mp['b']='i';
  mp['n']='n';
  mp['m']='w';
  mp[',']='v';
  mp['.']='g';
  mp['/']=char(39);
 

  mp['~']='~';
  mp['!']='!';
  mp['@']='@';
  mp['#']='#'; 
  mp['$']='Q';
  mp['%']='J';
  mp['^']='L';
  mp['&']='M';
  mp['*']='F';
  mp['(']='P';
  mp[')']='?';
  mp['_']='{';
  mp['+']='}';
  
  mp['Q']='$';
  mp['W']='%';
  mp['E']='^'; 
  mp['R']='>';
  mp['T']='O';
  mp['Y']='R';
  mp['U']='S';
  mp['I']='U';
  mp['O']='Y';
  mp['P']='B';
  mp['{']=':';
  mp['}']='+';
  mp['|']='|';

  mp['A']='&';
  mp['S']='*';
  mp['D']='('; 
  mp['F']='A';
  mp['G']='E';
  mp['H']='H';
  mp['J']='T';
  mp['K']='D';
  mp['L']='C';
  mp[':']='K';
  mp['"']='_';

  mp['Z']=')';
  mp['X']='Z';
  mp['C']='X'; 
  mp['V']='<';
  mp['B']='I';
  mp['N']='N';
  mp['M']='W';
  mp['<']='V';
  mp['>']='G';
  mp['?']='"';

  mp[' ']=' ';
  str s;
  while(getline(cin,s)){
    rep(i,0,s.size()){
      s[i]=mp[s[i]];
    }
    cout << s << endl;
  }
}
