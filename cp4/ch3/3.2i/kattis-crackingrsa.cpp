

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
int a,b,c;

ll ExtendedGcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    ll newx, newy;
    ll ret = ExtendedGcd(b, a % b, newx, newy);

    x = newy;
    y = newx - newy * (a / b);
    return ret;
}

int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("UT.txt","w",stdout);
 int prime[1002];
 FILL(prime,0);
 prime[2]=0;
 rep(i,4,1002){
     prime[i]=1;
     i+=1;
 }
 rep(i,3,1002){
     if( prime[i]==1) {     
         i+=1;
         continue;
     }
     int d=2;
     while(d*i<1002){
         prime[d*i]=1;
         d+=1;
     }


     i+=1;
 }


int t;
cin >> t;
while(t--){
    ll n,e,p,q;
    cin >> n >> e;
    rep(i,2,1002){
        if(prime[i]) continue;

        if(n%i==0 && prime[(n/i)]==0 ){
            p = i; q = n/i;
            break;
        }
    }
    ll euler = (p-1)*(q-1);
    ll x,y;
    ll g = ExtendedGcd(e,-1*euler, x,y);
    x *= 1/g;
    y *= 1/g;
    
    if(x<0) x+= euler;
    cout << x <<  "\n";
}
    
}
  
