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

struct photo{
  str time, plate, state, km;
};

bool cmpr(photo lhs,photo rhs) {
  return (lhs.time<rhs.time);
}


int main()
{ 
 //ios_base::sync_with_stdio(0);
// cin.tie(0);
 //cout.tie(0);
 //freopen("OUT.txt","w",stdout);
 int t;
 cin >> t;
 int k=0;
 while(t--){
   if(k)  cout << "\n";
   k=1;
    map<str,ld> mp;

    ld time[24];
    rep(i,0,24)cin >> time[i];

    str s;
    getline(cin,s);
    photo photo[1000];
    int j=0;
    while(getline(cin,s)&&s!=""){
       
        stringstream ss;
        ss.str(s);
        str token;
        int i=0;
        while(getline(ss,token,' ')){
            if(i==0)photo[j].plate=token;
            elif(i==1)photo[j].time=token;
            elif(i==2)photo[j].state=token;
            else photo[j].km=token;
            i++;
        }
        j++;
      
    }
    sort(photo,photo+j,cmpr);
    map< str,pair<int,str> > st;

    rep(i,0,j){
      
      if(photo[i].state=="enter"){
        int t = (photo[i].time[6]-'0')*10 + (photo[i].time[7]-'0');
        st[photo[i].plate] = pair<int,str>(time[t],photo[i].km);
      }
      else{
        if(st.find(photo[i].plate)==st.end()) continue;
        int t =st[photo[i].plate].fi;
        str km1 = st[photo[i].plate].se;
        stringstream geek(km1); 
        int x = 0; 
        geek >> x; 

        stringstream geeek(photo[i].km);
        int km2 =0;
        geeek >> km2;

        ld val = abs(x-km2)*t*1.0;
        if(mp.find(photo[i].plate)==mp.end()) mp[photo[i].plate]=200.0;
        mp[photo[i].plate]+=val+100;
       st.erase(st.find(photo[i].plate) ) ;
      }
    }

    FOR(x,mp){
      cout << x.fi << " $" << fixed << setprecision(2) << x.se/100 << "\n";
    }
   
 }
}
