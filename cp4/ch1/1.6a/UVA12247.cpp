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
#define ALL(v) v.begin(),v.end()
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

  int a,b,c,x,y;
  while(cin>>a>>b>>c>>x>>y && a){
    int st[55]={0};
    st[a]=1;
    st[b]=1;
    st[c]=1;
    st[x]=1;
    st[y]=1;
    if(x>y)swap(x,y);
  int cess[3] = {a,b,c};
  sort(cess,cess+3);
  int cntx=0,cnty=0;
  rep(i,0,3){
      if(x>cess[i]) cntx+=1;
  }
  rep(i,0,3){
      if(y>cess[i]) cnty+=1;
  }
  //cout << cntx << " " << cnty << " ";
  if((cntx<=1 && cnty <=2 )||(cntx<=2 && cnty<=1)) cout << "-1\n";
  else{
    
    if(cntx==3 && cnty ==3){ if(cess[0]==1){
      if(cess[1]==2){
        if(cess[2]==3){
          if(x==4){
            if(y==5){
              cout <<"6\n";
            }
            else
            cout << "5\n";
          }
          else
          cout << "4\n";
        }
        else
        cout << "3\n";
      }
      else
      cout << "2\n";
    }
    else
    cout <<"1\n";
    }
    else if (cnty==3 && cntx<=1){
      int x = cess[2]+1;
      while(st[x]) x++;
      if(x>52) cout << "-1\n";
      else
      cout << x << "\n";
    } 
    else 
    {
      int x=cess[1]+1;
      while(st[x]) x++;
      if(x>52) cout << "-1\n";
      else
      cout << x << "\n";
      
    }

    }
  }


}

//Logic thinking and deduction (Exhastive every cases)
