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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
int h,w;
cin >> h >> w;
str s[h+2];
int dx[] ={0,0,-1,1};
int dy[] = {1,-1,0,0};
rep(i,0,h) {
    cin >> s[i+1];
    s[i+1] = "." + s[i+1] + ".";
}
str add ="";
rep(j,0,w+2){
    add+=".";
}
s[0]=add;
s[h+1]=add;
rep(i,1,h+1){
    rep(j,1,w+1){
        if(s[i][j]!='.') continue;

        rep(c,1,6){
            bool can =true;

            rep(d,0,4){
                //cout << s[i+dx[d]][j+dy[d]];
                if(s[i+dx[d]][j+dy[d]] == '0' + c ){
                    can = false;
                    break;
                }
            }
            if(can) {s[i][j] = '0'+c; break;}
        }
    }
}
rep(i,1,h+1){
    rep(j,1,w+1) cout << s[i][j];
    cout << "\n";
}
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/