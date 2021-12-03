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
ll prime[N];

void sieve(){
    prime[1]=1;
    rep(i,4,N){
        prime[i]=1;
        i+=1;
    }
    prime[2]=0;

    rep(i,3,N){
        if(prime[i]) continue;

        int j = i*2;
        while(j<N) {
            prime[j] =1;
            j+=i;
        }
        
    }

}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  FILL(prime,0);
  int n;
  int cnt =0;
  int q;
  cin >> n >> q;
  str s;
   cin >> s;
   int memo[n];
   FILL(memo,-1);
   rep(i,0,n-2){
       if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c'){
           memo[i]=i;
           memo[i+1]=i;
           memo[i+2]=i;
           cnt++;
       }
   }

   while(q--){
       int i; 
       char c;
       cin >> i >> c;
       
       i--;
       
       if(s[i]!=c){
           s[i]=c;

           if(memo[i]!=-1){
              int de = memo[i];
              memo[de]=-1;
              memo[de+1]=-1;
              memo[de+2]=-1;
              cnt--;
           }
           
            if(c=='b') i-=1;
            if(c=='c') i-=2; 

            if(i<=n-3 && i>=0){
                //cout << i << " ";
                if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c'){
                    //cout << "YES ";
                    memo[i]=i;
                    memo[i+1]=i;
                    memo[i+2]=i;
                    cnt++;
                }
            }
               
           
       }
       //cout << s << " ";
       cout << cnt << "\n"; 
   }
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
