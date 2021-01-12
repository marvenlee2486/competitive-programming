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
int n;
bool rotate( str arr[]){
  str newa[n];
  
  rep(j,0,n){
    str s; 
    rrep(i,n-1,0){
         s+=arr[i][j];
    }
    //cout << s << endl;
    newa[j]=s;
  }
  rep(i,0,n) arr[i]=newa[i];

  return true;
}
bool reflect (str arr[]){
  rep(i,0,n/2) swap(arr[i],arr[n-i-1]);
  return true;
}
bool issame(str arr1[],str arr2[]){
  rep(i,0,n) if(arr1[i]!=arr2[i]) return false;
  
  return true;
}
int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("OUT.txt","w",stdout);

 int t=0;
 while(cin>>n){
   
   str ori[n];
    str cha[n];
  rep(i,0,n){
    cin >> ori[i] >> cha[i];
  }
  if(issame(ori,cha)) printf("Pattern %d was preserved.\n",++t);
  elif(rotate(ori) && issame(ori,cha))
  printf("Pattern %d was rotated 90 degrees.\n",++t);
  elif(rotate(ori) && issame(ori,cha))
  printf("Pattern %d was rotated 180 degrees.\n",++t);
  elif(rotate(ori) && issame(ori,cha))
  printf("Pattern %d was rotated 270 degrees.\n",++t);
  elif(rotate(ori)&&reflect(ori) && issame(ori,cha))
  printf("Pattern %d was reflected vertically.\n",++t);
  elif(rotate(ori) && issame(ori,cha))
  printf("Pattern %d was reflected vertically and rotated 90 degrees.\n",++t);
  elif(rotate(ori) && issame(ori,cha))
  printf("Pattern %d was reflected vertically and rotated 180 degrees.\n",++t);
  elif(rotate(ori) && issame(ori,cha))
  printf("Pattern %d was reflected vertically and rotated 270 degrees.\n",++t);
  else printf("Pattern %d was improperly transformed.\n",++t);
  


    

  
 }
}
