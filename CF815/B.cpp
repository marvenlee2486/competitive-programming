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

void solve(){
    ll n,m;
    cin >> n >> m;
    ll a[n];
    rep(i,0,n) cin >> a[i];
    ll sum = 0;
    rep(i,0,n){
        if(i!=0){
            if(a[i]!=a[i-1]) sum += i*(n-i);
        }
    }
    sum += n*(n+1)/2;

    while(m--){
        int i,x;
        cin >> i >> x;
        i--;
        if(i!=0 && a[i]==a[i-1] && x!=a[i]) sum += i*(n-i);
        if(i!=0 && a[i]!=a[i-1] && x==a[i-1]) sum -= i*(n-i);
        if(i!=n-1 && a[i]==a[i+1] && x!=a[i]) sum += (i+1)*(n-i-1);
        if(i!=n-1 && a[i]!=a[i+1] && x==a[i+1])sum -= (i+1)*(n-i-1);
        a[i] =x;
        cout << sum << "\n";
    }
    


}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  while(t--) solve();
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
