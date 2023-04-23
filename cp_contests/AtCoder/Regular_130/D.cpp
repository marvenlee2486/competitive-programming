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

const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;
const ll N = 3005;

#ifndef ONLINE_JUDGE
#define LOG(message) cerr << message << endl;
#else 
#define LOG(message)
#endif

#define fr(i, a, b) for(i=a; i<=b; i++)
#define fb(i, a, b) for(i=a; i>=b; i--)
#define ms(x, v) memset(x, v, sizeof x)

const int mod = 998244353;

int ADD(int a, int b, int m = mod) {
    int s = a;
    s += b;
    if( s >= m )
      s -= m;
    return s;
}

int MUL(int a, int b, int m = mod) {
    return (1LL * a * b % m);
}

int power(int a, int b, int m = mod) {
    int res = 1;
    while( b ) {
        if( b & 1 ) {
            res = 1LL * res * a % m;
        }
        a = 1LL * a * a % m;
        b /= 2;
    }
    return res;
}

ll nC2(ll x) {
    return ( x * ( x - 1 ) / 2 );
}

const int maxn = 3002;

vector<int> adj[maxn];
map<pair<int,int>, bool> dir;
int dp[maxn][maxn], sz[maxn], NcR[maxn][maxn];

int nCr(int n, int r) {
    if(r > n) return 0;
    if(n == 0 || r == 0) return 1; 
    int &ret = NcR[n][r];
    if(ret != -1) return ret;
    ret = 0;
    ret = nCr(n-1, r-1) + nCr(n-1, r);
    if( ret >= mod ) ret -= mod;
    return ret;
}

void dfs(int u, int p = -1) {
    sz[u] = 1;
    int total_left = 0, total_right = 0;
    for( auto it: adj[u] ) {
        if(it != p) {
            dfs(it, u);
            sz[u] += sz[it];
            if(dir[mp(u, it)]) {
                total_left += sz[it];
                int i; fr(i, 1, sz[it]) {
                    dp[it][i] += dp[it][i-1];
                    if(dp[it][i] >= mod) dp[it][i] -= mod;
                }
            } else {
                total_right += sz[it];
                int i; fb(i, sz[it]-1, 1) {
                    dp[it][i] += dp[it][i+1];
                    if(dp[it][i] >= mod) dp[it][i] -= mod;
                }
            }
        }
    }
    if(sz[u] == 1) { dp[u][1] = 1;}
    else {
        int left[2][total_left+1], right[2][total_right+1];
        ms(left, 0); ms(right, 0);
        int left_p = 0, left_n = 1, right_p = 0, right_n = 1;
        left[left_p][0] = right[right_p][0] = 1;
        int left_count = total_left;
        int right_count = total_right;
        total_left = total_right = 0;
        for( auto it: adj[u] ) {
            if(it != p) {
                if(dir[mp(u, it)]) {
                    total_left += sz[it];
                    int i, j; 
                    fr(i, 0, left_count) {
                        if(left[left_p][i]) {
                            fr(j, 1, sz[it]) {
                                int v = 1;
                                v = 1LL * nCr(i+j, j) * dp[it][j] % mod;
                                v = 1LL * v * left[left_p][i] % mod;
                                v = 1LL * v * nCr(total_left - (i+j), sz[it] - j) % mod; 
                                left[left_n][i+j] += v;
                                if(left[left_n][i+j] >= mod) left[left_n][i+j] -= mod;
                            }
                            left[left_p][i] = 0;
                        }
                    }
                    swap(left_p, left_n);
                } else {
                    total_right += sz[it];
                    int i, j; fr(i, 0, right_count) {
                        if(right[right_p][i]) {
                            fr(j, 1, sz[it]) {
                                int v = 1;
                                v = 1LL * nCr(i+j, j) * dp[it][sz[it] - j + 1] % mod;
                                v = 1LL * v * right[right_p][i] % mod;
                                v = 1LL * v * nCr(total_right - i - j, sz[it] - j) % mod; 
                                right[right_n][i+j] += v;
                                if(right[right_n][i+j] >= mod) right[right_n][i+j] -= mod;
                            }
                            right[right_p][i] = 0;
                        }
                    }
                    swap(right_p, right_n);
                }
            }
        }
        total_left = left_count;
        total_right = right_count;
        int i, j;
        fr(i, 1, sz[u]) {
            dp[u][i] = 0;
            fr(j, 0, min(i-1, total_left)) {
                int x = total_left - j;
                int v = left[left_p][j] % mod;
                v = 1LL * v * nCr(i-1, j) % mod;
                v = 1LL * v * nCr(sz[u] - i, x) % mod;
                if(sz[u] - i - x >= 0 && sz[u] - i - x <= total_right)
                    v = 1LL * v * right[right_p][sz[u] - i - x] % mod;
                else 
                    v = 0;
                dp[u][i] += v;
                if(dp[u][i] >= mod) dp[u][i] -= mod;
            }
        }
    }
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  FILL(NcR,-1);
  
  
  int n; scanf("&d",n);

  vii EL;
  rep(i,0,n-1){
      int u,v;
      scanf("&d &d",u,v);
      adj[u].push_back(v);
      adj[v].pb(u);
      ii x = {u,v};
      EL.pb(x);
  }
  int high[n+1];
  ms(high,0);
  queue<int> q;
  high[1]=1;
  q.push(1);
  while(!q.empty()){
      int u = q.front();
      q.pop();
      FOR(v,adj[u]){
          if(high[v]) continue;
          high[v] = (high[u]==1)?2:1;
          q.push(v);
      }
  }
 int i;
    fr(i, 0, n-2) {
        auto&[x,y]=EL[i];
        if(high[x]==2) swap(x,y);
 
        //cout << "YES";
        dir[mp(x, y)] = 1;
        dir[mp(y, x)] = 0;
        
  }
    int ans = 0, mult = 1;
    srand (time(NULL));
    int u = rand()%n +1;
    
    dfs(u);
    
    int m=n;
    fr(i, 1, n) { 
        //cerr<< dp[1][i] << " ";
        mult = 1LL * mult * m % MOD; m --;
        mult = 1LL * mult * power(i, MOD-2) % MOD;
        ans += dp[u][i]; ans %= MOD; 
        
    } 
    cout << 1LL * ans * mult *2 % MOD << "\n";
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) Think reversely
3) long long
3) Calm down you can do it!!!
*/
