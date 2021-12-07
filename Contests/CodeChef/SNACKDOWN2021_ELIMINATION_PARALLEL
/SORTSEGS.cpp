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


bool isSame(int a[], int n){
    rep(i,0,n) if(a[i]!=i+1) return false;
    return true;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

 int t;
 cin >> t;
 while(t--){
    int n ;
    int k;
    cin >> n >> k;
    int arr[n];
    int ans[n];
    rep(i,0,n){
        cin >> arr[i];
        ans[i] = arr[i];
    } 

    if(isSame(ans,n)) cout << "0\n";
    else{
        int p=0;
        int pl=0;
        rep(i,0,n){
            if(arr[i]!=i+1){
                p=i;
                break;
            }
        }
        rrep(i,n-1,0){
            if(arr[i]!=i+1) {
                pl=i;
                break;
            }
        }
        sort(arr+p,arr+ min(k+p,n));
        sort(ans+max(0,pl-k+1),ans+pl+1);
        if(isSame(arr,n)|| isSame(ans,n)) cout << "1\n";
        else{
            sort(ans+p,ans+ min(k+p,n));
            sort(arr+max(0,pl-k+1),arr+pl+1);
            if(isSame(arr,n)|| isSame(ans,n)) cout << "2\n";
            else cout << "3\n";
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