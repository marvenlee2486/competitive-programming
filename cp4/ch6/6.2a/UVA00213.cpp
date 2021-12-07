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

string addone(string s){
    rrep(i,s.size()-1,0){
        if(s[i]=='0') {
            s[i]='1';
            rep(i,0,s.size()) if(s[i]=='0')          return s;
            return addone(s);
        }else{
            s[i]='0';
        }
    }
    s+='0';
    return s;
}

bool isfull(string s){
    rep(i,0,s.size()) if(s[i]=='0') return false;
    return true;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  str s;
  while(getline(cin,s)){
      if(s=="n") break;
      map<string,char> hash;
      int k =1;
      str j ="0";
      rep(i,0,s.size()){
          hash[j] = s[i];
          //cout << j << endl;
        j = addone(j);
      }
        int st=0;
        int cnt=0;
        int si =0;
        str po = "";
        bool flag= false;
      while(true){
        getline(cin,s);
        //LOG ("wait");
        for(int i=0;i<s.size();i++){
            if(st==0){
                si *=2;
                si += s[i]-'0';
                cnt++;
                if(cnt ==3) {
                    st=1;
                    cnt =0;
                }
            }
            else if (st ==1){
                po += s[i];
                cnt++;
                if(cnt ==si){
                    if(isfull(po)){
                        st=0;
                        cnt=0;
                        si=0;
                        po="";
                        continue;
                    }
                    
                   // cout << po << endl;
                    cnt =0;
                    cout << hash[po];
                    po ="";
                    
                }

            }
            
            // << st << " " << si << endl;
           if(st ==1 && si == 0) {
               flag = true;
               break;
           }

        }
        if(flag){
            cout << "\n";
            break;
        }
      } 
  }
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
