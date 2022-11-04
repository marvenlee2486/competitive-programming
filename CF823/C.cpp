#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef string str;
typedef vector<ll>  vl;
typedef vector< vector<ll> > vvl;
typedef vector<ii> vii;
typedef vector< vector<ii> > vvii;
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

void solve(){
    string s;
    cin >> s;
    
    int minv[s.size()];
    int mi = s[s.size()-1]-'0';
    rrep(i,s.size()-1,0){
        mi = min(mi, s[i]-'0');
        minv[i] = mi;
    }
    int a[10];
    FILL(a,0);
    int st = -1;
    int rem = -1;
    rep(i,0,10){
        rem = -1;
        char out = '0' +i;
        int idx = s.size()-1;
        //cout << i << " STT " << st << "\n";
        rep(k,0,a[i]) cout << out;
        while(idx>st){
            if(s[idx]-'0' == i){
                cout << out;
                if(rem==-1)rem = idx;
            }
            else if(rem != -1){
                a[min(9,s[idx]-'0' +1)]++;
            }
            idx--;
        }
        //cout << i << " " << rem << "\n";
        if(rem!=-1) st = rem;
    }
    cout << "\n";
    // rep(i,0,s.size()){
    //     if(s[i]-'0' != minv[i]) a[min(s[i]-'0'+1,9)]++;
    //     else cout << s[i];
    // }
    // rep(i,0,10){
    //     rep(k,0,a[i]){
    //         char c = a[i]+'0';
    //         cout << c;
    //     }
    // }

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int t=1;
  cin >> t;
  while(t--) solve();
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
