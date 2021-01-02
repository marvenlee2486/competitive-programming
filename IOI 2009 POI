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
struct score{
  int total_score=0;
  int number=0;
  int id;
};

bool cmpr(score l, score r){
  if(l.total_score > r.total_score){
   return true;
  }
  elif (l.total_score < r.total_score) return false;
  elif (l.number > r.number){
    return true;
  }
  elif (l.number<r.number) return false;
  elif( l.id < r.id){
    return true;
  }

  return false;
}
/*
bool cmpr(score l, score r){
  return ((l.total_score>r.total_score)|| 
            ( (l.total_score==r.total_score && l.number>r.number) || 
                  (l.total_score==r.total_score && l.number==r.number && l.id<r.id)
                          ) 
                              );

*/
int main()
{ 
  int n,t,p;
  cin >> n >>t >> p;
  score sc[n];
  int task[n][t];
int solve[2001]={0};
  rep(i,0,n){
    rep(j,0,t){
      cin >> task[i][j];
      solve[j]+=task[i][j];    }
       
  }
  rep(i,0,n){
    sc[i].id = i;
    rep(j,0,t){
      if(task[i][j]){
        sc[i].number+=1;
        sc[i].total_score+=n-solve[j];
      
      }
     
    }
    
  }
  sort(sc,sc+n,cmpr);
  p--;

cout << endl;
  rep(i,0,n){
      if(sc[i].id==p){
        cout << sc[i].total_score << " " <<  i+1 << endl;
      }
  }
}


// Sort comparator !!
